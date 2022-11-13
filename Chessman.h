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
    bool has_moved = false;
    explicit Chessman(Color color = Color::white): _color{color}{}
    virtual ~Chessman()= default;
    [[nodiscard]] Color get_color() const {return _color;}
    [[nodiscard]] bool is_white() const;
    virtual bool is_legal(Coord& start, Coord& end) = 0;
    [[nodiscard]] virtual std::string get_symbol() const = 0;
};


#endif //GAMECHESSCORE_CHESSMAN_H
