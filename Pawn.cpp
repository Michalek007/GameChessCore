//
// Created by Michał on 08.11.2022.
//

#include "Pawn.h"

bool Pawn::is_legal(Coord& start, Coord& end){
    if (start.is_equal(end)){
        return false;
    }
    if (is_white()){
        if (start.get_x() == end.get_x()){
            if (start.get_y() + 1 == end.get_y()){
                return true;
            }
            if (start.get_y() + 2 == end.get_y()){
                return true;
            }
        }
        else{
            if (start.get_y() + 1 == end.get_y()){
                if (start.get_x() - 1 == end.get_x()){
                    return true;
                }
                if (start.get_x() + 1 == end.get_x()){
                    return true;
                }
            }
        }
        return false;
    }
    else{
        if (start.get_x() == end.get_x()){
            if (start.get_y() - 1 == end.get_y()){
                return true;
            }
            if (start.get_y() - 2 == end.get_y()){
                return true;
            }
        }
        else{
            if (start.get_y() - 1 == end.get_y()){
                if (start.get_x() - 1 == end.get_x()){
                    return true;
                }
                if (start.get_x() + 1 == end.get_x()){
                    return true;
                }
            }
        }
        return false;
    }
}