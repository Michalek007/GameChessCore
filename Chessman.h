//
// Created by Michał on 07.11.2022.
//

#ifndef GAMECHESSCORE_CHESSMAN_H
#define GAMECHESSCORE_CHESSMAN_H

enum class Color{
    white = 1,
    black = 0
};

class Chessman {
private:
    Color _color;
public:
    explicit Chessman(Color color = Color::white): _color{color}{}
    [[nodiscard]] Color get_color() const {return _color;}
    virtual bool is_legal() = 0;
};


#endif //GAMECHESSCORE_CHESSMAN_H
