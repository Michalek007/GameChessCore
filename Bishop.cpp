//
// Created by Michał on 08.11.2022.
//

#include "Bishop.h"

bool Bishop::is_legal(Coord& start, Coord& end){
    if (start.is_equal(end)){
        return false;
    }
    if (start.is_diagonal(end)){
        return true;
    }
    return false;
}
