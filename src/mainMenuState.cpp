#include <iostream>
#include "mainMenuState.h"
#include "stateManager.h"
#include "gamePlayState.h"
#include "settingState.h"

// Public functions
// Constructors
MainMenuState::MainMenuState(StateManager& stateManager) 
    : stateManager(stateManager) {
}

// Destructors
MainMenuState::~MainMenuState() {
}

// Intiliase the state   
void MainMenuState::init() {
	std::cout << "Initialisng MainMenuState..." << std::endl;
    // Background
    menuTexture.loadFromFile("../res/images/screens/menuScreen.png");
    menuSprite.setTexture(menuTexture);
    // Play
    menuPlayTexture.loadFromFile("../res/images/ui/menuPlay.png");
    menuPlaySprite.setTexture(menuPlayTexture);
    menuPlaySprite.setPosition(sf::Vector2f(93.f, 199.f));
    menuSprites.push_back(menuPlaySprite);
    // Options
    menuOptionsTexture.loadFromFile("../res/images/ui/menuOptions.png");
    menuOptionsSprite.setTexture(menuOptionsTexture);
    menuOptionsSprite.setPosition(sf::Vector2f(263.f, 199.f));
    menuSprites.push_back(menuOptionsSprite);
    // Quit
    menuQuitTexture.loadFromFile("../res/images/ui/menuQuit.png");
    menuQuitSprite.setTexture(menuQuitTexture);
    menuQuitSprite.setPosition(sf::Vector2f(483.f, 199.f));
    menuSprites.push_back(menuQuitSprite);
}

// Poll events
void MainMenuState::pollEvents(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Up) {
                if (menuChoicesIndex > 0) {
                    menuChoicesIndex--;
                }
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Down) {
                if (menuChoicesIndex < menuChoices.size() - 1) {
                    menuChoicesIndex++;
                    menuSprites[menuChoicesIndex].setColor(sf::Color::White);
                }
            }
            if (event.key.code == sf::Keyboard::Enter) {
                switch (menuChoicesIndex) {
                case 0:
                    stateManager.changeState(std::make_unique<gamePlayState>(stateManager));
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

// Update
void MainMenuState::update() {
    // Show selected menu choice
    for (std::size_t i = 0; i < menuSprites.size(); ++i) {
        if (i == menuChoicesIndex) {
            // Highlight current choice in white
            menuSprites[i].setColor(sf::Color(255, 255, 255, 255));
        }
        else {
            // Reset colour of other choices to green
            menuSprites[i].setColor(sf::Color(8, 255, 8, 255));
        }
    }
}

// Render
void MainMenuState::render(sf::RenderWindow* window) {
    // std::cout << "Rendering MainMenuState..." << std::endl;
    window->clear();
    // Draw the menu sprite
    window->draw(menuSprite);
    // Draw sprites
    for (const auto& sprite : menuSprites) {
        window->draw(sprite);
    }
    // Display the window
    window->display();
}