//
// Created by travis on 5/9/18.
//

#ifndef CS256_HW4_3_SHIP_H
#define CS256_HW4_3_SHIP_H

#include <string>
#include <iostream>

using namespace std;

class Ship {
    string ship_name, year_built;

public:
    Ship(string,string);
    string get_name();
    string get_year_built();
    virtual void print();
};


#endif //CS256_HW4_3_SHIP_H
