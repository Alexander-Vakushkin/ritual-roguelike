
#include <gtest/gtest.h>
#include <helpers/direction.h>

TEST(DirectionTests, TurnsLeft)
{
    EXPECT_EQ(CardinalDirection::WEST(), CardinalDirection::NORTH().turn_left());
}

TEST(DirectionTests, TurnsRight)
{
    EXPECT_EQ(CardinalDirection::WEST(), CardinalDirection::SOUTH().turn_right());
}

TEST(DirectionTests, TurnsAround)
{
    EXPECT_EQ(CardinalDirection::WEST(), CardinalDirection::EAST().turn_around());
}
