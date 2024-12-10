#include <iostream>
#include "gamePlayState.h"
#include "stateManager.h"
#include "pauseMenuState.h"

// Public functions
// Constructors
GamePlayState::GamePlayState(StateManager& stateManager)
    : stateManager(stateManager){ 
}

// Destructors
GamePlayState::~GamePlayState() {
}

// Initialise the state
void GamePlayState::init() {
    // Debug message
    std::cout << "Initialisng GamePlayState..." << std::endl;

    // Circles
    circle1.setRadius(20); // radius of the circle
    circle1.setFillColor(sf::Color::White); // set the color
    circle1.setPosition(50, 100); // set position

    circles.push_back(circle1);
    currentPositions.push_back(circle1.getPosition());
    previousPositions.push_back(circle1.getPosition());
    velocities.push_back(vel);

    circle2.setRadius(20); // radius of the circle
    circle2.setFillColor(sf::Color::Red); // set the color
    circle2.setPosition(50, 200); // set position
}

// Pause state
void GamePlayState::onPause() {
    isPaused = true;
}

// Resume state
void GamePlayState::onResume() {
    isPaused = false;
}

// Poll events
void GamePlayState::pollEvents(sf::RenderWindow* window) {
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
void GamePlayState::update(float deltaTime) {
    // Update the game logic here (e.g., player movement, physics, etc.)
    float dt = deltaTime; // Store the delta time for usage

    // Update vector of circles
    for (size_t i = 0; i < circles.size(); ++i) {
        // Update previous position
        previousPositions[i] = currentPositions[i];
        // Update current position based on the velocity
        currentPositions[i].x += velocities[i] * dt;
        // Set the new position for the circle
        circles[i].setPosition(currentPositions[i]);
    }

    // Move circle2 based on an independent velocity
    circle2.move(vel * dt, 0); // Assuming vel is a float representing the horizontal speed
}

// Render the screen
void GamePlayState::render(sf::RenderWindow* window, float alpha) {
    // Clear the window
    window->clear(sf::Color::Black);

    // Draw circles vector
    for (size_t i = 0; i < circles.size(); ++i) {
        // Interpolate position
        sf::Vector2f blendedPosition = currentPositions[i] * alpha + previousPositions[i] * (1.0f - alpha);
        circles[i].setPosition(blendedPosition); // Set the blended position for rendering
        window->draw(circles[i]); // Draw the circle
    }
    
    // Render uninterpolated circle
    window->draw(circle2);

    // Display the window contents
    window->display();
}