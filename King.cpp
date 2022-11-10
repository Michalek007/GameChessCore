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
//    else if (start.get_x() == end.get_x() && start.get_y() + 1 == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() == end.get_x() && start.get_y() - 1 == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() + 1 == end.get_x() && start.get_y() == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() - 1 == end.get_x() && start.get_y() == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() + 1 == end.get_x() && start.get_y() + 1 == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() + 1 == end.get_x() && start.get_y() - 1 == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() - 1 == end.get_x() && start.get_y() + 1 == end.get_y()){
//        return true;
//    }
//    else if (start.get_x() - 1 == end.get_x() && start.get_y() - 1 == end.get_y()){
//        return true;
//    }
//    else{
//        return false;
//    }
}
