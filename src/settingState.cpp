#include <iostream>
#include "settingState.h"
#include "stateManager.h" 
#include "mainMenuState.h"

// Public functions
// Constructors
SettingState::SettingState(StateManager& stateManager)
    : stateManager(stateManager){
}

// Destructors
SettingState::~SettingState() {
}

// Initialise the state
void SettingState::init() {
    // Debug message
    std::cout << "Initialising SettingState..." << std::endl;
    // Load resources
    // Video
    videoTexture.loadFromFile("../res/images/ui/settingsVideo.png");
    videoSprite.setTexture(videoTexture);
    videoSprite.setPosition(sf::Vector2f(20.f, 20.f));
    settingsSprites.push_back(videoSprite);
    // Controls
    controlsTexture.loadFromFile("../res/images/ui/settingsControl.png");
    controlsSprite.setTexture(controlsTexture);
    controlsSprite.setPosition(sf::Vector2f(190.f, 20.f));
    settingsSprites.push_back(controlsSprite);
    // Sound
    soundTexture.loadFromFile("../res/images/ui/settingsSound.png");
    soundSprite.setTexture(soundTexture);
    soundSprite.setPosition(sf::Vector2f(360.f, 20.f));
    settingsSprites.push_back(soundSprite);
}

// Poll events
void SettingState::pollEvents(sf::RenderWindow* window)
{
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                stateManager.popState();
            }
        }
    }
}

// Update the state (e.g., handle user input, etc.)
void SettingState::update() {
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
void SettingState::render(sf::RenderWindow* window) {
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
