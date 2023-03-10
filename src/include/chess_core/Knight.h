//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_KNIGHT_H
#define GAMECHESSCORE_KNIGHT_H
#include "Chessman.h"


class Knight: public Chessman {

public:
    explicit Knight(Color color=Color::white): Chessman(color) {}
    bool is_legal(Coord& start, Coord& end) override;
    [[nodiscard]] std::string get_symbol() const override {return "N";}

};


#endif //GAMECHESSCORE_KNIGHT_H
