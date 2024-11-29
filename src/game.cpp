#include "game.h"
#include "splashState.h"

// Private functions
// Initialise variables
void Game::initVariables() {
	this->window = nullptr;
}

// Initialise window
void Game::initWindow() {
	this->videoMode.height = 360;
	this->videoMode.width = 640;
	this->window = new sf::RenderWindow(this->videoMode, "Cyber Fortress");
}

// Public functions
// Constructors
Game::Game() {
	this->initVariables();
	this->initWindow();

    // Initialise first state (SplashState)
    stateManager.pushState(std::make_unique<SplashState>(stateManager));
}

// Destructors
Game::~Game() {
	delete this->window;
}

// Accessors
const bool Game::isRunning() const {
	return this->window->isOpen();
}

// Poll events
void Game::pollEvents() {
	stateManager.pollEvents(this->window);
}

// Update
void Game::update() {
    stateManager.update();
}

// Render
void Game::render() {
    stateManager.render(this->window);
}
