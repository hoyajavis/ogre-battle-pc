#include "boot_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Directory containing boot_pipeline.py; override at build time (-DOB_TOOLS_DIR=...) or via $OB_TOOLS_DIR. */
#ifndef OB_TOOLS_DIR
#define OB_TOOLS_DIR "tools"
#endif

static const char *ob_tools_dir(void) {
    const char *env = getenv("OB_TOOLS_DIR");
    return (env && env[0]) ? env : OB_TOOLS_DIR;
}

void ob_compute_snes_checksum(const uint8_t *rom_buffer, size_t rom_size, uint16_t *out_checksum, uint16_t *out_inverted) {
    if (!rom_buffer || !out_checksum || !out_inverted || rom_size < 0x8000) return;

    /* Copy buffer to temporarily place dummy checksum bytes */
    uint8_t *temp = (uint8_t *)malloc(rom_size);
    if (!temp) return;
    memcpy(temp, rom_buffer, rom_size);

    /* Standard SNES LoROM dummy bytes at 0x7FDC..0x7FE0 */
    temp[0x7FDC] = 0xFF;
    temp[0x7FDD] = 0xFF;
    temp[0x7FDE] = 0x00;
    temp[0x7FDF] = 0x00;

    uint32_t sum = 0;
    if (rom_size == OB_ROM_SIZE_1_5MB) {
        /* 12Mbit ROM = 1MB + 512KB*2 */
        for (size_t i = 0; i < 1048576; i++) {
            sum += temp[i];
        }
        for (size_t i = 1048576; i < OB_ROM_SIZE_1_5MB; i++) {
            sum += (uint32_t)temp[i] * 2;
        }
    } else {
        /* 16Mbit / 2MB ROM = linear sum */
        for (size_t i = 0; i < rom_size; i++) {
            sum += temp[i];
        }
    }

    uint16_t chk = (uint16_t)(sum & 0xFFFF);
    uint16_t inv = (uint16_t)(chk ^ 0xFFFF);

    *out_checksum = chk;
    *out_inverted = inv;
    free(temp);
}

bool ob_boot_loader_apply(uint8_t *rom_buffer, size_t in_rom_size, size_t max_buffer_capacity, size_t *out_final_size, const ob_boot_config_t *config) {
    if (!rom_buffer || in_rom_size < OB_ROM_SIZE_1_5MB || max_buffer_capacity < OB_ROM_SIZE_2_0MB || !out_final_size || !config) {
        fprintf(stderr, "[BootLoader] Invalid arguments: buffer must have capacity >= 2MB\n");
        return false;
    }

    printf("[BootLoader] Invoking Layered Boot Pipeline before CPU reset...\n");

    /* Write current in-memory buffer to temporary file for builder pass */
    const char *tmp_in = "/tmp/ob_boot_in.sfc";
    const char *tmp_out = "/tmp/ob_boot_out.sfc";
    
    FILE *f_in = fopen(tmp_in, "wb");
    if (!f_in) return false;
    fwrite(rom_buffer, 1, in_rom_size, f_in);
    fclose(f_in);

    /* Construct boot_pipeline CLI command */
    char cmd[4096];
    if (config->boot_config_path != NULL && strlen(config->boot_config_path) > 0) {
        snprintf(cmd, sizeof(cmd), "python3 %s/boot_pipeline.py --rom %s --config %s --out %s",
                 ob_tools_dir(), tmp_in, config->boot_config_path, tmp_out);
    } else {
        const char *preset = config->base_preset ? config->base_preset : "vanilla";
        snprintf(cmd, sizeof(cmd), "python3 %s/boot_pipeline.py --rom %s --preset %s --out %s",
                 ob_tools_dir(), tmp_in, preset, tmp_out);
        if (config->vanilla_manifest_dir) {
            strncat(cmd, " --manifests ", sizeof(cmd) - strlen(cmd) - 1);
            strncat(cmd, config->vanilla_manifest_dir, sizeof(cmd) - strlen(cmd) - 1);
        }
        for (size_t i = 0; i < config->mod_manifest_count; i++) {
            strncat(cmd, " --overlay ", sizeof(cmd) - strlen(cmd) - 1);
            strncat(cmd, config->mod_manifest_paths[i], sizeof(cmd) - strlen(cmd) - 1);
        }
        if (config->enable_magic_ai_fix) {
            strncat(cmd, " --enable-magic-fix", sizeof(cmd) - strlen(cmd) - 1);
        }
        if (config->enable_crown_drop_fix) {
            strncat(cmd, " --enable-crown-fix", sizeof(cmd) - strlen(cmd) - 1);
        }
        if (config->enable_extensible_size_table) {
            strncat(cmd, " --enable-size-table", sizeof(cmd) - strlen(cmd) - 1);
        }
    }

    int ret = system(cmd);
    if (ret != 0) {
        fprintf(stderr, "[BootLoader] Error executing boot_pipeline pass (exit code %d)\n", ret);
        return false;
    }

    /* Read back modified ROM buffer */
    FILE *f_out = fopen(tmp_out, "rb");
    if (!f_out) return false;
    fseek(f_out, 0, SEEK_END);
    long file_size = ftell(f_out);
    fseek(f_out, 0, SEEK_SET);

    if (file_size < 0 || (size_t)file_size > max_buffer_capacity) {
        fprintf(stderr, "[BootLoader] Error: Assembled ROM size %ld exceeds buffer capacity %zu\n", file_size, max_buffer_capacity);
        fclose(f_out);
        return false;
    }

    size_t read_bytes = fread(rom_buffer, 1, file_size, f_out);
    fclose(f_out);

    if (read_bytes != (size_t)file_size) {
        fprintf(stderr, "[BootLoader] Error reading back assembled ROM\n");
        return false;
    }

    *out_final_size = read_bytes;

    printf("[BootLoader] Successfully prepared ROM buffer (%zu bytes, 0 runtime overhead)\n", read_bytes);
    return true;
}
