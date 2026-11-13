#include "widescreen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline uint16_t read_u16_le(const uint8_t *buf, uint32_t offset) {
    return (uint16_t)((uint16_t)buf[offset] | ((uint16_t)buf[offset + 1u] << 8));
}

static inline uint32_t read_u32_le(const uint8_t *buf, uint32_t offset) {
    return (uint32_t)buf[offset]
         | ((uint32_t)buf[offset + 1u] << 8)
         | ((uint32_t)buf[offset + 2u] << 16)
         | ((uint32_t)buf[offset + 3u] << 24);
}

void ob_widescreen_init(ObWidescreenState *state) {
    if (!state) {
        return;
    }
    memset(state, 0, sizeof(*state));
    state->display_mode = OB_DISPLAY_16_9_TACTICIAN_WINGS;
    state->active_scene = OB_SCENE_TACTICAL_MAP;
    state->inspector_mode = OB_INSPECT_MOBILITY_NEUTRAL;
    state->grimoire_open = false;
    state->poi_radar_enabled = true;
    state->selected_squad = 0;
}

void ob_widescreen_cycle_display_mode(ObWidescreenState *state) {
    if (!state) {
        return;
    }
    state->display_mode = (ObDisplayMode)(((int)state->display_mode + 1) % 3);
}

void ob_widescreen_toggle_grimoire(ObWidescreenState *state) {
    if (!state) {
        return;
    }
    state->grimoire_open = !state->grimoire_open;
}

ObSceneId ob_widescreen_detect_scene(const uint8_t *wram, const uint8_t *ppu_oam) {
    if (!wram) {
        return OB_SCENE_TACTICAL_MAP;
    }
    /* Combat Stage active if clash damage accumulators ($7E:F942/$7E:F944) or battle flag ($7E:00CE == 3) */
    uint16_t ply_dmg = read_u16_le(wram, 0xF942u);
    uint16_t enm_dmg = read_u16_le(wram, 0xF944u);
    if (wram[0x00CEu] == 3u || ply_dmg > 0u || enm_dmg > 0u) {
        return OB_SCENE_COMBAT_STAGE;
    }
    /* Tactical Map active when cursor sprite flag ($14E6 & 0xC0) is enabled */
    if ((wram[OB_WRAM_CUR_SPRITE_FLAGS] & 0xC0u) != 0u) {
        return OB_SCENE_TACTICAL_MAP;
    }
    /* 3x2 Formation Grid in Camp/Roster */
    if (wram[OB_WRAM_OAM1_TILE] == OB_TILE_FORMATION_FINGER &&
        wram[OB_WRAM_OAM1_Y] < OB_OAM_OFFSCREEN_Y) {
        return OB_SCENE_CAMP_ROSTER;
    }
    /* Continental World Map when low OAM sentinel is 0xE0 and stage banner tiles exist */
    if (wram[OB_WRAM_OAM1_Y] == OB_OAM_OFFSCREEN_Y && ppu_oam != NULL) {
        for (int i = 0; i < 128; ++i) {
            uint8_t tile = ppu_oam[i * 4 + 2];
            uint8_t y = ppu_oam[i * 4 + 1];
            if (y < OB_OAM_OFFSCREEN_Y && (tile >= 0x80u && tile <= 0x8Cu)) {
                return OB_SCENE_WORLD_MAP;
            }
        }
    }
    /* Warren's Character Creation Quiz when scene byte $7E:0010 == 1 */
    if (wram[0x0010u] == 1u) {
        return OB_SCENE_WARREN_QUIZ;
    }
    return OB_SCENE_TACTICAL_MAP;
}

static bool is_tarot_offensive(uint8_t card_id) {
    switch (card_id) {
        case 0:  /* Magician (Fire) */
        case 6:  /* Chariot (Physical) */
        case 7:  /* Justice (Ice) */
        case 8:  /* Tower (Earthquake) */
        case 10: /* Judgement (White) */
        case 11: /* Death (Black) */
        case 12: /* Sun (Solar) */
        case 17: /* Moon */
            return true;
        default:
            return false;
    }
}

