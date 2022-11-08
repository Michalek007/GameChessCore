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
    Chessman* king = new King(Color::white);
    auto* a1 = new Square(1, 1, king);
    auto* a2 = new Square(1, 2);
    std::cout << a1->has_piece() << std::endl;
    std::cout << a2->has_piece() << std::endl;
    return 0;
}
