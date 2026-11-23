/*
 * platform_win32.c — Standalone Native Win32 Platform Runner
 *
 * Ogre Battle: The March of the Black Queen (1:1 Native PC Port)
 * Zero-dependency: single portable .exe with native Win32 GDI & waveOut audio.
 * Default Controls: Canonical ZSNES mapping.
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include <commdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/bus.h>
#include <snesrecomp/cpu.h>
#include <snesrecomp/func_table.h>
#include "snes.h"
#include "engine/input.h"

/* LakeSnes controller bitmasks (LakeSnes currentState format: bit k maps to auto-read bit 15-k) */
#define PAD_BTN_B       0x0001  /* Bit 0 -> Auto-read bit 15 (B) */
#define PAD_BTN_Y       0x0002  /* Bit 1 -> Auto-read bit 14 (Y) */
#define PAD_BTN_SELECT  0x0004  /* Bit 2 -> Auto-read bit 13 (Select) */
#define PAD_BTN_START   0x0008  /* Bit 3 -> Auto-read bit 12 (Start) */
#define PAD_BTN_UP      0x0010  /* Bit 4 -> Auto-read bit 11 (Up) */
#define PAD_BTN_DOWN    0x0020  /* Bit 5 -> Auto-read bit 10 (Down) */
#define PAD_BTN_LEFT    0x0040  /* Bit 6 -> Auto-read bit 9  (Left) */
#define PAD_BTN_RIGHT   0x0080  /* Bit 7 -> Auto-read bit 8  (Right) */
#define PAD_BTN_A       0x0100  /* Bit 8 -> Auto-read bit 7  (A) */
#define PAD_BTN_X       0x0200  /* Bit 9 -> Auto-read bit 6  (X) */
#define PAD_BTN_L       0x0400  /* Bit 10 -> Auto-read bit 5 (L) */
#define PAD_BTN_R       0x0800  /* Bit 11 -> Auto-read bit 4 (R) */

static uint16_t pad_to_ob_mask(uint16_t pad) {
    uint16_t m = 0;
    if (pad & PAD_BTN_B)      m |= OB_BTN_B;
    if (pad & PAD_BTN_Y)      m |= OB_BTN_Y;
    if (pad & PAD_BTN_SELECT) m |= OB_BTN_SELECT;
    if (pad & PAD_BTN_START)  m |= OB_BTN_START;
    if (pad & PAD_BTN_UP)     m |= OB_BTN_UP;
    if (pad & PAD_BTN_DOWN)   m |= OB_BTN_DOWN;
    if (pad & PAD_BTN_LEFT)   m |= OB_BTN_LEFT;
    if (pad & PAD_BTN_RIGHT)  m |= OB_BTN_RIGHT;
    if (pad & PAD_BTN_A)      m |= OB_BTN_A;
    if (pad & PAD_BTN_X)      m |= OB_BTN_X;
    if (pad & PAD_BTN_L)      m |= OB_BTN_L;
    if (pad & PAD_BTN_R)      m |= OB_BTN_R;
    return m;
}

static uint16_t ob_mask_to_pad(uint16_t m) {
    uint16_t pad = 0;
    if (m & OB_BTN_B)      pad |= PAD_BTN_B;
    if (m & OB_BTN_Y)      pad |= PAD_BTN_Y;
    if (m & OB_BTN_SELECT) pad |= PAD_BTN_SELECT;
    if (m & OB_BTN_START)  pad |= PAD_BTN_START;
    if (m & OB_BTN_UP)     pad |= PAD_BTN_UP;
    if (m & OB_BTN_DOWN)   pad |= PAD_BTN_DOWN;
    if (m & OB_BTN_LEFT)   pad |= PAD_BTN_LEFT;
    if (m & OB_BTN_RIGHT)  pad |= PAD_BTN_RIGHT;
    if (m & OB_BTN_A)      pad |= PAD_BTN_A;
    if (m & OB_BTN_X)      pad |= PAD_BTN_X;
    if (m & OB_BTN_L)      pad |= PAD_BTN_L;
    if (m & OB_BTN_R)      pad |= PAD_BTN_R;
    return pad;
}

/* Embedded ROM linkage */
extern const uint8_t g_embedded_rom[];
extern const uint32_t g_embedded_rom_size;

/* Recompiled bank registration */
extern void ob_recomp_register_all(void);
extern bool (*g_cpuRecompHook)(Cpu*);

