//
// Created by Michał on 07.11.2022.
//
#include "King.h"

bool King::is_legal(Coord& start, Coord& end){
    if (start.get_x() == end.get_x() && start.get_y() == end.get_y()){
        return false;
    }
    else if (start.get_x() == end.get_x() && start.get_y() == end.get_y() + 1){
        return true;
    }
    else if (start.get_x() == end.get_x() && start.get_y() == end.get_y() - 1){
        return true;
    }
    else if (start.get_x() == end.get_x() + 1 && start.get_y() == end.get_y()){
        return true;
    }
    else if (start.get_x() == end.get_x() - 1 && start.get_y() == end.get_y()){
        return true;
    }
    else if (start.get_x() == end.get_x() + 1 && start.get_y() == end.get_y() + 1){
        return true;
    }
    else if (start.get_x() == end.get_x() + 1 && start.get_y() == end.get_y() - 1){
        return true;
    }
    else if (start.get_x() == end.get_x() - 1 && start.get_y() == end.get_y() + 1){
        return true;
    }
    else if (start.get_x() == end.get_x() - 1 && start.get_y() == end.get_y() - 1){
        return true;
    }
    else{
        return false;
    }
}

bool King::is_white(){
    if (get_color() == Color::white){
        return true;
    }
    else {
        return false;
    }
}
