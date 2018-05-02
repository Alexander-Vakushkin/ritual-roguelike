#ifndef DUNGEON_MAP_GENERATOR_H_e56f797f93026d5fd61da31c5a88bd95e8e8fe95
#define DUNGEON_MAP_GENERATOR_H_e56f797f93026d5fd61da31c5a88bd95e8e8fe95

#include <map_generator.h>

#include "../map.h"

struct Room
{
    size_t upperLeftX;
    size_t upperLeftY;

    size_t width;
    size_t height;

    bool contains(size_t x, size_t y) const
    {
        return (x >= upperLeftX)
            && (y >= upperLeftY)
            && (x <= upperLeftX + width)
            && (y <= upperLeftY + height);
    }

    bool is_overlapping(const Room& other) const
    {
        // we suppose that this room starts to the left of other room
        if(upperLeftX > other.upperLeftX)
        {
            return other.is_overlapping(*this);
        }

        return contains(other.upperLeftX, other.upperLeftY)
            || contains(other.upperLeftX, other.upperLeftY + other.height);
    }

};

class DungeonMapGenerator
    : public IMapGenerator
{
public:
    virtual std::unique_ptr<IMap> generate(size_t height, size_t width) const final;

private:

};



#endif // DUNGEON_MAP_GENERATOR_H_e56f797f93026d5fd61da31c5a88bd95e8e8fe95
