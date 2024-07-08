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

void game_load(Game* g) {
    g->player = player_new((vec2){0, 0});
}

void game_unload(Game* g) {
    player_unload(&g->player);
}
void game_close(Game* g) {
    CloseWindow();
}


void game_update(Game* g) {
    ctx_update();
    g->should_close |= WindowShouldClose();
}
void game_draw(Game* g) {
    BeginDrawing();
    ClearBackground(WHITE);

    player_update(&g->player);
    player_draw(&g->player);

    #if DEBUG
        DrawFPS(10, 10);
    #endif
    EndDrawing();
}