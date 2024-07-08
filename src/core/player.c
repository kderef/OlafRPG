#pragma once

#include "ctx.c"
#include "spritesheet.c"
#include "embed.c"

embed(sprite_bytes, "res/spritesheet.png");

typedef struct Player {
    Spritesheet sprite;
    vec2 pos;
} Player;

Player player_new(vec2 pos) {
    Player p;
    p.pos = pos;
    p.sprite = spritesheet_load(
        load_texture_from_memory(".png", bin_sprite_bytes_data, bin_sprite_bytes_size),
        5, 1.5
    );
    return p;
}

void player_unload(Player* p) {
    spritesheet_unload(&p->sprite);
}

void player_update(Player* p) {
    spritesheet_update(&p->sprite, ctx.dt);
}

void player_draw(Player* p) {
    spritesheet_draw(&p->sprite, p->pos.x, p->pos.y, WHITE);
}