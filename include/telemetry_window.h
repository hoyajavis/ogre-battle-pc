#ifndef OB_TELEMETRY_WINDOW_H
#define OB_TELEMETRY_WINDOW_H

#include "telemetry.h"
#include "telemetry_math.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==========================================================================
 * Secondary Companion Telemetry Window Frontend (Pre-Gate 3 16:9 Widescreen)
 * ==========================================================================
 * Renders a 640x480 RGBA 4-quadrant tactical & exploratory telemetry window
 * completely decoupled from the certified 256x224 (4:3) primary game window.
 * ========================================================================== */

#define OB_COMPANION_WIDTH   640
#define OB_COMPANION_HEIGHT  480
#define OB_DIFF_LOG_CAPACITY  16

/* Switchable Multi-Page Companion Views */
typedef enum {
    OB_COMPANION_PAGE_TACTICAL = 0,    /* Page 1: 4-Quadrant Radar, Recapture Alert, Kinematics, PoI & Day/Night */
    OB_COMPANION_PAGE_COMBAT_TAROT,    /* Page 2: Live Combat Arena, 14 Tarot Hand & Leader ALI Guard, Promo Tree */
    OB_COMPANION_PAGE_CAMPAIGN_GUIDE   /* Page 3: 18 Hero Recruitment Tracker, 12 Zodiac Stones & Reputation Ledger */
} ObCompanionPage;

typedef struct {
    ObTelemetryHudMode   mode;
    ObCompanionPage      active_page;        /* 0: Tactical, 1: Combat/Tarot, 2: Campaign Guide */
    uint8_t              selected_unit_slot; /* 0..99 inspected unit */
    uint8_t              selected_squad_id;  /* 0..24 inspected squad */
    bool                 show_hidden_poi_radar; /* Toggle 'H': false = count only, true = radar coordinates */
    ObTelemetryDiffEvent recent_diffs[OB_DIFF_LOG_CAPACITY];
    size_t               recent_diff_count;
    uint32_t             total_diffs_observed;
} ObCompanionWindowState;

void ob_companion_window_init(ObCompanionWindowState *state);
void ob_companion_window_cycle_page(ObCompanionWindowState *state);
void ob_companion_window_toggle_poi(ObCompanionWindowState *state);

/* Updates recent bitflag diff ring buffer and renders the 4-panel 640x480 RGBA dashboard */
void ob_telemetry_render_companion_window(
    ObCompanionWindowState *state,
    const ObTelemetryFrame *prev_frame,
    const ObTelemetryFrame *curr_frame,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t *rgba_framebuffer,
    uint32_t width,
    uint32_t height
);

/* Exports an uncompressed 24-bit/32-bit PPM/BMP or PNG snapshot of the Companion Window */
bool ob_companion_window_save_ppm(
    const uint32_t *rgba_framebuffer,
    uint32_t width,
    uint32_t height,
    const char *filepath
);

#ifdef __cplusplus
}
#endif

#endif /* OB_TELEMETRY_WINDOW_H */
