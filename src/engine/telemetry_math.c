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

/* ==========================================================================
 * Phase 5B Implementations
 * ========================================================================== */

size_t ob_telemetry_detect_recapture_threats(
    const ObTelemetryFrame *frame,
    ObRecaptureThreat *out_threats,
    size_t max_threats
) {
    if (!frame || !out_threats || max_threats == 0) {
        return 0;
    }
    size_t count = 0;

    for (uint8_t s = 10; s < OB_MAX_DEPLOYED_SLOTS && count < max_threats; ++s) {
        const ObMapEntityTelemetry *enemy = &frame->map_entities[s];
        if (!enemy->is_active) continue;

        for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES && count < max_threats; ++c) {
            const ObCityTelemetry *city = &frame->cities[c];
            if (!city->exists) continue;
            /* Only check player-liberated cities and temples */
            if (!(city->ownership_mask & 0x01)) continue;

            int32_t dx = (int32_t)city->world_x - (int32_t)enemy->world_x;
            int32_t dy = (int32_t)city->world_y - (int32_t)enemy->world_y;
            int32_t dist = abs(dx) + abs(dy);

            /* Check if enemy target matches this city or enemy is within 180px and closing */
            bool targeted = (abs((int32_t)enemy->target_x - (int32_t)city->world_x) <= 16 &&
                             abs((int32_t)enemy->target_y - (int32_t)city->world_y) <= 16);
            bool approaching = (dist <= 180 &&
                                ((dx > 0 && enemy->vel_dx > 0) || (dx < 0 && enemy->vel_dx < 0) ||
                                 (dy > 0 && enemy->vel_dy > 0) || (dy < 0 && enemy->vel_dy < 0)));

            if (targeted || approaching) {
                ObRecaptureThreat *th = &out_threats[count++];
                th->enemy_slot        = s;
                th->target_city_index = c;
                th->distance_px       = dist;
                int32_t speed         = enemy->mobility_speed > 0 ? (int32_t)enemy->mobility_speed : 3;
                th->eta_ticks         = dist / speed;
                th->is_temple         = ((city->ownership_mask & 0x04) != 0);
                th->penalty_cf        = -5;
                snprintf(th->threat_summary, sizeof(th->threat_summary),
                         "ENEMY #%02u -> %s #%02u (DIST:%dpx, ETA:%dt)",
                         s, th->is_temple ? "TEMPLE" : "CITY", c, dist, th->eta_ticks);
            }
        }
    }
    return count;
}

