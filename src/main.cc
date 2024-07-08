#include "rl.hh"
#include "game.cc"

int main(void) {
    constexpr unsigned flags = FLAG_WINDOW_RESIZABLE;

    Game game(800, 600, "Olaf RPG", flags);

    while (game.running()) {
        game.update();
        game.draw();
    }

    return 0;
}