#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include "state.h"

/*
    This class handles the management of the game state.
*/

class StateManager {
private:
    // Stack to hold pointers to the current states
    std::stack<std::unique_ptr<State>> states;
    // Fixed time step for updates
    const float FIXED_TIME_STEP = 1.0f / 60.0f;
    // Clock to track time
    sf::Clock clock;

public:
    // Default constructor
    StateManager();

    // Virtual destructor
    ~StateManager();

    // Add a new state to the top of the stack
    void pushState(std::unique_ptr<State> state);

    // Remove the state at the top of the stack
    void popState();

    // Change state
    void changeState(std::unique_ptr<State> state);

    // Poll events
    void pollEvents(sf::RenderWindow* window);

    // Update the current state (should be called in the main game loop)
    void update();

    // Render the current state onto the provided window
    void render(sf::RenderWindow* window);

    // Check if there are no states in the stack
    bool isEmpty() const;
};