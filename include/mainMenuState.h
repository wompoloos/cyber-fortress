#pragma once

#include "state.h"

/*
	This class represents the main menu state.
*/

// Forward declaration of StateManager class
class StateManager;

class MainMenuState : public State {
private:
	StateManager& stateManager;
	// Texture for the menu image
	sf::Texture menuTexture;
	// Sprite for rendering the menu image
	sf::Sprite menuSprite;
	// Texture for play 
	sf::Texture menuPlayTexture;
	// Sprite for rendering play
	sf::Sprite menuPlaySprite;
	// Texture for options 
	sf::Texture menuOptionsTexture;
	// Sprite for rendering options
	sf::Sprite menuOptionsSprite;
	// Texture for quit 
	sf::Texture menuQuitTexture;
	// Sprite for rendering quit
	sf::Sprite menuQuitSprite;
	// Choices for the menu
	std::vector<std::string> menuChoices = { "Play", "Options", "Quit" };
	std::vector<sf::Sprite> menuSprites = { };
	int menuChoicesIndex = 0;

public:
	// Constructor with reference to StateManager
	MainMenuState(StateManager& stateManager);

	// Virtual destructor
	virtual ~MainMenuState();

	// Intiliase the state
	void init() override;

	// Poll events
	void pollEvents(sf::RenderWindow* window) override;

	// Update
	void update(float deltaTime) override;

	// Render
	void render(sf::RenderWindow* window) override;
};

