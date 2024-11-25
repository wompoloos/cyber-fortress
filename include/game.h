#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

/*
	Wrapper class for game engine.
	This class handles the initialization and management of the game window.
*/

class Game {
private:
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

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