// gameplay.cpp
#include "gameplay.h"
#include "stateManager.h"

GameplayState::GameplayState(StateManager& stateManager)
    : stateManager(stateManager), backgroundColor(sf::Color::Blue) {  // Set the background color to blue
}

GameplayState::~GameplayState() {}

void GameplayState::init() {
    // Initialization code for the gameplay state
    // You can change the background color if needed here
    backgroundColor = sf::Color::Green;  // Change background to green
}

void GameplayState::pollEvents(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();  // Close the window if the user clicks the close button
        }

        // Handle other events like player input for gameplay here
    }
}

void GameplayState::update() {
    // Update the game logic here (e.g., player movement, physics, etc.)
}

void GameplayState::render(sf::RenderWindow* window) {
    window->clear(backgroundColor);  // Use the background color
    // You can render game objects here after clearing the window

    window->display();  // Display the window contents
}
