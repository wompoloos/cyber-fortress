#pragma once

#include "state.h"

/*
	This class represents the splash screen state.
*/

// Forward declaration of StateManager class
class StateManager;

class SplashState : public State {
private:
	StateManager& stateManager;
	// Texture for the splash image
	sf::Texture splashTexture;
	// Sprite for rendering the splash image
	sf::Sprite splashSprite;

public:
	// Constructor with reference to StateManager
	SplashState(StateManager& stateManager);

	// Virtual destructor
	virtual ~SplashState();

	// Intiliase the state
	void init() override;

	// Poll events
	void pollEvents(sf::RenderWindow* window) override;

	// Update
	void update() override;

	// Render
	void render(sf::RenderWindow* window) override;
};

