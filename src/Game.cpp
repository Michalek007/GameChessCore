//
// Created by Michał on 10.11.2022.
//

#include "Game.h"

Game::Game(std::vector<std::vector<std::shared_ptr<Square>>>* board, Color turn){
    _board = board;
    _turn = turn;
    _game_record = new std::vector<std::map<std::string, std::string>>{};
}

void Game::change_turn(){
    if(_turn == Color::white){
        _turn = Color::black;
    }
    else{
        _turn = Color::white;
    }
}

std::shared_ptr<Square> Game::get_square(Coord& coord) const{
    return _board->at(coord.get_y()-1)[coord.get_x()-1];
}

std::shared_ptr<Chessman> Game::get_piece(Coord& coord) const{
    return get_square(coord)->get_piece();
}

bool Game::is_legal_override(Coord& start, Coord& end) const{
    std::shared_ptr<Chessman> piece = get_piece(start);
    if (piece == nullptr){
        return false;
    }
    if (piece->get_symbol() == "P"){
        if (!piece->is_legal(start, end)){
            return false;
        }
        if (piece->is_white()){
            if (start.get_x() == end.get_x()){
                if (get_square(end)->has_piece()){
                    if (get_piece(end)->is_white())
                        return false;
                }
            }
            if (!get_square(end)->has_piece()){
                return false;
            }
            if (get_piece(end)->is_white()){
                return false;
            }
            return true;
        }
        else{
            if (start.get_x() == end.get_x()){
                if (get_square(end)->has_piece()){
                    if (!get_piece(end)->is_white())
                        return false;
                }
            }
            if (!get_square(end)->has_piece()){
                return false;
            }
            if (!get_piece(end)->is_white()){
                return false;
            }
            return true;
        }
    }
    else{
        return piece->is_legal(start, end);
    }
}

