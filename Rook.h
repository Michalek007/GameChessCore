//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_ROOK_H
#define GAMECHESSCORE_ROOK_H
#include "Chessman.h"

class Rook: public Chessman {

public:
    explicit Rook(Color color): Chessman(color) {}
    bool is_legal(Coord& start, Coord& end) override;
};


#endif //GAMECHESSCORE_ROOK_H
