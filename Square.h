//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_SQUARE_H
#define GAMECHESSCORE_SQUARE_H
#include <optional>
#include "Chessman.h"

class Square {
private:
    int _x;
    int _y;
    Chessman* _piece;
public:
    [[nodiscard]] int get_x() const {return _x;}
    [[nodiscard]] int get_y() const {return _y;}
    [[nodiscard]] Chessman* get_piece() const {return _piece;}
    void set_piece(Chessman* piece) {_piece = piece;}
    Square(int x, int y, Chessman* piece=nullptr): _x{x}, _y(y), _piece{piece}{}
    bool has_piece(){
        //std::optional<Chessman*> test;
        //if (test.has_value())
        if (_piece == nullptr){
            return false;
        }
        else{
            return true;
        }
    }
};


#endif //GAMECHESSCORE_SQUARE_H
