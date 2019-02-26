//
// Created by tlinkey on 5/22/18.
//

#include <queue>
#include "ProductionWorker.h"

ProductionWorker::ProductionWorker(const string &name, int number, int date, int shift, double hourly_rate)
        : Employee(name, number, date),
          shift(shift), hourly_rate(hourly_rate) {}

// setters
void ProductionWorker::set_shift(int s) {
    shift = s;
}
void ProductionWorker::set_hourly_rate(double r) {
    hourly_rate = r;
}

// getters
int ProductionWorker::get_shift() {
    return shift;
}
double ProductionWorker::get_hourly_rate() {
    return hourly_rate;
}

// Misc
void ProductionWorker::print_info() {
    Employee::print_info();
    printf("Shift number: %d\n", get_shift());
    printf("Hourly rate: %.2f\n", get_hourly_rate());
}
