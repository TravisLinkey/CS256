//
// Created by travis on 5/8/18.
//

#include <iostream>
#include "PersonData.h"

// I/O
void PersonData::print_info() {
    std::cout << "Printing Customer Info: \n";
    std::cout << "\tFirst Name: " << this->get_firstName() << "\n";
    std::cout << "\tLast Name: " << this->get_lastName() << "\n";
    std::cout << "\tAddress: " << this->get_address() << "\n";
    std::cout << "\tCity: " << this->get_city() << "\n";
    std::cout << "\tState: " << this->get_state() << "\n";
    std::cout << "\tZip: " << this->get_zip() << "\n";
    std::cout << "\tPhone: " << this->get_phone() << "\n";
}

// Setters
void PersonData::set_lastName(string lname) {
    lastName = lname;
}
void PersonData::set_firstName(string fname) {
    firstName = fname;
}
void PersonData::set_address(string add) {
    address = add;
}
void PersonData::set_city(string c) {
    city = c;
}
void PersonData::set_state(string s) {
    state = s;
}
void PersonData::set_zip(string z) {
    zip = z;
}
void PersonData::set_phone(string ph) {
    phone = ph;
}

// Getters
string PersonData::get_lastName() {
    return lastName;
}
string PersonData::get_firstName() {
    return firstName;
}
string PersonData::get_address() {
    return address;
}
string PersonData::get_city() {
    return city;
}
string PersonData::get_state() {
    return state;
}
string PersonData::get_zip() {
    return zip;
}
string PersonData::get_phone() {
    return phone;
}

