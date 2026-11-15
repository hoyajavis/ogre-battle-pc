#ifndef OB_ENGINE_GUI_MENU_H
#define OB_ENGINE_GUI_MENU_H

#include <stdbool.h>
#include <stdint.h>
#include "config.h"
#include "snes_ui_rasterizer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ObGuiScreen {
    OB_GUI_SCREEN_NONE     = 0,
    OB_GUI_SCREEN_LAUNCHER = 1,
    OB_GUI_SCREEN_SETTINGS = 2
} ObGuiScreen;

typedef enum ObSettingsTab {
    OB_TAB_VIDEO    = 0,
    OB_TAB_AUDIO    = 1,
    OB_TAB_CONTROLS = 2,
    OB_TAB_SYSTEM   = 3,
    OB_TAB_COUNT    = 4
} ObSettingsTab;

typedef enum ObGuiAction {
    OB_GUI_ACTION_NONE            = 0,
    OB_GUI_ACTION_LAUNCH_GAME     = 1,
    OB_GUI_ACTION_RESUME_GAME     = 2,
    OB_GUI_ACTION_RETURN_LAUNCHER = 3,
    OB_GUI_ACTION_QUIT            = 4,
    OB_GUI_ACTION_CONFIG_CHANGED  = 5
} ObGuiAction;

/* Abstract navigation keys (independent of SDL2 for headless unit testing) */
typedef enum ObGuiKey {
    OB_GUI_KEY_NONE  = 0,
    OB_GUI_KEY_UP    = 1,
    OB_GUI_KEY_DOWN  = 2,
    OB_GUI_KEY_LEFT  = 3,
    OB_GUI_KEY_RIGHT = 4,
    OB_GUI_KEY_ENTER = 5,
    OB_GUI_KEY_ESC   = 6,
    OB_GUI_KEY_TAB   = 7
} ObGuiKey;

typedef struct ObGuiMenuState {
    ObGuiScreen screen;
    ObGuiScreen return_screen; /* Used when opening Settings from Launcher */
    ObSettingsTab active_tab;
    int selected_row;
    int hover_id;
    bool rom_verified;
    size_t rom_size_bytes;
} ObGuiMenuState;

/* Initialize GUI menu state */
void ob_gui_menu_init(ObGuiMenuState *gui, ObGuiScreen initial_screen, bool rom_verified, size_t rom_size_bytes);

/* Open/toggle in-game [Esc] settings overlay */
void ob_gui_menu_toggle_settings(ObGuiMenuState *gui);

/* Handle abstract keyboard/gamepad navigation */
ObGuiAction ob_gui_menu_handle_key(ObGuiMenuState *gui, ObUserConfig *cfg, ObGuiKey key);

/* Handle mouse pointer (800x448 canvas coordinates) and left-click edge */
ObGuiAction ob_gui_menu_handle_mouse(ObGuiMenuState *gui, ObUserConfig *cfg, int canvas_x, int canvas_y, bool left_clicked);

/* Render active GUI screen onto an 800x448 RGBA canvas */
void ob_gui_menu_render(const ObGuiMenuState *gui, const ObUserConfig *cfg, uint32_t *rgba_800x448);

#ifdef __cplusplus
}
#endif

#endif /* OB_ENGINE_GUI_MENU_H */
