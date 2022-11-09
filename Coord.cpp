//
// Created by Michał on 09.11.2022.
//

#include "Coord.h"

bool operator==(const Coord& l_coord, const Coord& r_coord){
    if (l_coord.get_x() == r_coord.get_x() && l_coord.get_y() == r_coord.get_y()){
        return true;
    }
    else{
        return false;
    }
}