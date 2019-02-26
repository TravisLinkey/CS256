//
// Created by travis on 5/9/18.
//

#ifndef CS256_HW4_3_CARGOSHIP_H
#define CS256_HW4_3_CARGOSHIP_H


#include "Ship.h"

class CargoShip : public Ship {
    int cargo_capacity;

public:
    CargoShip(string,string,int);
    void set_cargo_capacity(int);
    int get_cargo_capacity();
    void print();
};


#endif //CS256_HW4_3_CARGOSHIP_H
