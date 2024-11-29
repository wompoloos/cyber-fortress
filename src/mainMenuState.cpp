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
            if (event.key.code == sf::Keyboard::Up) {
                if (menuOptionsIndex > 0) {
                    menuOptionsIndex--;
                }
            }
            if (event.key.code == sf::Keyboard::Down) {
                if (menuOptionsIndex < menuOptions.size() - 1) {
                    menuOptionsIndex++;
                }
            }
            if (event.key.code == sf::Keyboard::Enter) {
                switch (menuOptionsIndex) {
                case 0:
                    std::cout << menuOptions[menuOptionsIndex] << std::endl;
                    break;
                case 1:
                    std::cout << menuOptions[menuOptionsIndex] << std::endl;
                    break;
                case 2:
                    std::cout << menuOptions[menuOptionsIndex] << std::endl;
                    break;
                }
            break;
            }
        }
    }
}

// Update
void MainMenuState::update() {
}

// Render
void MainMenuState::render(sf::RenderWindow* window) {
    // std::cout << "Rendering MainMenuState..." << std::endl;
    window->clear();
    window->display();
}