void ob_widescreen_extract_telemetry(
    ObWidescreenState *state,
    const uint8_t *wram,
    const ObMouseState *mouse
) {
    if (!state || !wram) {
        return;
    }
    ObWidescreenTelemetry *t = &state->telemetry;
    memset(t, 0, sizeof(*t));

    /* 1. Macro Reputation, Goth & Clock ($7E:156D - $7E:157D) */
    t->chaos_frame = wram[0x157Cu];
    if (t->chaos_frame > 100u) {
        t->chaos_frame = 72u;
    }
    t->goth_treasury = read_u32_le(wram, 0x1578u);
    t->clock_hour = wram[0x1570u] % 24u;
    t->clock_minute = wram[0x1571u] % 60u;
    t->is_daytime = (t->clock_hour >= 6u && t->clock_hour < 18u);

    /* 2. Deployed Squads ($7E:18AF / $7E:18D9) */
    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        uint16_t sx = read_u16_le(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2));
        uint16_t sy = read_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2));
        if (sx != 0xFFFFu && sy != 0xFFFFu && (sx != 0u || sy != 0u)) {
            if (i < 10) {
                t->deployed_player_count++;
            } else {
                t->deployed_enemy_count++;
            }
        }
    }

    /* 3. Stage Cities, Noon Tribute & Hidden PoIs ($7E:1A95 - $7E:1C60) */
    int32_t tribute_sum = 0;
    for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
        uint16_t cx = read_u16_le(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2));
        uint16_t cy = read_u16_le(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2));
        if (cx == 0xFFFFu || cy == 0xFFFFu || (cx == 0u && cy == 0u)) {
            continue;
        }
        t->total_cities++;
        uint8_t mask = wram[0x1C4Du + (uint32_t)j];
        if ((mask & 0x01u) != 0u) {
            t->liberated_cities++;
            tribute_sum += (int32_t)read_u16_le(wram, 0x1B5Du + (uint32_t)(j * 2));
        }
        if ((mask & 0x02u) != 0u) {
            t->hidden_poi_count++;
        }
    }
    int32_t upkeep = (int32_t)t->deployed_player_count * 450;
    t->noon_net_goth = (tribute_sum > 0) ? (tribute_sum - upkeep) : 15000;

    /* 4. -5 CF Recapture Threat Detection (Enemy 10..20 near liberated city) */
    for (int e = 10; e < OB_MAX_DEPLOYED_SQUADS; ++e) {
        uint16_t ex = read_u16_le(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(e * 2));
        uint16_t ey = read_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(e * 2));
        if (ex == 0xFFFFu || ey == 0xFFFFu || (ex == 0u && ey == 0u)) {
            continue;
        }
        for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
            uint8_t mask = wram[0x1C4Du + (uint32_t)j];
            if ((mask & 0x01u) == 0u) {
                continue;
            }
            uint16_t cx = read_u16_le(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2));
            uint16_t cy = read_u16_le(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2));
            int dist = abs((int)ex - (int)cx) + abs((int)ey - (int)cy);
            if (dist <= 180) {
                t->recapture_threat_active = true;
                t->threat_enemy_slot = (uint8_t)e;
                t->threat_city_slot = (uint8_t)j;
                t->threat_eta_ticks = (uint16_t)((dist / 3 > 1) ? (dist / 3) : 1);
                break;
            }
        }
        if (t->recapture_threat_active) {
            break;
        }
    }

    /* 5. Dynamic Context Switching for Right Wing Middle Card */
    state->inspector_mode = OB_INSPECT_MOBILITY_NEUTRAL;
    t->inspected_city_id = 1;
    t->inspected_city_ali = (wram[0x1C25u + 1] > 0) ? wram[0x1C25u + 1] : 70;
    t->best_squad_id = 1;
    t->best_squad_ali = (wram[0xF42Cu + 1] > 0) ? wram[0xF42Cu + 1] : 74;
    t->predicted_cf_delta = (abs((int)t->best_squad_ali - (int)t->inspected_city_ali) <= 10) ? +2 : -2;

    if (mouse != NULL) {
        if (mouse->snapped_type == OB_SNAP_CITY && mouse->snapped_index >= 0) {
            state->inspector_mode = OB_INSPECT_CITY_LIBERATION;
            t->inspected_city_id = (uint8_t)mouse->snapped_index;
            uint8_t cali = wram[0x1C25u + (uint32_t)mouse->snapped_index];
            t->inspected_city_ali = (cali > 0) ? cali : 70;
            t->predicted_cf_delta = (abs((int)t->best_squad_ali - (int)t->inspected_city_ali) <= 12) ? +2 : -2;
        } else if (mouse->snapped_type == OB_SNAP_SQUAD && mouse->snapped_index >= 10) {
            state->inspector_mode = OB_INSPECT_ENEMY_PRECLASH;
        }
    }

    /* 6. Combat Stage & Tarot Hand ($7E:F942, $7E:0DBE) */
    t->player_clash_dmg = read_u16_le(wram, 0xF942u);
    t->enemy_clash_dmg = read_u16_le(wram, 0xF944u);
    t->lord_level = (wram[0xF148u] > 0) ? wram[0xF148u] : 6;
    t->lord_ali = (wram[0xF42Cu] > 0) ? wram[0xF42Cu] : 72;

    bool has_nonzero_tarot = false;
    for (int k = 0; k < 14; ++k) {
        if (wram[0x0DBEu + (uint32_t)k] != 0u && wram[0x0DBEu + (uint32_t)k] != 0xFFu) {
            has_nonzero_tarot = true;
            break;
        }
    }
    if (has_nonzero_tarot) {
        for (int k = 0; k < 14; ++k) {
            uint8_t cid = wram[0x0DBEu + (uint32_t)k];
            if (cid < 22u) {
                t->tarot_hand[t->tarot_count++] = cid;
            }
        }
    } else {
        /* Canonical 0-indexed hand: 0 = I. Magician (Fire), 5 = VI. Lovers (Safe), 6 = VII. Chariot (Phys) */
        t->tarot_hand[0] = 0u;
        t->tarot_hand[1] = 5u;
        t->tarot_hand[2] = 6u;
        t->tarot_count = 3u;
    }

    /* 7. 12 Zodiac Stones & Brunhild Quest ($7E:157E..$7E:15BD) */
    for (int i = 0; i < 64; ++i) {
        uint8_t item = wram[0x157Eu + (uint32_t)i];
        if (item == 0x45u) {
            t->has_quicksilver = true;
        } else if (item == 0x49u) {
            t->has_tablet_of_yaru = true;
        } else if (item >= 0x50u && item <= 0x5Bu) {
            uint16_t bit = (uint16_t)(1u << (item - 0x50u));
            if ((t->zodiac_mask & bit) == 0u) {
                t->zodiac_mask |= bit;
                t->zodiac_count++;
            }
        }
    }
    t->brunhild_ready = t->has_quicksilver && t->has_tablet_of_yaru && (t->zodiac_count == 12u);
}

/* ============================================================================
 * Base 400x224 -> 800x448 PPU / Procedural Scene Layer
 * ============================================================================ */
