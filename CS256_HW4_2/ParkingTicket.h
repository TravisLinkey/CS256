//
// Created by travis on 5/8/18.
//

#ifndef INC_2_PARKINGTICKET_H
#define INC_2_PARKINGTICKET_H

#include <string>

using namespace std;

class ParkingTicket {

private:
    string officer_name, badge_number, car_make, car_model, car_color, car_license_number;
    int minutes_parked;

    const int first_hour_fine = 25;
    const int additional_hour_fine = 10;
    int total_fine;
public:
    ParkingTicket(const string &officer_name, const string &badge_number, const string &make, const string &model,
                  const string &color, const string &license_number, const int minutes_parked);
    void calculate_fine(const int minutes);

    void display_info();
};


#endif //INC_2_PARKINGTICKET_H
