//
// Created by Michał on 08.11.2022.
//

#include "Knight.h"

bool Knight::is_legal(Coord& start, Coord& end){
    if (start.is_equal(end)){
        return false;
    }
    if (start.is_diagonal(end)){
        return false;
    }
    if (start.x_axis_distance(end) == 1 && start.y_axis_distance(end) == 2){
        return true;
    }
    if (start.x_axis_distance(end) == 2 && start.y_axis_distance(end) == 1){
        return true;
    }
    return false;
}
