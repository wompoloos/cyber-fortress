#include <iostream>
#include "settingState.h"
#include "stateManager.h" 
#include "mainMenuState.h"
#include "pauseMenuState.h"
#include <SFML/Graphics.hpp>

// Constructor that initializes the StateManager reference
pauseMenuState::pauseMenuState(StateManager& stateManager)
    : stateManager(stateManager) {

}

// Destructor - clean up any dynamic resources if needed (none in this case)
pauseMenuState::~pauseMenuState() {
}

// Initialize the settings state (setting up resources, etc.)
void pauseMenuState::init() {
    std::cout << "pause Menu..." << std::endl;
    // Background
    pauseTexture.loadFromFile("../res/images/screens/menuScreen.png");
    pauseSprite.setTexture(pauseTexture);
    // Play
    pausePlayTexture.loadFromFile("../res/images/ui/pauseResume.png");
    pausePlaySprite.setTexture(pausePlayTexture);
    pausePlaySprite.setPosition(sf::Vector2f(93.f, 199.f));
    pauseSprites.push_back(pausePlaySprite);
    // Options
    pauseOptionsTexture.loadFromFile("../res/images/ui/menuOptions.png");
    pauseOptionsSprite.setTexture(pauseOptionsTexture);
    pauseOptionsSprite.setPosition(sf::Vector2f(263.f, 199.f));
    pauseSprites.push_back(pauseOptionsSprite);
    // Quit
    pauseQuitTexture.loadFromFile("../res/images/ui/menuQuit.png");
    pauseQuitSprite.setTexture(pauseQuitTexture);
    pauseQuitSprite.setPosition(sf::Vector2f(483.f, 199.f));
    pauseSprites.push_back(pauseQuitSprite);
}

void pauseMenuState::pollEvents(sf::RenderWindow* window)
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
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Up) {
                if (pauseChoicesIndex > 0) {
                    pauseChoicesIndex--;
                }
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Down) {
                if (pauseChoicesIndex < pauseChoices.size() - 1) {
                    pauseChoicesIndex++;
                    pauseSprites[pauseChoicesIndex].setColor(sf::Color::White);
                }
            }
            if (event.key.code == sf::Keyboard::Enter) {
                switch (pauseChoicesIndex) {
                case 0:
                    stateManager.popState();
                    break;
                case 1:
                    stateManager.changeState(std::make_unique<settingState>(stateManager));
                    break;
                case 2:
                    exit(0);
                    break;
                }
                break;
            }
        }
    }
}

// Update the state (e.g., handle user input, etc.)
void pauseMenuState::update() {

    for (std::size_t i = 0; i < pauseSprites.size(); ++i) {
        if (i == pauseChoicesIndex) {
            // Highlight current choice in white
            pauseSprites[i].setColor(sf::Color(255, 255, 255, 255));
        }
        else {
            // Reset colour of other choices to green
            pauseSprites[i].setColor(sf::Color(8, 255, 8, 255));
        }
    }
}


// Render the screen (show the blue background)
void pauseMenuState::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);

    window->draw(pauseSprite);
    // Draw sprites
    for (const auto& sprite : pauseSprites) {
        window->draw(sprite);
    }
    // You could render more UI elements here if desired (like buttons or text)
    // For now, we just display the blue background

    window->display();  // Display the current frame
}
