#pragma once

#include "state.h"

/*
    This class represents the gameplay state.
*/

// Forward declaration of StateManager class
class StateManager;

class GamePlayState : public State {
private:
    StateManager& stateManager;
    bool isPaused = false;
    
public:
    // Constructor with reference to StateManager
    GamePlayState(StateManager& stateManager);

    // Virtual destructor
    virtual ~GamePlayState();
        
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
