cmake_minimum_required(VERSION 3.7)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project(Ritual)

find_package(Tcod REQUIRED)

include_directories(${Tcod_INCLUDE_DIR})

link_directories(${Tcod_LIB_DIR})

include_directories(include)
file(GLOB SOURCES source/*.cpp)

add_executable(Ritual ${SOURCES})
target_link_libraries(Ritual ${Tcod_LIBRARIES})
