#include"../source/map_generators/dungeon_map_generator.h"

#include <gtest/gtest.h>

TEST(RoomTests, ContainsReturnsTrueForAPointInsideARoom)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.contains(1,1));
}

TEST(RoomTests, ContainsReturnsTrueForAPointOnTheBorder)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.contains(0,1));
}

TEST(RoomTests, ContainsReturnsTrueForACornerPoint)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.contains(0,0));
}
