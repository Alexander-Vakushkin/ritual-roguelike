#ifndef MAP_H_FU5O3d9jgNhJtpQsjmY2I8Cuu9pGp5Rb
#define MAP_H_FU5O3d9jgNhJtpQsjmY2I8Cuu9pGp5Rb

#include <tile.h>
#include <cstddef>

struct IMap
{
    virtual size_t height() const = 0;
    virtual size_t width() const = 0;

    virtual const Tile& get_tile(size_t height, size_t width) const = 0;
    virtual Tile& get_tile(size_t height, size_t width) = 0;

    //virtual void render() const = 0;
};

#endif // MAP_H_FU5O3d9jgNhJtpQsjmY2I8Cuu9pGp5Rb