void ob_telemetry_forecast_neutral_encounters(
    const ObTelemetryFrame *frame,
    uint8_t squad_index,
    ObNeutralSpawnForecast *out_forecast
) {
    if (!frame || !out_forecast) return;
    memset(out_forecast, 0, sizeof(*out_forecast));
    out_forecast->squad_index = squad_index;

    uint8_t terrain = 1; /* Default Plains */
    if (squad_index < OB_MAX_DEPLOYED_SLOTS && frame->map_entities[squad_index].is_active) {
        terrain = frame->map_entities[squad_index].terrain_under;
    }
    out_forecast->terrain_id = terrain;

    /* Check squad composition for recruiter classes */
    bool has_beast_master = false;
    bool has_witch = false;
    bool has_cleric = false;
    bool has_princess = false;
    bool has_wizard = false;

    if (squad_index < OB_MAX_SQUADS) {
        const ObSquadTelemetry *sq = &frame->squads[squad_index];
        for (uint8_t m = 0; m < OB_MAX_SQUAD_MEMBERS; ++m) {
            uint8_t r_id = sq->member_ids[m];
            if (r_id < OB_MAX_ROSTER_UNITS && frame->units[r_id].is_populated) {
                uint8_t cls = frame->units[r_id].class_id;
                if (cls == 13 || cls == 14) has_beast_master = true; /* Beast Tamer / Master */
                else if (cls == 18) has_witch = true;               /* Witch */
                else if (cls == 25 || cls == 26) has_cleric = true;  /* Cleric / Shaman */
                else if (cls == 28) has_princess = true;            /* Princess */
                else if (cls == 7 || cls == 8) has_wizard = true;   /* Wizard / Mage */
            }
        }
    }

    /* Has Glass Pumpkin in inventory? */
    bool has_glass_pumpkin = false;
    for (size_t i = 0; i < OB_MAX_CAMP_INVENTORY; ++i) {
        if (frame->camp_inventory[i] == 0x4D) { has_glass_pumpkin = true; break; }
    }

    switch (terrain) {
        case 2: /* Forest */
            snprintf(out_forecast->terrain_name, sizeof(out_forecast->terrain_name), "FOREST");
            snprintf(out_forecast->spawn_class_name, sizeof(out_forecast->spawn_class_name), "GHOST/SKELETON");
            out_forecast->spawn_level = 9;
            snprintf(out_forecast->recruiter_class_name, sizeof(out_forecast->recruiter_class_name), "CLERIC/HOLY");
            out_forecast->persuade_ready = has_cleric || has_princess;
            out_forecast->is_undead_ali_farm = true;
            break;
        case 3: /* Mountain */
            snprintf(out_forecast->terrain_name, sizeof(out_forecast->terrain_name), "MOUNTAIN");
            snprintf(out_forecast->spawn_class_name, sizeof(out_forecast->spawn_class_name), "GRIFFON/COCKATR");
            out_forecast->spawn_level = 8;
            snprintf(out_forecast->recruiter_class_name, sizeof(out_forecast->recruiter_class_name), "BEAST MASTER");
            out_forecast->persuade_ready = has_beast_master;
            break;
        case 5: /* Swamp */
            snprintf(out_forecast->terrain_name, sizeof(out_forecast->terrain_name), "SWAMP");
            snprintf(out_forecast->spawn_class_name, sizeof(out_forecast->spawn_class_name), "WRAITH/PHANTOM");
            out_forecast->spawn_level = 21;
            snprintf(out_forecast->recruiter_class_name, sizeof(out_forecast->recruiter_class_name), "CLERIC/HOLY");
            out_forecast->persuade_ready = has_cleric;
            out_forecast->is_undead_ali_farm = true;
            break;
        case 6: /* Desert */
            snprintf(out_forecast->terrain_name, sizeof(out_forecast->terrain_name), "DESERT");
            snprintf(out_forecast->spawn_class_name, sizeof(out_forecast->spawn_class_name), "SALAMANDER/WYRM");
            out_forecast->spawn_level = 17;
            snprintf(out_forecast->recruiter_class_name, sizeof(out_forecast->recruiter_class_name), "BEAST MASTER");
            out_forecast->persuade_ready = has_beast_master;
            break;
        case 7: /* Shallows */
        case 8: /* Deep Sea */
            snprintf(out_forecast->terrain_name, sizeof(out_forecast->terrain_name), "WATER/DEEP SEA");
            snprintf(out_forecast->spawn_class_name, sizeof(out_forecast->spawn_class_name), "OCTOPUS/KRAKEN");
            out_forecast->spawn_level = 10;
            snprintf(out_forecast->recruiter_class_name, sizeof(out_forecast->recruiter_class_name), "BEAST MASTER");
            out_forecast->persuade_ready = has_beast_master;
            break;
        default: /* Plains / Road */
            snprintf(out_forecast->terrain_name, sizeof(out_forecast->terrain_name), "PLAINS");
            snprintf(out_forecast->spawn_class_name, sizeof(out_forecast->spawn_class_name), "DRAGON/HAWKMAN");
            out_forecast->spawn_level = 7;
            snprintf(out_forecast->recruiter_class_name, sizeof(out_forecast->recruiter_class_name), "BEAST MASTER");
            out_forecast->persuade_ready = has_beast_master;
            break;
    }

    if (has_witch && has_glass_pumpkin && terrain == 3) {
        out_forecast->is_pumpkin_ali_tank = true;
    }
    if (has_wizard && (terrain == 1 || terrain == 4)) {
        out_forecast->persuade_ready = true;
    }
}

