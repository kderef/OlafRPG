#pragma once

#include "../rl.h"

struct Context {
    float dt;
    rect screen;
};

static struct Context ctx = {0};

void ctx_update() {
    ctx.dt = GetFrameTime();
    ctx.screen.width = GetScreenWidth();
    ctx.screen.height = GetScreenHeight();
}