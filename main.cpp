#include <iostream>
#include <vector>
#include "King.h"
#include "Square.h"

int main() {
    King test {Color::white};
    Chessman* chessman = new King(Color::black);
    Color color = chessman->get_color();
    if (color == Color::white) {
        std::cout << "White" << std::endl;
    }
    else {
        std::cout << "Black" << std::endl;
    }
    std::cout << &test << std::endl;
    std::cout << chessman << std::endl;
    std::cout << "Hello, World!" << std::endl;
    King* king = new King(Color::white);
    auto* a1 = new Square(1, 1, king);
    auto* a2 = new Square(1, 1);
    std::cout << a1->has_piece() << std::endl;
    std::cout << a2->has_piece() << std::endl;
    delete a1->get_piece();
    std::cout << a1->get_piece() << std::endl;
    std::cout << a1->has_piece() << std::endl;
    Coord c5 {3, 5};
    Coord c4 {3, 4};
    Coord c6 {3,6};
    Coord b5 {2, 5};
    Coord b4 {2, 4};
    Coord b6 {2, 6};
    Coord d5 {4, 5};
    Coord d4 {4, 4};
    Coord d6 {4, 6};
    std::cout << c5.x_axis_distance(c4) << std::endl;
    std::cout << c5.x_axis_distance(c6) << std::endl;
    std::cout << c5.x_axis_distance(b5) << std::endl;
    std::cout << c5.x_axis_distance(b4) << std::endl;
    std::cout << c5.x_axis_distance(b6) << std::endl;
    std::cout << c5.x_axis_distance(d4) << std::endl;
    std::cout << c5.x_axis_distance(d5) << std::endl;
    std::cout << c5.x_axis_distance(d6) << std::endl;
    std::cout << c5.y_axis_distance(c4) << std::endl;
    std::cout << c5.y_axis_distance(c6) << std::endl;
    std::cout << c5.y_axis_distance(b5) << std::endl;
    std::cout << c5.y_axis_distance(b4) << std::endl;
    std::cout << c5.y_axis_distance(b6) << std::endl;
    std::cout << c5.y_axis_distance(d4) << std::endl;
    std::cout << c5.y_axis_distance(d5) << std::endl;
    std::cout << c5.y_axis_distance(d6) << std::endl;
//    while(true){
//        int x = 0;
//        int y = 0;
//        std::cin >> x;
//        std::cin >> y;
//        try{
//            Coord coord{x, y};
//        }
//        catch (const std::invalid_argument& err){
//            continue;
//        }
//        break;
//    }
//    if (*a1 == *a2){
//        std::cout << "true" << std::endl;
//    }
    return 0;
}
