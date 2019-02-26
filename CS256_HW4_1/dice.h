//
// Created by travis on 5/8/18.
//

#ifndef INC_1_DICE_H
#define INC_1_DICE_H

#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iostream>


class dice {
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 6;
    int showing;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;

public:
    dice();
    int roll();
    void test_distribution();
};


#endif //INC_1_DICE_H
