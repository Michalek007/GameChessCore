//
// Created by Michał on 07.11.2022.
//

#ifndef GAMECHESSCORE_KING_H
#define GAMECHESSCORE_KING_H
#include "Chessman.h"

class King: public Chessman {

public:
    explicit King(Color color): Chessman(color) {}
    bool is_legal() override;
    bool is_white() override;
};


#endif //GAMECHESSCORE_KING_H
