#ifndef OB_ENGINE_CONFIG_H
#define OB_ENGINE_CONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include "../../include/boot_loader.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OB_CONFIG_PATH_MAX 512
#define OB_CONFIG_SEED_MAX 64

typedef enum ObBootProfileId {
    OB_PROFILE_VANILLA          = 0,
    OB_PROFILE_COMMUNITY        = 1,
    OB_PROFILE_FIN_071          = 2,
    OB_PROFILE_CLASS_EXPANSION  = 3,
    OB_PROFILE_COUNT            = 4
} ObBootProfileId;

typedef struct ObUserConfig {
    /* General / Boot (Area 4) */
    char rom_path[OB_CONFIG_PATH_MAX];
    ObBootProfileId boot_profile;
    bool enable_magic_ai_fix;
    bool enable_crown_drop_fix;
    bool enable_extensible_size_table;
    char randomizer_seed[OB_CONFIG_SEED_MAX];
    bool auto_boot;

    /* Video (Gate 3) */
    uint8_t display_mode;   /* 0=16:9 Wings, 1=16:9 Horizon, 2=4:3 Classic */
    bool fullscreen;
    uint8_t window_scale;   /* 1..4 (default 2 -> 1600x896) */
    bool crt_scanlines;
    bool vsync;

    /* Audio */
    uint8_t master_volume;  /* 0..100 */
    bool mute;

    /* Controls & Telemetry (Gate 2 + Area 1) */
    bool mouse_enabled;
    bool edge_pan_enabled;
    uint8_t edge_pan_speed; /* 2..8 px/frame */
    bool poi_radar_enabled;
} ObUserConfig;

/* Initialize configuration with safe defaults */
void ob_config_init_defaults(ObUserConfig *cfg);

/* Load configuration from an INI file. Returns true if loaded, false if file missing (defaults preserved). */
bool ob_config_load(ObUserConfig *cfg, const char *ini_path);

/* Save configuration to an INI file. */
bool ob_config_save(const ObUserConfig *cfg, const char *ini_path);

/* Enforce Area 4 ConflictValidator rules on boot toggles (e.g. Class Expansion vs Bank $30 fixes). */
void ob_config_sanitize_boot_toggles(ObUserConfig *cfg);

/* Populate ob_boot_config_t from ObUserConfig. */
void ob_config_to_boot_config(const ObUserConfig *cfg, ob_boot_config_t *out_boot, const char *vanilla_manifest_dir);

/* Human-readable name for ObBootProfileId. */
const char *ob_config_profile_name(ObBootProfileId id);

/* Profile key string for ob_boot_config_t.base_preset. */
const char *ob_config_profile_key(ObBootProfileId id);

#ifdef __cplusplus
}
#endif

#endif /* OB_ENGINE_CONFIG_H */
