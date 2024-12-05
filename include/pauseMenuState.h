// pauseMenuState.h
#pragma once
#include "state.h"

class pauseMenuState : public State {
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

	std::vector<std::string> pauseChoices = { "Play", "Options", "Quit" };
	std::vector<sf::Sprite> pauseSprites = { };
	int pauseChoicesIndex = 0;

public:

    pauseMenuState(StateManager& stateManager);
    virtual ~pauseMenuState();

    // Initialize the gameplay state (set up color and resources)
    void init() override;


    // Poll events (to be implemented in derived classes)
    void pollEvents(sf::RenderWindow* window);

    // Update gameplay logic (game state, player movement, etc.)
    void update() override;

    // Render the window (with background color)
    void render(sf::RenderWindow* window) override;
};
