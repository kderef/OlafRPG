#pragma once

#include "spritesheet.cc"
#include "embed.cc"

embed(sprite_bytes, "res/spritesheet.png");

class Player {
private:
    Spritesheet sprite;
    vec2 pos;
public:
    Player(float x, float y) : sprite(
        load_texture_from_memory(".png", bin_sprite_bytes_data, (int)bin_sprite_bytes_size),
        5u, 1.5f
    ),
    pos(vec2(x, y)) {}

    void update(float dt) {
        sprite.update(dt);
    }
    void draw(int x, int y, Color tint) {
        sprite.draw(x, y, tint);
    }
};