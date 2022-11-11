//
// Created by Michał on 07.11.2022.
//

#include "Chessman.h"

bool Chessman::is_white() const{
    if (get_color() == Color::white){
        return true;
    }
    else {
        return false;
    }
}
