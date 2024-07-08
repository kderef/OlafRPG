#pragma once

#include "../rl.hh"

namespace ctx {
    static float dt = 0.0;
    static rect screen = {0};

    /// Update all the variables (`dt`, etc.)
    void update() {
        dt = GetFrameTime();
        screen.width = GetScreenWidth();
        screen.height = GetScreenHeight();
    }
}