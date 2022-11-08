//
// Created by Michał on 07.11.2022.
//

#include "King.h"

bool King::is_legal(){
    return true;
}

bool King::is_white(){
    if (get_color() == Color::white){
        return true;
    }
    else {
        return false;
    }
}