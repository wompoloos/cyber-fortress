#include <iostream>
#include "splashState.h"

// Public functions
// Constructors
SplashState::SplashState() {
}

// Destructors
SplashState::~SplashState() {
}

// Intiliase the state
void SplashState::init() {
    std::cout << "Initialisng SplashState..." << std::endl;
}

// Poll events
void SplashState::pollEvents(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
            break;
        }
    }
}

// Update
void SplashState::update() {
}

// Render
void SplashState::render(sf::RenderWindow* window) {
    std::cout << "Rendering SplashState..." << std::endl;
    window->clear(); // Clear to black
    window->display();
}

// Check if the state is ended
bool SplashState::isEnd() {
	return false;
}