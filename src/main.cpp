# include "game.h"

int main() {
    // Init game engine
    Game game;

    // Game loop
    while (game.isRunning()) {
        // Update
        game.update();

        // Render
        game.render();
    }
    return 0;
}

