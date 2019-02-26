#include <iostream>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

int main() {
    Ship *ship_array[6] = {
            new Ship("Benjamin","1992"),
            new Ship("Tony","1950"),
            new CruiseShip("Josie","1996",500),
            new CruiseShip("Yuan","1965",1200),
            new CargoShip("Beauregard","1200", 6500),
            new CargoShip("Travis","1991", 4500),
    };

    std::cout << ">>> Printing Ship Info <<<\n";
    for(int i = 0; i <=5 ; i++)
    {
        std::cout << "\n";
        ship_array[i]->print();
    }

    return 0;
}