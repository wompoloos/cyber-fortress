#include <iostream>
#include "mainMenuState.h"
#include "stateManager.h"

// Public functions
// Constructors
MainMenuState::MainMenuState(StateManager& stateManager) : stateManager(stateManager) {
}

// Destructors
MainMenuState::~MainMenuState() {
}

// Intiliase the state
void MainMenuState::init() {
	std::cout << "Initialisng MainMenuState..." << std::endl;
}

// Poll events
void MainMenuState::pollEvents(sf::RenderWindow* window) {
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
void MainMenuState::update() {
}

// Render
void MainMenuState::render(sf::RenderWindow* window) {
    std::cout << "Rendering MainMenuState..." << std::endl;
    window->clear();
    window->display();
}