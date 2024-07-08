#pragma once

#include "../rl.h"
#define Key KeyboardKey

struct Keymap {
    Key mv_left, mv_right, mv_up, mv_down;
    Key ui_accept, ui_pause;
};

static struct Keymap keymap = {
    .mv_left = KEY_LEFT,
    .mv_right = KEY_RIGHT,
    .mv_up = KEY_UP,
    .mv_down = KEY_DOWN,
    .ui_accept = KEY_SPACE,
    .ui_pause = KEY_ESCAPE,
};

#undef Key