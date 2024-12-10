#pragma once

#include "state.h"

/*
    This class represents the gameplay state.
*/

// Forward declaration of StateManager class
class StateManager;


const unsigned char mapHeight = 11;
const unsigned char mapWidth = 10;
const unsigned char cellSize = 16;

enum cell {
    empty,
    wall
};

class testingState : public State {
private:
    StateManager& stateManager;
    bool isPaused = false;

public:
    // Constructor with reference to StateManager
    testingState(StateManager& stateManager);

    // Virtual destructor
    virtual ~testingState();

    // Initialise the state
    void init() override;

    // Pause
    void onPause() override;

    // Resume
    void onResume() override;

    // Poll events
    void pollEvents(sf::RenderWindow* window) override;

    // Update
    void update(float deltaTime) override;

    // Render
    void render(sf::RenderWindow* window) override;
};