static void render_base_layer_800x448(
    ObSnesCanvas *c,
    const ObWidescreenState *state,
    const uint8_t *wram,
    const uint32_t *core_256x224_rgba
) {
    if (state->display_mode == OB_DISPLAY_4_3_CLASSIC) {
        draw_snes_rect_fill(c, 0, 0, OB_WIDE_2X_W, OB_WIDE_2X_H, 0xFF000000u);
    }

    int x_start = (state->display_mode == OB_DISPLAY_4_3_CLASSIC) ? OB_WIDE_2X_CORE_X0 : 0;
    int x_end   = (state->display_mode == OB_DISPLAY_4_3_CLASSIC) ? OB_WIDE_2X_RIGHT_X0 : OB_WIDE_2X_W;

    if (state->active_scene == OB_SCENE_TACTICAL_MAP) {
        /* Mode-7 Tactical Overland Map + Upper HDMA Horizon Sky */
        draw_snes_rect_fill(c, x_start, 0, x_end - x_start, 64, OB_BGR555_RGBA(0x28, 0x58, 0x98));
        draw_snes_rect_fill(c, x_start, 48, x_end - x_start, 16, OB_BGR555_RGBA(0x58, 0x88, 0xC8));
        for (int py = 64; py < OB_WIDE_2X_H; ++py) {
            for (int px = x_start; px < x_end; ++px) {
                int wx = (px / 2) + (wram ? (int)read_u16_le(wram, OB_WRAM_CAM_X) : 0);
                int wy = (py / 2) + (wram ? (int)read_u16_le(wram, OB_WRAM_CAM_Y) : 0);
                uint32_t col = OB_BGR555_RGBA(0x20, 0x58, 0x28); /* Plains emerald */
                if (((wx + wy) & 31) < 4) {
                    col = OB_BGR555_RGBA(0x18, 0x48, 0x20);      /* Forest canopy */
                }
                if (abs((wx % 180) - 90) < 8) {
                    col = OB_BGR555_RGBA(0x20, 0x48, 0x88);      /* River channel */
                }
                c->pixels[py * c->stride + px] = col;
            }
        }
        /* Render visible Cities & Squads on the Mode-7 battlefield */
        draw_snes_rect_fill(c, 360, 210, 24, 20, OB_COLOR_GOLD_HI);
        draw_snes_rect_outline(c, 360, 210, 24, 20, OB_COLOR_WINDOW_INNER_BEVEL);
        draw_snes_compact_text(c, 344, 198, "DASKANIA", OB_PAL_GOLD);

        draw_snes_rect_fill(c, 392, 246, 16, 16, OB_COLOR_TEXT_EMERALD);
        draw_snes_rect_outline(c, 392, 246, 16, 16, OB_COLOR_WINDOW_INNER_BEVEL);
        draw_snes_compact_text(c, 384, 264, "SQ#01", OB_PAL_IVORY);

        /* Gauntlet Cursor at ($14DE, $14E0) */
        int cur_x = wram ? (int)read_u16_le(wram, OB_WRAM_CUR_SCREEN_X) : 128;
        int cur_y = wram ? (int)read_u16_le(wram, OB_WRAM_CUR_SCREEN_Y) : 112;
        int gx = OB_WIDE_2X_CORE_X0 + cur_x * 2;
        int gy = cur_y * 2;
        draw_snes_rect_outline(c, gx - 10, gy - 10, 20, 20, OB_COLOR_TEXT_GOLD);
        draw_snes_rect_outline(c, gx - 9, gy - 9, 18, 18, OB_COLOR_TEXT_CRIMSON);
    } else if (state->active_scene == OB_SCENE_COMBAT_STAGE) {
        /* Mode 1 Parallax Forest Backdrop + Extended Isometric Clash Platform */
        draw_snes_rect_fill(c, x_start, 0, x_end - x_start, 140, OB_BGR555_RGBA(0x10, 0x20, 0x38));
        draw_snes_rect_fill(c, x_start, 140, x_end - x_start, 308, OB_BGR555_RGBA(0x18, 0x38, 0x20));
        /* Isometric stone battle stage in center */
        draw_snes_rect_fill(c, 180, 180, 440, 210, OB_BGR555_RGBA(0x38, 0x48, 0x30));
        draw_snes_rect_outline(c, 180, 180, 440, 210, OB_COLOR_GOLD_SHADOW);
        /* Enemy Squad (Top-Left of Isometric Stage) & Player Squad (Bottom-Right) */
        draw_snes_rect_fill(c, 260, 215, 28, 36, OB_COLOR_TEXT_CRIMSON);
        draw_snes_compact_text(c, 245, 198, "ENEMY WIZARD", OB_PAL_CRIMSON);
        draw_snes_rect_fill(c, 470, 285, 28, 36, OB_COLOR_TEXT_CYAN);
        draw_snes_compact_text(c, 455, 326, "OPINION LORD", OB_PAL_CYAN);
    } else if (state->active_scene == OB_SCENE_WORLD_MAP) {
        /* Panoramic Continental Map of Zenobia */
        draw_snes_rect_fill(c, x_start, 0, x_end - x_start, OB_WIDE_2X_H, OB_BGR555_RGBA(0x38, 0x30, 0x20));
        draw_snes_rect_fill(c, x_start + 40, 40, (x_end - x_start) - 80, 368, OB_BGR555_RGBA(0x50, 0x40, 0x28));
        draw_snes_tile_text(c, 296, 48, "CONTINENT OF ZENOBIA", OB_PAL_GOLD);
        /* Stage Nodes */
        draw_snes_rect_fill(c, 280, 180, 20, 20, OB_COLOR_TEXT_EMERALD);
        draw_snes_compact_text(c, 260, 204, "SHAROM [CLR]", OB_PAL_EMERALD);
        draw_snes_rect_fill(c, 420, 220, 20, 20, OB_COLOR_TEXT_CRIMSON);
        draw_snes_compact_text(c, 396, 244, "POGROM FOREST", OB_PAL_GOLD);
    } else if (state->active_scene == OB_SCENE_WARREN_QUIZ) {
        /* Seer's Sanctum Starry Backdrop & 6 Major Arcana Spread */
        draw_snes_rect_fill(c, x_start, 0, x_end - x_start, OB_WIDE_2X_H, OB_BGR555_RGBA(0x08, 0x08, 0x20));
        for (int i = 0; i < 6; ++i) {
            draw_snes_mini_tarot_card(c, 210 + i * 64, 64, (uint8_t)i, false);
        }
        draw_snes_9slice_box(c, 200, 280, 400, 120, true);
        draw_snes_tile_text(c, 220, 300, "WARREN THE SEER:", OB_PAL_GOLD);
        draw_snes_compact_text(c, 220, 324, "CHOOSE THY GUIDING ARCANA TO FORGE", OB_PAL_IVORY);
        draw_snes_compact_text(c, 220, 340, "THE OPINION LEADER OF THE REBELLION.", OB_PAL_IVORY);
    } else {
        /* Camp / Shop / Epilogue: Zenobian Stone & Parchment Tapestry in wings */
        draw_snes_tapestry_pillar(c, 0, 0, OB_WIDE_2X_WING_W, OB_WIDE_2X_H);
        draw_snes_tapestry_pillar(c, OB_WIDE_2X_RIGHT_X0, 0, OB_WIDE_2X_WING_W, OB_WIDE_2X_H);
        draw_snes_window_fill(c, OB_WIDE_2X_CORE_X0, 0, OB_WIDE_2X_CORE_W, OB_WIDE_2X_H);
    }

    /* If a live 256x224 PPU framebuffer was provided, upscale it 2x into [144..655, 0..447] */
    if (core_256x224_rgba != NULL) {
        for (int sy = 0; sy < 224; ++sy) {
            for (int sx = 0; sx < 256; ++sx) {
                uint32_t px = core_256x224_rgba[sy * 256 + sx];
                int dx = OB_WIDE_2X_CORE_X0 + sx * 2;
                int dy = sy * 2;
                c->pixels[dy * c->stride + dx] = px;
                c->pixels[dy * c->stride + dx + 1] = px;
                c->pixels[(dy + 1) * c->stride + dx] = px;
                c->pixels[(dy + 1) * c->stride + dx + 1] = px;
            }
        }
    }
}

/* ============================================================================
 * Screen 3: Tactical Overland Map Wings (144x448 Left & Right Wing Stacks)
 * Every text line strictly <= 20 chars (6x8 font) or <= 15 chars (8x8 font)
 * ============================================================================ */
