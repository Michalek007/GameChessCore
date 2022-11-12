//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_BISHOP_H
#define GAMECHESSCORE_BISHOP_H
#include "Chessman.h"

class Bishop: public Chessman {

public:
    explicit Bishop(Color color): Chessman(color) {}
    bool is_legal(Coord& start, Coord& end) override;
    [[nodiscard]] std::string get_symbol() const override {return "B";}
};


#endif //GAMECHESSCORE_BISHOP_H
