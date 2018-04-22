cmake_minimum_required(VERSION 3.7)

project(Ritual)
include_directories(/home/alex/Libs/libtcod/include)
link_directories(/home/alex/Libs/libtcod/build/autotools/.libs)

file(GLOB SOURCES source/*.cpp)

add_executable(Ritual ${SOURCES})
target_link_libraries(Ritual tcod tcodxx)
