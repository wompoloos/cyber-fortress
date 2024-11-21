#include <SFML/Graphics.hpp>

int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode({640, 360}), "Cyber Fortress");
    sf::Event event;

    // Game loop
    while (window.isOpen()) {
        // Check for events
        while (window.pollEvent(event)) {
            // Handle events
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
            }
        }
        // Update


        // Render
        window.clear();
        window.display();
    }
    return 0;
}

