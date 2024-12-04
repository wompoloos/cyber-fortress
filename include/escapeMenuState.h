// settingState.h
#pragma once
#include "state.h"

class escapeMenuState : public State {
private:
    StateManager& stateManager;

	// Texture for the menu image
	sf::Texture escapeTexture;
	// Sprite for rendering the escape image
	sf::Sprite escapeSprite;
	// Texture for play 
	sf::Texture escapePlayTexture;
	// Sprite for rendering play
	sf::Sprite escapePlaySprite;
	// Texture for options 
	sf::Texture escapeOptionsTexture;
	// Sprite for rendering options
	sf::Sprite escapeOptionsSprite;
	// Texture for quit 
	sf::Texture escapeQuitTexture;
	// Sprite for rendering quit
	sf::Sprite escapeQuitSprite;

	std::vector<std::string> escapeChoices = { "Play", "Options", "Quit" };
	std::vector<sf::Sprite> escapeSprites = { };
	int escapeChoicesIndex = 0;

public:

    escapeMenuState(StateManager& stateManager);
    virtual ~escapeMenuState();

    // Initialize the gameplay state (set up color and resources)
    void init() override;


    // Poll events (to be implemented in derived classes)
    void pollEvents(sf::RenderWindow* window);

    // Update gameplay logic (game state, player movement, etc.)
    void update() override;

    // Render the window (with background color)
    void render(sf::RenderWindow* window) override;
};
