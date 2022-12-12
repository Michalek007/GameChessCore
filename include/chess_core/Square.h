//
// Created by Michał on 08.11.2022.
//

#ifndef GAMECHESSCORE_SQUARE_H
#define GAMECHESSCORE_SQUARE_H
#include <utility>

#include "Chessman.h"
#include "Coord.h"


class Square: private Coord {
private:
    std::shared_ptr<Chessman> _piece;
public:
    [[nodiscard]] std::shared_ptr<Chessman> get_piece() const {return _piece;}
    void set_piece(std::shared_ptr<Chessman> piece) {_piece = std::move(piece);}
    explicit Square(int x = 1, int y = 1, std::shared_ptr<Chessman> piece=nullptr): Coord(x, y), _piece{std::move(piece)}{}
    bool has_piece();
    void set_null();
    void capture_piece();
    [[nodiscard]] std::string get_piece_symbol() const;
    [[nodiscard]] std::string get_coord_symbol() const;
};

#endif //GAMECHESSCORE_SQUARE_H
