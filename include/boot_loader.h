#ifndef OGRE_BATTLE_BOOT_LOADER_H
#define OGRE_BATTLE_BOOT_LOADER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OB_ROM_SIZE_1_5MB 1572864
#define OB_ROM_SIZE_2_0MB 2097152
#define OB_ROM_SIZE OB_ROM_SIZE_1_5MB
#define OB_NUM_CLASSES 125
#define OB_NUM_STANDARD_CLASSES 101
#define OB_NUM_ITEMS 196
#define OB_NUM_EQUIPMENT_ITEMS 100
#define OB_NUM_STAGES 30

/**
 * Boot Loader Configuration
 */
typedef struct {
    const char *boot_config_path;      /* Path to boot_config.json (if set, takes precedence) */
    const char *base_preset;           /* "vanilla", "dragoner", "fin_071", "class_expansion" (default: "vanilla") */
    const char *vanilla_manifest_dir;  /* Path to directory containing extracted vanilla manifests */
    const char **mod_manifest_paths;   /* Array of paths to overlay mod manifests */
    size_t mod_manifest_count;         /* Number of overlay mods */
    bool enable_magic_ai_fix;          /* Enable Magic AI elemental resistance check fix */
    bool enable_crown_drop_fix;        /* Prevent Crown drops & reroll rare relics */
    bool enable_extensible_size_table; /* Decouple size tables in Bank 30 */
    const char *randomizer_seed;       /* Optional randomizer seed string (NULL for none) */
    bool recalculate_checksum;         /* Recalculate SNES internal checksum */
} ob_boot_config_t;

/**
 * Applies modular manifest patches and engine features directly to the in-memory ROM buffer
 * before SNES CPU reset / recomp_init. Supports dynamic buffer expansion up to 2MB.
 *
 * @param rom_buffer Pointer to pre-allocated ROM memory buffer (must have capacity >= 2MB).
 * @param in_rom_size Initial size of the loaded base ROM (e.g. 1.5MB).
 * @param max_buffer_capacity Maximum capacity allocated for rom_buffer (e.g. 2MB).
 * @param out_final_size Pointer to receive the final assembled ROM size (1.5MB or 2.0MB).
 * @param config Boot loader configuration, preset, and feature toggles.
 * @return true on successful application, false on error or conflict.
 */
bool ob_boot_loader_apply(uint8_t *rom_buffer, size_t in_rom_size, size_t max_buffer_capacity, size_t *out_final_size, const ob_boot_config_t *config);

/**
 * Computes SNES LoROM checksum across the ROM buffer (supports 1.5MB 12Mbit mirrored formula and 2.0MB linear formula).
 *
 * @param rom_buffer Pointer to ROM buffer.
 * @param rom_size Size of rom_buffer (1572864 or 2097152).
 * @param out_checksum Output 16-bit checksum.
 * @param out_inverted Output 16-bit inverted checksum.
 */
void ob_compute_snes_checksum(const uint8_t *rom_buffer, size_t rom_size, uint16_t *out_checksum, uint16_t *out_inverted);

#ifdef __cplusplus
}
#endif

#endif /* OGRE_BATTLE_BOOT_LOADER_H */
