// settingState.h
#pragma once
#include "state.h"
#include "stateManager.h"
#include <SFML/Graphics.hpp>

class settingState : public State {
private:
    StateManager& stateManager ;

public:

    settingState(StateManager& stateManager);
    virtual ~settingState();
    
    // Initialize the gameplay state (set up color and resources)
    void init() override;


    // Poll events (to be implemented in derived classes)
    void pollEvents(sf::RenderWindow* window);

    // Update gameplay logic (game state, player movement, etc.)
    void update() override;

    // Render the window (with background color)
    void render(sf::RenderWindow* window) override;
};
