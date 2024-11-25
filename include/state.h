#pragma once

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

	// Poll events (to be implemented in derived classes)
	virtual void pollEvents() = 0;

	// Update (to be implemented in derived classes)
	virtual void update() = 0;

	// Render (to be implemented in derived classes)
	virtual void render() = 0;
};

