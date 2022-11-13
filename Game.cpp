//
// Created by Michał on 10.11.2022.
//

#include "Game.h"

Game::Game(std::vector<std::vector<Square*>>* board, Color turn){
    _board = board;
    _turn = turn;
    _game_record = new std::vector<std::map<std::string, std::string>>{};
}

Square* Game::get_square(Coord& coord) const{
    return _board->at(coord.get_x())[coord.get_y()];
}

Chessman* Game::get_piece(Coord& coord) const{
    return get_square(coord)->get_piece();
}

bool Game::is_legal(Coord& start, Coord& end) {
    if (!get_piece(start)->is_legal(start, end)){
        return false;
    }
    // check if there is same color piece at the end position
    if (get_square(end)->has_piece()){
        if (get_piece(start)->get_color() == get_piece(end)->get_color())
            return false;
    }
    // check obstacles
    if (piece_between(start, end)){
        return false;
    }
    // make move and check if king is under attack
    make_move(start, end);
    undo_last_move();
    return true;
}

bool Game::piece_between(Coord& start, Coord& end) const{
    if (start.is_equal(end)){
        return false;
    }
    if (!start.is_diagonal(end)){
        return false;
    }
    if (start.x_axis_distance(end) < 2 && start.y_axis_distance(end) < 2){
        return false;
    }
    Direction direction = start.get_direction(end);
    switch (direction){
        case Direction::up:
            for(int i = 0; i < start.y_axis_distance(end); i++){
                Coord iter = start.up();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::down:
            for(int i = 0; i < start.y_axis_distance(end); i++){
                Coord iter = start.down();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::right:
            for(int i = 0; i < start.x_axis_distance(end); i++){
                Coord iter = start.right();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::left:
            for(int i = 0; i < start.x_axis_distance(end); i++){
                Coord iter = start.left();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::right_up:
            for(int i = 0; i < start.x_axis_distance(end); i++){
                Coord iter = start.right_up();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::right_down:
            for(int i = 0; i < start.x_axis_distance(end); i++){
                Coord iter = start.right_down();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::left_up:
            for(int i = 0; i < start.x_axis_distance(end); i++){
                Coord iter = start.left_up();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::left_down:
            for(int i = 0; i < start.x_axis_distance(end); i++){
                Coord iter = start.left_down();
                if (get_square(iter)->get_piece() != nullptr){
                    return true;
                }
            }
        case Direction::undefined:
            return false;
    }
    return true;
}

//bool Game::can_be_captured(Coord& start) const{
//        for(int i = 0; i < start.y_axis_distance(end); i++){
//            Coord iter = start.up();
//            if (get_square(iter)->get_piece() != nullptr){
//                if (get_square(iter)->get_piece()->is_white()){
//                    break;
//                }
//                else{
//
//                }
//            }
//        }
//        for(int i = 0; i < start.y_axis_distance(end); i++){
//            Coord iter = start.down();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//        for(int i = 0; i < start.x_axis_distance(end); i++){
//            Coord iter = start.right();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//        for(int i = 0; i < start.x_axis_distance(end); i++){
//            Coord iter = start.left();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//        for(int i = 0; i < start.x_axis_distance(end); i++){
//            Coord iter = start.right_up();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//        for(int i = 0; i < start.x_axis_distance(end); i++){
//            Coord iter = start.right_down();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//        for(int i = 0; i < start.x_axis_distance(end); i++){
//            Coord iter = start.left_up();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//        for(int i = 0; i < start.x_axis_distance(end); i++){
//            Coord iter = start.left_down();
//            if (get_square(iter)->get_piece() != nullptr){
//                return false;
//            }
//        }
//}

void Game::make_move(Coord& start, Coord& end){
    Square* begin = get_square(start);
    Square* dest = get_square(end);
    std::string taken{};
    if (begin->has_piece()){
        if (begin->get_piece()->get_symbol() == "K"){
            if (get_turn() == Color::white){
                _white_king = end;
            }
            else{
                _black_king = end;
            }
            begin->get_piece()->has_moved = true;
        }
        if (begin->get_piece()->get_symbol() == "R"){
            begin->get_piece()->has_moved = true;
        }
        if (dest->has_piece()){
            taken = dest->get_piece_symbol();
        }
        dest->capture_piece();
        dest->set_piece(begin->get_piece());
        begin->set_null();
        set_last_move(begin->get_coord_symbol(), dest->get_coord_symbol(), taken);
    }
}

void Game::set_last_move(std::string start, std::string end, std::string taken){
    std::map<std::string, std::string> move {};
    move["start"] = std::move(start);
    move["end"] = std::move(end);
    move["taken"] = std::move(taken);
    _game_record->push_back(move);
}

std::map<std::string, std::string> Game::get_last_move(){
    return _game_record->back();
}

void Game::undo_last_move(){
    std::map<std::string, std::string> last_move = get_last_move();
    Coord start = decode_coord(last_move["start"]);
    Coord end = decode_coord(last_move["end"]);
    get_square(start)->set_piece(get_square(end)->get_piece());
    get_square(end)->set_piece(decode_piece(last_move["taken"]));
}

Chessman* Game::decode_piece(std::string piece){
    if (piece.empty()){
        return nullptr;
    }
    switch (piece[0]) {
        case 'K':
            return new King();
        case 'Q':
            return new Queen();
        case 'B':
            return new Bishop();
        case 'N':
            return new Knight();
        case 'R':
            return new Rook();
        case 'P':
            return new Pawn();
    }
    return nullptr;
}

Coord Game::decode_coord(std::string coord){
    int x = (int)coord[0] - '0';
    int y = (int)coord[1] - '0';
    Coord result_coord {x, y};
    return result_coord;
}

std::vector<std::vector<Square*>>* Game::init(){
    auto* a1 = new Square(1, 1, new Rook());
    auto* a2 = new Square(1, 2, new Knight());
    auto* a3 = new Square(1, 3, new Bishop());
    auto* a4 = new Square(1, 4, new King());
    auto* a5 = new Square(1, 5, new Queen());
    auto* a6 = new Square(1, 6, new Bishop());
    auto* a7 = new Square(1, 7, new Knight());
    auto* a8 = new Square(1, 8, new Rook());
    auto* b1 = new Square(2, 1, new Pawn());
    auto* b2 = new Square(2, 2, new Pawn());
    auto* b3 = new Square(2, 3, new Pawn());
    auto* b4 = new Square(2, 4, new Pawn());
    auto* b5 = new Square(2, 5, new Pawn());
    auto* b6 = new Square(2, 6, new Pawn());
    auto* b7 = new Square(2, 7, new Pawn());
    auto* b8 = new Square(2, 8, new Pawn());
    auto* c1 = new Square(3, 1);
    auto* c2 = new Square(3, 2);
    auto* c3 = new Square(3, 3);
    auto* c4 = new Square(3, 4);
    auto* c5 = new Square(3, 5);
    auto* c6 = new Square(3, 6);
    auto* c7 = new Square(3, 7);
    auto* c8 = new Square(3, 8);
    auto* d1 = new Square(4, 1);
    auto* d2 = new Square(4, 2);
    auto* d3 = new Square(4, 3);
    auto* d4 = new Square(4, 4);
    auto* d5 = new Square(4, 5);
    auto* d6 = new Square(4, 6);
    auto* d7 = new Square(4, 7);
    auto* d8 = new Square(4, 8);
    auto* e1 = new Square(5, 1);
    auto* e2 = new Square(5, 2);
    auto* e3 = new Square(5, 3);
    auto* e4 = new Square(5, 4);
    auto* e5 = new Square(5, 5);
    auto* e6 = new Square(5, 6);
    auto* e7 = new Square(5, 7);
    auto* e8 = new Square(5, 8);
    auto* f1 = new Square(6, 1);
    auto* f2 = new Square(6, 2);
    auto* f3 = new Square(6, 3);
    auto* f4 = new Square(6, 4);
    auto* f5 = new Square(6, 5);
    auto* f6 = new Square(6, 6);
    auto* f7 = new Square(6, 7);
    auto* f8 = new Square(6, 8);
    auto* g1 = new Square(7, 1, new Pawn(Color::black));
    auto* g2 = new Square(7, 2, new Pawn(Color::black));
    auto* g3 = new Square(7, 3, new Pawn(Color::black));
    auto* g4 = new Square(7, 4, new Pawn(Color::black));
    auto* g5 = new Square(7, 5, new Pawn(Color::black));
    auto* g6 = new Square(7, 6, new Pawn(Color::black));
    auto* g7 = new Square(7, 7, new Pawn(Color::black));
    auto* g8 = new Square(7, 8, new Pawn(Color::black));
    auto* h1 = new Square(8, 1, new Rook(Color::black));
    auto* h2 = new Square(8, 2, new Knight(Color::black));
    auto* h3 = new Square(8, 3, new Bishop(Color::black));
    auto* h4 = new Square(8, 4, new King(Color::black));
    auto* h5 = new Square(8, 5, new Queen(Color::black));
    auto* h6 = new Square(8, 6, new Bishop(Color::black));
    auto* h7 = new Square(8, 7, new Knight(Color::black));
    auto* h8 = new Square(8, 8, new Rook(Color::black));
    std::vector<Square*> row1 {a1, a2, a3 ,a4, a5, a6, a7, a8};
    std::vector<Square*> row2 {b1, b2, b3 ,b4, b5, b6, b7, b8};
    std::vector<Square*> row3 {c1, c2, c3 ,c4, c5, c6, c7, c8};
    std::vector<Square*> row4 {d1, d2, d3 ,d4, d5, d6, d7, d8};
    std::vector<Square*> row5 {e1, e2, e3 ,e4, e5, e6, e7, e8};
    std::vector<Square*> row6 {f1, f2, f3 ,f4, f5, f6, f7, f8};
    std::vector<Square*> row7 {g1, g2, g3 ,g4, g5, g6, g7, g8};
    std::vector<Square*> row8 {h1, h2, h3 ,h4, h5, h6, h7, h8};
    auto* board = new std::vector<std::vector<Square*>>{row1, row2, row3, row4, row5, row6, row7, row8};
    return board;
}
