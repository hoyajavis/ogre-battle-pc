#include "telemetry_math.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ROM Offsets for Promotion Directed Graph & Thresholds (Bank $09) */
#define OB_ROM_PROMO_PTR_TABLE   0x04AD4CU
#define OB_ROM_PROMO_MIN_LVL     0x04AED4U
#define OB_ROM_PROMO_MIN_ALI     0x04AF21U
#define OB_ROM_PROMO_MAX_ALI     0x04AF6EU
#define OB_ROM_PROMO_MIN_CHA     0x04AFBBU
#define OB_ROM_PROMO_BRANCH_CNT  77U

/* Helper: Check if an item ID exists in Camp Inventory ($7E:157E..$7E:15FB) */
static bool item_in_camp_stock(const uint8_t *wram, uint8_t item_id) {
    if (!wram || item_id == 0) {
        return false;
    }
    for (uint32_t i = 0; i < OB_MAX_CAMP_INVENTORY; ++i) {
        if (wram[0x157E + i] == item_id) {
            return true;
        }
    }
    return false;
}

size_t ob_telemetry_eval_promotions(
    const ObUnitTelemetry *unit,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    ObPromotionCheck *out_branches,
    size_t max_branches
) {
    if (!unit || !rom || rom_size < OB_ROM_BASE_SIZE_BYTES || !out_branches || max_branches == 0) {
        return 0;
    }
    if (unit->class_id == 0 || unit->class_id > 125) {
        return 0;
    }

    size_t count = 0;
    uint32_t ptr_offset = OB_ROM_PROMO_PTR_TABLE + (uint32_t)(unit->class_id - 1U) * 2U;
    uint16_t snes_ptr = (uint16_t)rom[ptr_offset] | ((uint16_t)rom[ptr_offset + 1U] << 8);

    if (snes_ptr >= 0x8000U) {
        uint32_t target_list_off = 0x048000U + (uint32_t)(snes_ptr - 0x8000U);
        while (target_list_off < rom_size && rom[target_list_off] != 0 && count < max_branches) {
            uint8_t target_cid = rom[target_list_off++];
            if (target_cid == 0 || target_cid > OB_ROM_PROMO_BRANCH_CNT) {
                continue;
            }
            uint32_t b_idx = (uint32_t)(target_cid - 1U);
            ObPromotionCheck *chk = &out_branches[count++];
            memset(chk, 0, sizeof(*chk));

            chk->source_class_id = unit->class_id;
            chk->target_class_id = target_cid;
            ob_telemetry_get_class_name(rom, rom_size, target_cid, chk->target_class_name, sizeof(chk->target_class_name));

            chk->req_min_level = rom[OB_ROM_PROMO_MIN_LVL + b_idx];
            chk->req_min_ali   = rom[OB_ROM_PROMO_MIN_ALI + b_idx];
            chk->req_max_ali   = rom[OB_ROM_PROMO_MAX_ALI + b_idx];
            chk->req_min_cha   = rom[OB_ROM_PROMO_MIN_CHA + b_idx];

            chk->level_delta = (int8_t)((int)chk->req_min_level - (int)unit->level);
            chk->cha_delta   = (int8_t)((int)chk->req_min_cha - (int)unit->cha);

            if (unit->ali < chk->req_min_ali) {
                chk->ali_delta = (int8_t)((int)chk->req_min_ali - (int)unit->ali); /* Positive: needs +ALI */
            } else if (unit->ali > chk->req_max_ali) {
                chk->ali_delta = (int8_t)((int)chk->req_max_ali - (int)unit->ali); /* Negative: needs -ALI */
            } else {
                chk->ali_delta = 0;
            }

            chk->required_relic = 0;
            chk->relic_in_stock = true;
            chk->eligible_now = (chk->level_delta <= 0) &&
                                (chk->cha_delta <= 0) &&
                                (chk->ali_delta == 0);
        }
    }

    /* Evaluate Special Item-Triggered Promotions (Bank $06: $0317A6-$03181A) */
    struct {
        uint8_t src_class;
        uint8_t dst_class;
        uint8_t relic_id;
    } const kRelicPromos[] = {
        { 12, 14, 0x59 }, /* Monk/Cleric/Shaman/Muse -> Princess (Royal Crown 0x59) */
        { 10, 14, 0x59 }, /* Amazon -> Princess (Royal Crown 0x59)                  */
        { 20, 21, 0x55 }, /* Mage -> Sorcerer (Undead Staff 0x55)                   */
        { 21, 22, 0x56 }, /* Sorcerer -> Lich (Undead Ring 0x56)                    */
        {  2, 74, 0x57 }, /* Knight -> Vampyre (Blood Kiss 0x57)                    */
        {  1, 77, 0x58 }, /* Fighter -> Pumpkin (Rotten Pumpkin 0x58)               */
        { 17, 18, 0x5A }  /* Dragoner -> Dragon Master (Stone of Dragos 0x5A)       */
    };

    for (size_t r = 0; r < sizeof(kRelicPromos) / sizeof(kRelicPromos[0]) && count < max_branches; ++r) {
        if (unit->class_id == kRelicPromos[r].src_class) {
            ObPromotionCheck *chk = &out_branches[count++];
            memset(chk, 0, sizeof(*chk));
            chk->source_class_id = unit->class_id;
            chk->target_class_id = kRelicPromos[r].dst_class;
            ob_telemetry_get_class_name(rom, rom_size, chk->target_class_id, chk->target_class_name, sizeof(chk->target_class_name));
            chk->req_min_level   = 1;
            chk->req_min_ali     = 0;
            chk->req_max_ali     = 100;
            chk->req_min_cha     = 0;
            chk->level_delta     = 0;
            chk->ali_delta       = 0;
            chk->cha_delta       = 0;
            chk->required_relic  = kRelicPromos[r].relic_id;
            chk->relic_in_stock  = item_in_camp_stock(wram, chk->required_relic) ||
                                   (unit->equipped_item == chk->required_relic);
            chk->eligible_now    = chk->relic_in_stock;
        }
    }

    return count;
}

