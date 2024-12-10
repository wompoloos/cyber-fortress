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

std::array<std::array<cell, mapHeight>, mapWidth> convertSketch(const std::array<std::string, mapHeight>& i_map_sketch)
{
	std::array<std::array<cell, mapHeight>, mapWidth> outputMap{};

	for (unsigned char a = 0; a < mapHeight; a++)
	{
		for (unsigned char b = 0; b < mapWidth; b++)
		{
			//By default, every cell is empty.
			outputMap[b][a] = cell::empty;

			switch (i_map_sketch[a][b])
			{
			case '#':
			{
				outputMap[b][a] = cell::wall;

				break;
			}
			case '.':
			{
				outputMap[b][a] = cell::empty;

				break;
			}


			}
		}
	}
	return outputMap;
}
