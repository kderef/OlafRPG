#pragma once

#include "rl.hh"

class Game {
    bool should_close = false;
    rl::Window window;

public:
    Game(int w, int h, const char* title, unsigned flags)
    : window(w, h, title, flags) {

    }
    void update() {
        should_close |= window.ShouldClose();
    }
    void draw() {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Hello, World!", 100, 100, 30, WHITE);

        #if DEBUG
            DrawFPS(10, 10);
        #endif
        EndDrawing();
    }
    bool running() const {
        return !should_close;
    }
};