/* Global State */
static Snes *g_snes = NULL;
Snes *snesrecomp_get_snes(void) { return g_snes; }
bool g_recomp_validating = false;
bool g_recomp_frame_touched = false;

/* Platform Stubs */
void platform_set_headless(const char *r) { (void)r; }
bool platform_is_headless(void) { return false; }
bool platform_init(const char *w, int s) { (void)w; (void)s; return true; }
void platform_present_frame(const uint8_t *fb) { (void)fb; }
void platform_queue_audio(const int16_t *s, int c) { (void)s; (void)c; }
bool platform_poll_events(void) { return true; }
void platform_frame_sync(void) {}
void platform_request_screenshot(void) {}
bool platform_mouse_to_snes(int *x, int *y) { (void)x; (void)y; return false; }
void platform_shutdown(void) {}

/* Audio output: 32040 Hz stereo, 534 samples per frame */
#define AUDIO_SAMPLE_RATE 32040
#define SAMPLES_PER_FRAME 534
#define AUDIO_NUM_BUFFERS 4
static HWAVEOUT g_hWaveOut = NULL;
static WAVEHDR g_waveHeaders[AUDIO_NUM_BUFFERS];
static int16_t g_audioBuffers[AUDIO_NUM_BUFFERS][SAMPLES_PER_FRAME * 2];
static int g_currentAudioBuf = 0;
static int16_t g_frameAudio[SAMPLES_PER_FRAME * 2];

/* Video output: 512x480 pixel buffer */
static uint8_t g_pixelBuf[512 * 480 * 4];
static BITMAPINFO g_bmi;

/* Windowing & Three-Pillar Mouse State */
static HWND g_hwnd = NULL;
static bool g_running = true;
static uint16_t g_keyState = 0;
static ObMouseState g_mouse;
static int g_winMouseX = 512;
static int g_winMouseY = 448;
static bool g_leftDown = false;
static bool g_rightDown = false;
static bool g_middleDown = false;
static char g_srmPath[MAX_PATH] = "ogre_battle.srm";
static int g_last_client_w = 0;
static int g_last_client_h = 0;

/* Render the current frame to the specified DC */
static void RenderFrame(HDC hdc) {
    if (!g_hwnd || !hdc) return;
    RECT cr;
    GetClientRect(g_hwnd, &cr);
    int client_w = cr.right - cr.left;
    int client_h = cr.bottom - cr.top;
    if (client_w <= 0 || client_h <= 0) return;

    /* Maintain 4:3 Aspect Ratio */
    int draw_w = client_w;
    int draw_h = (draw_w * 3) / 4;
    if (draw_h > client_h) {
        draw_h = client_h;
        draw_w = (draw_h * 4) / 3;
    }
    int draw_x = (client_w - draw_w) / 2;
    int draw_y = (client_h - draw_h) / 2;

    /* Repaint black borders when window is resized */
    if (client_w != g_last_client_w || client_h != g_last_client_h) {
        HBRUSH black = (HBRUSH)GetStockObject(BLACK_BRUSH);
        FillRect(hdc, &cr, black);
        g_last_client_w = client_w;
        g_last_client_h = client_h;
    }

    /* Active 448 rows start at line 16 (16 * 2048 bytes) in g_pixelBuf */
    const uint8_t *src_pixels = g_pixelBuf + (16 * 2048);
    SetStretchBltMode(hdc, COLORONCOLOR);
    StretchDIBits(
        hdc,
        draw_x, draw_y, draw_w, draw_h,
        0, 0, 512, 448,
        src_pixels, &g_bmi,
        DIB_RGB_COLORS, SRCCOPY
    );
}

