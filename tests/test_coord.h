//
// Created by Michał on 19.12.2022.
//

#ifndef GAMECHESSCORE_TEST_COORD_H
#define GAMECHESSCORE_TEST_COORD_H

#include <cassert>
#include "Coord.h"


bool test1(){
    Coord t1 {1, 1};
    Coord t2 {4, 4};
    return t1.is_diagonal(t2);
}

bool test2(){
    Coord t1 {1, 1};
    Coord t2 {4, 2};
    return !t1.is_diagonal(t2);
}


#endif //GAMECHESSCORE_TEST_COORD_H
