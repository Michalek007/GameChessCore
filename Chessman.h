//
// Created by Michał on 07.11.2022.
//
#ifndef GAMECHESSCORE_CHESSMAN_H
#define GAMECHESSCORE_CHESSMAN_H
#include "Coord.h"

enum class Color{
    white = 1,
    black = 0
};

class Chessman {
private:
    Color _color;
public:
    explicit Chessman(Color color = Color::white): _color{color}{}
    [[nodiscard]] Color get_color() const {return _color;}
    virtual bool is_legal(Coord& start, Coord& end) = 0;
    bool is_white();
};


#endif //GAMECHESSCORE_CHESSMAN_H
