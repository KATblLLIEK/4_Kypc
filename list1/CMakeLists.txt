cmake_minimum_required(VERSION 3.14)
project(AVL_Tree)

SET(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_FLAGS
"${CMAKE_CXX_FLAGS} -Wall -pedantic-errors -fsanitize=undefined --coverage")

add_executable(main)

target_sources(main PRIVATE main.cpp)