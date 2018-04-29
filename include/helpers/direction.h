#ifndef DIRECTION_H_ef78165fa31ba3994728b22256775b63ca5742a0
#define DIRECTION_H_ef78165fa31ba3994728b22256775b63ca5742a0

class CardinalDirection
{
public:
    static CardinalDirection NORTH()
    {
        return CardinalDirection(0);
    }

    static CardinalDirection WEST()
    {
        return CardinalDirection(1);
    }

    static CardinalDirection SOUTH()
    {
        return CardinalDirection(2);
    }

    static CardinalDirection EAST()
    {
        return CardinalDirection(3);
    }


    CardinalDirection& turn_left()
    {
        m_direction = (5 + m_direction) % 4;
        return *this;
    }

    CardinalDirection& turn_right()
    {
        m_direction = (3 + m_direction) % 4;
        return *this;
    }

    CardinalDirection& turn_around()
    {
        m_direction = (2 + m_direction) % 4;
        return *this;
    }

    bool operator==(const CardinalDirection& other) const
    {
        return m_direction == other.m_direction;
    }

    bool operator!=(const CardinalDirection& other) const
    {
        return m_direction != other.m_direction;
    }

private:
    CardinalDirection(size_t internalDirection)
        : m_direction(internalDirection)
    {}

    size_t m_direction;
};

#endif //  DIRECTION_H_ef78165fa31ba3994728b22256775b63ca5742a0
