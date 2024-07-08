#pragma once

#include "core/player.c"
#include "core/spritesheet.c"
#include <stdbool.h>

typedef struct Game {
    bool should_close;
    Player player;
} Game;

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
}

/// Draw the game to the screen (Call Begin- and EndDrawing() with this in between)
void game_draw(Game* g) {
    ClearBackground(WHITE);

    player_update(&g->player);
    player_draw(&g->player);
}