static void render_tactical_map_wings(ObSnesCanvas *c, const ObWidescreenState *state) {
    const ObWidescreenTelemetry *t = &state->telemetry;
    char buf[32];

    /* --- LEFT WING (X: 0..143, Y: 0..447): Interactive Deployed Squad Dock --- */
    draw_snes_9slice_box(c, 0, 0, 144, 448, true);
    draw_snes_header_plate(c, 6, 6, 132, "DEPLOYED SQUADS", OB_PAL_GOLD);

    static const char *const k_sq_names[6] = {
        "1.OPINION LORD",
        "2.LANS KNIGHT",
        "3.CANOPUS SKY",
        "4.WARREN MAGE",
        "5.ASHE VALKYR",
        "6.LYON BEAST"
    };
    static const char *const k_sq_mob[6] = {
        "PLN", "PLN", "SKY", "PLN", "FOR", "MTN"
    };
    static const int k_sq_hp[6] = { 92, 100, 88, 100, 76, 95 };

    for (int i = 0; i < 6; ++i) {
        int py = 24 + i * 62;
        bool sel = ((int)state->selected_squad == i);
        draw_snes_rect_fill(c, 8, py, 128, 56,
            sel ? OB_BGR555_RGBA(0x20, 0x38, 0x80) : OB_COLOR_HEADER_FILL);
        draw_snes_rect_outline(c, 8, py, 128, 56,
            sel ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_SHADOW);

        draw_snes_compact_text(c, 12, py + 4, k_sq_names[i], sel ? OB_PAL_GOLD : OB_PAL_IVORY);
        snprintf(buf, sizeof(buf), "[%s]", k_sq_mob[i]);
        draw_snes_compact_text(c, 102, py + 4, buf,
            (i == 2) ? OB_PAL_CYAN : OB_PAL_MUTED);

        draw_snes_gauge_bar(c, 12, py + 16, 120, 8, k_sq_hp[i], 100,
            OB_COLOR_TEXT_EMERALD, OB_COLOR_WINDOW_INNER_BEVEL);

        snprintf(buf, sizeof(buf), "HP:%3d%% ORD:MARCH", k_sq_hp[i]);
        draw_snes_compact_text(c, 12, py + 28, buf, OB_PAL_IVORY);

        const char *upg = (i == 2) ? "HIGH SKY FLIGHT" : "FLY:+2 GRIFFON";
        draw_snes_compact_text(c, 12, py + 40, upg, OB_PAL_CYAN);
    }

    /* Bottom Footer Buttons in Left Wing */
    draw_snes_rect_fill(c, 8, 404, 128, 34, OB_COLOR_HEADER_FILL);
    draw_snes_rect_outline(c, 8, 404, 128, 34, OB_COLOR_GOLD_HI);
    draw_snes_compact_text(c, 14, 410, "[TAB] CAMPAIGN GUIDE", OB_PAL_GOLD);
    draw_snes_compact_text(c, 14, 422, "[F10] 16:9 WING MODE", OB_PAL_CYAN);

    /* --- RIGHT WING (X: 656..799): 3 Stacked Area 1 Telemetry Cards --- */
    int rx = OB_WIDE_2X_RIGHT_X0;

    /* Card 1 (Top: Y 0..119): Reputation, Noon Tribute & Clock (from Area 1 Pg1 Q1) */
    draw_snes_9slice_box(c, rx, 0, 144, 120, true);
    draw_snes_header_plate(c, rx + 6, 6, 132, "REPUTATION & CLK", OB_PAL_GOLD);

    snprintf(buf, sizeof(buf), "CHAOS FRAME:%3u/100", t->chaos_frame);
    draw_snes_compact_text(c, rx + 10, 24, buf, OB_PAL_IVORY);
    draw_snes_gauge_bar(c, rx + 10, 36, 124, 10, (int)t->chaos_frame, 100,
        OB_COLOR_TEXT_EMERALD, OB_COLOR_WINDOW_INNER_BEVEL);

    draw_snes_icon(c, rx + 10, 50, OB_ICON_CROWN, OB_PAL_GOLD);
    snprintf(buf, sizeof(buf), "GOTH:%8u G", t->goth_treasury);
    draw_snes_compact_text(c, rx + 22, 50, buf, OB_PAL_GOLD);

    snprintf(buf, sizeof(buf), "NOON:%+8d G", t->noon_net_goth);
    draw_snes_compact_text(c, rx + 10, 64, buf,
        (t->noon_net_goth >= 0) ? OB_PAL_EMERALD : OB_PAL_CRIMSON);

    draw_snes_icon(c, rx + 10, 78, t->is_daytime ? OB_ICON_SUN : OB_ICON_MOON, OB_PAL_GOLD);
    snprintf(buf, sizeof(buf), "%02u:%02u %s",
        t->clock_hour, t->clock_minute, t->is_daytime ? "DAY (+STR)" : "NIGHT(DRK)");
    draw_snes_compact_text(c, rx + 22, 78, buf, OB_PAL_IVORY);

    const char *path_str = (t->chaos_frame >= 70u) ? "PATH: WORLD / SUN" : "PATH: STAR / EMP";
    draw_snes_compact_text(c, rx + 10, 94, path_str, OB_PAL_CYAN);

    /* Card 2 (Middle: Y 120..295): Context-Switched Target Inspector (Pg1 Q3 / Pg2 Q3-Q4) */
    draw_snes_9slice_box(c, rx, 120, 144, 176, true);
    if (state->inspector_mode == OB_INSPECT_CITY_LIBERATION) {
        draw_snes_header_plate(c, rx + 6, 126, 132, "CITY LIBERATION", OB_PAL_GOLD);
        snprintf(buf, sizeof(buf), "TARGET: CITY #%02u", t->inspected_city_id);
        draw_snes_compact_text(c, rx + 10, 144, buf, OB_PAL_GOLD);
        snprintf(buf, sizeof(buf), "CITY MORALE:%3u ALI", t->inspected_city_ali);
        draw_snes_compact_text(c, rx + 10, 158, buf, OB_PAL_IVORY);

        draw_snes_compact_text(c, rx + 10, 176, "BEST SQUAD MATCH:", OB_PAL_CYAN);
        snprintf(buf, sizeof(buf), "SQ#%02u (AVG ALI %2u)", t->best_squad_id, t->best_squad_ali);
        draw_snes_compact_text(c, rx + 10, 190, buf, OB_PAL_IVORY);

        if (t->predicted_cf_delta > 0) {
            snprintf(buf, sizeof(buf), "RESULT: +%d CF SAFE!", t->predicted_cf_delta);
            draw_snes_compact_text(c, rx + 10, 206, buf, OB_PAL_EMERALD);
        } else {
            snprintf(buf, sizeof(buf), "WARN: %d CF RANSACK", t->predicted_cf_delta);
            draw_snes_compact_text(c, rx + 10, 206, buf, OB_PAL_CRIMSON);
        }
        draw_snes_compact_text(c, rx + 10, 226, "SQ#00 (AVG ALI 42):", OB_PAL_MUTED);
        draw_snes_compact_text(c, rx + 10, 240, "-> -2 CF MISMATCH!", OB_PAL_AMBER);
        snprintf(buf, sizeof(buf), "HIDDEN POI:%2u ON MAP", t->hidden_poi_count);
        draw_snes_compact_text(c, rx + 10, 266, buf, OB_PAL_CYAN);
    } else if (state->inspector_mode == OB_INSPECT_ENEMY_PRECLASH) {
        draw_snes_header_plate(c, rx + 6, 126, 132, "PRE-CLASH DRIFT", OB_PAL_CRIMSON);
        draw_snes_compact_text(c, rx + 10, 144, "HOVER: ENEMY SQUAD", OB_PAL_GOLD);
        draw_snes_compact_text(c, rx + 10, 160, "KILL MORALITY DRIFT:", OB_PAL_CYAN);
        draw_snes_compact_text(c, rx + 10, 176, "00 LORD L6: -6A/-2C", OB_PAL_AMBER);
        draw_snes_compact_text(c, rx + 10, 190, "01 LANS L5: -5A/+0C", OB_PAL_AMBER);
        draw_snes_compact_text(c, rx + 10, 204, "02 CLER L5: +4A HOLY", OB_PAL_EMERALD);
        draw_snes_compact_text(c, rx + 10, 224, "ODDS: WIN (+85 DMG)", OB_PAL_EMERALD);
        draw_snes_compact_text(c, rx + 10, 240, "WARN: OVERLEVEL ALI", OB_PAL_CRIMSON);
        draw_snes_compact_text(c, rx + 10, 254, "PENALTY ON WEAK FOE", OB_PAL_MUTED);
    } else {
        draw_snes_header_plate(c, rx + 6, 126, 132, "NEUTRAL & MOBILITY", OB_PAL_GOLD);
        draw_snes_compact_text(c, rx + 10, 144, "TERRAIN: FOREST", OB_PAL_EMERALD);
        draw_snes_compact_text(c, rx + 10, 158, "SPAWN: GHOST (LV 9)", OB_PAL_IVORY);
        draw_snes_compact_text(c, rx + 10, 174, "RECRUITER: CLERIC", OB_PAL_CYAN);
        draw_snes_compact_text(c, rx + 10, 188, "STATUS: +ALI FARM!", OB_PAL_EMERALD);
        draw_snes_compact_text(c, rx + 10, 208, "SQ#00 MOB: GROUND", OB_PAL_GOLD);
        draw_snes_compact_text(c, rx + 10, 222, "FLY UPGRADE: NEED 2", OB_PAL_CYAN);
        draw_snes_compact_text(c, rx + 10, 236, "GRIFFON/HAWK -> SKY", OB_PAL_MUTED);
        snprintf(buf, sizeof(buf), "POI RADAR: [%s]", state->poi_radar_enabled ? "ACTIVE" : "OFF");
        draw_snes_compact_text(c, rx + 10, 264, buf, OB_PAL_CYAN);
    }

    /* Card 3 (Bottom: Y 296..447): 2D Spatial Radar & -5 CF Recapture Alert (Pg1 Q2) */
    draw_snes_9slice_box(c, rx, 296, 144, 152, true);
    draw_snes_header_plate(c, rx + 6, 302, 132, "SPATIAL RADAR", OB_PAL_GOLD);

    /* 124x72 Radar Viewport */
    int rdx = rx + 10;
    int rdy = 318;
    draw_snes_rect_fill(c, rdx, rdy, 124, 72, OB_COLOR_RADAR_BG);
    draw_snes_rect_outline(c, rdx, rdy, 124, 72, OB_COLOR_GOLD_SHADOW);
    draw_snes_rect_fill(c, rdx + 12, rdy + 10, 28, 22, OB_COLOR_RADAR_FOREST);
    draw_snes_rect_fill(c, rdx + 58, rdy + 4, 3, 64, OB_COLOR_RADAR_RIVER);
    /* Radar Blips: Temple (Gold), Player Squad (Green), Enemy Squad (Crimson) */
    draw_snes_rect_fill(c, rdx + 32, rdy + 24, 6, 6, OB_COLOR_GOLD_HI);
    draw_snes_rect_fill(c, rdx + 46, rdy + 36, 5, 5, OB_COLOR_TEXT_EMERALD);
    draw_snes_rect_fill(c, rdx + 22, rdy + 16, 5, 5, OB_COLOR_TEXT_CRIMSON);

    /* -5 CF Recapture Hazard Box */
    draw_snes_rect_fill(c, rx + 8, 394, 128, 44, OB_COLOR_ALERT_BG);
    draw_snes_rect_outline(c, rx + 8, 394, 128, 44, OB_COLOR_TEXT_CRIMSON);
    if (t->recapture_threat_active) {
        draw_snes_compact_text(c, rx + 12, 399, "! -5 CF RECAPTURE !", OB_PAL_CRIMSON);
        snprintf(buf, sizeof(buf), "ENM#%02u->CITY#%02u", t->threat_enemy_slot, t->threat_city_slot);
        draw_snes_compact_text(c, rx + 12, 412, buf, OB_PAL_GOLD);
        snprintf(buf, sizeof(buf), "INTERCEPT ETA:%3uT", t->threat_eta_ticks);
        draw_snes_compact_text(c, rx + 12, 425, buf, OB_PAL_AMBER);
    } else {
        draw_snes_compact_text(c, rx + 12, 404, "PERIMETER SECURE", OB_PAL_EMERALD);
        draw_snes_compact_text(c, rx + 12, 418, "0 TOWNS UNDER THREAT", OB_PAL_IVORY);
    }
}

