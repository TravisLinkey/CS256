//
// Created by travis on 5/9/18.
//

#include "CruiseShip.h"

CruiseShip::CruiseShip(string name, string yr, int capacity) : Ship(name,yr) {
    max_capacity = capacity;
}
void CruiseShip::set_capacity(int capacity) {
    max_capacity = capacity;
}
int CruiseShip::get_capacity() {
    return max_capacity;
}
void CruiseShip::print() {
    std::cout << "Ship name: " << get_name() << "\n";
    std::cout << "Max capacity: " << get_capacity() << " humans"<< "\n";
}
