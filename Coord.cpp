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

Coord Coord::up() const{
    Coord coord{get_x(), get_y()+1};
    return coord;
}

Coord Coord::down() const{
    Coord coord{get_x(), get_y()-1};
    return coord;
}

Coord Coord::left() const{
    Coord coord{get_x()-1, get_y()};
    return coord;
}

Coord Coord::right() const{
    Coord coord{get_x()+1, get_y()};
    return coord;
}

Coord Coord::right_up() const{
    Coord coord{get_x()+1, get_y()+1};
    return coord;
}

Coord Coord::right_down() const{
    Coord coord{get_x()+1, get_y()-1};
    return coord;
}

Coord Coord::left_up() const{
    Coord coord{get_x()-1, get_y()+1};
    return coord;
}

Coord Coord::left_down() const{
    Coord coord{get_x()-1, get_y()-1};
    return coord;
}

Coord Coord::get_last_coord(Direction direction) const {
    switch (direction) {
        case Direction::up:{
            Coord up{get_x(), 8};
            return up;
        }
        case Direction::down:{
            Coord down{get_x(), 1};
            return down;
        }
        case Direction::right:{
            Coord right{8, get_y()};
            return right;
        }
        case Direction::left:{
            Coord left{1, get_y()};
            return left;
        }
        case Direction::right_up:{
            int value{0};
            if (get_y() >= get_x()){
                value = 8 - get_y();
            }
            else{
                value = 8 - get_x();
            }
            Coord right_up {get_x() + value, get_y() + value};
            return right_up;
        }
        case Direction::right_down:{
            int value{0};
            if (get_y() >= 0 ){
                value = get_x()-1;
            }
            else{
                value = get_y()-1;
            }
            Coord right_up {get_x()-value, get_y() - value};
            return right_up;
        }
        case Direction::left_up:{
            int value{0};
            if (get_y() >= 0 ){
                value = get_x()-1;
            }
            else{
                value = get_y()-1;
            }
            Coord right_up {get_x()-value, get_y() - value};
            return right_up;
        }
        case Direction::left_down:{
            int value{0};
            if (get_y() >= get_x() ){
                value = get_x()-1;
            }
            else{
                value = get_y()-1;
            }
            Coord right_up {get_x()-value, get_y() - value};
            return right_up;
        }
        case Direction::undefined:{
            Coord undefined{};
            return undefined;
        }
    }
}

//std::vector<Coord> Coord::get_coords_in_between(Coord& other) const{
//    return std::vector<Coord>{};
//}
