//
// Created by tlinkey on 5/22/18.
//

#ifndef EXCEPTION_HANDLING_IO_H
#define EXCEPTION_HANDLING_IO_H

#include <string>
#include "Employee.h"

using namespace std;

class IO {
    Employee *employee;
    /*Exception Classes*/
    class InvalidEmployeeNumber{};
    class InvalidEmployeeType {};
    class InvalidQuitInput {};
    class InvalidShift {};
    class InvalidPayRate {};

    string ask_name();
    int ask_number();
    int ask_hire_date();
    int ask_shift();
    double ask_pay_rate();
    int ask_employee_type();
    bool ask_done();

public:
    void start_program();
};


#endif //EXCEPTION_HANDLING_IO_H