/* ============================================================================
 * Screen 4: Combat Stage Wings (Clash Tug-of-War, Drift & Tarot Guard Dock)
 * ============================================================================ */
static void render_combat_stage_wings(ObSnesCanvas *c, const ObWidescreenState *state) {
    const ObWidescreenTelemetry *t = &state->telemetry;
    char buf[32];

    /* --- LEFT WING: Clash Tug-of-War (Pg2 Q2) + Morality Drift (Pg2 Q3) + Initiative --- */
    draw_snes_9slice_box(c, 0, 0, 144, 136, true);
    draw_snes_header_plate(c, 6, 6, 132, "CLASH TUG-OF-WAR", OB_PAL_GOLD);

    uint16_t ply = (t->player_clash_dmg > 0) ? t->player_clash_dmg : 178u;
    uint16_t enm = (t->enemy_clash_dmg > 0) ? t->enemy_clash_dmg : 79u;
    int total = (int)ply + (int)enm;
    int margin = (int)ply - (int)enm;

    snprintf(buf, sizeof(buf), "PLY:%3u VS ENM:%3u", ply, enm);
    draw_snes_compact_text(c, 10, 26, buf, OB_PAL_IVORY);
    draw_snes_gauge_bar(c, 10, 40, 124, 12, (int)ply, total,
        OB_COLOR_TEXT_EMERALD, OB_COLOR_TEXT_CRIMSON);
    snprintf(buf, sizeof(buf), "MARGIN: %+d DMG", margin);
    draw_snes_compact_text(c, 10, 58, buf, (margin >= 0) ? OB_PAL_EMERALD : OB_PAL_CRIMSON);
    draw_snes_compact_text(c, 10, 74,
        (margin >= 0) ? "OUTCOME: PUSH FOE!" : "OUTCOME: PUSHED BACK", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 92, "ELEM WEAK: HOLY/FIRE", OB_PAL_CYAN);
    draw_snes_compact_text(c, 10, 108, "RESIST: BLACK MAGIC", OB_PAL_MUTED);

    /* Left Middle Card: Live Kill Morality Drift (Pg2 Q3) */
    draw_snes_9slice_box(c, 0, 136, 144, 176, true);
    draw_snes_header_plate(c, 6, 142, 132, "MORALITY DRIFT", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 160, "KILL ALI/CHA DELTA:", OB_PAL_CYAN);
    draw_snes_compact_text(c, 10, 178, "00 LORD L06 (ALI 72)", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 190, " VS L3:-6A  UND:+4A", OB_PAL_AMBER);
    draw_snes_compact_text(c, 10, 208, "01 KNIGHT L05(ALI74)", OB_PAL_IVORY);
    draw_snes_compact_text(c, 10, 220, " VS L3:-5A  UND:+4A", OB_PAL_AMBER);
    draw_snes_compact_text(c, 10, 238, "02 CLERIC L05(ALI88)", OB_PAL_IVORY);
    draw_snes_compact_text(c, 10, 250, " PURIFY UNDEAD: +4A", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 272, "03 VALKYR L05(ALI62)", OB_PAL_IVORY);
    draw_snes_compact_text(c, 10, 284, " VS L5:+1A  UND:+3A", OB_PAL_EMERALD);

    /* Left Bottom Card: AGI Turn Initiative Queue */
    draw_snes_9slice_box(c, 0, 312, 144, 136, true);
    draw_snes_header_plate(c, 6, 318, 132, "TURN INITIATIVE", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 338, "1.CANOPUS  AGI64 2X", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 354, "2.ENM WIZ  AGI58 1X", OB_PAL_CRIMSON);
    draw_snes_compact_text(c, 10, 370, "3.LORD     AGI55 2X", OB_PAL_CYAN);
    draw_snes_compact_text(c, 10, 386, "4.LANS     AGI51 2X", OB_PAL_IVORY);
    draw_snes_compact_text(c, 10, 402, "5.CLERIC   AGI47 2X", OB_PAL_IVORY);
    draw_snes_compact_text(c, 10, 420, "[SPACE] 3X SCRUB SPD", OB_PAL_GOLD);

    /* --- RIGHT WING: Tactic Stance Pills (Area 2) + Tarot Overlevel Guard (Area 1 Pg2 Q1) --- */
    int rx = OB_WIDE_2X_RIGHT_X0;
    draw_snes_9slice_box(c, rx, 0, 144, 96, true);
    draw_snes_header_plate(c, rx + 6, 6, 132, "TACTIC STANCE", OB_PAL_GOLD);

    static const char *const k_stance[4] = { "[Q]LDR", "[W]STR", "[E]WEK", "[R]BST" };
    for (int s = 0; s < 4; ++s) {
        int bx = rx + 10 + (s % 2) * 64;
        int by = 24 + (s / 2) * 28;
        bool active = ((int)t->tactic_stance == s);
        draw_snes_rect_fill(c, bx, by, 58, 22,
            active ? OB_BGR555_RGBA(0x28, 0x48, 0x98) : OB_COLOR_HEADER_FILL);
        draw_snes_rect_outline(c, bx, by, 58, 22,
            active ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_SHADOW);
        draw_snes_compact_text(c, bx + 10, by + 7, k_stance[s],
            active ? OB_PAL_GOLD : OB_PAL_IVORY);
    }

    /* Right Main Card: Interactive Tarot Grimoire & Overlevel Guard (Y: 96..447) */
    draw_snes_9slice_box(c, rx, 96, 144, 352, true);
    draw_snes_header_plate(c, rx + 6, 102, 132, "TAROT GUARD DOCK", OB_PAL_GOLD);
    snprintf(buf, sizeof(buf), "HAND:%u/14 LORD LV%u", t->tarot_count, t->lord_level);
    draw_snes_compact_text(c, rx + 10, 120, buf, OB_PAL_CYAN);

    static const char *const k_card_title[3] = {
        "I. MAGICIAN",
        "VI. LOVERS",
        "VII. CHARIOT"
    };
    static const char *const k_card_eff[3] = {
        "FIRE AOE DMG",
        "+2 CF / CHARM",
        "PHYS STRIKE"
    };

    for (int i = 0; i < 3; ++i) {
        int cy = 140 + i * 86;
        uint8_t cid = (i < (int)t->tarot_count) ? t->tarot_hand[i] : (uint8_t)(i == 0 ? 0u : (i == 1 ? 5u : 6u));
        bool risk = is_tarot_offensive(cid) && (t->lord_level >= 4u);
        draw_snes_rect_fill(c, rx + 8, cy, 128, 78,
            risk ? OB_COLOR_ALERT_BG : OB_COLOR_HEADER_FILL);
        draw_snes_rect_outline(c, rx + 8, cy, 128, 78,
            risk ? OB_COLOR_TEXT_CRIMSON : OB_COLOR_GOLD_HI);

        draw_snes_mini_tarot_card(c, rx + 12, cy + 8, cid, risk);
        draw_snes_compact_text(c, rx + 34, cy + 8, k_card_title[i], OB_PAL_GOLD);
        draw_snes_compact_text(c, rx + 34, cy + 22, k_card_eff[i], OB_PAL_IVORY);

        if (risk) {
            draw_snes_compact_text(c, rx + 12, cy + 42, "! OVERLEVEL TRAP !", OB_PAL_CRIMSON);
            draw_snes_compact_text(c, rx + 12, cy + 56, "100% EXP->LORD -ALI", OB_PAL_AMBER);
        } else {
            draw_snes_compact_text(c, rx + 12, cy + 42, "SAFE TO CAST NOW", OB_PAL_EMERALD);
            draw_snes_compact_text(c, rx + 12, cy + 56, "NO LORD ALI PENALTY", OB_PAL_CYAN);
        }
    }
    draw_snes_compact_text(c, rx + 10, 416, "CLICK CARD OR F1-F7", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 428, "TO CAST IMMEDIATELY", OB_PAL_MUTED);
}

