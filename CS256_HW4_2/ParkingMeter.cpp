//
// Created by travis on 5/8/18.
//

#include "ParkingMeter.h"


void ParkingMeter::set_time(int time_purchased) {
    this->time_purchased = time_purchased;
}

int ParkingMeter::get_time_purchased() {
    return time_purchased;
}
