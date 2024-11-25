#include "game.h"

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
    // Check for events
    while (this->window->pollEvent(this->event)) {
        // Handle events
        switch (this->event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;
        }
    }
}

// Update
void Game::update() {
    this->pollEvents();
}

// Render
void Game::render() {
    this->window->clear();
    this->window->display();
}
