// settingState.h
#pragma once
#include "state.h"
#include "stateManager.h"
#include <SFML/Graphics.hpp>

class settingState : public State {
private:
    StateManager& stateManager ;

    sf::Texture settingsTexture;
    sf::Sprite settingsSprite;

    sf::Texture videoTexture;
    sf::Sprite videoSprite;

    sf::Texture controlsTexture;
    sf::Sprite controlsSprite;

    sf::Texture soundTexture;
    sf::Sprite soundSprite;


    std::vector<std::string> settingsChoices = { "Video", "Controls", "Sound" };
    std::vector<sf::Sprite> settingsSprites = { };
    int settingsChoicesIndex = 0;

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
