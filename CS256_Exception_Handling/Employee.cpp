//
// Created by tlinkey on 5/22/18.
//

#include "Employee.h"

Employee::Employee(const string &name, int employee_number, int hire_date)
        : name(name), employee_number(employee_number),hire_date(hire_date) {}

// getters
string Employee::get_name() {
    return name;
}
int Employee::get_number() {
    return employee_number;
}
int Employee::get_hire_date() {
    return hire_date;
}

// setters
void Employee::set_name(const string n) {
    name = n;
}
void Employee::set_number(int num) {
    employee_number = num;
}
void Employee::set_hire_date(int date) {
    hire_date = date;
}

// Misc
void Employee::print_info() {
    printf("Name: %s\n", get_name().c_str());
    printf("Employee ID: %d\n", get_number());
    printf("Hire Date: %d\n\n", get_hire_date());
}
