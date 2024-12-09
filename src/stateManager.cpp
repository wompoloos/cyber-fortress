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

// Update the current state (should be called in the main game loop)
void StateManager::update() {
    // Check if there is at least one state to update
    if (!states.empty()) {
        states.top()->update();
    }
}

// Render the current state onto the provided window
void StateManager::render(sf::RenderWindow* window) {
    if (!states.empty()) {
        states.top()->render(window);
    }
}

// Check if there are no states in the stack
bool StateManager::isEmpty() const {
	return states.empty();
}