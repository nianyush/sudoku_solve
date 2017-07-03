cmake_minimum_required(VERSION 3.5)
project(sudoku_solve)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(sudoku_solve ${SOURCE_FILES})