//
// Created by Michał on 10.11.2022.
//

#include "Game.h"

Game::Game(std::vector<std::vector<Square*>>* board, Color turn){
    _board = board;
    _turn = turn;
}

std::vector<std::vector<Square*>>* Game::init(){
    auto* a1 = new Square(1, 1);
    auto* a2 = new Square(1, 2);
    auto* a3 = new Square(1, 3);
    auto* a4 = new Square(1, 4);
    auto* a5 = new Square(1, 5);
    auto* a6 = new Square(1, 6);
    auto* a7 = new Square(1, 7);
    auto* a8 = new Square(1, 8);
    auto* b1 = new Square(2, 1);
    auto* b2 = new Square(2, 2);
    auto* b3 = new Square(2, 3);
    auto* b4 = new Square(2, 4);
    auto* b5 = new Square(2, 5);
    auto* b6 = new Square(2, 6);
    auto* b7 = new Square(2, 7);
    auto* b8 = new Square(2, 8);
    std::vector<Square*> row1 {a1, a2, a3 ,a4, a5, a6, a7, a8};
    std::vector<Square*> row2 {b1, b2, b3 ,b4, b5, b6, b7, b8};
    auto* board = new std::vector<std::vector<Square*>>{row1, row2};
    return board;
}

Square* Game::get_square(Coord& coord){
    return _board->at(coord.get_x())[coord.get_y()];
}

Chessman* Game::get_piece(Coord& coord){
    return get_square(coord)->get_piece();
}

bool Game::is_legal(Coord& start, Coord& end){
    // check if there is same color piece at the end position
    if (get_square(end)->has_piece()){
        if (get_piece(start)->get_color() == get_piece(end)->get_color())
            return false;
    }
    // check obstacles
    Direction direction = start.get_direction(end);
    switch (direction){
        case Direction::up:
            for(int i = start.get_y() + 1; i < end.get_y(); i++){
                Coord iter{start.get_x(), i};
                if (get_square(iter)->get_piece() != nullptr){
                    return false;
                }
            }
        case Direction::down:
            for(int i = start.get_y() - 1; i > end.get_y(); i--){
                Coord iter{start.get_x(), i};
                if (get_square(iter)->get_piece() != nullptr){
                    return false;
                }
            }
        case Direction::right:
            break;
        case Direction::left:
            break;
        case Direction::right_up:
            break;
        case Direction::right_down:
            break;
        case Direction::left_up:
            break;
        case Direction::left_down:
            break;
        case Direction::undefined:
            return false;
    }
    // make move and check if king is under attack
    if (get_piece(start)->is_legal(start, end)){
        return true;
    }
    else{
        return false;
    }
}

void Game::make_move(Coord& start, Coord& end){
    Square* begin = get_square(start);
    Square* dest = get_square(end);
    if (begin->has_piece()){
        dest->kill_piece();
        dest->set_piece(begin->get_piece());
        begin->set_null();
    }
}
