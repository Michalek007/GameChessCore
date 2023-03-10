//
// Created by Michał on 07.11.2022.
//

#ifndef GAMECHESSCORE_KING_H
#define GAMECHESSCORE_KING_H
#include "Chessman.h"

class King: public Chessman {

public:
    explicit King(Color color=Color::white): Chessman(color) {}
    bool is_legal(Coord& start, Coord& end) override;
    [[nodiscard]] std::string get_symbol() const override {return "K";}
};


#endif //GAMECHESSCORE_KING_H
