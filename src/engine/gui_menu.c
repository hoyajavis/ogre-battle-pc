#include "gui_menu.h"

#include <stdio.h>
#include <string.h>

#define CANVAS_W 800
#define CANVAS_H 448

typedef struct GuiRect {
    int x, y, w, h;
} GuiRect;

static bool pt_in_rect(int px, int py, GuiRect r) {
    return px >= r.x && px < (r.x + r.w) && py >= r.y && py < (r.y + r.h);
}

static void dim_framebuffer(uint32_t *rgba, int w, int h) {
    int count = w * h;
    for (int i = 0; i < count; ++i) {
        uint32_t c = rgba[i];
        uint32_t r = ((c >> 16) & 0xFF) >> 1;
        uint32_t g = ((c >> 8) & 0xFF) >> 1;
        uint32_t b = (c & 0xFF) >> 1;
        rgba[i] = 0xFF000000u | (r << 16) | (g << 8) | b;
    }
}

static void draw_button(ObSnesCanvas *c, GuiRect r, const char *label, bool selected, bool hovered, ObSnesPaletteId pal) {
    draw_snes_9slice_box(c, r.x, r.y, r.w, r.h, true);
    if (selected || hovered) {
        draw_snes_rect_outline(c, r.x + 4, r.y + 4, r.w - 8, r.h - 8,
                               ob_snes_palette_color(selected ? OB_PAL_GOLD : OB_PAL_CYAN));
    }
    int text_w = (int)strlen(label) * 8;
    int tx = r.x + (r.w - text_w) / 2;
    int ty = r.y + (r.h - 8) / 2;
    draw_snes_tile_text(c, tx, ty, label, (selected || hovered) ? OB_PAL_GOLD : pal);
}

static void draw_selectable_row_bg(ObSnesCanvas *c, GuiRect r, bool active, bool hovered) {
    if (active) {
        draw_snes_rect_fill(c, r.x, r.y, r.w, r.h, 0xFF304888u);
        draw_snes_rect_outline(c, r.x, r.y, r.w, r.h, ob_snes_palette_color(OB_PAL_GOLD));
    } else if (hovered) {
        draw_snes_rect_fill(c, r.x, r.y, r.w, r.h, 0xFF22366Eu);
        draw_snes_rect_outline(c, r.x, r.y, r.w, r.h, ob_snes_palette_color(OB_PAL_CYAN));
    } else {
        draw_snes_rect_fill(c, r.x, r.y, r.w, r.h, 0xFF101848u);
        draw_snes_rect_outline(c, r.x, r.y, r.w, r.h, 0xFF384878u);
    }
}

/* ==========================================================================
 * Layout Geometry
 * ========================================================================== */

/* Launcher: 8 rows (0..3 profiles, 4..6 toggles, 7 auto_boot) + 3 buttons */
#define LAUNCHER_ROWS 8
static GuiRect launcher_profile_rect(int i) {
    return (GuiRect){ 104, 108 + i * 32, 280, 26 };
}
static GuiRect launcher_toggle_rect(int i) {
    /* i=0..2: engine fixes; i=3: auto_boot */
    int y = (i < 3) ? (148 + i * 32) : 256;
    return (GuiRect){ 416, y, 280, 26 };
}
static const GuiRect k_btn_launch   = { 128, 352, 216, 40 };
static const GuiRect k_btn_settings = { 368, 352, 160, 40 };
static const GuiRect k_btn_quit     = { 552, 352, 120, 40 };

/* Settings Overlay: 4 tabs */
static GuiRect settings_tab_rect(int t) {
    return (GuiRect){ 136 + t * 134, 80, 126, 24 };
}
static GuiRect settings_row_rect(int row) {
    return (GuiRect){ 144, 124 + row * 40, 512, 32 };
}
static const GuiRect k_btn_resume = { 288, 360, 224, 32 };

static int settings_row_count(ObSettingsTab tab) {
    switch (tab) {
        case OB_TAB_VIDEO:    return 5;
        case OB_TAB_AUDIO:    return 2;
        case OB_TAB_CONTROLS: return 4;
        case OB_TAB_SYSTEM:   return 4;
        default:              return 0;
    }
}

/* ==========================================================================
 * State Management
 * ========================================================================== */

