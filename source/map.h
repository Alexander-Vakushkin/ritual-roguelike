#ifndef MAP_H_JdXDWuf/9apaGlvmxfWOQ5+QkQuKid2k
#define MAP_H_JdXDWuf/9apaGlvmxfWOQ5+QkQuKid2k

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

#endif //  MAP_H_JdXDWuf/9apaGlvmxfWOQ5+QkQuKid2k
