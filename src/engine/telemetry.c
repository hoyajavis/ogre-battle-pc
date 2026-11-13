#include "telemetry.h"
#include <string.h>
#include <stdio.h>

static inline uint16_t read_u16_le(const uint8_t *buf, uint32_t offset) {
    return (uint16_t)buf[offset] | ((uint16_t)buf[offset + 1] << 8);
}

static inline int16_t read_s16_le(const uint8_t *buf, uint32_t offset) {
    return (int16_t)read_u16_le(buf, offset);
}

static inline uint32_t read_u32_le(const uint8_t *buf, uint32_t offset) {
    return (uint32_t)buf[offset] |
           ((uint32_t)buf[offset + 1] << 8) |
           ((uint32_t)buf[offset + 2] << 16) |
           ((uint32_t)buf[offset + 3] << 24);
}

static ObScreenCategory classify_screen_mode(const uint8_t *wram, const ObCombatTelemetry *combat) {
    uint8_t cb = wram[0x00CB];
    uint8_t cc = wram[0x00CC];
    uint16_t m07a2 = read_u16_le(wram, 0x07A2);
    uint32_t goth = read_u32_le(wram, 0x1578);

    if (combat->in_combat) {
        return OB_SCREEN_COMBAT_CLASH;
    }
    /* Before campaign initialization, Goth == 0 and Lord template == 0 */
    if (goth == 0 && wram[0x07BA] == 0) {
        if (cb >= 1 && cb <= 6 && wram[0x00D4] != 0) {
            return OB_SCREEN_WARREN_QUIZ;
        }
        return OB_SCREEN_TITLE_BOOT;
    }
    /* Check if active deployed squad 0 has valid world coordinates */
    int16_t sq0_x = read_s16_le(wram, 0x18AF);
    if (sq0_x != 0x7FFF && sq0_x != 0 && sq0_x != -1) {
        return OB_SCREEN_TACTICAL_MAP;
    }
    if (m07a2 != 0 || cc >= 2) {
        return OB_SCREEN_WORLD_MAP;
    }
    return OB_SCREEN_CAMP_ROSTER;
}