void ob_telemetry_predict_kill_morality(
    const ObUnitTelemetry *attacker,
    const ObUnitTelemetry *defender,
    bool disable_overlevel_ali_penalty,
    ObMoralityDriftForecast *out_forecast
) {
    if (!attacker || !defender || !out_forecast) {
        return;
    }
    memset(out_forecast, 0, sizeof(*out_forecast));
    out_forecast->attacker_slot = attacker->slot_index;
    out_forecast->defender_slot = defender->slot_index;

    int lvl_diff = (int)defender->level - (int)attacker->level;

    /* 1. Charisma (CHA) Kill Delta (Bank $03 level comparison rule) */
    int cha_delta = 0;
    if (lvl_diff >= 2) {
        cha_delta = +2;
    } else if (lvl_diff >= 0) {
        cha_delta = +1;
    } else if (lvl_diff <= -3) {
        cha_delta = -2;
        out_forecast->overlevel_penalty = true;
    } else {
        cha_delta = -1;
        out_forecast->overlevel_penalty = true;
    }

    /* 2. Alignment (ALI) Kill Delta (Level diff + Target ALI polarity + Undead bonus) */
    int ali_delta = 0;
    bool target_is_undead_or_evil = ((defender->status_mask & 0x20) != 0) || (defender->ali < 30);
    bool target_is_holy           = (defender->ali >= 70) && ((defender->status_mask & 0x20) == 0);

    if (target_is_undead_or_evil) {
        ali_delta += 2;
    } else if (target_is_holy) {
        ali_delta -= 3;
        if (attacker->ali >= 60) {
            out_forecast->holy_on_law_penalty = true;
        }
    }

    if (lvl_diff >= 2) {
        ali_delta += 2;
    } else if (lvl_diff <= -2) {
        if (!disable_overlevel_ali_penalty) {
            ali_delta += (lvl_diff < -6) ? -6 : lvl_diff;
        }
    }

    out_forecast->predicted_ali_delta = (int8_t)ali_delta;
    out_forecast->predicted_cha_delta = (int8_t)cha_delta;
}

