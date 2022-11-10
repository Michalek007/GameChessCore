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

Coord::Coord(int x, int y){
    if (x < 1 || x > 8 || y < 1 || y > 8){
        throw std::invalid_argument("Coordinates must have value from 1:8.");
    }
    else{
        _x = x;
        _y = y;
    }
}

bool Coord::is_equal(Coord& other){
    if (get_x() == other.get_x() && get_y() == other.get_y()){
        return true;
    }
    else{
        return false;
    }
}

int Coord::x_axis_distance(Coord& other){
    return abs(get_x() - other.get_x());
}

int Coord::y_axis_distance(Coord& other){
    return abs(get_y() - other.get_y());
}

int Coord::is_diagonal(Coord& other){
    if (x_axis_distance(other) == y_axis_distance(other)){
        return true;
    }
    return false;
}
