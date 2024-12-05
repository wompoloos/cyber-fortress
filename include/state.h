#pragma once

#include <SFML/Graphics.hpp>

/*
	Abstract base class for state.
	This class defines the interface for all game states.
*/

class State {
public:
	// Default constructor
	State() {};

	// Virtual destructor
	virtual ~State() {};

	// Intiliase the state (to be implemented in derived classes)
	virtual void init() = 0;

	// Pause (to be implemented in derived classes)
	virtual void onPause() {}

	// Resume (to be implemented in derived classes)
	virtual void onResume() {}

	// Poll events (to be implemented in derived classes)
	virtual void pollEvents(sf::RenderWindow* window) = 0;

	// Update (to be implemented in derived classes)
	virtual void update() = 0;

	// Render (to be implemented in derived classes)
	virtual void render(sf::RenderWindow* window) = 0;	
};

