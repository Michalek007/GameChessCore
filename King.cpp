//
// Created by Michał on 07.11.2022.
//
#include "King.h"

bool King::is_legal(Coord& start, Coord& end){
    if (start.is_equal(end)){
        return false;
    }
    if (start.x_axis_distance(end) > 1){
        return false;
    }
    if (start.y_axis_distance(end) > 1){
        return false;
    }
    return true;
}
