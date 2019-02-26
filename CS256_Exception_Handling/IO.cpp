//
// Created by tlinkey on 5/22/18.
//

#include <iostream>
#include "IO.h"
#include "ProductionWorker.h"


void IO::start_program() {
    bool input_valid = false;
    bool again = false;
    int type;

    do{
        do{
            try{
                type = ask_employee_type();
            } catch(IO::InvalidEmployeeType) {
                printf("Invalid Employee type!\nPlease enter a 1 or 2\n");
            }

            switch(type)
            {
                case 1:
                {
                    try {
                        employee = new Employee(ask_name().c_str(),ask_number(),ask_hire_date());
                        input_valid = true;
                        employee->print_info();
                        break;
                    } catch(InvalidEmployeeNumber) {
                        printf("Employee number invalid! Must be between 0 - 9999\n\n");
                        break;
                    }
                }
                case 2:
                {
                    try {
                        employee = new ProductionWorker(ask_name(),ask_number(),ask_hire_date(),ask_pay_rate(),ask_shift());
                        input_valid = true;
                        employee->print_info();
                        break;
                    } catch (InvalidEmployeeNumber) {
                        printf("Employee number invalid! Must be between 0 - 9999\n\n");
                        break;
                    } catch (InvalidPayRate) {
                        printf("Invalid Pay Rate!\n\n");
                        break;
                    } catch (InvalidShift) {
                        printf("Invalid Shift!\n\n");
                        break;
                    }
                }
            }
        }while(!input_valid);

        try{
            again = ask_done();
        } catch(IO::InvalidQuitInput) {
            printf("Invalid user input. Please enter 1 or 2");
            break;
        }
    } while(again);

    delete employee;

}
string IO::ask_name() {
    string name;
    printf("Enter employee name: \n");
    cin >> name;

    return name;
}
int IO::ask_number() {
    int number;
    printf("Enter employee number: \n");
    scanf("%d", &number);

    if(number < 0 || number > 9999)
        throw InvalidEmployeeNumber();

    return number;
}
int IO::ask_hire_date() {
    int date;
    printf("Enter employee start date: \n");
    scanf("%d", &date);

    return date;
}
int IO::ask_shift() {
    int shift;
    printf("Enter employee shift number: \n");
    scanf("%d", &shift);

    if(shift == 1 || shift ==2 )
        return shift;
    else
        throw InvalidShift();
}
double IO::ask_pay_rate() {
    double rate;
    printf("Enter employee hourly rate: \n");
    scanf("%f", &rate);

    if(rate < 0)
        throw InvalidPayRate();

    return rate;
}
int IO::ask_employee_type() {
    int type;
    printf("Enter Employee type:\n\t1.Employee\n\t2.Production Worker\n");
    scanf("%d", &type);

    return type;
}
bool IO::ask_done() {
    int ans;
    printf("Would you like to create another employee?\n\t1.Yes\n\t2.No\n");
    scanf("%d", &ans);

    if(ans == 1)
        return true;

    return false;
}
