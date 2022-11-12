//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_QUEEN_H
#define GAMECHESSCORE_QUEEN_H
#include "Chessman.h"

class Queen: public Chessman {

public:
    explicit Queen(Color color): Chessman(color) {}
    bool is_legal(Coord& start, Coord& end) override;
    [[nodiscard]] std::string get_symbol() const override {return "Q";}
};


#endif //GAMECHESSCORE_QUEEN_H
