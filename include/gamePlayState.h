#pragma once

#include "state.h"

/*
    This class represents the gameplay state.
*/

// Forward declaration of StateManager class
class StateManager;

class gamePlayState : public State {
private:
    StateManager& stateManager;
    bool isPaused = false;
    
public:
    // Constructor with reference to StateManager
    gamePlayState(StateManager& stateManager);

    // Virtual destructor
    virtual ~gamePlayState();
        
    // Initialise the state
    void init() override;

    // Pause
    void onPause() override;

    // Resume
    void onResume() override;

    // Poll events
    void pollEvents(sf::RenderWindow* window) override;

    // Update
    void update() override;

    // Render
    void render(sf::RenderWindow* window) override;
};
