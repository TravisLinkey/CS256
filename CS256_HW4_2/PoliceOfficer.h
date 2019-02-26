//
// Created by travis on 5/8/18.
//

#ifndef INC_2_POLICEOFFICER_H
#define INC_2_POLICEOFFICER_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include <string>

using namespace std;

class PoliceOfficer {
    string name, badge_number;

public:
    PoliceOfficer(const string name, const string badge_number);
    void generate_ticket(ParkedCar *pCar);
    bool check_time_expired(ParkedCar &car, ParkingMeter &meter);
};


#endif //INC_2_POLICEOFFICER_H
