cmake_minimum_required(VERSION 3.23)
project(GameChessCore)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameChessCore main.cpp Chessman.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp Coord.cpp Square.cpp Game.cpp)
