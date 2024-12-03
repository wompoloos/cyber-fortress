# include "game.h"
int main() {
    // Init game engine
    Game game;

    // Game loop
    while (game.isRunning()) {
        // Poll events
        game.pollEvents();

        // Update
        game.update();

        // Render
        game.render();
    }
    return 0;
}