void ob_telemetry_eval_engagement(
    const ObMapEntityTelemetry *player_entity,
    const ObMapEntityTelemetry *enemy_entity,
    const ObCombatTelemetry *combat,
    ObTacticalEngagementForecast *out_forecast
) {
    if (!out_forecast) {
        return;
    }
    memset(out_forecast, 0, sizeof(*out_forecast));

    if (player_entity && enemy_entity && player_entity->is_active && enemy_entity->is_active) {
        out_forecast->player_deployed_slot = player_entity->deployed_slot;
        out_forecast->enemy_deployed_slot  = enemy_entity->deployed_slot;

        int32_t dx = (int32_t)enemy_entity->world_x - (int32_t)player_entity->world_x;
        int32_t dy = (int32_t)enemy_entity->world_y - (int32_t)player_entity->world_y;
        int32_t dist = abs(dx) + abs(dy);
        out_forecast->manhattan_distance_px = dist;

        /* Relative closing speed along separation vector */
        int32_t rel_vx = (int32_t)player_entity->vel_dx - (int32_t)enemy_entity->vel_dx;
        int32_t rel_vy = (int32_t)player_entity->vel_dy - (int32_t)enemy_entity->vel_dy;
        int32_t closing = 0;
        if (dx != 0) {
            closing += (dx > 0) ? rel_vx : -rel_vx;
        }
        if (dy != 0) {
            closing += (dy > 0) ? rel_vy : -rel_vy;
        }
        out_forecast->closing_speed_px_per_tick = closing;
        out_forecast->estimated_ticks_to_contact = (closing > 0) ? (dist / closing) : -1;
    }

    if (combat) {
        int16_t margin = (int16_t)((int32_t)combat->player_clash_damage - (int32_t)combat->enemy_clash_damage);
        out_forecast->clash_damage_margin  = margin;
        out_forecast->player_winning_clash = (margin >= 0);
    }
}

size_t ob_telemetry_match_city_liberators(
    const ObTelemetryFrame *frame,
    ObCityLiberationMatch *out_matches,
    size_t max_matches
) {
    if (!frame || !out_matches || max_matches == 0) {
        return 0;
    }

    size_t count = 0;
    for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES && count < max_matches; ++c) {
        const ObCityTelemetry *city = &frame->cities[c];
        if (!city->exists) {
            continue;
        }
        /* Focus on unliberated cities (bit 0 == 0) */
        if ((city->ownership_mask & 0x01) != 0) {
            continue;
        }

        uint8_t best_squad = 0;
        uint8_t best_dist  = 255;
        for (uint8_t s = 0; s < 10; ++s) {
            if (!frame->map_entities[s].is_active && frame->squads[s].member_count == 0) {
                continue;
            }
            uint8_t sq_ali = frame->squads[s].avg_alignment;
            uint8_t dist = (uint8_t)abs((int)sq_ali - (int)city->compatibility);
            if (dist < best_dist) {
                best_dist  = dist;
                best_squad = s;
            }
        }

        ObCityLiberationMatch *m = &out_matches[count++];
        m->city_index            = c;
        m->recommended_squad_id  = best_squad;
        m->ali_mismatch_distance = best_dist;
        if (best_dist <= 12) {
            m->predicted_cf_delta = +2;
        } else if (best_dist <= 25) {
            m->predicted_cf_delta = +1;
        } else if (best_dist <= 40) {
            m->predicted_cf_delta = 0;
        } else {
            m->predicted_cf_delta = -2;
        }
    }
    return count;
}