void ob_gui_menu_init(ObGuiMenuState *gui, ObGuiScreen initial_screen, bool rom_verified, size_t rom_size_bytes) {
    if (!gui) return;
    memset(gui, 0, sizeof(*gui));
    gui->screen = initial_screen;
    gui->return_screen = OB_GUI_SCREEN_NONE;
    gui->active_tab = OB_TAB_VIDEO;
    gui->selected_row = 0;
    gui->hover_id = -1;
    gui->rom_verified = rom_verified;
    gui->rom_size_bytes = rom_size_bytes;
}

void ob_gui_menu_toggle_settings(ObGuiMenuState *gui) {
    if (!gui) return;
    if (gui->screen == OB_GUI_SCREEN_NONE) {
        gui->screen = OB_GUI_SCREEN_SETTINGS;
        gui->return_screen = OB_GUI_SCREEN_NONE;
        gui->selected_row = 0;
        gui->hover_id = -1;
    } else if (gui->screen == OB_GUI_SCREEN_SETTINGS) {
        gui->screen = gui->return_screen;
        gui->return_screen = OB_GUI_SCREEN_NONE;
        gui->selected_row = 0;
        gui->hover_id = -1;
    }
}

static void apply_launcher_row_toggle(ObUserConfig *cfg, int row) {
    if (!cfg) return;
    if (row >= 0 && row < OB_PROFILE_COUNT) {
        cfg->boot_profile = (ObBootProfileId)row;
        if (cfg->boot_profile == OB_PROFILE_COMMUNITY) {
            cfg->enable_magic_ai_fix = true;
            cfg->enable_crown_drop_fix = true;
            cfg->enable_extensible_size_table = true;
        }
        ob_config_sanitize_boot_toggles(cfg);
    } else if (row == 4 && cfg->boot_profile != OB_PROFILE_CLASS_EXPANSION) {
        cfg->enable_magic_ai_fix = !cfg->enable_magic_ai_fix;
    } else if (row == 5 && cfg->boot_profile != OB_PROFILE_CLASS_EXPANSION) {
        cfg->enable_crown_drop_fix = !cfg->enable_crown_drop_fix;
    } else if (row == 6 && cfg->boot_profile != OB_PROFILE_CLASS_EXPANSION) {
        cfg->enable_extensible_size_table = !cfg->enable_extensible_size_table;
    } else if (row == 7) {
        cfg->auto_boot = !cfg->auto_boot;
    }
}

static ObGuiAction apply_settings_row_delta(ObGuiMenuState *gui, ObUserConfig *cfg, int row, int delta) {
    if (!gui || !cfg) return OB_GUI_ACTION_NONE;
    switch (gui->active_tab) {
        case OB_TAB_VIDEO:
            if (row == 0) {
                int m = (int)cfg->display_mode + delta;
                if (m < 0) m = 2;
                if (m > 2) m = 0;
                cfg->display_mode = (uint8_t)m;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 1) {
                cfg->fullscreen = !cfg->fullscreen;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 2) {
                int s = (int)cfg->window_scale + delta;
                if (s < 1) s = 4;
                if (s > 4) s = 1;
                cfg->window_scale = (uint8_t)s;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 3) {
                cfg->crt_scanlines = !cfg->crt_scanlines;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 4) {
                cfg->vsync = !cfg->vsync;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            }
            break;

        case OB_TAB_AUDIO:
            if (row == 0) {
                int v = (int)cfg->master_volume + delta * 10;
                if (v < 0) v = 0;
                if (v > 100) v = 100;
                cfg->master_volume = (uint8_t)v;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 1) {
                cfg->mute = !cfg->mute;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            }
            break;

        case OB_TAB_CONTROLS:
            if (row == 0) {
                cfg->mouse_enabled = !cfg->mouse_enabled;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 1) {
                cfg->edge_pan_enabled = !cfg->edge_pan_enabled;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 2) {
                int sp = (int)cfg->edge_pan_speed + delta;
                if (sp < 2) sp = 2;
                if (sp > 8) sp = 8;
                cfg->edge_pan_speed = (uint8_t)sp;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 3) {
                cfg->poi_radar_enabled = !cfg->poi_radar_enabled;
                return OB_GUI_ACTION_CONFIG_CHANGED;
            }
            break;

        case OB_TAB_SYSTEM:
            if (row == 1 && delta == 0) {
                char saved_rom[OB_CONFIG_PATH_MAX];
                strncpy(saved_rom, cfg->rom_path, sizeof(saved_rom) - 1);
                saved_rom[sizeof(saved_rom) - 1] = '\0';
                ob_config_init_defaults(cfg);
                strncpy(cfg->rom_path, saved_rom, sizeof(cfg->rom_path) - 1);
                return OB_GUI_ACTION_CONFIG_CHANGED;
            } else if (row == 2 && delta == 0) {
                gui->screen = OB_GUI_SCREEN_LAUNCHER;
                gui->return_screen = OB_GUI_SCREEN_NONE;
                gui->selected_row = 0;
                return OB_GUI_ACTION_RETURN_LAUNCHER;
            } else if (row == 3 && delta == 0) {
                return OB_GUI_ACTION_QUIT;
            }
            break;

        default:
            break;
    }
    return OB_GUI_ACTION_NONE;
}

