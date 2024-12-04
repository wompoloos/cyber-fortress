#include <iostream>
#include "settingState.h"
#include "stateManager.h" 
#include "mainMenuState.h"
#include "escapeMenuState.h"
#include <SFML/Graphics.hpp>

// Constructor that initializes the StateManager reference
escapeMenuState::escapeMenuState(StateManager& stateManager)
    : stateManager(stateManager) {

}

// Destructor - clean up any dynamic resources if needed (none in this case)
escapeMenuState::~escapeMenuState() {
}

// Initialize the settings state (setting up resources, etc.)
void escapeMenuState::init() {
    std::cout << "Escape Menu..." << std::endl;
    // Background
    escapeTexture.loadFromFile("../res/images/screens/menuScreen.png");
    escapeSprite.setTexture(escapeTexture);
    // Play
    escapePlayTexture.loadFromFile("../res/images/ui/menuPlay.png");
    escapePlaySprite.setTexture(escapePlayTexture);
    escapePlaySprite.setPosition(sf::Vector2f(93.f, 199.f));
    escapeSprites.push_back(escapePlaySprite);
    // Options
    escapeOptionsTexture.loadFromFile("../res/images/ui/menuOptions.png");
    escapeOptionsSprite.setTexture(escapeOptionsTexture);
    escapeOptionsSprite.setPosition(sf::Vector2f(263.f, 199.f));
    escapeSprites.push_back(escapeOptionsSprite);
    // Quit
    escapeQuitTexture.loadFromFile("../res/images/ui/menuQuit.png");
    escapeQuitSprite.setTexture(escapeQuitTexture);
    escapeQuitSprite.setPosition(sf::Vector2f(483.f, 199.f));
    escapeSprites.push_back(escapeQuitSprite);
}

void escapeMenuState::pollEvents(sf::RenderWindow* window)
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
                if (escapeChoicesIndex > 0) {
                    escapeChoicesIndex--;
                }
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Down) {
                if (escapeChoicesIndex < escapeChoices.size() - 1) {
                    escapeChoicesIndex++;
                    escapeSprites[escapeChoicesIndex].setColor(sf::Color::White);
                }
            }
            if (event.key.code == sf::Keyboard::Enter) {
                switch (escapeChoicesIndex) {
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
void escapeMenuState::update() {

    for (std::size_t i = 0; i < escapeSprites.size(); ++i) {
        if (i == escapeChoicesIndex) {
            // Highlight current choice in white
            escapeSprites[i].setColor(sf::Color(255, 255, 255, 255));
        }
        else {
            // Reset colour of other choices to green
            escapeSprites[i].setColor(sf::Color(8, 255, 8, 255));
        }
    }
}


// Render the screen (show the blue background)
void escapeMenuState::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Blue);

    window->draw(escapeSprite);
    // Draw sprites
    for (const auto& sprite : escapeSprites) {
        window->draw(sprite);
    }
    // You could render more UI elements here if desired (like buttons or text)
    // For now, we just display the blue background

    window->display();  // Display the current frame
}
