#include <iostream>
#include "King.h"

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
    return 0;
}