ObGuiAction ob_gui_menu_handle_key(ObGuiMenuState *gui, ObUserConfig *cfg, ObGuiKey key) {
    if (!gui || !cfg || gui->screen == OB_GUI_SCREEN_NONE) return OB_GUI_ACTION_NONE;

    if (gui->screen == OB_GUI_SCREEN_LAUNCHER) {
        if (key == OB_GUI_KEY_UP) {
            gui->selected_row = (gui->selected_row + LAUNCHER_ROWS - 1) % LAUNCHER_ROWS;
        } else if (key == OB_GUI_KEY_DOWN) {
            gui->selected_row = (gui->selected_row + 1) % LAUNCHER_ROWS;
        } else if (key == OB_GUI_KEY_LEFT || key == OB_GUI_KEY_RIGHT) {
            gui->selected_row = (gui->selected_row + 4) % LAUNCHER_ROWS;
        } else if (key == OB_GUI_KEY_TAB) {
            apply_launcher_row_toggle(cfg, gui->selected_row);
            return OB_GUI_ACTION_CONFIG_CHANGED;
        } else if (key == OB_GUI_KEY_ENTER) {
            if (gui->selected_row >= 0 && gui->selected_row < LAUNCHER_ROWS) {
                apply_launcher_row_toggle(cfg, gui->selected_row);
            }
            return OB_GUI_ACTION_LAUNCH_GAME;
        } else if (key == OB_GUI_KEY_ESC) {
            return OB_GUI_ACTION_QUIT;
        }
        return OB_GUI_ACTION_NONE;
    }

    if (gui->screen == OB_GUI_SCREEN_SETTINGS) {
        int count = settings_row_count(gui->active_tab);
        if (key == OB_GUI_KEY_ESC) {
            ObGuiScreen ret = gui->return_screen;
            gui->screen = ret;
            gui->return_screen = OB_GUI_SCREEN_NONE;
            return (ret == OB_GUI_SCREEN_NONE) ? OB_GUI_ACTION_RESUME_GAME : OB_GUI_ACTION_NONE;
        } else if (key == OB_GUI_KEY_TAB) {
            gui->active_tab = (ObSettingsTab)((gui->active_tab + 1) % OB_TAB_COUNT);
            gui->selected_row = 0;
        } else if (key == OB_GUI_KEY_UP && count > 0) {
            gui->selected_row = (gui->selected_row + count - 1) % count;
        } else if (key == OB_GUI_KEY_DOWN && count > 0) {
            gui->selected_row = (gui->selected_row + 1) % count;
        } else if (key == OB_GUI_KEY_LEFT) {
            return apply_settings_row_delta(gui, cfg, gui->selected_row, -1);
        } else if (key == OB_GUI_KEY_RIGHT) {
            return apply_settings_row_delta(gui, cfg, gui->selected_row, 1);
        } else if (key == OB_GUI_KEY_ENTER) {
            ObGuiAction act = apply_settings_row_delta(gui, cfg, gui->selected_row, 0);
            if (act == OB_GUI_ACTION_NONE) {
                act = apply_settings_row_delta(gui, cfg, gui->selected_row, 1);
            }
            return act;
        }
    }

    return OB_GUI_ACTION_NONE;
}

