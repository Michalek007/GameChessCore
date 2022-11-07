cmake_minimum_required(VERSION 3.23)
project(GameChessCore)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameChessCore main.cpp King.cpp Chessman.cpp)
