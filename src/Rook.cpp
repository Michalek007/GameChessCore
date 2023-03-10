//
// Created by Michał on 08.11.2022.
//

#include "Rook.h"

bool Rook::is_legal(Coord& start, Coord& end){
    if (start.is_equal(end)){
        return false;
    }
    if (start.x_axis_distance(end) == 0){
        return true;
    }
    if (start.y_axis_distance(end) == 0){
        return true;
    }
    return false;
}
