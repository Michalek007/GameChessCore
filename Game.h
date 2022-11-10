//
// Created by Michał on 10.11.2022.
//

#ifndef GAMECHESSCORE_GAME_H
#define GAMECHESSCORE_GAME_H
#include <vector>
#include "Square.h"

class Game {
private:
    std::vector<std::vector<Square*>>* _board;
    Color _turn;
public:
    Game(std::vector<std::vector<Square*>>* board, Color turn=Color::white);
    static std::vector<std::vector<Square*>>* init(){
        Square* a1 = new Square(1, 1);
        Square* a2 = new Square(1, 2);
        Square* a3 = new Square(1, 3);
        Square* a4 = new Square(1, 4);
        Square* a5 = new Square(1, 5);
        Square* a6 = new Square(1, 6);
        Square* a7 = new Square(1, 7);
        Square* a8 = new Square(1, 8);
        Square* b1 = new Square(2, 1);
        Square* b2 = new Square(2, 2);
        Square* b3 = new Square(2, 3);
        Square* b4 = new Square(2, 4);
        Square* b5 = new Square(2, 5);
        Square* b6 = new Square(2, 6);
        Square* b7 = new Square(2, 7);
        Square* b8 = new Square(2, 8);
        std::vector<Square*> row1 {a1, a2, a3 ,a4, a5, a6, a7, a8};
        std::vector<Square*> row2 {b1, b2, b3 ,b4, b5, b6, b7, b8};
        std::vector<std::vector<Square*>>* board = new std::vector<std::vector<Square*>>{row1, row2};
        return board;
    }
};


#endif //GAMECHESSCORE_GAME_H
