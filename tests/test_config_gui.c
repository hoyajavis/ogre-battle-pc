#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "gui_menu.h"
#include "snes_ui_rasterizer.h"

static void test_config_ini_roundtrip(void) {
    ObUserConfig cfg;
    ob_config_init_defaults(&cfg);
    assert(cfg.boot_profile == OB_PROFILE_VANILLA);
    assert(cfg.master_volume == 80);
    assert(cfg.window_scale == 2);
    assert(cfg.mouse_enabled == true);

    snprintf(cfg.rom_path, sizeof(cfg.rom_path), "/tmp/ogre_battle.sfc");
    cfg.boot_profile = OB_PROFILE_FIN_071;
    cfg.enable_magic_ai_fix = true;
    cfg.enable_crown_drop_fix = true;
    cfg.auto_boot = true;
    cfg.display_mode = 1;
    cfg.fullscreen = true;
    cfg.window_scale = 3;
    cfg.crt_scanlines = true;
    cfg.master_volume = 60;
    cfg.mute = true;
    cfg.edge_pan_speed = 6;

    const char *tmp_ini = "/tmp/test_ogre_battle.ini";
    assert(ob_config_save(&cfg, tmp_ini));

    ObUserConfig loaded;
    ob_config_init_defaults(&loaded);
    assert(ob_config_load(&loaded, tmp_ini));

    assert(strcmp(loaded.rom_path, "/tmp/ogre_battle.sfc") == 0);
    assert(loaded.boot_profile == OB_PROFILE_FIN_071);
    assert(loaded.enable_magic_ai_fix == true);
    assert(loaded.enable_crown_drop_fix == true);
    assert(loaded.auto_boot == true);
    assert(loaded.display_mode == 1);
    assert(loaded.fullscreen == true);
    assert(loaded.window_scale == 3);
    assert(loaded.crt_scanlines == true);
    assert(loaded.master_volume == 60);
    assert(loaded.mute == true);
    assert(loaded.edge_pan_speed == 6);

    remove(tmp_ini);
    printf("  [PASS] test_config_ini_roundtrip\n");
}

static void test_conflict_sanitization(void) {
    ObUserConfig cfg;
    ob_config_init_defaults(&cfg);
    cfg.boot_profile = OB_PROFILE_CLASS_EXPANSION;
    cfg.enable_magic_ai_fix = true;
    cfg.enable_crown_drop_fix = true;
    cfg.enable_extensible_size_table = true;

    ob_config_sanitize_boot_toggles(&cfg);
    assert(cfg.enable_magic_ai_fix == false);
    assert(cfg.enable_crown_drop_fix == false);
    assert(cfg.enable_extensible_size_table == false);

    ob_boot_config_t boot;
    ob_config_to_boot_config(&cfg, &boot, "data/vanilla");
    assert(strcmp(boot.base_preset, "class_expansion") == 0);
    assert(boot.enable_magic_ai_fix == false);
    printf("  [PASS] test_conflict_sanitization\n");
}

static void test_gui_launcher_and_settings(void) {
    ObUserConfig cfg;
    ob_config_init_defaults(&cfg);

    ObGuiMenuState gui;
    ob_gui_menu_init(&gui, OB_GUI_SCREEN_LAUNCHER, true, 1572864);

    /* Click Community Fixes profile row (x=150, y=148 -> row 1) */
    ObGuiAction act = ob_gui_menu_handle_mouse(&gui, &cfg, 150, 148, true);
    assert(act == OB_GUI_ACTION_CONFIG_CHANGED);
    assert(cfg.boot_profile == OB_PROFILE_COMMUNITY);
    assert(cfg.enable_magic_ai_fix == true);

    /* Click Class Expansion profile row (y=212 -> row 3), verifying Bank $30 lock */
    act = ob_gui_menu_handle_mouse(&gui, &cfg, 150, 212, true);
    assert(act == OB_GUI_ACTION_CONFIG_CHANGED);
    assert(cfg.boot_profile == OB_PROFILE_CLASS_EXPANSION);
    assert(cfg.enable_magic_ai_fix == false);

    /* Open Settings from Launcher */
    act = ob_gui_menu_handle_mouse(&gui, &cfg, 420, 370, true);
    assert(act == OB_GUI_ACTION_NONE);
    assert(gui.screen == OB_GUI_SCREEN_SETTINGS);
    assert(gui.return_screen == OB_GUI_SCREEN_LAUNCHER);

    /* Switch to Audio tab via keyboard TAB, adjust volume down with LEFT */
    ob_gui_menu_handle_key(&gui, &cfg, OB_GUI_KEY_TAB);
    assert(gui.active_tab == OB_TAB_AUDIO);
    act = ob_gui_menu_handle_key(&gui, &cfg, OB_GUI_KEY_LEFT);
    assert(act == OB_GUI_ACTION_CONFIG_CHANGED);
    assert(cfg.master_volume == 70);

    /* Return to Launcher via ESC */
    act = ob_gui_menu_handle_key(&gui, &cfg, OB_GUI_KEY_ESC);
    assert(gui.screen == OB_GUI_SCREEN_LAUNCHER);

    /* Click Launch Campaign button */
    act = ob_gui_menu_handle_mouse(&gui, &cfg, 200, 370, true);
    assert(act == OB_GUI_ACTION_LAUNCH_GAME);

    /* Render Launcher and Settings to PPM for visual verification */
    uint32_t *rgba = (uint32_t *)calloc(800 * 448, sizeof(uint32_t));
    assert(rgba != NULL);
    ObSnesCanvas canvas;
    ob_snes_canvas_init(&canvas, rgba, 800, 448);

    ob_gui_menu_render(&gui, &cfg, rgba);
    assert(ob_snes_ui_save_ppm(&canvas, "/tmp/gui_launcher.ppm"));

    gui.screen = OB_GUI_SCREEN_NONE;
    ob_gui_menu_toggle_settings(&gui);
    assert(gui.screen == OB_GUI_SCREEN_SETTINGS);
    gui.active_tab = OB_TAB_VIDEO;
    ob_gui_menu_render(&gui, &cfg, rgba);
    assert(ob_snes_ui_save_ppm(&canvas, "/tmp/gui_settings_video.ppm"));

    free(rgba);
    printf("  [PASS] test_gui_launcher_and_settings\n");
}

int main(void) {
    printf("Running COA 3 Config & GUI Menu Tests...\n");
    test_config_ini_roundtrip();
    test_conflict_sanitization();
    test_gui_launcher_and_settings();
    printf("All Config & GUI Menu tests passed!\n");
    return 0;
}
