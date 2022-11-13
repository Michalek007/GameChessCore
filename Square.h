//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_SQUARE_H
#define GAMECHESSCORE_SQUARE_H
#include "Chessman.h"
#include "Coord.h"


class Square: public Coord {
private:
    Chessman* _piece;
public:
    [[nodiscard]] Chessman* get_piece() const {return _piece;}
    void set_piece(Chessman* piece) {_piece = piece;}
    Square(int x, int y, Chessman* piece=nullptr): Coord(x, y), _piece{piece}{}
    bool has_piece();
    void set_null();
    void capture_piece();
    [[nodiscard]] std::string get_piece_symbol() const;
    [[nodiscard]] std::string get_coord_symbol() const;
};

#endif //GAMECHESSCORE_SQUARE_H
