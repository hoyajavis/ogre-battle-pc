#include "replay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ReplayTrace* replay_create(const char* title, size_t initial_capacity) {
    ReplayTrace* trace = (ReplayTrace*)malloc(sizeof(ReplayTrace));
    if (!trace) return NULL;

    memset(trace, 0, sizeof(ReplayTrace));
    trace->header.magic = OBREC_MAGIC;
    trace->header.version = OBREC_VERSION;
    trace->header.frame_count = 0;
    if (title) {
        strncpy(trace->header.title, title, sizeof(trace->header.title) - 1);
    }

    trace->capacity = (initial_capacity > 0) ? initial_capacity : 3600; // default 1 minute at 60fps
    trace->inputs = (uint16_t*)calloc(trace->capacity, sizeof(uint16_t));
    if (!trace->inputs) {
        free(trace);
        return NULL;
    }

    return trace;
}

void replay_free(ReplayTrace* trace) {
    if (!trace) return;
    if (trace->inputs) free(trace->inputs);
    free(trace);
}

bool replay_record_frame(ReplayTrace* trace, uint16_t joypad_word) {
    if (!trace) return false;

    if (trace->header.frame_count >= trace->capacity) {
        size_t new_cap = trace->capacity * 2;
        uint16_t* new_inputs = (uint16_t*)realloc(trace->inputs, new_cap * sizeof(uint16_t));
        if (!new_inputs) return false;
        trace->inputs = new_inputs;
        trace->capacity = new_cap;
    }

    trace->inputs[trace->header.frame_count++] = joypad_word;
    return true;
}

bool replay_save_file(const ReplayTrace* trace, const char* filepath) {
    if (!trace || !filepath || !trace->inputs) return false;
    FILE* f = fopen(filepath, "wb");
    if (!f) return false;

    if (fwrite(&trace->header, sizeof(ReplayHeader), 1, f) != 1) {
        fclose(f);
        return false;
    }

    if (trace->header.frame_count > 0) {
        size_t written = fwrite(trace->inputs, sizeof(uint16_t), trace->header.frame_count, f);
        if (written != trace->header.frame_count) {
            fclose(f);
            return false;
        }
    }

    fclose(f);
    return true;
}

ReplayTrace* replay_load_file(const char* filepath) {
    if (!filepath) return NULL;
    FILE* f = fopen(filepath, "rb");
    if (!f) return NULL;

    ReplayTrace* trace = (ReplayTrace*)malloc(sizeof(ReplayTrace));
    if (!trace) {
        fclose(f);
        return NULL;
    }

    if (fread(&trace->header, sizeof(ReplayHeader), 1, f) != 1) {
        fclose(f);
        free(trace);
        return NULL;
    }

    if (trace->header.magic != OBREC_MAGIC || trace->header.version != OBREC_VERSION) {
        fclose(f);
        free(trace);
        return NULL;
    }

    trace->capacity = trace->header.frame_count;
    trace->inputs = (uint16_t*)malloc(trace->capacity * sizeof(uint16_t));
    if (!trace->inputs) {
        fclose(f);
        free(trace);
        return NULL;
    }

    if (fread(trace->inputs, sizeof(uint16_t), trace->header.frame_count, f) != trace->header.frame_count) {
        fclose(f);
        free(trace->inputs);
        free(trace);
        return NULL;
    }

    fclose(f);
    return trace;
}

uint16_t replay_get_frame_input(const ReplayTrace* trace, uint32_t frame_number) {
    if (!trace || !trace->inputs || frame_number >= trace->header.frame_count) {
        return 0;
    }
    return trace->inputs[frame_number];
}
