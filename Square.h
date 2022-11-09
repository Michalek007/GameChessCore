//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_SQUARE_H
#define GAMECHESSCORE_SQUARE_H
#include "Chessman.h"
#include "Coord.h"
// #include <optional>


class Square: public Coord {
private:
    //Coord* _coord;
    Chessman* _piece;
public:
    //[[nodiscard]] Coord* get_coord() const {return _coord;}
    //[[nodiscard]] int get_x() const {return _coord->get_x();}
    //[[nodiscard]] int get_y() const {return _coord->get_y();}
    [[nodiscard]] Chessman* get_piece() const {return _piece;}
    void set_piece(Chessman* piece) {_piece = piece;}
    //Square(int x, int y, Chessman* piece=nullptr): _x{x}, _y(y), _piece{piece}{}
    Square(int x, int y, Chessman* piece=nullptr): Coord(x, y), _piece{piece}{}
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
    void set_null() {
        _piece = nullptr;
    }
};


#endif //GAMECHESSCORE_SQUARE_H
