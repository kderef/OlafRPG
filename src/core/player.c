#pragma once

#include "ctx.c"
#include "spritesheet.c"
#include "embed.c"

embed(sprite_bytes, "res/spritesheet.png");

typedef struct Player {
    Spritesheet sprite;
    vec2 pos;
    Camera2D camera;
} Player;

Player player_new(vec2 pos) {
    Player p;
    p.pos = pos;
    p.sprite = spritesheet_load(
        load_texture_from_memory(".png", bin_sprite_bytes_data, bin_sprite_bytes_size),
        5, 1.5
    );
    p.camera = (Camera2D) {
        .target = pos,
        .zoom = {0},
        .offset = {0},
        .rotation = 0.0
    };
    return p;
}

void player_update_camera(Player* p) {
    
}

void player_unload(Player* p) {
    spritesheet_unload(&p->sprite);
}

void player_update(Player* p) {
    spritesheet_update(&p->sprite, ctx.dt);
}

void player_draw(Player* p) {
    player_update_camera(p);

    BeginMode2D(p->camera);

    spritesheet_draw(&p->sprite, p->pos.x, p->pos.y, WHITE);

    EndMode2D();
}