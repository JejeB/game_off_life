cmake_minimum_required(VERSION 3.10)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)

add_executable(game_of_life src/main.cpp src/game.cpp)