size_t ob_telemetry_audit_tarot_hand(
    const ObTelemetryFrame *frame,
    ObTarotAudit *out_audits,
    size_t max_cards
) {
    if (!frame || !out_audits || max_cards == 0) return 0;

    static const struct {
        const char *name;
        const char *draw;
        const char *battle;
        bool offensive;
    } kTarotTable[22] = {
        {"MAGICIAN",   "INT +1",         "Fire Magic AOE",      true},
        {"PRIESTESS",  "ALI +1",         "Heal 50 HP All",      false},
        {"EMPRESS",    "CHA +2",         "Full Heal All",       false},
        {"EMPEROR",    "CHA +2",         "+1 Action All",       false},
        {"HIEROPHANT", "ALI +2",         "Sleep Enemies",       false},
        {"LOVERS",     "CF +2",          "Charm Enemies",       false},
        {"CHARIOT",    "STR +2",         "Loki Physical AOE",   true},
        {"STRENGTH",   "STR +1",         "+Defense Rating",     false},
        {"HERMIT",     "INT +2",         "Merlin Lightning",    true},
        {"FORTUNE",    "CF Random",      "Flee Enemies",        false},
        {"JUSTICE",    "HP +1",          "Ice Storm AOE",       true},
        {"HANGED MAN", "STR -1",         "-Enemy Defense",      false},
        {"DEATH",      "CF -2",          "Wipe <50% HP Foes",   true},
        {"TEMPERANCE", "CF +2",          "Cure Status All",     false},
        {"DEVIL",      "CF -2",          "Asmodeus Black Magic",true},
        {"TOWER",      "ALI -2",         "Earthquake (Ground)", true},
        {"STAR",       "AGI +1",         "+Agility/Evade",      false},
        {"MOON",       "Nighttime",      "Invert Ranks",        false},
        {"SUN",        "Daytime",        "Holy AOE vs Evil",    true},
        {"JUDGEMENT",  "HP +2",          "White Magic AOE",     true},
        {"WORLD",      "All Units Buff", "Magic Shield",        false},
        {"FOOL",       "LUK +1",         "Flee Grunts",         false}
    };

    uint8_t leader_lvl = frame->units[0].is_populated ? frame->units[0].level : 5;
    size_t count = 0;

    for (uint8_t i = 0; i < frame->tarot_hand_count && count < max_cards; ++i) {
        uint8_t id = frame->tarot_hand[i];
        if (id >= 22) continue;

        ObTarotAudit *a = &out_audits[count++];
        a->card_id      = id;
        snprintf(a->card_name, sizeof(a->card_name), "%s", kTarotTable[id].name);
        snprintf(a->draw_effect, sizeof(a->draw_effect), "%s", kTarotTable[id].draw);
        snprintf(a->battle_effect, sizeof(a->battle_effect), "%s", kTarotTable[id].battle);
        a->is_offensive = kTarotTable[id].offensive;

        /* Opinion Leader Overlevel & ALI Trap: Offensive cards award kill XP & ALI deltas to Lord */
        a->leader_overlevel_risk = (a->is_offensive && leader_lvl >= 4);
    }
    return count;
}

