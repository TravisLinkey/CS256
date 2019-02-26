//
// Created by travis on 5/8/18.
//

#include "ParkedCar.h"

ParkedCar::ParkedCar(const string make, const string model, const string color, const string license_number, int minutes_parked)
        : make(make), model(model), color(color), license_number(license_number), minutes_parked(minutes_parked) {}

string ParkedCar::get_make() {
    return make;
}

string ParkedCar::get_model() {
    return model;
}

string ParkedCar::get_color() {
    return color;
}

string ParkedCar::get_license_number() {
    return license_number;
}

int ParkedCar::get_minutes_parked() {
    return minutes_parked;
}
