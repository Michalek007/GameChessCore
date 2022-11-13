//
// Created by Michał on 08.11.2022.
//

#include "Square.h"

bool Square::has_piece(){
    if (_piece == nullptr){
        return false;
    }
    else{
        return true;
    }
}
void Square::set_null() {
    _piece = nullptr;
}
void Square::capture_piece() {
    delete _piece;
    set_null();
}

std::string Square::get_piece_symbol() const{
    return _piece->get_symbol();
}

std::string Square::get_coord_symbol() const{
    return std::to_string(get_x()) + std::to_string(get_y());
}
