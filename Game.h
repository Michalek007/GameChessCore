//
// Created by Michał on 10.11.2022.
//

#ifndef GAMECHESSCORE_GAME_H
#define GAMECHESSCORE_GAME_H
#include <map>
#include <string>
#include "Square.h"

class Game {
private:
    std::vector<std::vector<Square*>>* _board;
    Color _turn;
    std::vector<std::map<std::string, std::string>>* _game_record {};
public:
    explicit Game(std::vector<std::vector<Square*>>* board, Color turn=Color::white);
    static std::vector<std::vector<Square*>>* init();
    Square* get_square(Coord& coord);
    Chessman* get_piece(Coord& coord);
    bool is_legal(Coord& start, Coord& end);
    void make_move(Coord& start, Coord& end);



};


#endif //GAMECHESSCORE_GAME_H
