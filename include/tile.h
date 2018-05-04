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

    static const Tile FLOOR;//{ '.', true };
    static const Tile WALL;// { '#', false };

private:
    char m_view;
    bool m_walkable;
};

<<<<<<< HEAD

#endif // TILE_H+vD8S/mkyimBAwdTHOeUUQe9C6ngub0+
=======
#endif // TILE_H_1dce7124ea14bd7e4ab48983fd563f4864c46732
>>>>>>> master