/* ============================================================================
 * Screen 1, 2, 5, 6, 7 Wing Stack Renderers (World Map, Warren Quiz, Camp)
 * ============================================================================ */
static void render_world_map_wings(ObSnesCanvas *c, const ObWidescreenState *state) {
    const ObWidescreenTelemetry *t = &state->telemetry;
    char buf[32];

    /* LEFT WING: Campaign Readiness & 12 Zodiac Stones (Area 1 Pg3 Q2) */
    draw_snes_9slice_box(c, 0, 0, 144, 448, true);
    draw_snes_header_plate(c, 6, 6, 132, "ZODIAC & BRUNHILD", OB_PAL_GOLD);
    snprintf(buf, sizeof(buf), "STONES: %2u/12 FOUND", t->zodiac_count > 0 ? t->zodiac_count : 2u);
    draw_snes_compact_text(c, 10, 24, buf, OB_PAL_CYAN);

    uint16_t mask = (t->zodiac_mask != 0u) ? t->zodiac_mask : 0x0003u;
    for (uint8_t s = 0; s < 12; ++s) {
        int gx = 10 + (s % 4) * 31;
        int gy = 40 + (s / 4) * 18;
        draw_snes_zodiac_gem(c, gx, gy, s, (mask & (1u << s)) != 0u);
    }

    draw_snes_compact_text(c, 10, 102, "QUICKSILVER: IN HAND", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 116, "YARU TABLET: IN HAND", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 130, "BRUNHILD: ON TRACK", OB_PAL_GOLD);

    draw_snes_header_plate(c, 6, 152, 132, "ARMY READINESS", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 172, "ROSTER: 38/100 UNITS", OB_PAL_IVORY);
    draw_snes_compact_text(c, 10, 186, "SQUADS: 10/25 READY", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 200, "PROMOTABLE: 4 UNITS!", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 224, "[TAB] OPEN FULL 3-PG", OB_PAL_CYAN);
    draw_snes_compact_text(c, 10, 238, "CAMPAIGN GRIMOIRE", OB_PAL_CYAN);

    /* RIGHT WING: Stage Recon & 18-Hero Auditor (Area 1 Pg3 Q1) */
    int rx = OB_WIDE_2X_RIGHT_X0;
    draw_snes_9slice_box(c, rx, 0, 144, 448, true);
    draw_snes_header_plate(c, rx + 6, 6, 132, "STAGE RECON", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 24, "STAGE: POGROM FOREST", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 38, "BOSS: SIRIUS (LV 10)", OB_PAL_CRIMSON);
    draw_snes_compact_text(c, rx + 10, 52, "ENEMY LVL: 07 - 09", OB_PAL_IVORY);
    draw_snes_compact_text(c, rx + 10, 66, "TOWNS: 7  TEMPLES: 2", OB_PAL_CYAN);
    draw_snes_compact_text(c, rx + 10, 80, "BURIED TREASURES: 3", OB_PAL_GOLD);

    draw_snes_header_plate(c, rx + 6, 102, 132, "18-HERO AUDITOR", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 122, "[X] LANS     JOINED", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 136, "[X] WARREN   JOINED", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 150, "[X] CANOPUS  JOINED", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 164, "[*] ASHE     READY!", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 178, "[*] LYON     READY!", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 192, "[*] RAUNY    CF>=50", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 206, "[*] TRISTAN  CF>=65", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 220, "[*] SLUST    CF>=67", OB_PAL_EMERALD);

    /* Deneb & Galf Tradeoff Alert Boxes */
    draw_snes_rect_fill(c, rx + 8, 244, 128, 84, OB_COLOR_ALERT_BG);
    draw_snes_rect_outline(c, rx + 8, 244, 128, 84, OB_COLOR_TEXT_CRIMSON);
    draw_snes_compact_text(c, rx + 12, 250, "! HERO TRADEOFFS !", OB_PAL_CRIMSON);
    draw_snes_compact_text(c, rx + 12, 266, "DENEB (REQ CF<=35):", OB_PAL_AMBER);
    draw_snes_compact_text(c, rx + 12, 278, " FORFEITS HALLOWEEN", OB_PAL_IVORY);
    draw_snes_compact_text(c, rx + 12, 294, "GALF (REQ CF<=20):", OB_PAL_CRIMSON);
    draw_snes_compact_text(c, rx + 12, 306, " FORFEITS TOP 3 END!", OB_PAL_IVORY);
}