/* Window Procedure */
static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            RenderFrame(hdc);
            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_KEYDOWN: {
            /* Canonical ZSNES Default Layout (Zero Overlap / Double-Mapping):
             * D-Pad: Arrow keys
             * Face Buttons: A='X', B='Z', X='S', Y='A'
             * Shoulders:    L='D', R='C'
             * Controls:     Start=Enter, Select=Space or Shift
             */
            switch (wParam) {
                case VK_UP:    case VK_NUMPAD8: g_keyState |= PAD_BTN_UP; break;
                case VK_DOWN:  case VK_NUMPAD2: g_keyState |= PAD_BTN_DOWN; break;
                case VK_LEFT:  case VK_NUMPAD4: g_keyState |= PAD_BTN_LEFT; break;
                case VK_RIGHT: case VK_NUMPAD6: g_keyState |= PAD_BTN_RIGHT; break;
                case 'X':       g_keyState |= PAD_BTN_A; break;
                case 'Z':       g_keyState |= PAD_BTN_B; break;
                case 'S':       g_keyState |= PAD_BTN_X; break;
                case 'A':       g_keyState |= PAD_BTN_Y; break;
                case 'D':       g_keyState |= PAD_BTN_L; break;
                case 'C':       g_keyState |= PAD_BTN_R; break;
                case VK_RETURN: g_keyState |= PAD_BTN_START; break;
                case VK_SPACE: case VK_SHIFT: case VK_LSHIFT: case VK_RSHIFT: g_keyState |= PAD_BTN_SELECT; break;
                case VK_ESCAPE: PostQuitMessage(0); break;
            }
            return 0;
        }
        case WM_KEYUP: {
            switch (wParam) {
                case VK_UP:    case VK_NUMPAD8: g_keyState &= ~PAD_BTN_UP; break;
                case VK_DOWN:  case VK_NUMPAD2: g_keyState &= ~PAD_BTN_DOWN; break;
                case VK_LEFT:  case VK_NUMPAD4: g_keyState &= ~PAD_BTN_LEFT; break;
                case VK_RIGHT: case VK_NUMPAD6: g_keyState &= ~PAD_BTN_RIGHT; break;
                case 'X':       g_keyState &= ~PAD_BTN_A; break;
                case 'Z':       g_keyState &= ~PAD_BTN_B; break;
                case 'S':       g_keyState &= ~PAD_BTN_X; break;
                case 'A':       g_keyState &= ~PAD_BTN_Y; break;
                case 'D':       g_keyState &= ~PAD_BTN_L; break;
                case 'C':       g_keyState &= ~PAD_BTN_R; break;
                case VK_RETURN: g_keyState &= ~PAD_BTN_START; break;
                case VK_SPACE: case VK_SHIFT: case VK_LSHIFT: case VK_RSHIFT: g_keyState &= ~PAD_BTN_SELECT; break;
            }
            return 0;
        }
        case WM_MOUSEMOVE: {
            g_winMouseX = (short)LOWORD(lParam);
            g_winMouseY = (short)HIWORD(lParam);
            return 0;
        }
        case WM_LBUTTONDOWN: g_leftDown = true; return 0;
        case WM_LBUTTONUP:   g_leftDown = false; return 0;
        case WM_RBUTTONDOWN: g_rightDown = true; return 0;
        case WM_RBUTTONUP:   g_rightDown = false; return 0;
        case WM_MBUTTONDOWN: g_middleDown = true; return 0;
        case WM_MBUTTONUP:   g_middleDown = false; return 0;
        case WM_ERASEBKGND:
            return 1; /* Suppress background flicker */
        case WM_SIZE:
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        case WM_CLOSE:
            g_running = false;
            DestroyWindow(hwnd);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProcA(hwnd, msg, wParam, lParam);
    }
}

/* Save / Load SRAM Battery State */
static void load_srm(void) {
    FILE *f = fopen(g_srmPath, "rb");
    if (f) {
        fseek(f, 0, SEEK_END);
        long sz = ftell(f);
        fseek(f, 0, SEEK_SET);
        if (sz > 0) {
            uint8_t *srm = (uint8_t *)malloc(sz);
            fread(srm, 1, sz, f);
            snes_loadBattery(g_snes, srm, (int)sz);
            free(srm);
            printf("[SRM] Loaded battery save from %s (%ld bytes)\n", g_srmPath, sz);
        }
        fclose(f);
    }
}

static void save_srm(void) {
    if (!g_snes || !g_snes->cart || !g_snes->cart->ram || g_snes->cart->ramSize == 0) return;
    uint8_t *buf = (uint8_t *)malloc(g_snes->cart->ramSize);
    int sz = snes_saveBattery(g_snes, buf);
    if (sz > 0) {
        FILE *f = fopen(g_srmPath, "wb");
        if (f) {
            fwrite(buf, 1, sz, f);
            fclose(f);
        }
    }
    free(buf);
}

