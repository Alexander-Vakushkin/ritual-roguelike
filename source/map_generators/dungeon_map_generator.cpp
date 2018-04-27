#include "dungeon_map_generator.h"
#include "../map.h"
#include <tile.h>
#include <libtcod.hpp>
#include <iostream>

std::unique_ptr<IMap> DungeonMapGenerator::generate(size_t height, size_t width) const
{
    std::unique_ptr<IMap> result = std::make_unique<Map>(height, width);
    std::unique_ptr<TCODRandom> rng = std::make_unique<TCODRandom>();

    int nMainCorridors = rng->getInt(6, 10);
    int x = rng->getInt(0, result->width()-1);
    int y = rng->getInt(0, result->height()-1);
    int direction = rng->getInt(0, 3);

    for(int i = 0; i < nMainCorridors; ++i)
    {
        std::cout << "DIRECTION: " << direction << std::endl;
        size_t corridorLength = rng->getInt(10, 15);
        for(size_t j = 0; j < corridorLength; ++j)
        {
            result->get_tile(y, x) = Tile::FLOOR;

            int d = direction / 2, m = direction % 2;
            int newX = x + m * (1 - 2*d);
            int newY = y + (1-m) * (1 - 2*d);

            std::cout << x << " " << y << std::endl;

            if(newX < 0 || newY < 0 || newX >= result->width() || newY >= result->height())
            {
                break;
            }
            else
            {
                x = newX;
                y = newY;
            }
        }

        direction = (4 + direction + (1 - 2 * rng->getInt(0, 1))) % 4;

    }

    return std::move(result);
}
