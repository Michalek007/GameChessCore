cmake_minimum_required(VERSION 3.23)
project(GameChessCore)

set(CMAKE_CXX_STANDARD 20)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

set(SOURCES main.cpp Chessman.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp Coord.cpp Square.cpp Game.cpp tests/test_coord.h)

add_executable(GameChessCore ${SOURCES})

target_include_directories(GameChessCore PRIVATE include/chess_core)

set(CMAKE_EXE_LINKER_FLAGS "-static")
