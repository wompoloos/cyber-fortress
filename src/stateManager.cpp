#include "stateManager.h"
#include <iostream>

// Public functions
// Constructors
StateManager::StateManager() {
}

// Destructors
StateManager::~StateManager() {
    // Clean up all states in the stack to prevent memory leaks
    while (!states.empty()) {
        states.pop();
    }
}

// Add a new state to the top of the stack
void StateManager::pushState(std::unique_ptr<State> state) {
    // Move the unique_ptr into the stack
    states.push(std::move(state));
    // Initialise the new state
    states.top()->init();
}

// Remove the state at the top of the stack
void StateManager::popState() {
    // Only pop if there is at least one state in the stack
    if (!states.empty()) {
        // Remove the top state from the stack
        states.pop();
        // Resume state if stack not empty
        if (!states.empty()) {
            states.top()->onResume();
        }
    }
}

// Change the current state by popping the top state and pushing a new state
void StateManager::changeState(std::unique_ptr<State> state) {
    // Remove the current top state if it exists
    popState();
    // Push the new state onto the stack
    pushState(std::move(state));
}

// Poll events
void StateManager::pollEvents(sf::RenderWindow* window) {
    if (!states.empty()) {
        states.top()->pollEvents(window);
    }
}

// Update the current state
void StateManager::update() {
    // Check if there is at least one state to update
    if (!states.empty()) {
        // Accumulator for time
        static float accumulator = 0.0f;
        // Measure elapsed time
        float frameTime = clock.restart().asSeconds();
        // Accumulate time
        accumulator += frameTime;
        // Fixed update loop for handling time accumulation
        while (accumulator >= FIXED_TIME_STEP) {
            // Update the state
            states.top()->update(FIXED_TIME_STEP);
            // Reduce accumulator by fixed timestep
            accumulator -= FIXED_TIME_STEP;
        }
        // Calculate alpha for blending
        alpha = accumulator / FIXED_TIME_STEP;
    }
}

// Render the current state onto the provided window
void StateManager::render(sf::RenderWindow* window) {
    if (!states.empty()) {
        states.top()->render(window, alpha);
    }
}

// Check if there are no states in the stack
bool StateManager::isEmpty() const {
	return states.empty();
}