#ifndef TILE_H_1dce7124ea14bd7e4ab48983fd563f4864c46732
#define TILE_H_1dce7124ea14bd7e4ab48983fd563f4864c46732

class Tile
{
public:
    Tile(char view, bool walkable)
        : m_view(view)
        , m_walkable(walkable)
    {}

    char get_view() const { return m_view; }
    bool is_walkable() const { return m_walkable; }

private:
    char m_view;
    bool m_walkable;
};

#endif // TILE_H_1dce7124ea14bd7e4ab48983fd563f4864c46732
