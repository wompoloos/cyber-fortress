#include <iostream>
#include "settingState.h"
#include "stateManager.h" 
#include "mainMenuState.h"
#include <SFML/Graphics.hpp>

// Constructor that initializes the StateManager reference
settingState::settingState(StateManager& stateManager)
    : stateManager(stateManager){
   
}

// Destructor - clean up any dynamic resources if needed (none in this case)
settingState::~settingState() {
}

// Initialize the settings state (setting up resources, etc.)
void settingState::init() {
}

void settingState::pollEvents(sf::RenderWindow* window)
{
    sf::Event event;
    while (window->pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                stateManager.changeState(std::make_unique<MainMenuState>(stateManager));
            }
    }
}

// Update the state (e.g., handle user input, etc.)
void settingState::update() {
}


// Render the screen (show the blue background)
void settingState::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Yellow);

    // You could render more UI elements here if desired (like buttons or text)
    // For now, we just display the blue background

    window->display();  // Display the current frame
}
