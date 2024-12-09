#pragma once

#include "state.h"

/*
	This class represents the pause menu state.
*/

// Forward declaration of StateManager class
class StateManager;

class PauseMenuState : public State {
private:
    StateManager& stateManager;
	// Texture for the menu image
	sf::Texture pauseTexture;
	// Sprite for rendering the pause image
	sf::Sprite pauseSprite;
	// Texture for play 
	sf::Texture pausePlayTexture;
	// Sprite for rendering play
	sf::Sprite pausePlaySprite;
	// Texture for options 
	sf::Texture pauseOptionsTexture;
	// Sprite for rendering options
	sf::Sprite pauseOptionsSprite;
	// Texture for quit 
	sf::Texture pauseQuitTexture;
	// Sprite for rendering quit
	sf::Sprite pauseQuitSprite;
	// Choices for the menu
	std::vector<std::string> pauseChoices = { "Play", "Options", "Quit" };
	std::vector<sf::Sprite> pauseSprites = { };
	int pauseChoicesIndex = 0;

public:
	// Constructor with reference to StateManager
    PauseMenuState(StateManager& stateManager);
    virtual ~PauseMenuState();

    // Initialise the state
    void init() override;

    // Poll events
    void pollEvents(sf::RenderWindow* window);

    // Update
    void update(float deltaTime) override;

    // Render
    void render(sf::RenderWindow* window) override;
};
