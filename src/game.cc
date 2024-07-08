#pragma once

#include "core/player.cc"
#include "core/spritesheet.cc"

class Game {
    bool should_close = false;
    rl::Window window;
    Player player;

public:
    Game(int w, int h, const char* title, unsigned flags)
    : window(w, h, title, flags),
    player(20.0, 20.0) {

    }
    void update() {
        should_close |= window.ShouldClose();
    }
    void draw() {
        BeginDrawing();
        ClearBackground(WHITE);

        player.update(GetFrameTime());
        player.draw(100, 100, WHITE);

        #if DEBUG
            DrawFPS(10, 10);
        #endif
        EndDrawing();
    }
    bool running() const {
        return !should_close;
    }
};