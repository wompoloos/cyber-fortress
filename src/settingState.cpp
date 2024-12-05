#include <iostream>
#include "settingState.h"
#include "stateManager.h" 
#include "mainMenuState.h"
#include <SFML/Graphics.hpp>

// Constructor that initializes the StateManager reference
settingState::settingState(StateManager& stateManager)
    : stateManager(stateManager){
   
}

// Destructor - clean up any dynamic resources if needed (none in this case)
settingState::~settingState() {
}

// Initialize the settings state (setting up resources, etc.)
void settingState::init() {
    std::cout << "Settings..." << std::endl;

    settingsTexture.setSrgb(0);

    videoTexture.loadFromFile("../res/images/ui/settingsVideo.png");
    videoSprite.setTexture(videoTexture);
    videoSprite.setPosition(sf::Vector2f(20.f, 20.f));
    settingsSprites.push_back(videoSprite);

    controlsTexture.loadFromFile("../res/images/ui/settingsControl.png");
    controlsSprite.setTexture(controlsTexture);
    controlsSprite.setPosition(sf::Vector2f(190.f, 20.f));
    settingsSprites.push_back(controlsSprite);

    soundTexture.loadFromFile("../res/images/ui/settingsSound.png");
    soundSprite.setTexture(soundTexture);
    soundSprite.setPosition(sf::Vector2f(360.f, 20.f));
    settingsSprites.push_back(soundSprite);
}

void settingState::pollEvents(sf::RenderWindow* window)
{
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
            if (event.key.code == sf::Keyboard::Escape) {
                stateManager.popState();
            }
        }
    }
}

// Update the state (e.g., handle user input, etc.)
void settingState::update() {
    for (std::size_t i = 0; i < settingsSprites.size(); ++i) {
        if (i == settingsChoicesIndex) {
            // Highlight current choice in white
            settingsSprites[i].setColor(sf::Color(255, 255, 255, 255));
        }
        else {
            // Reset colour of other choices to green
            settingsSprites[i].setColor(sf::Color(8, 255, 8, 255));
        }
    }
}


// Render the screen (show the blue background)
void settingState::render(sf::RenderWindow* window) {
        window->clear(sf::Color::Blue);

        window->draw(settingsSprite);
        // Draw sprites
        for (const auto& sprite : settingsSprites) {
            window->draw(sprite);
        }
        // You could render more UI elements here if desired (like buttons or text)
        // For now, we just display the blue background

        window->display();  // Display the current frame
}
