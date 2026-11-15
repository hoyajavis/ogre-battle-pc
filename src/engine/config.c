#include "config.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void safe_strcpy(char *dst, size_t dst_size, const char *src) {
    if (!dst || dst_size == 0) return;
    if (!src) {
        dst[0] = '\0';
        return;
    }
    strncpy(dst, src, dst_size - 1);
    dst[dst_size - 1] = '\0';
}

static char *trim_whitespace(char *s) {
    while (*s && isspace((unsigned char)*s)) s++;
    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[--len] = '\0';
    }
    return s;
}

static bool parse_bool(const char *val, bool fallback) {
    if (!val) return fallback;
    if (strcmp(val, "1") == 0 || strcmp(val, "true") == 0 || strcmp(val, "yes") == 0 || strcmp(val, "on") == 0) {
        return true;
    }
    if (strcmp(val, "0") == 0 || strcmp(val, "false") == 0 || strcmp(val, "no") == 0 || strcmp(val, "off") == 0) {
        return false;
    }
    return fallback;
}

static int clamp_int(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

void ob_config_init_defaults(ObUserConfig *cfg) {
    if (!cfg) return;
    memset(cfg, 0, sizeof(*cfg));
    safe_strcpy(cfg->rom_path, sizeof(cfg->rom_path), "ogre_battle.sfc");
    cfg->boot_profile = OB_PROFILE_VANILLA;
    cfg->enable_magic_ai_fix = false;
    cfg->enable_crown_drop_fix = false;
    cfg->enable_extensible_size_table = false;
    cfg->randomizer_seed[0] = '\0';
    cfg->auto_boot = false;

    cfg->display_mode = 0; /* OB_DISPLAY_16_9_TACTICIAN_WINGS */
    cfg->fullscreen = false;
    cfg->window_scale = 2; /* 1600x896 */
    cfg->crt_scanlines = false;
    cfg->vsync = true;

    cfg->master_volume = 80;
    cfg->mute = false;

    cfg->mouse_enabled = true;
    cfg->edge_pan_enabled = true;
    cfg->edge_pan_speed = 4;
    cfg->poi_radar_enabled = true;
}

const char *ob_config_profile_name(ObBootProfileId id) {
    switch (id) {
        case OB_PROFILE_VANILLA:         return "Vanilla Purist";
        case OB_PROFILE_COMMUNITY:       return "Community Fixes";
        case OB_PROFILE_FIN_071:         return "Fin 0.71 Overhaul";
        case OB_PROFILE_CLASS_EXPANSION: return "Class Expansion";
        default:                         return "Vanilla Purist";
    }
}

const char *ob_config_profile_key(ObBootProfileId id) {
    switch (id) {
        case OB_PROFILE_VANILLA:         return "vanilla";
        case OB_PROFILE_COMMUNITY:       return "vanilla";
        case OB_PROFILE_FIN_071:         return "fin_071";
        case OB_PROFILE_CLASS_EXPANSION: return "class_expansion";
        default:                         return "vanilla";
    }
}

static ObBootProfileId parse_profile_key(const char *s) {
    if (!s) return OB_PROFILE_VANILLA;
    if (strcmp(s, "community") == 0) return OB_PROFILE_COMMUNITY;
    if (strcmp(s, "fin_071") == 0) return OB_PROFILE_FIN_071;
    if (strcmp(s, "class_expansion") == 0) return OB_PROFILE_CLASS_EXPANSION;
    return OB_PROFILE_VANILLA;
}

void ob_config_sanitize_boot_toggles(ObUserConfig *cfg) {
    if (!cfg) return;
    if (cfg->boot_profile >= OB_PROFILE_COUNT) {
        cfg->boot_profile = OB_PROFILE_VANILLA;
    }
    /* Area 4 ConflictValidator: UPRC Class Expansion cannot combine with Bank $30 engine fixes */
    if (cfg->boot_profile == OB_PROFILE_CLASS_EXPANSION) {
        cfg->enable_magic_ai_fix = false;
        cfg->enable_crown_drop_fix = false;
        cfg->enable_extensible_size_table = false;
    }
}

bool ob_config_load(ObUserConfig *cfg, const char *ini_path) {
    if (!cfg || !ini_path) return false;
    FILE *f = fopen(ini_path, "r");
    if (!f) return false;

    char line[1024];
    char section[64] = "";

    while (fgets(line, sizeof(line), f)) {
        char *s = trim_whitespace(line);
        if (s[0] == '\0' || s[0] == '#' || s[0] == ';') continue;

        if (s[0] == '[') {
            char *end = strchr(s, ']');
            if (end) {
                *end = '\0';
                safe_strcpy(section, sizeof(section), trim_whitespace(s + 1));
            }
            continue;
        }

        char *eq = strchr(s, '=');
        if (!eq) continue;
        *eq = '\0';
        char *key = trim_whitespace(s);
        char *val = trim_whitespace(eq + 1);

        if (strcmp(section, "boot") == 0) {
            if (strcmp(key, "rom_path") == 0) {
                safe_strcpy(cfg->rom_path, sizeof(cfg->rom_path), val);
            } else if (strcmp(key, "profile") == 0) {
                cfg->boot_profile = parse_profile_key(val);
            } else if (strcmp(key, "magic_ai_fix") == 0) {
                cfg->enable_magic_ai_fix = parse_bool(val, cfg->enable_magic_ai_fix);
            } else if (strcmp(key, "crown_drop_fix") == 0) {
                cfg->enable_crown_drop_fix = parse_bool(val, cfg->enable_crown_drop_fix);
            } else if (strcmp(key, "extensible_size_table") == 0) {
                cfg->enable_extensible_size_table = parse_bool(val, cfg->enable_extensible_size_table);
            } else if (strcmp(key, "randomizer_seed") == 0) {
                safe_strcpy(cfg->randomizer_seed, sizeof(cfg->randomizer_seed), val);
            } else if (strcmp(key, "auto_boot") == 0) {
                cfg->auto_boot = parse_bool(val, cfg->auto_boot);
            }
        } else if (strcmp(section, "video") == 0) {
            if (strcmp(key, "display_mode") == 0) {
                cfg->display_mode = (uint8_t)clamp_int(atoi(val), 0, 2);
            } else if (strcmp(key, "fullscreen") == 0) {
                cfg->fullscreen = parse_bool(val, cfg->fullscreen);
            } else if (strcmp(key, "window_scale") == 0) {
                cfg->window_scale = (uint8_t)clamp_int(atoi(val), 1, 4);
            } else if (strcmp(key, "crt_scanlines") == 0) {
                cfg->crt_scanlines = parse_bool(val, cfg->crt_scanlines);
            } else if (strcmp(key, "vsync") == 0) {
                cfg->vsync = parse_bool(val, cfg->vsync);
            }
        } else if (strcmp(section, "audio") == 0) {
            if (strcmp(key, "master_volume") == 0) {
                cfg->master_volume = (uint8_t)clamp_int(atoi(val), 0, 100);
            } else if (strcmp(key, "mute") == 0) {
                cfg->mute = parse_bool(val, cfg->mute);
            }
        } else if (strcmp(section, "controls") == 0) {
            if (strcmp(key, "mouse_enabled") == 0) {
                cfg->mouse_enabled = parse_bool(val, cfg->mouse_enabled);
            } else if (strcmp(key, "edge_pan_enabled") == 0) {
                cfg->edge_pan_enabled = parse_bool(val, cfg->edge_pan_enabled);
            } else if (strcmp(key, "edge_pan_speed") == 0) {
                cfg->edge_pan_speed = (uint8_t)clamp_int(atoi(val), 2, 8);
            } else if (strcmp(key, "poi_radar_enabled") == 0) {
                cfg->poi_radar_enabled = parse_bool(val, cfg->poi_radar_enabled);
            }
        }
    }

    fclose(f);
    ob_config_sanitize_boot_toggles(cfg);
    return true;
}

bool ob_config_save(const ObUserConfig *cfg, const char *ini_path) {
    if (!cfg || !ini_path) return false;
    FILE *f = fopen(ini_path, "w");
    if (!f) return false;

    const char *profile_str = "vanilla";
    switch (cfg->boot_profile) {
        case OB_PROFILE_VANILLA:         profile_str = "vanilla"; break;
        case OB_PROFILE_COMMUNITY:       profile_str = "community"; break;
        case OB_PROFILE_FIN_071:         profile_str = "fin_071"; break;
        case OB_PROFILE_CLASS_EXPANSION: profile_str = "class_expansion"; break;
        default: break;
    }

    fprintf(f, "# Ogre Battle: The March of the Black Queen - PC Configuration\n\n");
    fprintf(f, "[boot]\n");
    fprintf(f, "rom_path = %s\n", cfg->rom_path);
    fprintf(f, "profile = %s\n", profile_str);
    fprintf(f, "magic_ai_fix = %s\n", cfg->enable_magic_ai_fix ? "true" : "false");
    fprintf(f, "crown_drop_fix = %s\n", cfg->enable_crown_drop_fix ? "true" : "false");
    fprintf(f, "extensible_size_table = %s\n", cfg->enable_extensible_size_table ? "true" : "false");
    fprintf(f, "randomizer_seed = %s\n", cfg->randomizer_seed);
    fprintf(f, "auto_boot = %s\n\n", cfg->auto_boot ? "true" : "false");

    fprintf(f, "[video]\n");
    fprintf(f, "display_mode = %u\n", cfg->display_mode);
    fprintf(f, "fullscreen = %s\n", cfg->fullscreen ? "true" : "false");
    fprintf(f, "window_scale = %u\n", cfg->window_scale);
    fprintf(f, "crt_scanlines = %s\n", cfg->crt_scanlines ? "true" : "false");
    fprintf(f, "vsync = %s\n\n", cfg->vsync ? "true" : "false");

    fprintf(f, "[audio]\n");
    fprintf(f, "master_volume = %u\n", cfg->master_volume);
    fprintf(f, "mute = %s\n\n", cfg->mute ? "true" : "false");

    fprintf(f, "[controls]\n");
    fprintf(f, "mouse_enabled = %s\n", cfg->mouse_enabled ? "true" : "false");
    fprintf(f, "edge_pan_enabled = %s\n", cfg->edge_pan_enabled ? "true" : "false");
    fprintf(f, "edge_pan_speed = %u\n", cfg->edge_pan_speed);
    fprintf(f, "poi_radar_enabled = %s\n", cfg->poi_radar_enabled ? "true" : "false");

    fclose(f);
    return true;
}

void ob_config_to_boot_config(const ObUserConfig *cfg, ob_boot_config_t *out_boot, const char *vanilla_manifest_dir) {
    if (!cfg || !out_boot) return;
    memset(out_boot, 0, sizeof(*out_boot));
    out_boot->base_preset = ob_config_profile_key(cfg->boot_profile);
    out_boot->vanilla_manifest_dir = vanilla_manifest_dir;
    out_boot->enable_magic_ai_fix = cfg->enable_magic_ai_fix;
    out_boot->enable_crown_drop_fix = cfg->enable_crown_drop_fix;
    out_boot->enable_extensible_size_table = cfg->enable_extensible_size_table;
    if (cfg->boot_profile == OB_PROFILE_CLASS_EXPANSION) {
        out_boot->enable_magic_ai_fix = false;
        out_boot->enable_crown_drop_fix = false;
        out_boot->enable_extensible_size_table = false;
    }
    out_boot->randomizer_seed = (cfg->randomizer_seed[0] != '\0') ? cfg->randomizer_seed : NULL;
    out_boot->recalculate_checksum = true;
}
