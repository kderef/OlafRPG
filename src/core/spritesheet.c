#pragma once

#include "../rl.h"

typedef struct Spritesheet {
    Texture texture;
    unsigned frames;
    unsigned frame;
    float passed_time;
    float length_s;
} Spritesheet;

Spritesheet spritesheet_load(Texture texture, unsigned frames, float length_s) {
    Spritesheet s = {0};
    s.texture = texture;
    s.frames = frames;
    s.length_s = length_s;
    return s;
}
void spritesheet_unload(Spritesheet* ss) {
    UnloadTexture(ss->texture);
}

void spritesheet_update(Spritesheet* ss, float dt) {
    float frame_length = ss->length_s / ss->frames;
    ss->passed_time += dt;

    unsigned new_frame = ss->passed_time / frame_length;
    if (new_frame > ss->frame) {
        if (new_frame >= ss->frames) {
            ss->passed_time = 0.0;
            ss->frame = 0;
        }
        else ss->frame = new_frame;
    }
}
void spritesheet_draw(Spritesheet* ss, int x, int y, Color tint) {
    int segment_width = ss->texture.width / ss->frames;
    DrawTextureRec(
        ss->texture,
        (rect) {
            .x = segment_width * ss->frame,
            .y = 0,
            .width = segment_width,
            .height = ss->texture.height
        },
        (vec2){x, y},
        tint
    );
}