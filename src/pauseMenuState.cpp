#include <iostream>
#include "pauseMenuState.h"
#include "stateManager.h"
#include "settingState.h" 

// Public functions
// Constructors
PauseMenuState::PauseMenuState(StateManager& stateManager)
    : stateManager(stateManager) {
}

// Destructors
PauseMenuState::~PauseMenuState() {
}

// Initialise the state
void PauseMenuState::init() {
    // Debug message
    std::cout << "Initialising PauseMenuState..." << std::endl;
    // Load resources
    // Background
    pauseTexture.loadFromFile("../res/images/screens/pauseScreen.png");
    pauseSprite.setTexture(pauseTexture);
    // Resume
    pausePlayTexture.loadFromFile("../res/images/ui/menuResume.png");
    pausePlaySprite.setTexture(pausePlayTexture);
    pausePlaySprite.setPosition(sf::Vector2f(271.f, 169.f));
    pauseSprites.push_back(pausePlaySprite);
    // Options
    pauseOptionsTexture.loadFromFile("../res/images/ui/menuOptions.png");
    pauseOptionsSprite.setTexture(pauseOptionsTexture);
    pauseOptionsSprite.setPosition(sf::Vector2f(263.f, 205.f));
    pauseSprites.push_back(pauseOptionsSprite);
    // Quit
    pauseQuitTexture.loadFromFile("../res/images/ui/menuQuit.png");
    pauseQuitSprite.setTexture(pauseQuitTexture);
    pauseQuitSprite.setPosition(sf::Vector2f(288.f, 241.f));
    pauseSprites.push_back(pauseQuitSprite);
}

// Poll events
void PauseMenuState::pollEvents(sf::RenderWindow* window)
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
            if (event.key.code == sf::Keyboard::Up) {
                if (pauseChoicesIndex > 0) {
                    pauseChoicesIndex--;
                }
            }
            if (event.key.code == sf::Keyboard::Down) {
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
                    stateManager.pushState(std::make_unique<SettingState>(stateManager));
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

// Update the state
void PauseMenuState::update(float deltaTime) {
    // Show the selected pause menu choice
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


// Render the screen
void PauseMenuState::render(sf::RenderWindow* window, float alpha) {
    window->clear(sf::Color::Black);
    // Draw the pause sprite
    window->draw(pauseSprite);
    // Draw choices sprites
    for (const auto& sprite : pauseSprites) {
        window->draw(sprite);
    }
    // Display the window
    window->display();
}