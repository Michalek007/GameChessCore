#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "King.h"
#include "Square.h"
#include "Game.h"

//int char_to_int(const char digit) { return (int)digit - '0'; }

int main() {
//    std::string S {"213245123002"};
//    std::string result_str{};
//    int digit_number{0};
//    int counter{0};
//    std::map<int, int> numbers;
//    std::string str_number{};
//    for (char digit : S){
//        if (digit_number == counter){
//            digit_number = char_to_int(digit);
//            counter = 0;
//            if (!str_number.empty()){
//                numbers[digit_number] = std::stoi(str_number);
//            }
//
//            str_number.erase();
//            continue;
//        }
//        std::cout << digit << std::endl;
//        str_number.push_back(digit);
//        counter++;
//    }
//    numbers[digit_number] = std::stoi(str_number);
//    std::sort(numbers.begin(), numbers.end());
//    for (auto x : numbers){
//        std::cout << x.first << std::endl;
//        std::cout << x.second << std::endl;
//        result_str += std::to_string(x.first) + std::to_string(x.second);
//    }
//    std::cout << result_str << std::endl;
    King test {Color::white};
    Chessman* chessman = new King(Color::black);
    Color color = chessman->get_color();
    if (color == Color::white) {
        std::cout << "White" << std::endl;
    }
    else {
        std::cout << "Black" << std::endl;
    }
    //std::cout << &test << std::endl;
    //std::cout << chessman << std::endl;
    //std::cout << "Hello, World!" << std::endl;
    King* king = new King(Color::white);
//    auto* a1 = new Square(1, 1, king);
//    auto* a2 = new Square(1, 1);
//    //std::cout << a1->has_piece() << std::endl;
//    //std::cout << a2->has_piece() << std::endl;
//    //delete a1->get_piece();
//    std::cout << a1->get_piece() << std::endl;
//    delete a1;
//    auto* a3 = new Square(1, 1);
//    auto* a4 = new Square(1, 1);
//    std::cout << a1->get_piece() << std::endl;
//    std::cout << a1->has_piece() << std::endl;
    Coord start (1, 2);
    Coord end(1, 2);
    auto* x = (Chessman*) new King(Color::white);
    std::cout << x->is_legal(start, end) << std::endl;
    auto* game = new Game(Game::init());
    Coord a1 {1, 1};
    Coord a2 {1, 2};
    Coord c5 {3, 5};
    Coord c4 {3, 4};
    Coord c6 {3,6};
    Coord b5 {2, 5};
    Coord b4 {2, 4};
    Coord b6 {2, 6};
    Coord d5 {4, 5};
    Coord d4 {4, 4};
    Coord d6 {4, 6};
    game->make_move(a1, a2);
//    std::cout << c5.x_axis_distance(c4) << std::endl;
//    std::cout << c5.x_axis_distance(c6) << std::endl;
//    std::cout << c5.x_axis_distance(b5) << std::endl;
//    std::cout << c5.x_axis_distance(b4) << std::endl;
//    std::cout << c5.x_axis_distance(b6) << std::endl;
//    std::cout << c5.x_axis_distance(d4) << std::endl;
//    std::cout << c5.x_axis_distance(d5) << std::endl;
//    std::cout << c5.x_axis_distance(d6) << std::endl;
//    std::cout << c5.y_axis_distance(c4) << std::endl;
//    std::cout << c5.y_axis_distance(c6) << std::endl;
//    std::cout << c5.y_axis_distance(b5) << std::endl;
//    std::cout << c5.y_axis_distance(b4) << std::endl;
//    std::cout << c5.y_axis_distance(b6) << std::endl;
//    std::cout << c5.y_axis_distance(d4) << std::endl;
//    std::cout << c5.y_axis_distance(d5) << std::endl;
//    std::cout << c5.y_axis_distance(d6) << std::endl;
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
