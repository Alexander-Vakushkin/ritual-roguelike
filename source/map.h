#ifndef MAP_H_58e37245127b719b1492e32d412b6f15ac80148e
#define MAP_H_58e37245127b719b1492e32d412b6f15ac80148e

#include <map.h>

#include <vector>
#include <memory>

class Map
    : public IMap
{
public:
    Map(size_t height, size_t width);

    size_t width() const final;
    size_t height() const final;

    const Tile& get_tile(size_t height, size_t width) const final;
    Tile& get_tile(size_t height, size_t width) final;

    //virtual void render() const final;

private:
    size_t m_width;
    size_t m_height;

    std::vector<std::unique_ptr<Tile>> m_tiles;
};

#endif //  MAP_H_58e37245127b719b1492e32d412b6f15ac80148e
