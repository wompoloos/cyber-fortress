#pragma once

#include "state.h"

/*
    This class represents the gameplay state.
*/

// Forward declaration of StateManager class
class StateManager;

class GamePlayState : public State {
private:
    StateManager& stateManager;
    bool isPaused = false;

    // Circles
    sf::CircleShape circle1;
    sf::CircleShape circle2;

    // Speed of movement
    float vel = 20.0f; // pixels per second

    // Vectors
    std::vector<sf::CircleShape> circles = { };
    std::vector<sf::Vector2f> currentPositions;  // Current positions
    std::vector<sf::Vector2f> previousPositions; // Previous positions
    std::vector<float> velocities;           // Velocity for movement
    
public:
    // Constructor with reference to StateManager
    GamePlayState(StateManager& stateManager);

    // Virtual destructor
    virtual ~GamePlayState();
        
    // Initialise the state
    void init() override;

    // Pause
    void onPause() override;

    // Resume
    void onResume() override;

    // Poll events
    void pollEvents(sf::RenderWindow* window) override;

    // Update
    void update(float deltaTime) override;

    // Render
    void render(sf::RenderWindow* window, float alpha) override;
};
