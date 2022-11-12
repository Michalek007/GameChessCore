//
// Created by Michał on 10.11.2022.
//

#ifndef GAMECHESSCORE_GAME_H
#define GAMECHESSCORE_GAME_H
#include <map>
#include <string>
#include "Square.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

class Game {
private:
    std::vector<std::vector<Square*>>* _board;
    Color _turn;
    std::vector<std::map<std::string, std::string>>* _game_record;
public:
    explicit Game(std::vector<std::vector<Square*>>* board, Color turn=Color::white);
    static std::vector<std::vector<Square*>>* init();
    [[nodiscard]] Color get_turn() const {return _turn;}
    Square* get_square(Coord& coord);
    Chessman* get_piece(Coord& coord);
    bool is_legal(Coord& start, Coord& end);
    void make_move(Coord& start, Coord& end);
    void set_last_move(std::string start, std::string end, std::string taken);
    std::map<std::string, std::string> get_last_move();
    void undo_last_move();
    static Chessman* decode_piece(std::string piece);
    static Coord decode_coord(std::string coord);
};


#endif //GAMECHESSCORE_GAME_H
