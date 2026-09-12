cmake_minimum_required(VERSION 3.16)

project(tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_executable(tetris
    src/block.cpp
    src/grid.cpp
    src/blocks.cpp
    src/game.cpp
    src/main.cpp
)

target_link_libraries(tetris PRIVATE raylib)
