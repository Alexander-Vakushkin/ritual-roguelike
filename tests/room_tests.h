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

TEST(RoomTests, ContainsReturnsFalseForAPointOutsideTheRoom)
{
    Room r{0,0,3,4};
    EXPECT_FALSE(r.contains(5,5));
}

TEST(RoomTests, OverlapsReturnsTrueForARoomInsideARoom)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.is_overlapping({1,1,1,1}));
}

TEST(RoomTests, OverlapsReturnsTrueForAPartiallyOverlappingRoom)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.is_overlapping({1,1,5,5}));
}

TEST(RoomTests, OverlapsReturnsTrueForRoomsSharingABorder)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.is_overlapping({3,0,5,5}));
}

TEST(RoomTests, OverlapsReturnsTrueForRoomsSharingACorner)
{
    Room r{0,0,3,4};
    EXPECT_TRUE(r.is_overlapping({3,4,5,5}));
}

TEST(RoomTests, OverlapsReturnsTrueWhenTwoRoomsFormACross)
{
    Room r{2,2,10,10};
    EXPECT_TRUE(r.is_overlapping({5,0,3,20}));
}