void ob_telemetry_poll_vblank(
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t frame_counter,
    ObTelemetryFrame *out_frame
) {
    (void)rom;
    (void)rom_size;
    if (!wram || !out_frame) {
        return;
    }

    memset(out_frame, 0, sizeof(*out_frame));
    out_frame->frame_counter = frame_counter;

    /* 1. Engine, Screen, Camera & Audio State (Domain J) */
    out_frame->raw_mode_cb   = wram[0x00CB];
    out_frame->raw_mode_cc   = wram[0x00CC];
    out_frame->raw_mode_07a2 = read_u16_le(wram, 0x07A2);
    out_frame->bgm_track_id  = wram[0x00D4];
    out_frame->sfx_last_id   = wram[0x00D5];
    out_frame->camera_world_x = read_s16_le(wram, 0x0420);
    out_frame->camera_world_y = read_s16_le(wram, 0x0422);

    /* Scan OAM mirror ($7E:0100..$7E:01FF) for active tactical sword cursor (tile 0xCE or 0xCC) */
    out_frame->cursor_screen_x = -1;
    out_frame->cursor_screen_y = -1;
    for (uint32_t oam_off = 0x0100; oam_off < 0x0200; oam_off += 4) {
        uint8_t sx = wram[oam_off];
        uint8_t sy = wram[oam_off + 1];
        uint8_t tile = wram[oam_off + 2];
        if ((tile == 0xCE || tile == 0xCC) && sy < 224) {
            out_frame->cursor_screen_x = (int16_t)sx;
            out_frame->cursor_screen_y = (int16_t)sy;
            break;
        }
    }

    /* 2. Global Campaign, Economy & Reputation Registers (Tier 1) */
    memcpy(out_frame->lord_profile, &wram[0x07A4], 17);
    out_frame->stages_cleared_cnt = read_u16_le(wram, 0x1576);
    out_frame->goth_treasury      = read_u32_le(wram, 0x1578);
    out_frame->chaos_frame        = wram[0x157C];
    out_frame->chaos_frame_sub    = wram[0x157D];
    out_frame->boss_aggro_state   = wram[0x15FC];
    memcpy(out_frame->stage_event_locks, &wram[0x1659], 5);
    out_frame->enemy_spawn_timer  = read_u16_le(wram, 0x12B3);
    out_frame->enemy_spawn_wave   = read_u16_le(wram, 0x12B5);
    out_frame->prng_entropy_sample = read_u16_le(wram, 0x10000); /* $7F:0000 */

    /* 3. 7-Register Celestial & Lunar Calendar ($7E:156D .. $7E:1575) (Domain H) */
    out_frame->calendar.year          = wram[0x156D];
    out_frame->calendar.month         = wram[0x156E];
    out_frame->calendar.lunar_weekday = wram[0x156F];
    out_frame->calendar.day           = wram[0x1570];
    out_frame->calendar.hour          = wram[0x1571];
    out_frame->calendar.minute        = wram[0x1572];
    out_frame->calendar.sub_tick      = wram[0x1573];
    out_frame->calendar.clock_speed   = wram[0x1575];

    uint8_t hr = out_frame->calendar.hour % 24;
    uint8_t mn = out_frame->calendar.minute % 60;
    out_frame->calendar.is_nighttime = (hr >= 18 || hr < 6);

    uint16_t cur_mins = (uint16_t)(hr * 60 + mn);
    uint16_t noon_mins = 12 * 60;
    out_frame->calendar.minutes_to_noon = (cur_mins <= noon_mins)
        ? (noon_mins - cur_mins)
        : (uint16_t)((24 * 60 - cur_mins) + noon_mins);

    uint16_t next_shift_mins = (hr >= 6 && hr < 18) ? (18 * 60) : (6 * 60);
    out_frame->calendar.minutes_to_phase_shift = (cur_mins <= next_shift_mins)
        ? (next_shift_mins - cur_mins)
        : (uint16_t)((24 * 60 - cur_mins) + next_shift_mins);

    /* 4. 100-Slot Character Roster Struct-of-Arrays (SoA) */
    uint8_t active_units = 0;
    for (uint8_t i = 0; i < OB_MAX_ROSTER_UNITS; ++i) {
        ObUnitTelemetry *u = &out_frame->units[i];
        u->slot_index    = i;
        u->template_id   = wram[0x07BA + i];
        u->class_id      = wram[0x085A + i];
        u->status_mask   = wram[0x08FA + i];
        u->level         = wram[0xF148 + i];
        u->exp           = wram[0xF1E8 + i];
        u->hp_current    = read_u16_le(wram, 0x099A + (uint32_t)i * 2);
        u->hp_max        = read_u16_le(wram, 0x0ADA + (uint32_t)i * 2);
        u->str           = wram[0xF24C + i];
        u->agi           = wram[0xF2EC + i];
        u->intel         = wram[0xF38C + i];
        u->cha           = wram[0xF42C + i];
        u->ali           = wram[0x0C1A + i];
        u->luk           = wram[0xF490 + i];
        u->deploy_cost   = read_u16_le(wram, 0xF4F4 + (uint32_t)i * 2);
        u->career_record = read_u16_le(wram, 0x0C7E + (uint32_t)i * 2);
        u->equipped_item = wram[0xF5BC + i];
        u->squad_id      = wram[0x0F35 + i];

        u->resistances[0] = wram[0xF621 + i]; /* Physical  */
        u->resistances[1] = wram[0xF685 + i]; /* Fire      */
        u->resistances[2] = wram[0xF6E9 + i]; /* Cold/Ice  */
        u->resistances[3] = wram[0xF74D + i]; /* Lightning */
        u->resistances[4] = wram[0xF7B1 + i]; /* Black     */
        u->resistances[5] = wram[0xF815 + i]; /* White     */

        u->is_populated = (u->template_id != 0 && u->class_id != 0 && u->hp_max > 0);
        if (u->is_populated) {
            active_units++;
        }
    }
    out_frame->active_roster_count = active_units;

    /* 5. 25-Slot Squad Formation Tables ($7E:0DCD, $7E:0E81, $7E:F901) */
    for (uint8_t s = 0; s < OB_MAX_SQUADS; ++s) {
        ObSquadTelemetry *sq = &out_frame->squads[s];
        sq->squad_index   = s;
        sq->tactic_stance = wram[0xF901 + s] & 0x03;
        uint32_t sum_ali = 0;
        uint32_t sum_lvl = 0;
        uint8_t  cnt = 0;
        uint16_t cost = 0;

        for (uint8_t m = 0; m < OB_MAX_SQUAD_MEMBERS; ++m) {
            uint32_t idx = (uint32_t)s * OB_MAX_SQUAD_MEMBERS + m;
            uint8_t uid = wram[0x0E81 + idx];
            uint8_t pos_act = wram[0x0DCD + idx];
            sq->member_ids[m]     = uid;
            sq->grid_positions[m] = pos_act & 0x0F;
            sq->actions_left[m]   = (pos_act >> 4) & 0x0F;

            if (uid < OB_MAX_ROSTER_UNITS && out_frame->units[uid].is_populated) {
                if (m == 0) {
                    sq->has_leader = true;
                }
                sum_ali += out_frame->units[uid].ali;
                sum_lvl += out_frame->units[uid].level;
                cost    += out_frame->units[uid].deploy_cost;
                cnt++;
            }
        }
        sq->member_count      = cnt;
        sq->total_deploy_cost = cost;
        sq->avg_alignment     = (cnt > 0) ? (uint8_t)(sum_ali / cnt) : 50;
        sq->avg_level         = (cnt > 0) ? (uint8_t)(sum_lvl / cnt) : 0;
    }

    /* 6. 21-Slot Tactical Map Squad Kinematics & AI State ($7E:18AF .. $7E:1A94) (Domains E & F) */
    uint32_t active_upkeep = 0;
    for (uint8_t slot = 0; slot < OB_MAX_DEPLOYED_SLOTS; ++slot) {
        ObMapEntityTelemetry *ent = &out_frame->map_entities[slot];
        uint32_t off = (uint32_t)slot * 2;
        ent->deployed_slot  = slot;
        ent->is_enemy       = (slot >= 10);
        ent->world_x        = read_s16_le(wram, 0x18AF + off);
        ent->world_y        = read_s16_le(wram, 0x18D9 + off);
        ent->is_active      = (ent->world_x != 0x7FFF && ent->world_x != -1 && ent->world_x != 0);

        if (slot < 20) {
            ent->target_x       = read_s16_le(wram, 0x1905 + off);
            ent->target_y       = read_s16_le(wram, 0x192D + off);
            ent->vel_dx         = read_s16_le(wram, 0x1955 + off);
            ent->vel_dy         = read_s16_le(wram, 0x197D + off);
            ent->ai_order_state = read_u16_le(wram, 0x19A5 + off);
            ent->fatigue_stun   = read_u16_le(wram, 0x19CD + off);
            ent->mobility_speed = read_u16_le(wram, 0x1A11 + off);
            ent->move_type      = wram[0x1A45 + off];
            ent->terrain_under  = wram[0x1A46 + off];
            ent->facing_dir     = wram[0x1A6D + off];
        }

        if (!ent->is_enemy && ent->is_active && slot < OB_MAX_SQUADS) {
            active_upkeep += out_frame->squads[slot].total_deploy_cost;
        }
    }

    /* 7. 20-Slot Stage City & Temple State ($7E:1A95 .. $7E:1C9D) (Domain H) */
    uint32_t tribute_income = 0;
    for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        ObCityTelemetry *city = &out_frame->cities[c];
        uint32_t off = (uint32_t)c * 2;
        city->city_index     = c;
        city->world_x        = read_s16_le(wram, 0x1A95 + off);
        city->world_y        = read_s16_le(wram, 0x1B0D + off);
        city->tribute_base   = read_u16_le(wram, 0x1B5D + off);
        city->shop_id        = wram[0x1C11 + off];
        city->compatibility  = wram[0x1C25 + off];
        city->ownership_mask = wram[0x1C4D + off];
        city->live_morale    = wram[0x1C75 + off];
        city->event_drawn    = wram[0x1C9D + off];
        city->exists         = (city->world_x != 0x7FFF && city->world_x > 0 && city->world_y > 0);

        /* Player-liberated cities contribute tribute at 12:00 Noon */
        if (city->exists && (city->ownership_mask & 0x01)) {
            tribute_income += (uint32_t)city->tribute_base * 10U;
        }
    }
    out_frame->active_upkeep_drain      = active_upkeep;
    out_frame->projected_tribute_income = tribute_income;
    out_frame->projected_noon_net       = (int32_t)tribute_income - (int32_t)active_upkeep;

    /* 8. Live Combat Arena Micro-Telemetry ($7E:F925 .. $7E:F9FC) (Domain G) */
    ObCombatTelemetry *cmb = &out_frame->combat;
    cmb->active_tactic       = wram[0xF92E] & 0x03;
    cmb->acting_slot         = wram[0xF931];
    cmb->target_slot         = wram[0xF934];
    cmb->attack_element      = wram[0xF93A];
    cmb->hit_outcome_flags   = wram[0xF93B];
    cmb->last_hit_damage     = wram[0xF93C];
    cmb->total_actions_left  = wram[0xF941];
    cmb->player_clash_damage = read_u16_le(wram, 0xF942);
    cmb->enemy_clash_damage  = read_u16_le(wram, 0xF944);

    bool any_combatant_active = false;
    for (uint8_t k = 0; k < OB_MAX_COMBATANTS; ++k) {
        cmb->turn_queue[k]      = wram[0xF977 + k];
        cmb->combat_status[k]   = wram[0xF982 + k];
        cmb->roster_id[k]       = wram[0xF98C + k];
        cmb->attacks_left[k]    = wram[0xF996 + k];
        cmb->grid_pos[k]        = wram[0xF9AA + k];
        cmb->active_skill_id[k] = wram[0xF9C8 + k];
        if (cmb->attacks_left[k] > 0 && cmb->attacks_left[k] <= 6) {
            any_combatant_active = true;
        }
    }
    cmb->in_combat = (wram[0xF92B] != 0) &&
                     (cmb->total_actions_left > 0 || any_combatant_active ||
                      cmb->player_clash_damage > 0 || cmb->enemy_clash_damage > 0);

    /* 9. Tarot Hand, Camp Inventory, Stage Flags & 2,344-Bit Story Bitmaps (Domain I) */
    uint8_t t_cnt = 0;
    for (uint8_t t = 0; t < OB_MAX_TAROT_HAND; ++t) {
        uint8_t card = wram[0x0DBE + t];
        out_frame->tarot_hand[t] = card;
        if (card < 22) {
            t_cnt++;
        }
    }
    out_frame->tarot_hand_count = t_cnt;

    memcpy(out_frame->camp_inventory, &wram[0x157E], OB_MAX_CAMP_INVENTORY);
    memcpy(out_frame->stage_flags, &wram[0x1723], OB_MAX_STAGES);
    memcpy(out_frame->stage_aux_1741, &wram[0x1741], 7);
    memcpy(out_frame->stage_aux_1748, &wram[0x1748], 4);
    memcpy(out_frame->story_bitmap, &wram[0x8600], OB_STORY_BITMAP_BYTES);
    memcpy(out_frame->chronicle_block, &wram[0xF028], OB_CHRONICLE_BLOCK_BYTES);

    out_frame->screen_category = classify_screen_mode(wram, cmb);
}

