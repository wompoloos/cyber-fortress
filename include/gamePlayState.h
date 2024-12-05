// gameplay.h
#pragma once
#include "state.h"
#include "stateManager.h"
#include <SFML/Graphics.hpp>

class gamePlayState : public State {
private:
    StateManager& stateManager;
    bool isPaused = false;
    
public:
    // Constructor with reference to StateManager
    gamePlayState(StateManager& stateManager);
    virtual ~gamePlayState();
        
    // Initialize the gameplay state (set up color and resources)
    void init() override;

    // Pause
    void onPause() override;

    // Resume
    void onResume() override;

    // Poll for events (keyboard input, window events)
    void pollEvents(sf::RenderWindow* window) override;

    // Update gameplay logic (game state, player movement, etc.)
    void update() override;

    // Render the window (with background color)
    void render(sf::RenderWindow* window) override;
};
