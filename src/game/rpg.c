#pragma once

#include "game.h"

void rpg_update(Game* g) {
    player_update(&g->player);
}

void rpg_draw(Game* g) {
    ClearBackground(BLACK);

    player_draw(&g->player);
}