size_t ob_telemetry_audit_special_recruits(
    const ObTelemetryFrame *frame,
    ObHeroRecruitmentAudit *out_heroes,
    size_t max_heroes
) {
    if (!frame || !out_heroes || max_heroes == 0) return 0;

    static const struct {
        const char *name;
        const char *stage;
        uint8_t min_cf;
        uint8_t max_cf;
        uint8_t min_ali;
        uint8_t max_ali;
        const char *item;
        const char *warn;
    } kHeroDefs[18] = {
        {"LANS",     "Castle of Warren", 0,   100, 0,   100, "None",           ""},
        {"WARREN",   "Castle of Warren", 0,   100, 0,   100, "None",           ""},
        {"CANOPUS",  "Sharom District",  0,   100, 0,   100, "Wing of Victory",""},
        {"GILBERT",  "Sharom District",  0,   100, 0,   100, "Fight w/ Canopus",""},
        {"ASHE",     "Slums of Zenobia", 0,   100, 0,   100, "By'Roit Yes",    ""},
        {"LYON",     "Slums of Zenobia", 0,   100, 0,   100, "20,000 Goth",    ""},
        {"AISHA",    "Island Avalon",    51,  100, 0,   100, "Hidden Temple",  ""},
        {"NORN",     "Diaspola",         0,   100, 0,   100, "Refuse to Kill", ""},
        {"RAUNY",    "Valley of Kastro", 51,  100, 0,   100, "Hidden Temple",  ""},
        {"SARADIN",  "Balmorian Ruins",  51,  100, 0,   100, "Bell of Light",  ""},
        {"SLUST",    "Muspelm",          67,  100, 70,  100, "Star of Heroes", ""},
        {"FENRIL",   "Organa",           67,  100, 70,  100, "Star of Heroes", ""},
        {"TRISTAN",  "City of Malano",   0,   100, 0,   100, "Key of Destiny", ""},
        {"YUSHIS",   "Antalia",          67,  100, 0,   100, "Hidden Temple",  ""},
        {"DEBONAIR", "Shangrila",        0,   100, 0,   100, "Recruited Norn", ""},
        {"FOGEL",    "Shiguld",          67,  100, 70,  100, "Star of Heroes", ""},
        {"DENEB",    "Deneb's Garden",   0,   33,  0,   100, "Golden Bough",   "Blocks Halloween Upgrade!"},
        {"GALF",     "Antanjyl",         0,   15,  0,   30,  "Brunhild Sword", "Locks Out Top 3 Endings!"}
    };

    uint8_t cf = frame->chaos_frame;
    uint8_t leader_ali = frame->units[0].is_populated ? frame->units[0].ali : 50;

    size_t count = 0;
    for (size_t i = 0; i < 18 && count < max_heroes; ++i) {
        ObHeroRecruitmentAudit *h = &out_heroes[count++];
        h->hero_id = (uint8_t)i;
        snprintf(h->hero_name, sizeof(h->hero_name), "%s", kHeroDefs[i].name);
        snprintf(h->stage_found, sizeof(h->stage_found), "%s", kHeroDefs[i].stage);
        snprintf(h->required_item_name, sizeof(h->required_item_name), "%s", kHeroDefs[i].item);
        snprintf(h->tradeoff_warning, sizeof(h->tradeoff_warning), "%s", kHeroDefs[i].warn);

        h->prereq_cf_met  = (cf >= kHeroDefs[i].min_cf && cf <= kHeroDefs[i].max_cf);
        h->prereq_ali_met = (leader_ali >= kHeroDefs[i].min_ali && leader_ali <= kHeroDefs[i].max_ali);
        h->prereq_item_met = true; /* Simplified item presence flag */

        /* Check if recruited by bitflag or name in roster */
        h->is_recruited = false;
        for (uint8_t u = 0; u < OB_MAX_ROSTER_UNITS; ++u) {
            if (frame->units[u].is_populated && frame->units[u].template_id == (i + 1)) {
                h->is_recruited = true;
                break;
            }
        }

        if (h->is_recruited) {
            snprintf(h->status_summary, sizeof(h->status_summary), "RECRUITED (IN ROSTER)");
        } else if (h->prereq_cf_met && h->prereq_ali_met) {
            snprintf(h->status_summary, sizeof(h->status_summary), "READY (CF/ALI OK)");
        } else {
            snprintf(h->status_summary, sizeof(h->status_summary), "LOCKED (CF:%u..%u ALI:%u..%u)",
                     kHeroDefs[i].min_cf, kHeroDefs[i].max_cf, kHeroDefs[i].min_ali, kHeroDefs[i].max_ali);
        }
    }
    return count;
}

