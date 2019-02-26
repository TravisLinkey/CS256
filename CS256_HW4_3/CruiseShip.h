//
// Created by travis on 5/9/18.
//

#ifndef CS256_HW4_3_CRUISESHIP_H
#define CS256_HW4_3_CRUISESHIP_H


#include "Ship.h"

class CruiseShip : public Ship{
    int max_capacity;

public:
    CruiseShip(string,string,int);
    void set_capacity(int);
    int get_capacity();
    void print();
};


#endif //CS256_HW4_3_CRUISESHIP_H
