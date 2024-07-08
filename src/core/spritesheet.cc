#pragma once

#include "../rl.hh"

class Spritesheet {
private:
    rl::Texture texture;
    unsigned frames;
    unsigned frame = 0;
    float passed_time = 0.0;
    float length_s;
public:
    Spritesheet(rl::Texture&& texture, unsigned frames, float length_s)
        : texture(std::move(texture)),
        frames(frames), 
        length_s(length_s) {
    }
    void update(float dt) {
        float frame_length = length_s / (float)frames;
        passed_time += dt;

        unsigned new_frame = passed_time / frame_length;
        if (new_frame > frame) {
            if (new_frame >= frames) {
                passed_time = 0.0;
                frame = 0;
            }
            else frame = new_frame;
        }
    }
    void draw(int x, int y, Color color) const {
        int segment_width = texture.width / frames;
        DrawTextureRec(
            texture, rect(segment_width * frame, 0, segment_width, texture.height),
            vec2(x, y), color
        );
    }
};