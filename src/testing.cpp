#include <vector>
#include <array>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "testing.h"
#include "stateManager.h"
#include "pauseMenuState.h"
#include "game.h"
#include "convertSketch.h"
#include "drawMap.h"

// Public functions
// Constructors
testingState::testingState(StateManager& stateManager)
    : stateManager(stateManager) {
}

// Destructors
testingState::~testingState() {
}


std::array<std::string, mapHeight> mapSketch = {
    "#.########",
    "#........#",
    "########.#",
    "#......#.#",
    "#.####...#",
    "#.########",
    "#.####...#",
    "#......#.#",
    "########.#",
    "#........#",
    "#.########"
};
std::array<std::array<cell, mapHeight>, mapWidth> map{};

// Initialise the state
void testingState::init() {
    std::cout << "testing state";

    const float gameHeight = 340.0f;
    const float gameWidth = 640.0f;
    const float wallThickness = 50.0f;



    map = convertSketch(mapSketch);

}

// Pause state
void testingState::onPause() {
    isPaused = true;
}

// Resume state
void testingState::onResume() {
    isPaused = false;
}

// Poll events
void testingState::pollEvents(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();  // Close the window if the user clicks the close button
        }
        if (event.key.code == sf::Keyboard::Escape) {
            if (isPaused) {
                stateManager.pushState(std::make_unique<PauseMenuState>(stateManager));
            }
            else {
                onPause();
            }
        }
    }
}

// Update the state
void testingState::update(float deltaTime) {
    
}

// Render the screen
void testingState::render(sf::RenderWindow* window) {
    // You can render game objects here after clearing the window
    // Clear the window with a color (e.g., black)
    window->clear(sf::Color::Black);

    drawMap(map, *window);
    // Display the window contents
    window->display();
}