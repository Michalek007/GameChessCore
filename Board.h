//
// Created by Michał on 10.11.2022.
//

#ifndef GAMECHESSCORE_BOARD_H
#define GAMECHESSCORE_BOARD_H
#include <vector>
#include <algorithm>
#include "Square.h"

class Board {
private:
    Square a1 {1, 1};
    Square a2 {1, 2};
    Square a3 {1, 3};
    Square a4 {1, 4};
    Square a5 {1, 5};
    Square a6 {1, 6};
    Square a7 {1, 7};
    Square a8 {1, 8};
    Square b1 {2, 1};
    Square b2 {2, 2};
    Square b3 {2, 3};
    Square b4 {2, 4};
    Square b5 {2, 5};
    Square b6 {2, 6};
    Square b7 {2, 7};
    Square b8 {2, 8};
public:
    Board() = default;
};


#endif //GAMECHESSCORE_BOARD_H
