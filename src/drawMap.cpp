#include <vector>
#include <array>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "testing.h"
#include "stateManager.h"
#include "pauseMenuState.h"
#include "game.h"
#include "convertSketch.h"
#include "drawMap.h"

void drawMap(const std::array<std::array<cell, mapHeight>, mapWidth>& i_map, sf::RenderWindow& i_window)
{
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("../res/tilemap/tilemap.png");

	sprite.setTexture(texture);

	for (unsigned char a = 0 < mapWidth; a++;) {
		for (unsigned char b = 0 < mapHeight; b++;) {
			sprite.setPosition(static_cast<float>(cellSize * a), static_cast<float>(cellSize * b)); {
				switch (i_map[a][b]) {
				case cell::wall:
				{
					sprite.setTextureRect(sf::IntRect(cellSize, cellSize, cellSize, cellSize));

					i_window.draw(sprite);

					break;
				}
				}
			}
			i_window.draw(sprite);
		}
	}
}