/* WinMain Entry Point */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    (void)hPrevInstance; (void)lpCmdLine; (void)nCmdShow;

    /* High precision timer */
    timeBeginPeriod(1);

    /* Register Window Class */
    WNDCLASSEXA wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXA);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = "OgreBattlePC";
    RegisterClassExA(&wc);

    /* 4:3 Window client size (1024 x 896 = 4x scale) */
    RECT wr = {0, 0, 1024, 896};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    int win_w = wr.right - wr.left;
    int win_h = wr.bottom - wr.top;

    g_hwnd = CreateWindowExA(
        0, "OgreBattlePC",
        "Ogre Battle: The March of the Black Queen (Native PC Port)",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, win_w, win_h,
        NULL, NULL, hInstance, NULL
    );

    if (!g_hwnd) return 1;

    /* Initialize Bitmap Header (512x448, 32-bit RGBX top-down) */
    memset(&g_bmi, 0, sizeof(g_bmi));
    g_bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    g_bmi.bmiHeader.biWidth = 512;
    g_bmi.bmiHeader.biHeight = -448; /* Top-down */
    g_bmi.bmiHeader.biPlanes = 1;
    g_bmi.bmiHeader.biBitCount = 32;
    g_bmi.bmiHeader.biCompression = BI_RGB;

    /* Initialize Audio (waveOut) */
    WAVEFORMATEX wfx = {0};
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 2;
    wfx.nSamplesPerSec = AUDIO_SAMPLE_RATE;
    wfx.wBitsPerSample = 16;
    wfx.nBlockAlign = wfx.nChannels * (wfx.wBitsPerSample / 8);
    wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;

    if (waveOutOpen(&g_hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) == MMSYSERR_NOERROR) {
        for (int i = 0; i < AUDIO_NUM_BUFFERS; i++) {
            memset(&g_waveHeaders[i], 0, sizeof(WAVEHDR));
            g_waveHeaders[i].lpData = (LPSTR)g_audioBuffers[i];
            g_waveHeaders[i].dwBufferLength = SAMPLES_PER_FRAME * sizeof(int16_t) * 2;
            waveOutPrepareHeader(g_hWaveOut, &g_waveHeaders[i], sizeof(WAVEHDR));
            g_waveHeaders[i].dwFlags |= WHDR_DONE; /* Mark initially ready */
        }
    }

    /* Initialize LakeSnes & Recompiled Core */
    g_snes = snes_init();
    /*
     * Color Format: pixelFormatXRGB sets ppu_pixelOutputFormatXBGR (0).
     * This places Byte 0=Blue, Byte 1=Green, Byte 2=Red, Byte 3=0 in memory,
     * which matches Windows GDI 32-bit DIB pixel format identically.
     */
    snes_setPixelFormat(g_snes, pixelFormatXRGB);

    /* Try loading external ROM or fall back to embedded certified ROM */
    bool loaded = false;
    FILE *f_ext = fopen("ogre_battle.sfc", "rb");
    if (f_ext) {
        fseek(f_ext, 0, SEEK_END);
        long sz = ftell(f_ext);
        fseek(f_ext, 0, SEEK_SET);
        uint8_t *rom_ext = (uint8_t *)malloc(sz);
        fread(rom_ext, 1, sz, f_ext);
        fclose(f_ext);
        loaded = snes_loadRom(g_snes, rom_ext, (int)sz);
        free(rom_ext);
    }
    if (!loaded && g_embedded_rom_size > 0) {
        loaded = snes_loadRom(g_snes, g_embedded_rom, (int)g_embedded_rom_size);
    }
    if (!loaded) {
        MessageBoxA(g_hwnd, "Error: Could not load Ogre Battle ROM.", "Load Error", MB_ICONERROR);
        return 1;
    }

    /* Load persistent save if available */
    load_srm();

    /* Initialize Recomp Dispatch Table & Intercepts */
    func_table_init();
    ob_recomp_register_all();
    recomp_interp_set_enabled(true);
    recomp_timed_add_intercept(0x058299, false); /* Bank 05 character creation personality table setup */
    recomp_timed_recomp_enable();

    /* Initialize Gate 2 Three-Pillar Mouse State Machine (Rev 9+) */
    ob_input_init(&g_mouse, OB_VIEWPORT_WIDTH_4_3, OB_VIEWPORT_HEIGHT);

    /* Timing initialization */
    LARGE_INTEGER qpcFreq, qpcLast, qpcNow;
    QueryPerformanceFrequency(&qpcFreq);
    QueryPerformanceCounter(&qpcLast);
    const double targetFrameTime = (double)qpcFreq.QuadPart / 60.0988;

    uint32_t frame_count = 0;

    /* Main Emulation Loop */
    MSG msg;
    while (g_running) {
        while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                g_running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        if (!g_running) break;

        /* Gate 2 (Rev 9+): Three-Pillar Direct-State & Hit-Box Mouse Architecture */
        RECT cr;
        GetClientRect(g_hwnd, &cr);
        int client_w = (cr.right - cr.left) > 0 ? (cr.right - cr.left) : 1024;
        int client_h = (cr.bottom - cr.top) > 0 ? (cr.bottom - cr.top) : 896;

        ob_input_on_mouse_move(&g_mouse, g_winMouseX, g_winMouseY, client_w, client_h, frame_count);
        ob_input_on_mouse_button(&g_mouse, g_leftDown, g_rightDown, g_middleDown, frame_count);

        uint16_t ob_joy = pad_to_ob_mask(g_keyState);
        ob_joy = ob_input_step_frame(
            &g_mouse,
            g_snes->ram,
            (const uint8_t *)g_snes->ppu->oam,
            ob_joy,
            frame_count
        );
        g_snes->input1->currentState = ob_mask_to_pad(ob_joy);

        /* Run 1 Lockstep Emulation Frame */
        snes_runFrame(g_snes);
        frame_count++;

        /* Extract rendered pixels and audio samples from SNES PPU / APU */
        snes_setPixels(g_snes, g_pixelBuf);
        snes_setSamples(g_snes, g_frameAudio, SAMPLES_PER_FRAME);

        /* Periodically save SRAM (every 5 seconds / 300 frames) */
        if (frame_count % 300 == 0) {
            save_srm();
        }

        /* Queue Audio via waveOut */
        if (g_hWaveOut) {
            WAVEHDR *hdr = &g_waveHeaders[g_currentAudioBuf];
            if (hdr->dwFlags & WHDR_DONE) {
                waveOutUnprepareHeader(g_hWaveOut, hdr, sizeof(WAVEHDR));
                memcpy(hdr->lpData, g_frameAudio, sizeof(g_frameAudio));
                hdr->dwBufferLength = sizeof(g_frameAudio);
                waveOutPrepareHeader(g_hWaveOut, hdr, sizeof(WAVEHDR));
                waveOutWrite(g_hWaveOut, hdr, sizeof(WAVEHDR));
                g_currentAudioBuf = (g_currentAudioBuf + 1) % AUDIO_NUM_BUFFERS;
            }
        }

        /* Render Video via GDI */
        HDC hdc = GetDC(g_hwnd);
        RenderFrame(hdc);
        ReleaseDC(g_hwnd, hdc);

        /* 60 FPS Frame Sync */
        QueryPerformanceCounter(&qpcNow);
        double elapsed = (double)(qpcNow.QuadPart - qpcLast.QuadPart);
        while (elapsed < targetFrameTime) {
            double remaining_ms = (targetFrameTime - elapsed) * 1000.0 / (double)qpcFreq.QuadPart;
            if (remaining_ms > 2.0) {
                Sleep((DWORD)(remaining_ms - 1.0));
            } else {
                YieldProcessor();
            }
            QueryPerformanceCounter(&qpcNow);
            elapsed = (double)(qpcNow.QuadPart - qpcLast.QuadPart);
        }
        qpcLast.QuadPart += (LONGLONG)targetFrameTime;
        if (qpcNow.QuadPart - qpcLast.QuadPart > (LONGLONG)targetFrameTime * 4) {
            qpcLast = qpcNow; /* Don't accumulate massive frame debt if window was dragged */
        }
    }

    /* Final Save on Exit */
    save_srm();

    /* Cleanup */
    if (g_hWaveOut) {
        waveOutReset(g_hWaveOut);
        for (int i = 0; i < AUDIO_NUM_BUFFERS; i++) {
            waveOutUnprepareHeader(g_hWaveOut, &g_waveHeaders[i], sizeof(WAVEHDR));
        }
        waveOutClose(g_hWaveOut);
    }
    if (g_snes) snes_free(g_snes);
    timeEndPeriod(1);

    return 0;
}
