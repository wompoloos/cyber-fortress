#pragma once

#include "state.h"

/*
    This class represents the settings state.
*/

// Forward declaration of StateManager class
class StateManager;

class SettingState : public State {
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
    // Constructor with reference to StateManager
    SettingState(StateManager& stateManager);

    // Virtual destructor
    virtual ~SettingState();
    
    // Initialise the state
    void init() override;

    // Poll events
    void pollEvents(sf::RenderWindow* window);

    // Update
    void update(float deltaTime) override;

    // Render
    void render(sf::RenderWindow* window) override;
};