void ob_telemetry_track_zodiac_stones(
    const ObTelemetryFrame *frame,
    ObZodiacQuestStatus *out_status
) {
    if (!frame || !out_status) return;
    memset(out_status, 0, sizeof(*out_status));

    uint8_t stone_cnt = 0;
    uint16_t mask = 0;

    for (size_t i = 0; i < OB_MAX_CAMP_INVENTORY; ++i) {
        uint8_t itm = frame->camp_inventory[i];
        if (itm == 0x45) out_status->quicksilver_in_hand = true;
        else if (itm == 0x46) out_status->gem_of_doun_in_hand = true;
        else if (itm == 0x47) out_status->olden_orb_in_hand = true;
        else if (itm == 0x48) out_status->gem_of_truth_in_hand = true;
        else if (itm == 0x49) out_status->tablet_of_yaru_in_hand = true;
        else if (itm >= 0x50 && itm <= 0x5B) {
            uint8_t s_idx = itm - 0x50;
            if (!(mask & (1U << s_idx))) {
                mask |= (1U << s_idx);
                stone_cnt++;
            }
        }
        else if (itm == 0x5C) out_status->beehive_in_hand = true;
        else if (itm == 0x5D) out_status->sentoul_demon_in_hand = true;
        else if (itm == 0x5E) out_status->ginger_cake_in_hand = true;
        else if (itm == 0x21) out_status->wind_weapons_mask |= 1; /* Notos */
        else if (itm == 0x22) out_status->wind_weapons_mask |= 2; /* Zephyrus */
        else if (itm == 0x23) out_status->wind_weapons_mask |= 4; /* Boreas */
        else if (itm == 0x24) out_status->wind_weapons_mask |= 8; /* Euros */
    }

    out_status->stones_collected_count = stone_cnt;
    out_status->stones_mask            = mask;
    out_status->pearl_stone_ready      = out_status->ginger_cake_in_hand && out_status->tablet_of_yaru_in_hand;
    out_status->fireseal_ready         = ((out_status->wind_weapons_mask & 0x0F) == 0x0F);
}

void ob_telemetry_analyze_squad_mobility(
    const ObTelemetryFrame *frame,
    uint8_t squad_index,
    ObSquadMobilityAnalysis *out_analysis
) {
    if (!frame || !out_analysis) return;
    memset(out_analysis, 0, sizeof(*out_analysis));
    out_analysis->squad_index = squad_index;

    static const char *const kMoveNames[10] = {
        "HIGH SKY", "LOW SKY", "FAST", "SNOW", "NORMAL", "FOREST", "MOUNTAIN", "SLOW", "SHALLOWS", "DEEP SEA"
    };

    uint8_t m_type = 4; /* Normal */
    if (squad_index < OB_MAX_DEPLOYED_SLOTS && frame->map_entities[squad_index].is_active) {
        m_type = frame->map_entities[squad_index].move_type % 10;
    }
    out_analysis->move_type_id = m_type;
    snprintf(out_analysis->move_type_name, sizeof(out_analysis->move_type_name), "%s", kMoveNames[m_type]);

    /* Count flying units */
    uint8_t flyers = 0;
    uint32_t total_ali = 0;
    uint8_t m_count = 0;

    if (squad_index < OB_MAX_SQUADS) {
        const ObSquadTelemetry *sq = &frame->squads[squad_index];
        for (uint8_t m = 0; m < OB_MAX_SQUAD_MEMBERS; ++m) {
            uint8_t r_id = sq->member_ids[m];
            if (r_id < OB_MAX_ROSTER_UNITS && frame->units[r_id].is_populated) {
                uint8_t cls = frame->units[r_id].class_id;
                /* Flyers: Hawkman(11/12), Angel/Cherub/Seraph(20/21/22), Griffon/Cockatris(44/45), Wyrm/Wyvern(46/47) */
                if (cls == 11 || cls == 12 || cls == 20 || cls == 21 || cls == 22 ||
                    cls == 44 || cls == 45 || cls == 46 || cls == 47) {
                    flyers++;
                }
                total_ali += frame->units[r_id].ali;
                m_count++;
            }
        }
    }

    out_analysis->flyers_count = flyers;
    out_analysis->flyers_needed_for_sky = (flyers >= 2) ? 0 : (2 - flyers);

    uint8_t avg_ali = (m_count > 0) ? (uint8_t)(total_ali / m_count) : 50;
    out_analysis->is_day_favored   = (avg_ali >= 55);
    out_analysis->is_night_favored = (avg_ali <= 45);

    snprintf(out_analysis->synergy_summary, sizeof(out_analysis->synergy_summary),
             "%s (%s) | %s",
             out_analysis->move_type_name,
             (flyers >= 2) ? "SKY READY" : "NEEDS FLYER",
             out_analysis->is_day_favored ? "SOLAR/DAY SYNERGY" : (out_analysis->is_night_favored ? "NIGHT SYNERGY" : "BALANCED"));
}

