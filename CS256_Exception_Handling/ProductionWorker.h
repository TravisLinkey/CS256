//
// Created by tlinkey on 5/22/18.
//

#ifndef EXCEPTION_HANDLING_PRODUCTIONWORKER_H
#define EXCEPTION_HANDLING_PRODUCTIONWORKER_H


#include "Employee.h"

class ProductionWorker : public Employee{
    int shift;
    double hourly_rate;

public:

    ProductionWorker(const string &, int, int, int shift, double hourly_rate);
    void print_info();

    // setters
    void set_shift(int);
    void set_hourly_rate(double);

    // getters
    int get_shift();
    double get_hourly_rate();
};


#endif //EXCEPTION_HANDLING_PRODUCTIONWORKER_H
