#include <iostream>
#include "PoliceOfficer.h"

int main() {

    // Create an instance of an Officer
    PoliceOfficer cop("Officer Nima", "123456");

    // Create an instance of a Parking Meter for Josie
    ParkingMeter meter1;
    ParkingMeter meter2;
    ParkingMeter meter3;

    // Create an instance of a Car
    ParkedCar josieCar("Accent","Hyundai", "Gold", "5KEA250", 50);
    meter1.set_time(30);

    // Create another instance of a Car
    ParkedCar travisCar("3.5RL","Accura", "White", "548KI95", 10);
    meter2.set_time(30);

    // Create another instance of a Car
    ParkedCar joshCar("Accord","Honda", "Black", "NLD784H", 135);
    meter3.set_time(15);

    // Cop checks the meters
    cop.check_time_expired(josieCar,meter1);
    cop.check_time_expired(travisCar,meter2);
    cop.check_time_expired(joshCar,meter3);

    return 0;
}