#include "map.h"
#include <tile.h>

Map::Map(size_t height, size_t width)
    : m_height(height)
    , m_width(width)
{
    m_tiles.reserve(height * width);

    for(size_t i = 0; i < height; ++i)
    {
        for(size_t j = 0; j < width; ++j)
        {
            m_tiles.emplace_back(std::make_unique<Tile>(Tile::WALL));
        }
    }
}

size_t Map::width() const
{
    return m_width;
}

size_t Map::height() const
{
    return m_height;
}

const Tile& Map::get_tile(size_t height, size_t width) const
{
    return *(m_tiles[height * m_width + width]);
}

Tile& Map::get_tile(size_t height, size_t width)
{
    return *(m_tiles[height * m_width + width]);
}