void ob_telemetry_audit_ending(
    const ObTelemetryFrame *frame,
    ObEndingAudit *out_audit
) {
    if (!frame || !out_audit) {
        return;
    }
    memset(out_audit, 0, sizeof(*out_audit));

    uint8_t cf = frame->chaos_frame;
    uint8_t leader_ali = frame->units[0].is_populated ? frame->units[0].ali : 50;
    bool has_royal_heroes = ((frame->story_bitmap[230] & 0x07) == 0x07); /* Tristan/Rauny/Debonair bits */

    if (cf >= 80 && leader_ali >= 65 && has_royal_heroes) {
        out_audit->projected_ending_id = 21;
        snprintf(out_audit->ending_name, sizeof(out_audit->ending_name), "THE WORLD");
        snprintf(out_audit->nearest_alt_name, sizeof(out_audit->nearest_alt_name), "THE SUN (No Tristan)");
        snprintf(out_audit->audit_summary, sizeof(out_audit->audit_summary),
                 "CF=%u (>=80 OK), Lord ALI=%u (>=65 OK), Royal Heroes Recruited (OK)", cf, leader_ali);
    } else if (cf >= 80 && leader_ali >= 65) {
        out_audit->projected_ending_id = 19;
        snprintf(out_audit->ending_name, sizeof(out_audit->ending_name), "THE SUN");
        snprintf(out_audit->nearest_alt_name, sizeof(out_audit->nearest_alt_name), "THE WORLD (Recruit Tristan)");
        snprintf(out_audit->audit_summary, sizeof(out_audit->audit_summary),
                 "CF=%u (>=80 OK), Lord ALI=%u (>=65 OK), Missing Royal Trio Flag", cf, leader_ali);
    } else if (cf >= 60 && leader_ali >= 50) {
        out_audit->projected_ending_id = 17;
        snprintf(out_audit->ending_name, sizeof(out_audit->ending_name), "THE STAR");
        snprintf(out_audit->nearest_alt_name, sizeof(out_audit->nearest_alt_name), "THE SUN (Needs CF>=80)");
        snprintf(out_audit->audit_summary, sizeof(out_audit->audit_summary),
                 "CF=%u (60..79), Lord ALI=%u (>=50) -> High-Moral Republic Track", cf, leader_ali);
    } else if (cf >= 40 && leader_ali >= 35) {
        out_audit->projected_ending_id = 8;
        snprintf(out_audit->ending_name, sizeof(out_audit->ending_name), "JUSTICE");
        snprintf(out_audit->nearest_alt_name, sizeof(out_audit->nearest_alt_name), "THE STAR (Needs CF>=60)");
        snprintf(out_audit->audit_summary, sizeof(out_audit->audit_summary),
                 "CF=%u (40..59), Lord ALI=%u (35..64) -> Balanced Order Track", cf, leader_ali);
    } else if (cf < 25 || leader_ali < 20) {
        out_audit->projected_ending_id = 15;
        snprintf(out_audit->ending_name, sizeof(out_audit->ending_name), "THE DEVIL");
        snprintf(out_audit->nearest_alt_name, sizeof(out_audit->nearest_alt_name), "THE TOWER (CF 25..39)");
        snprintf(out_audit->audit_summary, sizeof(out_audit->audit_summary),
                 "CF=%u (<25) or Lord ALI=%u (<20) -> Dark Conquerer Track", cf, leader_ali);
    } else {
        out_audit->projected_ending_id = 16;
        snprintf(out_audit->ending_name, sizeof(out_audit->ending_name), "THE TOWER");
        snprintf(out_audit->nearest_alt_name, sizeof(out_audit->nearest_alt_name), "JUSTICE (Needs CF>=40)");
        snprintf(out_audit->audit_summary, sizeof(out_audit->audit_summary),
                 "CF=%u, Lord ALI=%u -> Low Reputation Military Rule Track", cf, leader_ali);
    }
}
