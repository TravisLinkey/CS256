//
// Created by travis on 5/9/18.
//

#include "Ship.h"

Ship::Ship(string name, string yr) {
    ship_name = name;
    year_built = yr;
}

string Ship::get_name() {
    return ship_name;
}

string Ship::get_year_built() {
    return year_built;
}

void Ship::print() {
    std::cout << "Ship name: " << get_name() << "\n";
    std::cout << "Year build: " << get_year_built() << "\n";
}

