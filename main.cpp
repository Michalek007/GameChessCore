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
//    King test {Color::white};
//    Chessman* chessman = new King(Color::black);
//    Color color = chessman->get_color();
//    if (color == Color::white) {
//        std::cout << "White" << std::endl;
//    }
//    else {
//        std::cout << "Black" << std::endl;
//    }
//    Coord start (1, 2);
//    Coord end(1, 2);
//    auto* x = (Chessman*) new King(Color::white);
//    std::cout << x->is_legal(start, end) << std::endl;
//    auto* game = new Game();
//    Coord a1 {1, 1};
//    Coord a2 {1, 2};
//    Coord c5 {3, 5};
//    Coord c4 {3, 4};
//    Coord c6 {3,6};
//    Coord b5 {2, 5};
//    Coord b4 {2, 4};
//    Coord b6 {2, 6};
//    Coord d5 {4, 5};
//    Coord d4 {4, 4};
//    Coord d6 {4, 6};
//    a1.set_x(1);
//    game->make_move(a1, a2);
//    return 0;
    auto* game = new Game();
    std::string start_str {};
    std::string end_str {};
    game->print();
    while (true){
        try{
            std::cin >> start_str;
            std::cin >> end_str;
            Coord start {Game::decode_coord(start_str)};
            Coord end {Game::decode_coord(end_str)};
            if (game->is_legal(start, end)){
                game->make_move(start, end);
                game->print();
            }
            else{
                continue;
            }
        }
        catch (const std::invalid_argument&){
            continue;
        }
    }
}
