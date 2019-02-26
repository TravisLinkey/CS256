//
// Created by travis on 5/8/18.
//

#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(const string name, const string badge_number) : name(name), badge_number(badge_number) {}

bool PoliceOfficer::check_time_expired(ParkedCar &car, ParkingMeter &meter) {
    if(car.get_minutes_parked() > meter.get_time_purchased())
        generate_ticket(&car);
}

void PoliceOfficer::generate_ticket(ParkedCar *pCar) {
    std::cout << "Generating Parking Ticket. . .\n";
    ParkingTicket parkingTicket(this->name,
                                this->badge_number,
                                pCar->get_make(),
                                pCar->get_model(),
                                pCar->get_color(),
                                pCar->get_license_number(),
                                pCar->get_minutes_parked());
    parkingTicket.display_info();
}