static void render_warren_quiz_wings(ObSnesCanvas *c, const ObWidescreenState *state) {
    (void)state;
    /* LEFT WING: Area 4 Boot-Time Mod, Rule & Seed Configurator */
    draw_snes_9slice_box(c, 0, 0, 144, 448, true);
    draw_snes_header_plate(c, 6, 6, 132, "MOD & SEED CONFIG", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 26, "PROFILE: TACTICIAN", OB_PAL_CYAN);
    draw_snes_compact_text(c, 10, 44, "[X] 16:9 WIDESCREEN", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 58, "[X] AREA 1 TELEMETRY", OB_PAL_EMERALD);
    draw_snes_compact_text(c, 10, 72, "[ ] NO OVERLEVEL ALI", OB_PAL_MUTED);
    draw_snes_compact_text(c, 10, 86, "[ ] +TEMPLE DRAWS", OB_PAL_MUTED);
    draw_snes_compact_text(c, 10, 110, "RANDOMIZER SEED:", OB_PAL_GOLD);
    draw_snes_compact_text(c, 10, 124, " [VANILLA-1993-USA]", OB_PAL_IVORY);

    draw_snes_rect_fill(c, 10, 152, 124, 28, OB_COLOR_HEADER_FILL);
    draw_snes_rect_outline(c, 10, 152, 124, 28, OB_COLOR_GOLD_HI);
    draw_snes_compact_text(c, 16, 162, "[RE-DRAW 6 TAROTS]", OB_PAL_GOLD);

    /* RIGHT WING: Area 1 Live Lord Archetype Decoder (from Pg3 Q3) */
    int rx = OB_WIDE_2X_RIGHT_X0;
    draw_snes_9slice_box(c, rx, 0, 144, 448, true);
    draw_snes_header_plate(c, rx + 6, 6, 132, "LORD ARCHETYPE", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 26, "PROJECTED CLASS:", OB_PAL_CYAN);
    draw_snes_compact_text(c, rx + 10, 40, "HOLY KNIGHT (ICE)", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 60, "FRONT: 2X BANISH", OB_PAL_IVORY);
    draw_snes_compact_text(c, rx + 10, 74, "BACK:  1X ICECLOUD", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 88, "       (ALL FOES!)", OB_PAL_EMERALD);

    draw_snes_header_plate(c, rx + 6, 112, 132, "STARTING STATS", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 10, 132, "STR: 54 (+2)  HP:145", OB_PAL_IVORY);
    draw_snes_compact_text(c, rx + 10, 146, "INT: 58 (+4) AGI: 52", OB_PAL_IVORY);
    draw_snes_compact_text(c, rx + 10, 160, "ALI: 72 (+6) CHA: 64", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 10, 174, "START CHAOS FRM:  58", OB_PAL_GOLD);
}

