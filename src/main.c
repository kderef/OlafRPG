#include "rl.h"
#include "game.c"

int main(void) {
    const unsigned flags = FLAG_WINDOW_RESIZABLE;

    Game game = game_new();
    game_init(&game, 800, 600, "Olaf RPG", flags);

    game_load(&game);

    while (!game.should_close) {
        game_update(&game);

        BeginDrawing();
        game_draw(&game);

    #if DEBUG
        DrawFPS(10, 10);
    #endif

        EndDrawing();
    }

    game_unload(&game);
    game_close(&game);

    return 0;
}