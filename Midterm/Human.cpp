//
// Created by tlinkey on 5/15/18.
//

#include "Human.h"


// setters
void Human::set_name(string n) {
    this->name = n;
}
void Human::set_age(int a) {
    this->age = a;
}
void Human::set_sex(char s) {
    this->sex = s;
}

// getters
string Human::get_name() {
    return name;
}
int Human::get_age() {
    return age;
}
char Human::get_sex() {
   return sex;
}