bool Game::is_legal(Coord& start, Coord& end) {
    if (!is_legal_override(start, end)){
        return false;
    }
//    if (!get_piece(start)->is_legal(start, end)){
//        return false;
//    }
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
    if (get_piece(start)->is_white()){
        if (can_be_captured(_white_king)){
            return false;
        }
    }
    else{
        if(can_be_captured(_black_king)){
            return false;
        }
    }
    // undo move
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

bool Game::can_be_captured(Coord& start) const{
    std::vector<Coord> end_coords {
            start.get_last_coord(Direction::up),
            start.get_last_coord(Direction::down),
            start.get_last_coord(Direction::right),
            start.get_last_coord(Direction::down),
            start.get_last_coord(Direction::right_up),
            start.get_last_coord(Direction::right_down),
            start.get_last_coord(Direction::left_up),
            start.get_last_coord(Direction::left_down)};
    for (auto &end: end_coords){
        Direction direction = start.get_direction(end);
        switch (direction){
            case Direction::up:
                for(int i = 0; i < 8-start.get_y(); i++){
                    Coord iter = start.up();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::down:
                for(int i = 0; i < start.get_y()-1; i++){
                    Coord iter = start.down();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::right:
                for(int i = 0; i < 8-start.get_x(); i++){
                    Coord iter = start.right();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::left:
                for(int i = 0; i < start.get_x()-1; i++){
                    Coord iter = start.left();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::right_up:
                for(int i = 0; i < start.x_axis_distance(end); i++){
                    Coord iter = start.right_up();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::right_down:
                for(int i = 0; i < start.x_axis_distance(end); i++){
                    Coord iter = start.right_down();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::left_up:
                for(int i = 0; i < start.x_axis_distance(end); i++){
                    Coord iter = start.left_up();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::left_down:
                for(int i = 0; i < start.x_axis_distance(end); i++){
                    Coord iter = start.left_down();
                    if (get_square(iter)->get_piece() != nullptr){
                        if (is_legal_override(iter, start)){
                            return true;
                        }
                    }
                }
            case Direction::undefined:
                return true;
        }
    }
    std::map<int , int> l_values {{1, 2}, {1, -2}, {2, 1}, {2, -1},
                                  {-1, 2}, {-1, -2}, {-2 , 1}, {-2 , -1}};
    for (auto value: l_values){
        try{
            Coord l_coord {start.get_x() + value.first, start.get_y() + value.second};
            if (get_square(l_coord)->has_piece()){
                if (get_piece(l_coord)->get_symbol() == "N"){
                    return true;
                }
            }
        }
        catch (const std::invalid_argument& err){
            continue;
        }
    }
    return false;
}

void Game::make_move(Coord& start, Coord& end){
    std::shared_ptr<Square> begin = get_square(start);
    std::shared_ptr<Square> dest = get_square(end);
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
        change_turn();
        // TODO: pawn promotion when at the 1st or 8th line
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

std::shared_ptr<Chessman> Game::decode_piece(std::string piece) const{
    // TODO: color as argument, static method
    if (piece.empty()){
        return nullptr;
    }
    Color color = get_turn();
    if (color == Color::white){
        color = Color::black;
    }
    else{
        color = Color::white;
    }
    switch (piece[0]) {
        case 'K':
            return std::make_shared<King>(color);
        case 'Q':
            return std::make_shared<Queen>(color);
        case 'B':
            return std::make_shared<Bishop>(color);
        case 'N':
            return std::make_shared<Knight>(color);
        case 'R':
            return std::make_shared<Rook>(color);
        case 'P':
            return std::make_shared<Pawn>(color);
    }
    return nullptr;
}

Coord Game::decode_coord(std::string coord){
    int x = (int)coord[0] - '0';
    int y = (int)coord[1] - '0';
    Coord result_coord {x, y};
    return result_coord;
}

std::vector<std::vector<std::shared_ptr<Square>>>* Game::init(){
    std::shared_ptr<Square> a1 (new Square(1, 1, std::make_shared<Rook>()));
    std::shared_ptr<Square> a2  (new Square(1, 2, std::make_shared<Knight>()));
    std::shared_ptr<Square> a3  (new Square(1, 3, std::make_shared<Bishop>()));
    std::shared_ptr<Square> a4  (new Square(1, 4, std::make_shared<King>()));
    std::shared_ptr<Square> a5  (new Square(1, 5, std::make_shared<Queen>()));
    std::shared_ptr<Square> a6  (new Square(1, 6, std::make_shared<Bishop>()));
    std::shared_ptr<Square> a7  (new Square(1, 7, std::make_shared<Knight>()));
    std::shared_ptr<Square> a8  (new Square(1, 8, std::make_shared<Rook>()));
    std::shared_ptr<Square> b1  (new Square(2, 1, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b2  (new Square(2, 2, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b3  (new Square(2, 3, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b4  (new Square(2, 4, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b5  (new Square(2, 5, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b6  (new Square(2, 6, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b7  (new Square(2, 7, std::make_shared<Pawn>()));
    std::shared_ptr<Square> b8  (new Square(2, 8, std::make_shared<Pawn>()));
    std::shared_ptr<Square> c1  (new Square(3, 1));
    std::shared_ptr<Square> c2  (new Square(3, 2));
    std::shared_ptr<Square> c3  (new Square(3, 3));
    std::shared_ptr<Square> c4  (new Square(3, 4));
    std::shared_ptr<Square> c5  (new Square(3, 5));
    std::shared_ptr<Square> c6  (new Square(3, 6));
    std::shared_ptr<Square> c7  (new Square(3, 7));
    std::shared_ptr<Square> c8  (new Square(3, 8));
    std::shared_ptr<Square> d1  (new Square(4, 1));
    std::shared_ptr<Square> d2  (new Square(4, 2));
    std::shared_ptr<Square> d3  (new Square(4, 3));
    std::shared_ptr<Square> d4  (new Square(4, 4));
    std::shared_ptr<Square> d5  (new Square(4, 5));
    std::shared_ptr<Square> d6  (new Square(4, 6));
    std::shared_ptr<Square> d7  (new Square(4, 7));
    std::shared_ptr<Square> d8  (new Square(4, 8));
    std::shared_ptr<Square> e1  (new Square(5, 1));
    std::shared_ptr<Square> e2  (new Square(5, 2));
    std::shared_ptr<Square> e3  (new Square(5, 3));
    std::shared_ptr<Square> e4  (new Square(5, 4));
    std::shared_ptr<Square> e5  (new Square(5, 5));
    std::shared_ptr<Square> e6  (new Square(5, 6));
    std::shared_ptr<Square> e7  (new Square(5, 7));
    std::shared_ptr<Square> e8  (new Square(5, 8));
    std::shared_ptr<Square> f1  (new Square(6, 1));
    std::shared_ptr<Square> f2  (new Square(6, 2));
    std::shared_ptr<Square> f3  (new Square(6, 3));
    std::shared_ptr<Square> f4  (new Square(6, 4));
    std::shared_ptr<Square> f5  (new Square(6, 5));
    std::shared_ptr<Square> f6  (new Square(6, 6));
    std::shared_ptr<Square> f7  (new Square(6, 7));
    std::shared_ptr<Square> f8  (new Square(6, 8));
    std::shared_ptr<Square> g1  (new Square(7, 1, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g2  (new Square(7, 2, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g3  (new Square(7, 3, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g4  (new Square(7, 4, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g5  (new Square(7, 5, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g6  (new Square(7, 6, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g7  (new Square(7, 7, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> g8  (new Square(7, 8, std::make_shared<Pawn>(Color::black)));
    std::shared_ptr<Square> h1  (new Square(8, 1, std::make_shared<Rook>(Color::black)));
    std::shared_ptr<Square> h2  (new Square(8, 2, std::make_shared<Knight>(Color::black)));
    std::shared_ptr<Square> h3  (new Square(8, 3, std::make_shared<Bishop>(Color::black)));
    std::shared_ptr<Square> h4  (new Square(8, 4, std::make_shared<King>(Color::black)));
    std::shared_ptr<Square> h5  (new Square(8, 5, std::make_shared<Queen>(Color::black)));
    std::shared_ptr<Square> h6  (new Square(8, 6, std::make_shared<Bishop>(Color::black)));
    std::shared_ptr<Square> h7  (new Square(8, 7, std::make_shared<Knight>(Color::black)));
    std::shared_ptr<Square> h8  (new Square(8, 8, std::make_shared<Rook>(Color::black)));

    std::vector<std::shared_ptr<Square>> row1 {a1, a2, a3 ,a4, a5, a6, a7, a8};
    std::vector<std::shared_ptr<Square>> row2 {b1, b2, b3 ,b4, b5, b6, b7, b8};
    std::vector<std::shared_ptr<Square>> row3 {c1, c2, c3 ,c4, c5, c6, c7, c8};
    std::vector<std::shared_ptr<Square>> row4 {d1, d2, d3 ,d4, d5, d6, d7, d8};
    std::vector<std::shared_ptr<Square>> row5 {e1, e2, e3 ,e4, e5, e6, e7, e8};
    std::vector<std::shared_ptr<Square>> row6 {f1, f2, f3 ,f4, f5, f6, f7, f8};
    std::vector<std::shared_ptr<Square>> row7 {g1, g2, g3 ,g4, g5, g6, g7, g8};
    std::vector<std::shared_ptr<Square>> row8 {h1, h2, h3 ,h4, h5, h6, h7, h8};

    auto* board = new std::vector<std::vector<std::shared_ptr<Square>>> {row1, row2, row3, row4, row5, row6, row7, row8};
    return board;
}

void Game::print(){
    for (auto &vec: *_board){
        for (auto &square: vec){
            if (square->has_piece()){
                std::cout << square->get_piece()->get_symbol();
            }
            else{
                std::cout << ".";
            }
        }
        std::cout << " " << std::endl;
    }
}
