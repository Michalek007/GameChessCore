//
// Created by Michał on 09.11.2022.
//

#ifndef GAMECHESSCORE_COORD_H
#define GAMECHESSCORE_COORD_H
#include <iostream>
#include <stdexcept>

class Coord {
private:
    int _x;
    int _y;
public:
    [[nodiscard]] int get_x() const {return _x;}
    [[nodiscard]] int get_y() const {return _y;}
    void set_x(int x) {_x = x;}
    void set_y(int y) {_y = y;}
    explicit Coord(int x = 1, int y = 1);
    bool is_equal(Coord& other);
    int x_axis_distance(Coord& other);
    int y_axis_distance(Coord& other);
    int is_diagonal(Coord& other);
};

#endif //GAMECHESSCORE_COORD_H