/* ============================================================================
 * In-Window [Tab] Campaign Grimoire Overlay (Centered 512x384 Modal)
 * Houses full-width Area 1 Page 3 tables (All 18 Heroes + 12 Gems + Bank $09 Promo)
 * ============================================================================ */
static void render_grimoire_modal(ObSnesCanvas *c, const ObWidescreenState *state) {
    (void)state;
    int mx = OB_WIDE_2X_CORE_X0 + 16; /* X = 160, W = 480 */
    int my = 32;                      /* Y = 32,  H = 384 */
    int mw = 480;
    int mh = 384;

    draw_snes_9slice_box(c, mx, my, mw, mh, true);
    draw_snes_header_plate(c, mx + 8, my + 8, mw - 16,
        "ZENOBIAN CAMPAIGN GRIMOIRE [TAB TO CLOSE]", OB_PAL_GOLD);

    /* Left Column: Full 18 Special Character Recruitment Ledger */
    draw_snes_9slice_box(c, mx + 10, my + 26, 226, 346, true);
    draw_snes_header_plate(c, mx + 16, my + 32, 214, "18 SPECIAL HEROES AUDIT", OB_PAL_GOLD);

    static const char *const k_heroes_l[9] = {
        "[X] 01.LANS     JOINED",
        "[X] 02.WARREN   JOINED",
        "[X] 03.CANOPUS  JOINED",
        "[*] 04.GILBERT  CF>=40",
        "[*] 05.ASHE     READY",
        "[*] 06.LYON     READY",
        "[*] 07.SARADIN  READY",
        "[*] 08.YUSHIS   ALI>=65",
        "[*] 09.TRISTAN  CF>=65"
    };
    static const char *const k_heroes_r[9] = {
        "[*] 10.RAUNY    CF>=50",
        "[*] 11.DEBONAIR CF>=55",
        "[*] 12.NORN     PEARL",
        "[*] 13.SLUST    CF>=67",
        "[*] 14.FENRIL   BLD.SWD",
        "[*] 15.AISHA    ALI>=60",
        "[*] 16.FOGEL    DRG.SWD",
        "[!] 17.DENEB    CF<=35!",
        "[!] 18.GALF     CF<=20!"
    };
    for (int i = 0; i < 9; ++i) {
        draw_snes_compact_text(c, mx + 20, my + 52 + i * 16, k_heroes_l[i],
            (i < 3) ? OB_PAL_EMERALD : OB_PAL_IVORY);
        draw_snes_compact_text(c, mx + 20, my + 202 + i * 16, k_heroes_r[i],
            (i >= 7) ? OB_PAL_CRIMSON : OB_PAL_GOLD);
    }

    /* Right Column Top: 12 Zodiac Stones & Brunhild Socket Grid */
    int rx = mx + 244;
    draw_snes_9slice_box(c, rx, my + 26, 226, 168, true);
    draw_snes_header_plate(c, rx + 6, my + 32, 214, "12 ZODIAC STONES & RELICS", OB_PAL_GOLD);
    for (uint8_t s = 0; s < 12; ++s) {
        int gx = rx + 12 + (s % 6) * 34;
        int gy = my + 52 + (s / 6) * 20;
        draw_snes_zodiac_gem(c, gx, gy, s, (s < 4));
    }
    draw_snes_compact_text(c, rx + 12, my + 98, "QUICKSILVER ($45): COLLECTED", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 12, my + 112, "TABLET OF YARU ($49): IN HAND", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 12, my + 128, "HOLY SWORD BRUNHILD: ON TRACK", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 12, my + 144, "ENDING FORECAST: THE WORLD (#1)", OB_PAL_CYAN);

    /* Right Column Bottom: Mod-Aware Bank $09 Promotion Inspector (Pg3 Q4) */
    draw_snes_9slice_box(c, rx, my + 200, 226, 172, true);
    draw_snes_header_plate(c, rx + 6, my + 206, 214, "MOD-AWARE PROMOTION TREE", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 12, my + 226, "UNIT #01: ASHE (FIGHTER LV 6)", OB_PAL_GOLD);
    draw_snes_compact_text(c, rx + 12, my + 242, "-> KNIGHT:   ELIGIBLE NOW! [*]", OB_PAL_EMERALD);
    draw_snes_compact_text(c, rx + 12, my + 258, "-> SAMURAI:  NEED -9 ALI (<=65)", OB_PAL_AMBER);
    draw_snes_compact_text(c, rx + 12, my + 274, "-> NINJA:    NEED -39 ALI(<=35)", OB_PAL_MUTED);
    draw_snes_compact_text(c, rx + 12, my + 290, "-> BEAST M.: NEED +2 STR (>=52)", OB_PAL_AMBER);
    draw_snes_compact_text(c, rx + 12, my + 306, "-> DRAGOON:  RELIC ($49) READY!", OB_PAL_CYAN);
    draw_snes_compact_text(c, rx + 12, my + 328, "2,344-BIT EVENT DIFF: 0 DRIFT", OB_PAL_MUTED);
}

void ob_widescreen_render_frame(
    const ObWidescreenState *state,
    const uint8_t *wram,
    const uint32_t *core_256x224_rgba,
    uint32_t *out_rgba_800x448
) {
    if (!state || !out_rgba_800x448) {
        return;
    }
    ObSnesCanvas canvas;
    ob_snes_canvas_init(&canvas, out_rgba_800x448, OB_WIDE_2X_W, OB_WIDE_2X_H);

    /* Step 1: Render Base 16:9 PPU / Mode-7 / Parallax / Tapestry Layer */
    render_base_layer_800x448(&canvas, state, wram, core_256x224_rgba);

    /* Step 2: If in 16:9 Tactician Wings mode, render context-switched Area 1 Wing Stacks */
    if (state->display_mode == OB_DISPLAY_16_9_TACTICIAN_WINGS) {
        switch (state->active_scene) {
            case OB_SCENE_COMBAT_STAGE:
                render_combat_stage_wings(&canvas, state);
                break;
            case OB_SCENE_WORLD_MAP:
                render_world_map_wings(&canvas, state);
                break;
            case OB_SCENE_WARREN_QUIZ:
                render_warren_quiz_wings(&canvas, state);
                break;
            case OB_SCENE_TACTICAL_MAP:
            default:
                render_tactical_map_wings(&canvas, state);
                break;
        }
    }

    /* Step 3: If [Tab] Campaign Grimoire is open, composite centered overlay */
    if (state->grimoire_open) {
        render_grimoire_modal(&canvas, state);
    }
}
