#include "dungeon_map_generator.h"
#include "../map.h"
#include <tile.h>
#include <libtcod.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

std::unique_ptr<IMap> DungeonMapGenerator::generate(size_t height, size_t width) const
{
    std::unique_ptr<IMap> result = std::make_unique<Map>(height, width);
    std::unique_ptr<TCODRandom> rng = std::make_unique<TCODRandom>();

    size_t nRooms = rng->getInt(6, 8);

    std::vector<Room> rooms;
    while(rooms.size() < nRooms)
    {
        Room newRoomCandidate = Room{    rng->getInt(0, width - 10)
                                        ,rng->getInt(0, height - 10)
                                        ,rng->getInt(6, 11)
                                        ,rng->getInt(6, 11)};
        if(! std::any_of(rooms.begin(), rooms.end(), [&newRoomCandidate] (const Room& r) { return r.is_overlapping(newRoomCandidate); }))
        {
            rooms.push_back(newRoomCandidate);
        }
    }

    for(const Room& r : rooms)
    {
        for(size_t x = r.upperLeftX+1; x < r.upperLeftX + r.width; ++x)
        {
            for(size_t y = r.upperLeftY+1; y < r.upperLeftY + r.height; ++y)
            {
                result->get_tile(y, x) = Tile::FLOOR;
            }
        }
    }

    return std::move(result);
}
