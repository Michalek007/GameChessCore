//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_PAWN_H
#define GAMECHESSCORE_PAWN_H
#include "Chessman.h"

class Pawn: public Chessman {

public:
    explicit Pawn(Color color): Chessman(color) {}
    bool is_legal(Coord& start, Coord& end) override;
    [[nodiscard]] std::string get_symbol() const override {return "P";}
};


#endif //GAMECHESSCORE_PAWN_H
