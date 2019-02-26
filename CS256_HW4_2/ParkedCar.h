//
// Created by travis on 5/8/18.
//

#ifndef INC_2_PARKEDCAR_H
#define INC_2_PARKEDCAR_H

#include <iostream>
#include <string>

using namespace std;

class ParkedCar {
    string make, model, color, license_number;
    int minutes_parked;

public:
    ParkedCar(const string make,const string model,const string color,const string license_number, int minutes_parked);
    string get_make();
    string get_model();
    string get_color();
    string get_license_number();
    int get_minutes_parked();
};


#endif //INC_2_PARKEDCAR_H
