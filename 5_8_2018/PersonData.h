//
// Created by travis on 5/8/18.
//

#ifndef INC_5_8_2018_PERSONDATA_H
#define INC_5_8_2018_PERSONDATA_H

#include <string>

using namespace std;

class PersonData {
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
public:
    void set_lastName(string);
    void set_firstName(string);
    void set_address(string);
    void set_city(string);
    void set_state(string);
    void set_zip(string);
    void set_phone(string);

    string get_lastName();
    string get_firstName();
    string get_address();
    string get_city();
    string get_state();
    string get_zip();
    string get_phone();

    void print_info();

};


#endif //INC_5_8_2018_PERSONDATA_H
