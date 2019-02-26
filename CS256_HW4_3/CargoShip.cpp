//
// Created by travis on 5/9/18.
//

#include "CargoShip.h"

CargoShip::CargoShip(string name, string yr, int cargo) : Ship(name,yr){
    cargo_capacity = cargo;
}
void CargoShip::set_cargo_capacity(int cargo) {
    cargo_capacity = cargo;
}
int CargoShip::get_cargo_capacity() {
    return cargo_capacity;
}
void CargoShip::print() {
    std::cout << "Ship name: " << get_name() << "\n";
    std::cout << "Max cargo weight: " << get_cargo_capacity() << " tons"<< "\n";
}
