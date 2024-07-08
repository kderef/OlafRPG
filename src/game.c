#pragma once

#include <stdbool.h>

#include "game/game.h"
#include "game/state.h"
#include "game/menu.c"
#include "game/rpg.c"
#include "core/player.c"
#include "core/spritesheet.c"


Game game_new() {
    Game g = {0};
    return g;
}
void game_init(Game* g, int w, int h, const char* title, unsigned flags) {
    SetConfigFlags(flags);
    InitWindow(w, h, title);
}

/// Load all the game assets and objects
void game_load(Game* g) {
    g->player = player_new((vec2){0, 0});
}

/// Unload all the game assets and objects. Must be called BEFORE game_close()
void game_unload(Game* g) {
    player_unload(&g->player);
}

/// Close the window.
void game_close(Game* g) {
    CloseWindow();
}

/// Update the game state 
void game_update(Game* g) {
    ctx_update();
    g->should_close |= WindowShouldClose();

    switch (g->state) {
        case GAME_MENU: menu_update(g); break;
        case GAME_RUNNING: rpg_update(g); break;
    }
}

/// Draw the game to the screen (Call Begin- and EndDrawing() with this in between)
void game_draw(Game* g) {
    switch (g->state) {
        case GAME_MENU: menu_draw(g); break;
        case GAME_RUNNING: rpg_draw(g); break;
    }
}