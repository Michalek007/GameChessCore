//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_SQUARE_H
#define GAMECHESSCORE_SQUARE_H
#include "Chessman.h"
#include "Coord.h"


class Square: public Coord {
private:
    //Coord* _coord;
    Chessman* _piece;
public:
    [[nodiscard]] Chessman* get_piece() const {return _piece;}
    void set_piece(Chessman* piece) {_piece = piece;}
    Square(int x, int y, Chessman* piece=nullptr): Coord(x, y), _piece{piece}{}
    bool has_piece(){
        if (_piece == nullptr){
            return false;
        }
        else{
            return true;
        }
    }
    void set_null() {
        _piece = nullptr;
    }
    void kill_piece() {
        delete _piece;
    }
};

#endif //GAMECHESSCORE_SQUARE_H
