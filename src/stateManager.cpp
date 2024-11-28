#include "stateManager.h"

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
    states.push(std::move(state)); // Move the unique_ptr into the stack
    states.top()->init();          // Initialize the new state
}

// Remove the state at the top of the stack
void StateManager::popState() {
    // Only pop if there is at least one state in the stack
    if (!states.empty()) {
        states.pop();           // Remove the top state from the stack
    }
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
        states.top()->update(); // Call update on the top state
        // Check if the top state requests to be removed
        if (states.top()->isEnd()) {
            popState();
        }
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