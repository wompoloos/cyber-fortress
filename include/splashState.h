#pragma once

#include "state.h"

/*
	This class represents the splash screen state.
*/

class SplashState : public State {
public:
	// Default constructor
	SplashState();

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

	// Check if the state is ended
	bool isEnd() override;
};

