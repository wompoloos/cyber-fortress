#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

/*
	Wrapper class for game engine
*/

class Game
{
private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// Private functions
	void initVariables();
	void initWindow();

public:
	// Public functions
	// Constructors
	Game();

	// Destructors
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Event polling
	void pollEvents();

	// Update
	void update();

	// Render
	void render();
};