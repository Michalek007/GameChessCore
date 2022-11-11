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

bool Coord::is_equal(Coord& other) const{
    if (get_x() == other.get_x() && get_y() == other.get_y()){
        return true;
    }
    else{
        return false;
    }
}

int Coord::x_axis_distance(Coord& other) const{
    return abs(get_x() - other.get_x());
}

int Coord::y_axis_distance(Coord& other) const{
    return abs(get_y() - other.get_y());
}

int Coord::is_diagonal(Coord& other) const{
    if (x_axis_distance(other) == y_axis_distance(other)){
        return true;
    }
    return false;
}

Direction Coord::get_direction(Coord& other) const{
    if (is_equal(other)){
        return Direction::undefined;
    }
    if (get_x() == other.get_x()){
        if (get_y() > other.get_y()){
            return Direction::down;
        }
        else{
            return Direction::up;
        }
    }
    if (get_y() == other.get_y()){
        if (get_x() > other.get_x()){
            return Direction::left;
        }
        else{
            return Direction::right;
        }
    }
    if (!is_diagonal(other)){
        return Direction::undefined;
    }
    if (get_x() > other.get_x() && get_y() > other.get_y()){
        return Direction::left_down;
    }
    if (get_x() < other.get_x() && get_y() < other.get_y()){
        return Direction::right_up;
    }
    if (get_x() > other.get_x() && get_y() < other.get_y()){
        return Direction::left_up;
    }
    if (get_x() < other.get_x() && get_y() > other.get_y()){
        return Direction::right_down;
    }
    return Direction::undefined;
}

//std::vector<Coord> Coord::get_coords_in_between(Coord& other) const{
//    return std::vector<Coord>{};
//}