size_t ob_telemetry_diff_frames(
    const ObTelemetryFrame *prev_frame,
    const ObTelemetryFrame *curr_frame,
    ObTelemetryDiffEvent *out_events,
    size_t max_events
) {
    if (!prev_frame || !curr_frame || !out_events || max_events == 0) {
        return 0;
    }

    size_t count = 0;

    /* 1. Check Chaos Frame change */
    if (prev_frame->chaos_frame != curr_frame->chaos_frame && count < max_events) {
        ObTelemetryDiffEvent *ev = &out_events[count++];
        ev->frame_number = curr_frame->frame_counter;
        ev->wram_address = 0x157C;
        ev->bit_index    = 0xFFFF;
        ev->old_value    = prev_frame->chaos_frame;
        ev->new_value    = curr_frame->chaos_frame;
        snprintf(ev->category, sizeof(ev->category), "CHAOS_FRAME");
    }

    /* 2. Check Stage Completion Flags ($7E:1723..$7E:1740) */
    for (uint16_t s = 0; s < OB_MAX_STAGES && count < max_events; ++s) {
        if (prev_frame->stage_flags[s] != curr_frame->stage_flags[s]) {
            ObTelemetryDiffEvent *ev = &out_events[count++];
            ev->frame_number = curr_frame->frame_counter;
            ev->wram_address = (uint16_t)(0x1723 + s);
            ev->bit_index    = s;
            ev->old_value    = prev_frame->stage_flags[s];
            ev->new_value    = curr_frame->stage_flags[s];
            snprintf(ev->category, sizeof(ev->category), "STAGE_FLAG");
        }
    }

    /* 3. Check 2,344-Bit Story, Treasure & Recruitment Bitmaps ($7E:8600..$7E:8F27) */
    for (uint16_t b = 0; b < OB_STORY_BITMAP_BYTES && count < max_events; ++b) {
        uint8_t diff = prev_frame->story_bitmap[b] ^ curr_frame->story_bitmap[b];
        if (diff == 0) {
            continue;
        }
        for (uint8_t bit = 0; bit < 8 && count < max_events; ++bit) {
            if (diff & (1U << bit)) {
                ObTelemetryDiffEvent *ev = &out_events[count++];
                ev->frame_number = curr_frame->frame_counter;
                ev->wram_address = (uint16_t)(0x8600 + b);
                ev->bit_index    = (uint16_t)(b * 8 + bit);
                ev->old_value    = (prev_frame->story_bitmap[b] >> bit) & 1U;
                ev->new_value    = (curr_frame->story_bitmap[b] >> bit) & 1U;
                if (b < 150) {
                    snprintf(ev->category, sizeof(ev->category), "STORY_BIT_A");
                } else if (b < 225) {
                    snprintf(ev->category, sizeof(ev->category), "TREASURE_BIT_B");
                } else {
                    snprintf(ev->category, sizeof(ev->category), "RECRUIT_BIT_C");
                }
            }
        }
    }

    return count;
}

