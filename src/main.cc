#include "rl.hh"

int main(void) {
    constexpr unsigned flags = FLAG_WINDOW_RESIZABLE;

    rl::Window window(800, 600, "Olaf RPG", flags);

    while (!window.ShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Hello, World!", 100, 100, 30, WHITE);

    #if DEBUG
        DrawFPS(10, 10);
    #endif
        EndDrawing();
    }

    return 0;
}