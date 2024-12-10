#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "stateManager.h"

/*
	Wrapper class for game engine.
	This class handles the initialisation and management of the game window.
*/



class Game {
private:
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	// State manager
	StateManager stateManager;

	// Private functions
	void initVariables();
	void initWindow();

public:
	// Default constructor
	Game();

	// Virtual destructor
	virtual ~Game();

	// Accessors
	const bool isRunning() const;

	// Poll events
	void pollEvents();

	// Update
	void update();

	// Render
	void render();

};