size_t ob_telemetry_format_diff_jsonl(
    const ObTelemetryDiffEvent *events,
    size_t event_count,
    char *out_buf,
    size_t max_len
) {
    if (!events || !out_buf || max_len == 0) {
        return 0;
    }
    size_t written = 0;
    out_buf[0] = '\0';
    for (size_t i = 0; i < event_count; ++i) {
        int n = snprintf(
            out_buf + written,
            max_len - written,
            "{\"frame\":%u,\"wram\":\"$7E:%04X\",\"bit\":%u,\"old\":%u,\"new\":%u,\"category\":\"%s\"}\n",
            events[i].frame_number,
            events[i].wram_address,
            events[i].bit_index,
            events[i].old_value,
            events[i].new_value,
            events[i].category
        );
        if (n < 0 || (size_t)n >= (max_len - written)) {
            break;
        }
        written += (size_t)n;
    }
    return written;
}

/* Canonical Class Name Lookup Table (Verified against ROM 0x8BB29) */
static const char *const kCanonicalClassNames[126] = {
    "NONE",       "FIGHTER",    "KNIGHT",     "PALADIN",    "SAMURAI",    "MASTER",
    "AMAZON",     "VALKYRIE",   "MUSE",       "CLERIC",     "PRIEST",     "SHAMAN",
    "MONK",       "WITCH",      "PRINCESS",   "BEAST MAN",  "BEAST MSTR", "DRAGONER",
    "DRGN MSTR",  "WIZARD",     "MAGE",       "SORCERER",   "LICH",       "NINJA",
    "ASN",        "NINJA MSTR", "BERSERKER",  "WILD MAN",   "DOLL MAGE",  "DOLL MSTR",
    "GOLEM",      "ROCK GOLEM", "IRON GOLEM", "TITAN",      "GIANT",      "ICE GIANT",
    "FIRE GIANT", "HAWK MAN",   "RAVEN MAN",  "EAGLE MAN",  "OCTOPUS",    "KRAKEN",
    "MERMAID",    "NIXIE",      "WYRM",       "WYVERN",     "COCKATRICE", "PYRODRAKE",
    "GRYPHON",    "HELLHOUND",  "CERBERUS",   "GHOST",      "PHANTOM",    "WRAITH",
    "SKELETON",   "SKELTYRN",   "IMP",        "DEVIL",      "DEMON",      "DRAGON",
    "RED DRGN",   "SILVER DRG", "BLACK DRGN", "GOLD DRGN",  "SALAMANDER", "PLATINUM",
    "TIAMAT",     "ZOMBIE D",   "FAERIE",     "PIXIE",      "SYLPH",      "ANGEL",
    "CHERUBIM",   "SERAPHIM",   "VAMPYRE",    "WEREWOLF",   "TIGER MAN",  "PUMPKIN",
    "HALLOWEEN",  "LORD",       "LORD",       "LORD",       "LORD",       "GENERAL",
    "SNIPER",     "SYLPHID",    "SAGE",       "GEMSTONE",   "PALADIN+",   "BEAST+",
    "MAGE+",      "SORCERER+",  "VALKYRIE+",  "MUSE+",      "CLERIC+",    "SHAMAN+",
    "HIGHLANDER", "DRAGOON",    "SUMMONER",   "DARK KNIGHT","TEMPLAR",    "DEVIL+",
    "ASURA",      "DEBONAIR",   "NORMA",      "USURPER",    "FENRIL",     "ALBERICH",
    "GALF",       "LUVALON",    "FIGARO",     "CASTOR",     "POLLUX",     "GANYA",
    "MIZAL",      "pos115",     "pos116",     "pos117",     "pos118",     "pos119",
    "pos120",     "pos121",     "pos122",     "pos123",     "DIABLO",     "GALF+"
};

const char *ob_telemetry_get_class_name(
    const uint8_t *rom,
    uint32_t rom_size,
    uint8_t class_id,
    char *out_name,
    size_t max_len
) {
    (void)rom;
    (void)rom_size;
    if (!out_name || max_len == 0) {
        return "UNKNOWN";
    }
    const char *src = (class_id <= 125) ? kCanonicalClassNames[class_id] : "EXPANDED";
    snprintf(out_name, max_len, "%s", src);
    return out_name;
}
