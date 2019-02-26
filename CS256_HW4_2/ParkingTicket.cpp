//
// Created by travis on 5/8/18.
//

#include <iostream>
#include "ParkingTicket.h"


ParkingTicket::ParkingTicket(const string &officer_name,
                             const string &badge_number,
                             const string &make,
                             const string &model,
                             const string &color,
                             const string &license_number,
                             const int minutes)
        : officer_name(officer_name),
          badge_number(badge_number),
          car_make(make),
          car_model(model),
          car_color(color),
          car_license_number(license_number),
          minutes_parked(minutes){
    calculate_fine(minutes);
}

void ParkingTicket::calculate_fine(const int minutes) {
    total_fine = 10*(minutes/60) + 25;
}

void ParkingTicket::display_info() {
    std::cout << "\n>>>> Printing Ticket Info <<<<\n";

    std::cout << ">>>OFFICER INFO";
    std::cout << "\n Officer Name: "
            << this->officer_name
            << "\n Badge Number: "
              << this->badge_number << "\n\n";
    std::cout << ">>>CAR INFO"
            << "\n Make: "
            << this->car_make
            << "\n Model: "
            << this->car_model
            << "\n Color: "
            << this->car_color
            << "\n License Plate Num: "
            << this->car_license_number
            << "\n Minutes Parked: "
            << this->minutes_parked
            << "\n Total Fine: $"
            << this->total_fine << "\n\n";

}

