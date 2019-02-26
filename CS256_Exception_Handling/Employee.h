//
// Created by tlinkey on 5/22/18.
//

#ifndef EXCEPTION_HANDLING_EMPLOYEE_H
#define EXCEPTION_HANDLING_EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
public:

    Employee(const string &name, int employee_number, int hire_date);
    virtual void print_info();

    // getters
    string get_name();
    int get_number();
    int get_hire_date();

    // setters
    void set_name(const string);
    void set_number(int);
    void set_hire_date(int);

private:
    string name;
    int employee_number;
    int hire_date;
};


#endif //EXCEPTION_HANDLING_EMPLOYEE_H
