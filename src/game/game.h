#pragma once

#include <stdbool.h>
#include "../core/player.c"
#include "state.h"

typedef struct Game {
    bool should_close;
    Player player;
    GameState state;
} Game;