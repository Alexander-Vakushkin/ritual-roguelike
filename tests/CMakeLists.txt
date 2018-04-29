project(RitualTests)

find_package(Gtest REQUIRED)
link_directories(${Gtest_LIB_DIR})
include_directories(${Gtest_INCLUDE_DIR})
#include_directories(${Gmock_INCLUDE_DIR})

set(MAIN_SOURCE main.cpp)

file(GLOB TEST_SOURCES  helpers/direction_tests.h)

add_executable(tests ${MAIN_SOURCE} ${TEST_SOURCES})
target_link_libraries(tests ${Gtest_LIBS})

add_test(NAME test COMMAND tests)
