//
// Created by Michał on 09.11.2022.
//

#ifndef GAMECHESSCORE_COORD_H
#define GAMECHESSCORE_COORD_H
#include <iostream>
#include <stdexcept>
#include <vector>


enum class Direction{
    up,
    down,
    right,
    left,
    right_up,
    right_down,
    left_up,
    left_down,
    undefined
};

class Coord {
private:
    int _x;
    int _y;
public:
    void set_x(int x) {_x = x;}
    void set_y(int y) {_y = y;}
    [[nodiscard]] int get_x() const {return _x;}
    [[nodiscard]] int get_y() const {return _y;}
    explicit Coord(int x = 1, int y = 1);
    bool is_equal(Coord& other) const;
    int x_axis_distance(Coord& other) const;
    int y_axis_distance(Coord& other) const;
    int is_diagonal(Coord& other) const;
    Direction get_direction(Coord& other) const;
    [[nodiscard]] Coord up() const;
    [[nodiscard]] Coord down() const;
    [[nodiscard]] Coord left() const;
    [[nodiscard]] Coord right() const;
    [[nodiscard]] Coord right_up() const;
    [[nodiscard]] Coord right_down() const;
    [[nodiscard]] Coord left_up() const;
    [[nodiscard]] Coord left_down() const;
    [[nodiscard]] Coord get_last_coord(Direction direction) const;
//    std::vector<Coord> get_coords_in_between(Coord& other) const;
};

#endif //GAMECHESSCORE_COORD_H
