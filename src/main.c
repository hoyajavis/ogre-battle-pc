/**
 * OgreBattlePC: Unified Native Desktop Runner
 * Integrates:
 *  - Gate 1: Lifted 65816 C core (libob_recomp.a) + LakeSnes silicon runtime
 *  - Gate 2: Three-Pillar Direct-State & Hit-Box Mouse (src/engine/input.c)
 *  - Gate 3: 800x448 16:9 Widescreen Compositor & Area 1 Wings (src/engine/widescreen.c)
 *  - Area 4: Boot-Time Profile/Mod Loader (src/engine/boot_loader.c)
 *  - COA 3:  SNES-Styled Pre-Boot Launcher & [Esc] Settings Overlay + ogre_battle.ini
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>
#include <snesrecomp/bus.h>
#include <snesrecomp/func_table.h>

#include "boot_loader.h"
#include "engine/config.h"
#include "engine/gui_menu.h"
#include "engine/input.h"
#include "engine/widescreen.h"
#include "ob_recomp.h"
#include "snes.h"

#define OB_INI_PATH "ogre_battle.ini"
#define OB_AUDIO_SAMPLE_RATE 32040
#define OB_AUDIO_SAMPLES_PER_FRAME 534

static void apply_crt_scanlines(uint32_t *rgba, int w, int h) {
    for (int y = 1; y < h; y += 2) {
        uint32_t *row = &rgba[y * w];
        for (int x = 0; x < w; ++x) {
            uint32_t c = row[x];
            uint32_t r = (((c >> 16) & 0xFF) * 3) >> 2;
            uint32_t g = (((c >> 8) & 0xFF) * 3) >> 2;
            uint32_t b = ((c & 0xFF) * 3) >> 2;
            row[x] = 0xFF000000u | (r << 16) | (g << 8) | b;
        }
    }
}

static void extract_core_256x224(const Snes *snes, uint32_t *out_256x224) {
    int fmt = snes->ppu->pixelOutputFormat;
    for (int y = 0; y < 224; ++y) {
        const uint8_t *src_line = &snes->ppu->pixelBuffer[y * 2048];
        for (int x = 0; x < 256; ++x) {
            uint8_t b = src_line[x * 8 + fmt + 0];
            uint8_t g = src_line[x * 8 + fmt + 1];
            uint8_t r = src_line[x * 8 + fmt + 2];
            out_256x224[y * 256 + x] = 0xFF000000u | (r << 16) | (g << 8) | b;
        }
    }
}

static bool load_rom_file(const char *path, uint8_t *buf_2mb, size_t *out_size) {
    FILE *f = fopen(path, "rb");
    if (!f) return false;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0 || (size_t)sz > OB_ROM_SIZE_2_0MB) {
        fclose(f);
        return false;
    }
    if (fread(buf_2mb, 1, (size_t)sz, f) != (size_t)sz) {
        fclose(f);
        return false;
    }
    fclose(f);
    *out_size = (size_t)sz;
    return true;
}

static uint16_t poll_keyboard_joypad(const uint8_t *keys) {
    uint16_t j = 0;
    if (keys[SDL_SCANCODE_Z] || keys[SDL_SCANCODE_J]) j |= OB_BTN_B;
    if (keys[SDL_SCANCODE_X] || keys[SDL_SCANCODE_K]) j |= OB_BTN_A;
    if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_U]) j |= OB_BTN_Y;
    if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_I]) j |= OB_BTN_X;
    if (keys[SDL_SCANCODE_Q]) j |= OB_BTN_L;
    if (keys[SDL_SCANCODE_W]) j |= OB_BTN_R;
    if (keys[SDL_SCANCODE_RETURN]) j |= OB_BTN_START;
    if (keys[SDL_SCANCODE_RSHIFT] || keys[SDL_SCANCODE_BACKSPACE]) j |= OB_BTN_SELECT;
    if (keys[SDL_SCANCODE_UP])    j |= OB_BTN_UP;
    if (keys[SDL_SCANCODE_DOWN])  j |= OB_BTN_DOWN;
    if (keys[SDL_SCANCODE_LEFT])  j |= OB_BTN_LEFT;
    if (keys[SDL_SCANCODE_RIGHT]) j |= OB_BTN_RIGHT;
    return j;
}

static ObGuiKey sdl_key_to_gui_key(SDL_Keycode sym) {
    switch (sym) {
        case SDLK_UP:     return OB_GUI_KEY_UP;
        case SDLK_DOWN:   return OB_GUI_KEY_DOWN;
        case SDLK_LEFT:   return OB_GUI_KEY_LEFT;
        case SDLK_RIGHT:  return OB_GUI_KEY_RIGHT;
        case SDLK_RETURN:
        case SDLK_KP_ENTER: return OB_GUI_KEY_ENTER;
        case SDLK_ESCAPE: return OB_GUI_KEY_ESC;
        case SDLK_TAB:    return OB_GUI_KEY_TAB;
        default:          return OB_GUI_KEY_NONE;
    }
}

static void apply_video_settings(SDL_Window *window, const ObUserConfig *cfg, ObWidescreenState *ws) {
    ws->display_mode = (ObDisplayMode)(cfg->display_mode % 3);
    ws->poi_radar_enabled = cfg->poi_radar_enabled;
    if (cfg->fullscreen) {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(window, 0);
        int scale = cfg->window_scale ? cfg->window_scale : 2;
        SDL_SetWindowSize(window, OB_WIDE_2X_W * scale / 2, OB_WIDE_2X_H * scale / 2);
    }
}

int main(int argc, char *argv[]) {
    ObUserConfig cfg;
    ob_config_init_defaults(&cfg);
    ob_config_load(&cfg, OB_INI_PATH);

    bool headless = false;
    int max_frames = 0; /* 0 = unlimited in interactive mode */

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--headless") == 0) {
            headless = true;
            if (max_frames == 0) max_frames = 180;
        } else if (strncmp(argv[i], "--frames=", 9) == 0) {
            max_frames = atoi(argv[i] + 9);
        } else if (strncmp(argv[i], "--rom=", 6) == 0) {
            strncpy(cfg.rom_path, argv[i] + 6, sizeof(cfg.rom_path) - 1);
            cfg.rom_path[sizeof(cfg.rom_path) - 1] = '\0';
        } else if (argv[i][0] != '-') {
            strncpy(cfg.rom_path, argv[i], sizeof(cfg.rom_path) - 1);
            cfg.rom_path[sizeof(cfg.rom_path) - 1] = '\0';
        }
    }

    uint8_t *rom_buf = (uint8_t *)calloc(1, OB_ROM_SIZE_2_0MB);
    uint32_t *core_256x224 = (uint32_t *)calloc(256 * 224, sizeof(uint32_t));
    uint32_t *canvas_800x448 = (uint32_t *)calloc(OB_WIDE_2X_W * OB_WIDE_2X_H, sizeof(uint32_t));
    if (!rom_buf || !core_256x224 || !canvas_800x448) {
        fprintf(stderr, "[ERROR] Out of memory allocating buffers\n");
        free(rom_buf);
        free(core_256x224);
        free(canvas_800x448);
        return 1;
    }

    size_t rom_size = 0;
    bool rom_ok = load_rom_file(cfg.rom_path, rom_buf, &rom_size);

    func_table_init();
    gen_register_all();

    if (headless) {
        if (!rom_ok) {
            fprintf(stderr, "[ERROR] Failed to open ROM: %s\n", cfg.rom_path);
            free(rom_buf); free(core_256x224); free(canvas_800x448);
            return 1;
        }
        ob_boot_config_t boot_cfg;
        ob_config_to_boot_config(&cfg, &boot_cfg, "data/vanilla");
        size_t final_size = rom_size;
        ob_boot_loader_apply(rom_buf, rom_size, OB_ROM_SIZE_2_0MB, &final_size, &boot_cfg);

        Snes *snes = snes_init();
        snes_loadRom(snes, rom_buf, (int)final_size);
        snes_reset(snes, true);
        snesrecomp_set_snes(snes);
        recomp_timed_recomp_enable();
        for (int f = 0; f < max_frames; ++f) {
            snes_runFrame(snes);
        }
        recomp_timed_recomp_disable();
        snes_free(snes);
        free(rom_buf); free(core_256x224); free(canvas_800x448);
        printf("[PASS] Headless execution completed (%d frames).\n", max_frames);
        return 0;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "[ERROR] SDL_Init failed: %s\n", SDL_GetError());
        free(rom_buf); free(core_256x224); free(canvas_800x448);
        return 1;
    }

    int init_scale = cfg.window_scale ? cfg.window_scale : 2;
    SDL_Window *window = SDL_CreateWindow(
        "Ogre Battle: The March of the Black Queen (PC)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        OB_WIDE_2X_W * init_scale / 2, OB_WIDE_2X_H * init_scale / 2,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | (cfg.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0)
    );
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | (cfg.vsync ? SDL_RENDERER_PRESENTVSYNC : 0)
    );
    SDL_RenderSetLogicalSize(renderer, OB_WIDE_2X_W, OB_WIDE_2X_H);
    SDL_Texture *texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
        OB_WIDE_2X_W, OB_WIDE_2X_H
    );

    SDL_AudioSpec want, have;
    SDL_zero(want);
    want.freq = OB_AUDIO_SAMPLE_RATE;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = 1024;
    SDL_AudioDeviceID audio_dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (audio_dev > 0) SDL_PauseAudioDevice(audio_dev, 0);
    int16_t audio_buf[OB_AUDIO_SAMPLES_PER_FRAME * 2];

    ObGuiMenuState gui;
    ob_gui_menu_init(&gui, cfg.auto_boot && rom_ok ? OB_GUI_SCREEN_NONE : OB_GUI_SCREEN_LAUNCHER, rom_ok, rom_size);

    ObWidescreenState ws;
    ob_widescreen_init(&ws);
    apply_video_settings(window, &cfg, &ws);

    ObMouseState mouse;
    ob_input_init(&mouse);

    Snes *snes = NULL;
    bool running = true;
    int frame_count = 0;

    while (running && (max_frames == 0 || frame_count < max_frames)) {
        if (!snes && gui.screen == OB_GUI_SCREEN_NONE && rom_ok) {
            size_t raw_size = 0;
            if (load_rom_file(cfg.rom_path, rom_buf, &raw_size)) {
                ob_boot_config_t boot_cfg;
                ob_config_to_boot_config(&cfg, &boot_cfg, "data/vanilla");
                size_t final_size = raw_size;
                ob_boot_loader_apply(rom_buf, raw_size, OB_ROM_SIZE_2_0MB, &final_size, &boot_cfg);
                snes = snes_init();
                snes_loadRom(snes, rom_buf, (int)final_size);
                snes_reset(snes, true);
                snesrecomp_set_snes(snes);
                recomp_timed_recomp_enable();
            } else {
                gui.screen = OB_GUI_SCREEN_LAUNCHER;
                gui.rom_verified = false;
            }
        }

        bool left_clicked = false;
        int win_x = 0, win_y = 0, win_w = OB_WIDE_2X_W, win_h = OB_WIDE_2X_H;
        uint32_t btn_mask = SDL_GetMouseState(&win_x, &win_y);
        SDL_GetWindowSize(window, &win_w, &win_h);
        int canvas_x = (win_w > 0) ? (win_x * OB_WIDE_2X_W) / win_w : 0;
        int canvas_y = (win_h > 0) ? (win_y * OB_WIDE_2X_H) / win_h : 0;

        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                running = false;
            } else if (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT) {
                left_clicked = true;
            } else if (ev.type == SDL_KEYDOWN && !ev.key.repeat) {
                if (gui.screen != OB_GUI_SCREEN_NONE) {
                    ObGuiKey gk = sdl_key_to_gui_key(ev.key.keysym.sym);
                    ObGuiAction act = ob_gui_menu_handle_key(&gui, &cfg, gk);
                    if (act == OB_GUI_ACTION_LAUNCH_GAME && gui.rom_verified) {
                        gui.screen = OB_GUI_SCREEN_NONE;
                        ob_config_save(&cfg, OB_INI_PATH);
                    } else if (act == OB_GUI_ACTION_CONFIG_CHANGED) {
                        apply_video_settings(window, &cfg, &ws);
                        ob_config_save(&cfg, OB_INI_PATH);
                    } else if (act == OB_GUI_ACTION_RETURN_LAUNCHER && snes) {
                        recomp_timed_recomp_disable();
                        snes_free(snes);
                        snes = NULL;
                    } else if (act == OB_GUI_ACTION_QUIT) {
                        running = false;
                    }
                } else {
                    if (ev.key.keysym.sym == SDLK_ESCAPE) {
                        ob_gui_menu_toggle_settings(&gui);
                    } else if (ev.key.keysym.sym == SDLK_F10) {
                        ob_widescreen_cycle_display_mode(&ws);
                        cfg.display_mode = (uint8_t)ws.display_mode;
                        ob_config_save(&cfg, OB_INI_PATH);
                    } else if (ev.key.keysym.sym == SDLK_TAB) {
                        ob_widescreen_toggle_grimoire(&ws);
                    } else if (ev.key.keysym.sym == SDLK_p) {
                        ws.poi_radar_enabled = !ws.poi_radar_enabled;
                        cfg.poi_radar_enabled = ws.poi_radar_enabled;
                        ob_config_save(&cfg, OB_INI_PATH);
                    }
                }
            }
        }

        if (gui.screen != OB_GUI_SCREEN_NONE) {
            ObGuiAction act = ob_gui_menu_handle_mouse(&gui, &cfg, canvas_x, canvas_y, left_clicked);
            if (act == OB_GUI_ACTION_LAUNCH_GAME && gui.rom_verified) {
                gui.screen = OB_GUI_SCREEN_NONE;
                ob_config_save(&cfg, OB_INI_PATH);
            } else if (act == OB_GUI_ACTION_CONFIG_CHANGED) {
                apply_video_settings(window, &cfg, &ws);
                ob_config_save(&cfg, OB_INI_PATH);
            } else if (act == OB_GUI_ACTION_RESUME_GAME) {
                ob_config_save(&cfg, OB_INI_PATH);
            } else if (act == OB_GUI_ACTION_RETURN_LAUNCHER && snes) {
                recomp_timed_recomp_disable();
                snes_free(snes);
                snes = NULL;
            } else if (act == OB_GUI_ACTION_QUIT) {
                running = false;
            }
        }

        if (snes && gui.screen == OB_GUI_SCREEN_NONE) {
            const uint8_t *keys = SDL_GetKeyboardState(NULL);
            uint16_t joy = poll_keyboard_joypad(keys);
            if (cfg.mouse_enabled) {
                int sx = 0, sy = 0;
                ob_input_map_window_to_snes(
                    win_x, win_y, win_w, win_h,
                    (ws.display_mode != OB_DISPLAY_4_3_CLASSIC) ? OB_VIEWPORT_WIDTH_16_9 : OB_VIEWPORT_WIDTH_4_3,
                    OB_VIEWPORT_HEIGHT, &sx, &sy
                );
                uint16_t mouse_joy = ob_input_process_frame(
                    &mouse, snes->ram, snes->ppu->oam, sx, sy,
                    (btn_mask & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (btn_mask & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (btn_mask & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0,
                    joy,
                    (ws.display_mode != OB_DISPLAY_4_3_CLASSIC) ? OB_VIEWPORT_WIDTH_16_9 : OB_VIEWPORT_WIDTH_4_3,
                    OB_VIEWPORT_HEIGHT
                );
                joy |= mouse_joy;
            }

            for (int b = 0; b < 12; ++b) {
                snes_setButtonState(snes, 1, b, (joy & (1u << (15 - b))) != 0);
            }

            snes_runFrame(snes);
            frame_count++;

            if (audio_dev > 0) {
                snes_setSamples(snes, audio_buf, OB_AUDIO_SAMPLES_PER_FRAME);
                int vol = cfg.mute ? 0 : cfg.master_volume;
                if (vol < 100) {
                    for (int i = 0; i < OB_AUDIO_SAMPLES_PER_FRAME * 2; ++i) {
                        audio_buf[i] = (int16_t)((audio_buf[i] * vol) / 100);
                    }
                }
                if (SDL_GetQueuedAudioSize(audio_dev) < (uint32_t)(OB_AUDIO_SAMPLES_PER_FRAME * 4 * 4)) {
                    SDL_QueueAudio(audio_dev, audio_buf, sizeof(audio_buf));
                }
            }

            extract_core_256x224(snes, core_256x224);
            ws.active_scene = ob_widescreen_detect_scene(snes->ram, snes->ppu->oam);
            ob_widescreen_extract_telemetry(&ws, snes->ram, &mouse);
            ob_widescreen_render_frame(&ws, snes->ram, core_256x224, canvas_800x448);
        }

        if (gui.screen != OB_GUI_SCREEN_NONE) {
            ob_gui_menu_render(&gui, &cfg, canvas_800x448);
        }

        if (cfg.crt_scanlines) {
            apply_crt_scanlines(canvas_800x448, OB_WIDE_2X_W, OB_WIDE_2X_H);
        }

        void *pixels = NULL;
        int pitch = 0;
        if (SDL_LockTexture(texture, NULL, &pixels, &pitch) == 0) {
            for (int y = 0; y < OB_WIDE_2X_H; ++y) {
                memcpy((uint8_t *)pixels + y * pitch, &canvas_800x448[y * OB_WIDE_2X_W], OB_WIDE_2X_W * 4);
            }
            SDL_UnlockTexture(texture);
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    ob_config_save(&cfg, OB_INI_PATH);
    if (snes) {
        recomp_timed_recomp_disable();
        snes_free(snes);
    }
    if (audio_dev > 0) SDL_CloseAudioDevice(audio_dev);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(rom_buf);
    free(core_256x224);
    free(canvas_800x448);
    return 0;
}