void ob_telemetry_preview_lord_archetype(
    const uint8_t *wram,
    ObLordArchetypePreview *out_preview
) {
    if (!wram || !out_preview) return;
    memset(out_preview, 0, sizeof(*out_preview));

    uint8_t raw_ali = wram[0x0C1A]; /* Unit 0 ALI */
    if (raw_ali >= 65) {
        out_preview->projected_archetype   = 0;
        out_preview->projected_starting_ali = raw_ali;
        snprintf(out_preview->archetype_name, sizeof(out_preview->archetype_name), "HOLY KNIGHT (ICECLOUD)");
        snprintf(out_preview->front_skill, sizeof(out_preview->front_skill), "2x BANISH");
        snprintf(out_preview->back_skill, sizeof(out_preview->back_skill), "1x ICECLOUD (ALL)");
        snprintf(out_preview->starting_troops, sizeof(out_preview->starting_troops), "3 FIGHTERS + 1 CLERIC");
    } else if (raw_ali >= 50) {
        out_preview->projected_archetype   = 1;
        out_preview->projected_starting_ali = raw_ali;
        snprintf(out_preview->archetype_name, sizeof(out_preview->archetype_name), "WARRIOR (IAINUKI)");
        snprintf(out_preview->front_skill, sizeof(out_preview->front_skill), "3x SLASH");
        snprintf(out_preview->back_skill, sizeof(out_preview->back_skill), "1x IAINUKI");
        snprintf(out_preview->starting_troops, sizeof(out_preview->starting_troops), "3 FIGHTERS + 1 VALKYRIE");
    } else if (raw_ali >= 40) {
        out_preview->projected_archetype   = 2;
        out_preview->projected_starting_ali = raw_ali;
        snprintf(out_preview->archetype_name, sizeof(out_preview->archetype_name), "BEAST TACTICIAN (THUNDER)");
        snprintf(out_preview->front_skill, sizeof(out_preview->front_skill), "2x SLASH");
        snprintf(out_preview->back_skill, sizeof(out_preview->back_skill), "1x THUNDER (ALL)");
        snprintf(out_preview->starting_troops, sizeof(out_preview->starting_troops), "3 FIGHTERS + 1 BEASTMAN");
    } else {
        out_preview->projected_archetype   = 3;
        out_preview->projected_starting_ali = raw_ali;
        snprintf(out_preview->archetype_name, sizeof(out_preview->archetype_name), "SORCERER (PHANTOM)");
        snprintf(out_preview->front_skill, sizeof(out_preview->front_skill), "2x POISON");
        snprintf(out_preview->back_skill, sizeof(out_preview->back_skill), "1x PHANTOM (ALL)");
        snprintf(out_preview->starting_troops, sizeof(out_preview->starting_troops), "3 FIGHTERS + 1 WIZARD");
    }
}

void ob_telemetry_audit_hidden_poi(
    const ObTelemetryFrame *frame,
    ObHiddenPoISummary *out_summary
) {
    if (!frame || !out_summary) return;
    memset(out_summary, 0, sizeof(*out_summary));

    for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        const ObCityTelemetry *city = &frame->cities[c];
        if (!city->exists) continue;
        out_summary->total_cities++;

        bool is_temple = ((city->ownership_mask & 0x04) != 0);
        bool is_hidden = ((city->ownership_mask & 0x02) != 0);
        bool is_liberated = ((city->ownership_mask & 0x01) != 0);

        if (!is_liberated) {
            out_summary->unliberated_cities_count++;
        }

        if (is_hidden) {
            if (is_temple) {
                out_summary->hidden_temples_count++;
                if (!is_liberated) out_summary->unrevealed_temples_count++;
            } else {
                out_summary->hidden_cities_count++;
                if (!is_liberated) out_summary->unrevealed_cities_count++;
            }
        }
    }

    /* Buried treasures across story_bitmap[150..224] (TREASURE_BIT_B) */
    out_summary->buried_treasures_total = 4; /* Canonical 3-4 treasures per map */
    uint8_t found = 0;
    for (uint16_t b = 150; b < 225; ++b) {
        if (frame->story_bitmap[b] != 0) found++;
    }
    out_summary->buried_treasures_found = (found > 4) ? 4 : found;
}