ObGuiAction ob_gui_menu_handle_mouse(ObGuiMenuState *gui, ObUserConfig *cfg, int canvas_x, int canvas_y, bool left_clicked) {
    if (!gui || !cfg || gui->screen == OB_GUI_SCREEN_NONE) return OB_GUI_ACTION_NONE;

    gui->hover_id = -1;

    if (gui->screen == OB_GUI_SCREEN_LAUNCHER) {
        for (int i = 0; i < OB_PROFILE_COUNT; ++i) {
            if (pt_in_rect(canvas_x, canvas_y, launcher_profile_rect(i))) {
                gui->hover_id = i;
                if (left_clicked) {
                    gui->selected_row = i;
                    apply_launcher_row_toggle(cfg, i);
                    return OB_GUI_ACTION_CONFIG_CHANGED;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (pt_in_rect(canvas_x, canvas_y, launcher_toggle_rect(i))) {
                gui->hover_id = 4 + i;
                if (left_clicked) {
                    gui->selected_row = 4 + i;
                    apply_launcher_row_toggle(cfg, 4 + i);
                    return OB_GUI_ACTION_CONFIG_CHANGED;
                }
            }
        }
        if (pt_in_rect(canvas_x, canvas_y, k_btn_launch)) {
            gui->hover_id = 100;
            if (left_clicked) return OB_GUI_ACTION_LAUNCH_GAME;
        }
        if (pt_in_rect(canvas_x, canvas_y, k_btn_settings)) {
            gui->hover_id = 101;
            if (left_clicked) {
                gui->return_screen = OB_GUI_SCREEN_LAUNCHER;
                gui->screen = OB_GUI_SCREEN_SETTINGS;
                gui->selected_row = 0;
                gui->hover_id = -1;
            }
        }
        if (pt_in_rect(canvas_x, canvas_y, k_btn_quit)) {
            gui->hover_id = 102;
            if (left_clicked) return OB_GUI_ACTION_QUIT;
        }
        return OB_GUI_ACTION_NONE;
    }

    if (gui->screen == OB_GUI_SCREEN_SETTINGS) {
        for (int t = 0; t < OB_TAB_COUNT; ++t) {
            if (pt_in_rect(canvas_x, canvas_y, settings_tab_rect(t))) {
                gui->hover_id = 200 + t;
                if (left_clicked) {
                    gui->active_tab = (ObSettingsTab)t;
                    gui->selected_row = 0;
                }
                return OB_GUI_ACTION_NONE;
            }
        }
        int count = settings_row_count(gui->active_tab);
        for (int r = 0; r < count; ++r) {
            GuiRect rr = settings_row_rect(r);
            if (pt_in_rect(canvas_x, canvas_y, rr)) {
                gui->hover_id = r;
                if (left_clicked) {
                    gui->selected_row = r;
                    /* For gauge sliders (Audio row 0, Controls row 2), left/right half controls -/+ */
                    if ((gui->active_tab == OB_TAB_AUDIO && r == 0) ||
                        (gui->active_tab == OB_TAB_CONTROLS && r == 2)) {
                        int delta = (canvas_x < rr.x + rr.w / 2 + 40) ? -1 : 1;
                        return apply_settings_row_delta(gui, cfg, r, delta);
                    }
                    ObGuiAction act = apply_settings_row_delta(gui, cfg, r, 0);
                    if (act == OB_GUI_ACTION_NONE) {
                        act = apply_settings_row_delta(gui, cfg, r, 1);
                    }
                    return act;
                }
            }
        }
        if (pt_in_rect(canvas_x, canvas_y, k_btn_resume)) {
            gui->hover_id = 300;
            if (left_clicked) {
                ObGuiScreen ret = gui->return_screen;
                gui->screen = ret;
                gui->return_screen = OB_GUI_SCREEN_NONE;
                return (ret == OB_GUI_SCREEN_NONE) ? OB_GUI_ACTION_RESUME_GAME : OB_GUI_ACTION_NONE;
            }
        }
    }

    return OB_GUI_ACTION_NONE;
}

/* ==========================================================================
 * Rendering
 * ========================================================================== */

static void render_launcher(ObSnesCanvas *c, const ObGuiMenuState *gui, const ObUserConfig *cfg) {
    /* Full-canvas Zenobian tapestry backdrop + Royal Blue main ledger */
    draw_snes_tapestry_pillar(c, 0, 0, CANVAS_W, CANVAS_H);
    draw_snes_9slice_box(c, 80, 24, 640, 400, true);
    draw_snes_header_plate(c, 96, 40, 608, "OGRE BATTLE PC  -  CAMPAIGN LAUNCHER", OB_PAL_GOLD);

    /* Left Column: Area 4 Boot Profiles */
    draw_snes_tile_text(c, 104, 80, "BOOT PROFILE (AREA 4)", OB_PAL_CYAN);
    for (int i = 0; i < OB_PROFILE_COUNT; ++i) {
        GuiRect r = launcher_profile_rect(i);
        bool is_active = ((int)cfg->boot_profile == i);
        bool is_hover = (gui->hover_id == i || gui->selected_row == i);
        draw_selectable_row_bg(c, r, is_active, is_hover);

        char buf[64];
        snprintf(buf, sizeof(buf), "%c %s", is_active ? '*' : ' ', ob_config_profile_name((ObBootProfileId)i));
        draw_snes_tile_text(c, r.x + 8, r.y + 9, buf, is_active ? OB_PAL_GOLD : OB_PAL_IVORY);
    }

    /* Profile Info / Conflict Box */
    draw_snes_9slice_box(c, 104, 244, 280, 92, true);
    draw_snes_compact_text(c, 116, 256, "PROFILE NOTES:", OB_PAL_GOLD);
    if (cfg->boot_profile == OB_PROFILE_VANILLA) {
        draw_snes_compact_text(c, 116, 274, "100% BIT-EXACT USA LOROM", OB_PAL_EMERALD);
        draw_snes_compact_text(c, 116, 290, "1.5MB CLEAN BASELINE", OB_PAL_IVORY);
    } else if (cfg->boot_profile == OB_PROFILE_COMMUNITY) {
        draw_snes_compact_text(c, 116, 274, "2.0MB EXPANDED + BANK $30", OB_PAL_CYAN);
        draw_snes_compact_text(c, 116, 290, "DRAGONER + AI + CROWN FIXES", OB_PAL_IVORY);
    } else if (cfg->boot_profile == OB_PROFILE_FIN_071) {
        draw_snes_compact_text(c, 116, 274, "FIN 0.71 REBALANCE + DRAGONER", OB_PAL_CYAN);
        draw_snes_compact_text(c, 116, 290, "COMPATIBLE WITH BANK $30 FIX", OB_PAL_IVORY);
    } else {
        draw_snes_compact_text(c, 116, 274, "UPRC +14 NEW CLASSES (2.0MB)", OB_PAL_AMBER);
        draw_snes_compact_text(c, 116, 290, "CONFLICT: BANK $30 LOCKED", OB_PAL_CRIMSON);
    }

    /* Right Column: ROM Status & Toggles */
    draw_snes_tile_text(c, 416, 80, "ROM & ENGINE PATCHES", OB_PAL_CYAN);
    draw_snes_9slice_box(c, 416, 104, 280, 36, true);
    if (gui->rom_verified) {
        char rbuf[48];
        snprintf(rbuf, sizeof(rbuf), "ROM: READY (%.1f MB)", (double)gui->rom_size_bytes / (1024.0 * 1024.0));
        draw_snes_compact_text(c, 428, 118, rbuf, OB_PAL_EMERALD);
    } else {
        draw_snes_compact_text(c, 428, 118, "ROM: MISSING / UNVERIFIED", OB_PAL_CRIMSON);
    }

    const char *toggle_labels[4] = {
        "MAGIC AI FIX",
        "CROWN DROP FIX",
        "SIZE TABLE EXT",
        "AUTO-BOOT NEXT"
    };
    bool toggle_vals[4] = {
        cfg->enable_magic_ai_fix,
        cfg->enable_crown_drop_fix,
        cfg->enable_extensible_size_table,
        cfg->auto_boot
    };
    bool locked = (cfg->boot_profile == OB_PROFILE_CLASS_EXPANSION);

    for (int i = 0; i < 4; ++i) {
        GuiRect r = launcher_toggle_rect(i);
        bool is_hover = (gui->hover_id == 4 + i || gui->selected_row == 4 + i);
        bool row_locked = (i < 3 && locked);
        draw_selectable_row_bg(c, r, false, is_hover && !row_locked);
        draw_snes_compact_text(c, r.x + 8, r.y + 9, toggle_labels[i], row_locked ? OB_PAL_MUTED : OB_PAL_IVORY);
        const char *state_str = row_locked ? "[LOCK]" : (toggle_vals[i] ? "[ ON ]" : "[OFF ]");
        ObSnesPaletteId spal = row_locked ? OB_PAL_CRIMSON : (toggle_vals[i] ? OB_PAL_EMERALD : OB_PAL_MUTED);
        draw_snes_compact_text(c, r.x + r.w - 44, r.y + 9, state_str, spal);
    }

    draw_snes_compact_text(c, 416, 296, "PRESS [ENTER] TO LAUNCH", OB_PAL_MUTED);
    draw_snes_compact_text(c, 416, 312, "PRESS [ESC] IN-GAME FOR MENU", OB_PAL_MUTED);

    /* Action Buttons */
    draw_button(c, k_btn_launch, "LAUNCH CAMPAIGN", gui->hover_id == 100, gui->hover_id == 100, OB_PAL_EMERALD);
    draw_button(c, k_btn_settings, "SETTINGS", gui->hover_id == 101, gui->hover_id == 101, OB_PAL_IVORY);
    draw_button(c, k_btn_quit, "QUIT", gui->hover_id == 102, gui->hover_id == 102, OB_PAL_CRIMSON);
}

static void render_settings(ObSnesCanvas *c, const ObGuiMenuState *gui, const ObUserConfig *cfg) {
    dim_framebuffer(c->pixels, CANVAS_W, CANVAS_H);

    draw_snes_9slice_box(c, 120, 40, 560, 368, true);
    draw_snes_header_plate(c, 136, 52, 528, "SYSTEM CONFIGURATION  [ESC]", OB_PAL_GOLD);

    const char *tab_names[OB_TAB_COUNT] = { "VIDEO", "AUDIO", "CONTROLS", "SYSTEM" };
    for (int t = 0; t < OB_TAB_COUNT; ++t) {
        GuiRect tr = settings_tab_rect(t);
        bool active = ((int)gui->active_tab == t);
        bool hovered = (gui->hover_id == 200 + t);
        draw_button(c, tr, tab_names[t], active, hovered, OB_PAL_IVORY);
    }

    int count = settings_row_count(gui->active_tab);
    for (int r = 0; r < count; ++r) {
        GuiRect rr = settings_row_rect(r);
        bool sel = (gui->selected_row == r);
        bool hov = (gui->hover_id == r);
        draw_selectable_row_bg(c, rr, sel, hov);

        char val_buf[48] = "";
        ObSnesPaletteId val_pal = OB_PAL_CYAN;

        if (gui->active_tab == OB_TAB_VIDEO) {
            const char *labels[5] = { "DISPLAY MODE", "FULLSCREEN", "WINDOW SCALE", "CRT SCANLINES", "VSYNC" };
            draw_snes_tile_text(c, rr.x + 12, rr.y + 12, labels[r], OB_PAL_IVORY);
            if (r == 0) {
                const char *modes[3] = { "< 16:9 WINGS >", "< 16:9 HORIZON >", "< 4:3 CLASSIC >" };
                snprintf(val_buf, sizeof(val_buf), "%s", modes[cfg->display_mode % 3]);
            } else if (r == 1) {
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->fullscreen ? "[ ON ]" : "[ OFF ]");
                val_pal = cfg->fullscreen ? OB_PAL_EMERALD : OB_PAL_MUTED;
            } else if (r == 2) {
                snprintf(val_buf, sizeof(val_buf), "< %ux >", cfg->window_scale);
            } else if (r == 3) {
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->crt_scanlines ? "[ ON ]" : "[ OFF ]");
                val_pal = cfg->crt_scanlines ? OB_PAL_EMERALD : OB_PAL_MUTED;
            } else if (r == 4) {
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->vsync ? "[ ON ]" : "[ OFF ]");
                val_pal = cfg->vsync ? OB_PAL_EMERALD : OB_PAL_MUTED;
            }
            int vw = (int)strlen(val_buf) * 8;
            draw_snes_tile_text(c, rr.x + rr.w - vw - 12, rr.y + 12, val_buf, val_pal);
        } else if (gui->active_tab == OB_TAB_AUDIO) {
            if (r == 0) {
                draw_snes_tile_text(c, rr.x + 12, rr.y + 12, "MASTER VOLUME", OB_PAL_IVORY);
                draw_snes_gauge_bar(c, rr.x + 260, rr.y + 10, 160, 12,
                                    cfg->master_volume, 100,
                                    ob_snes_palette_color(OB_PAL_EMERALD), 0xFF101830u);
                snprintf(val_buf, sizeof(val_buf), "%3u%%", cfg->master_volume);
                draw_snes_tile_text(c, rr.x + 436, rr.y + 12, val_buf, OB_PAL_GOLD);
            } else {
                draw_snes_tile_text(c, rr.x + 12, rr.y + 12, "MUTE AUDIO", OB_PAL_IVORY);
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->mute ? "[ ON ]" : "[ OFF ]");
                draw_snes_tile_text(c, rr.x + rr.w - (int)strlen(val_buf) * 8 - 12, rr.y + 12,
                                    val_buf, cfg->mute ? OB_PAL_CRIMSON : OB_PAL_MUTED);
            }
        } else if (gui->active_tab == OB_TAB_CONTROLS) {
            const char *labels[4] = { "MOUSE CONTROL", "EDGE PANNING", "EDGE PAN SPEED", "POI RADAR [P]" };
            draw_snes_tile_text(c, rr.x + 12, rr.y + 12, labels[r], OB_PAL_IVORY);
            if (r == 0) {
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->mouse_enabled ? "[ ON ]" : "[ OFF ]");
                val_pal = cfg->mouse_enabled ? OB_PAL_EMERALD : OB_PAL_MUTED;
                draw_snes_tile_text(c, rr.x + rr.w - (int)strlen(val_buf) * 8 - 12, rr.y + 12, val_buf, val_pal);
            } else if (r == 1) {
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->edge_pan_enabled ? "[ ON ]" : "[ OFF ]");
                val_pal = cfg->edge_pan_enabled ? OB_PAL_EMERALD : OB_PAL_MUTED;
                draw_snes_tile_text(c, rr.x + rr.w - (int)strlen(val_buf) * 8 - 12, rr.y + 12, val_buf, val_pal);
            } else if (r == 2) {
                draw_snes_gauge_bar(c, rr.x + 260, rr.y + 10, 160, 12,
                                    cfg->edge_pan_speed - 2, 6,
                                    ob_snes_palette_color(OB_PAL_CYAN), 0xFF101830u);
                snprintf(val_buf, sizeof(val_buf), "%u PX", cfg->edge_pan_speed);
                draw_snes_tile_text(c, rr.x + 436, rr.y + 12, val_buf, OB_PAL_GOLD);
            } else {
                snprintf(val_buf, sizeof(val_buf), "%s", cfg->poi_radar_enabled ? "[ ON ]" : "[ OFF ]");
                val_pal = cfg->poi_radar_enabled ? OB_PAL_EMERALD : OB_PAL_MUTED;
                draw_snes_tile_text(c, rr.x + rr.w - (int)strlen(val_buf) * 8 - 12, rr.y + 12, val_buf, val_pal);
            }
        } else if (gui->active_tab == OB_TAB_SYSTEM) {
            if (r == 0) {
                draw_snes_tile_text(c, rr.x + 12, rr.y + 12, "ACTIVE PROFILE", OB_PAL_MUTED);
                const char *pname = ob_config_profile_name(cfg->boot_profile);
                draw_snes_tile_text(c, rr.x + rr.w - (int)strlen(pname) * 8 - 12, rr.y + 12, pname, OB_PAL_GOLD);
            } else if (r == 1) {
                draw_snes_tile_text(c, rr.x + 12, rr.y + 12, "RESET TO DEFAULTS", OB_PAL_AMBER);
            } else if (r == 2) {
                draw_snes_tile_text(c, rr.x + 12, rr.y + 12, "RETURN TO LAUNCHER", OB_PAL_CYAN);
            } else if (r == 3) {
                draw_snes_tile_text(c, rr.x + 12, rr.y + 12, "QUIT TO DESKTOP", OB_PAL_CRIMSON);
            }
        }
    }

    draw_button(c, k_btn_resume,
                (gui->return_screen == OB_GUI_SCREEN_LAUNCHER) ? "BACK TO LAUNCHER" : "APPLY & RESUME",
                gui->hover_id == 300, gui->hover_id == 300, OB_PAL_EMERALD);
}

void ob_gui_menu_render(const ObGuiMenuState *gui, const ObUserConfig *cfg, uint32_t *rgba_800x448) {
    if (!gui || !cfg || !rgba_800x448 || gui->screen == OB_GUI_SCREEN_NONE) return;

    ObSnesCanvas canvas;
    ob_snes_canvas_init(&canvas, rgba_800x448, CANVAS_W, CANVAS_H);

    if (gui->screen == OB_GUI_SCREEN_LAUNCHER) {
        render_launcher(&canvas, gui, cfg);
    } else if (gui->screen == OB_GUI_SCREEN_SETTINGS) {
        render_settings(&canvas, gui, cfg);
    }
}
