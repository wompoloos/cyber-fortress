#pragma once

#include "state.h"


/*
	This class represents the main menu screen state.
*/

// Forward declaration of StateManager class
class StateManager;

class MainMenuState : public State {
private:
	StateManager& stateManager;
	// Options for the menu
	std::vector<std::string> menuOptions = { "Play", "Options", "Quit" };
	int menuOptionsIndex = 0;
	bool startGame = false;

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
	void update() override;

	// Render
	void render(sf::RenderWindow* window) override;
};

