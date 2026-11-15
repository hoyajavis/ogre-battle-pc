/**
 * OgreBattlePC: Milestone 0 Scaffolding Runner
 * Boots LakeSnes virtual silicon runtime with Ogre Battle (USA) LoROM.
 * Supports both headless verification and SDL2 presentation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <SDL.h>
#include "snes.h"

#define SNES_NATIVE_WIDTH 256
#define SNES_NATIVE_HEIGHT 224

// Default read handler for LakeSnes cartridge ROM access
static uint8_t s_rom_read(void* user_data, uint8_t bank, uint16_t adr) {
    uint8_t* rom = (uint8_t*)user_data;
    // Standard LoROM mapping: 32KB banks at $8000-$FFFF
    uint32_t offset = ((bank & 0x7F) * 0x8000) | (adr & 0x7FFF);
    return rom[offset % 0x180000]; // 1.5 MB wrap
}

// Default write handler for cartridge SRAM (Bank $70-$7D: $0000-$7FFF)
static void s_sram_write(void* user_data, uint8_t bank, uint16_t adr, uint8_t val) {
    (void)user_data;
    (void)bank;
    (void)adr;
    (void)val;
}

int main(int argc, char* argv[]) {
    const char* rom_path = (argc > 1) ? argv[1] : "ogre_battle.sfc";
    bool headless = false;
    int max_frames = 180; // Run 3 seconds of boot in headless mode

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--headless") == 0) {
            headless = true;
        } else if (strncmp(argv[i], "--frames=", 9) == 0) {
            max_frames = atoi(argv[i] + 9);
        }
    }

    printf("==================================================\n");
    printf("Ogre Battle 1:1 PC Port [Milestone 0 Runner]\n");
    printf("==================================================\n");
    printf("Loading ROM: %s\n", rom_path);

    FILE* f = fopen(rom_path, "rb");
    if (!f) {
        fprintf(stderr, "[ERROR] Failed to open ROM: %s\n", rom_path);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long rom_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    uint8_t* rom_data = (uint8_t*)malloc(rom_size);
    if (!rom_data) {
        fprintf(stderr, "[ERROR] Out of memory allocating %ld bytes\n", rom_size);
        fclose(f);
        return 1;
    }

    if (fread(rom_data, 1, rom_size, f) != (size_t)rom_size) {
        fprintf(stderr, "[ERROR] Failed to read complete ROM file\n");
        free(rom_data);
        fclose(f);
        return 1;
    }
    fclose(f);
    printf("Successfully loaded %ld bytes into memory.\n", rom_size);

    // Initialize LakeSnes core
    Snes* snes = snes_init();
    if (!snes) {
        fprintf(stderr, "[ERROR] Failed to initialize LakeSnes system core!\n");
        free(rom_data);
        return 1;
    }

    // Configure cartridge read callbacks
    snes_loadRom(snes, rom_data, rom_size);
    snes_reset(snes, true);
    printf("LakeSnes silicon core initialized and reset.\n");

    if (headless) {
        printf("Running in HEADLESS mode for %d frames...\n", max_frames);
        for (int frame = 0; frame < max_frames; ++frame) {
            snes_runFrame(snes);
        }
        printf("Headless execution completed successfully! %d frames executed without crash.\n", max_frames);
        snes_free(snes);
        free(rom_data);
        printf("[PASS] Milestone 0 silicon runtime certified!\n");
        printf("==================================================\n");
        return 0;
    }

    // SDL2 Presentation mode
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "[WARN] SDL_Init failed: %s. Falling back to headless validation.\n", SDL_GetError());
        for (int frame = 0; frame < max_frames; ++frame) {
            snes_runFrame(snes);
        }
        printf("Headless fallback completed %d frames successfully.\n", max_frames);
        snes_free(snes);
        free(rom_data);
        return 0;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Ogre Battle PC (Milestone 0 - Silicon Runtime Scaffolding)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SNES_NATIVE_WIDTH * 3, SNES_NATIVE_HEIGHT * 3,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        fprintf(stderr, "[WARN] Failed to create SDL window (headless display environment?): %s\n", SDL_GetError());
        for (int frame = 0; frame < max_frames; ++frame) {
            snes_runFrame(snes);
        }
        printf("Executed %d frames headlessly.\n", max_frames);
        snes_free(snes);
        free(rom_data);
        SDL_Quit();
        return 0;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture* texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
        SNES_NATIVE_WIDTH, SNES_NATIVE_HEIGHT
    );

    printf("SDL2 window and hardware renderer initialized successfully.\n");
    printf("Running main emulation loop...\n");

    bool running = true;
    SDL_Event event;
    int frame_count = 0;

    while (running && frame_count < max_frames) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        snes_runFrame(snes);
        frame_count++;

        // Present framebuffer
        void* pixels;
        int pitch;
        if (SDL_LockTexture(texture, NULL, &pixels, &pitch) == 0) {
            uint32_t* dst = (uint32_t*)pixels;
            int pitch32 = pitch / 4;
            int fmt = snes->ppu->pixelOutputFormat; // 1 for BGRX
            for (int y = 0; y < SNES_NATIVE_HEIGHT; ++y) {
                uint8_t* src_line = &snes->ppu->pixelBuffer[y * 2048];
                for (int x = 0; x < SNES_NATIVE_WIDTH; ++x) {
                    uint8_t b = src_line[x * 8 + fmt + 0];
                    uint8_t g = src_line[x * 8 + fmt + 1];
                    uint8_t r = src_line[x * 8 + fmt + 2];
                    dst[y * pitch32 + x] = (0xFF << 24) | (r << 16) | (g << 8) | b;
                }
            }
            SDL_UnlockTexture(texture);
        }


        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    snes_free(snes);
    free(rom_data);

    printf("Execution complete: %d frames rendered.\n", frame_count);
    return 0;
}
