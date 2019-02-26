//
// Created by tlinkey on 5/15/18.
//

#include <iostream>
#include "Parent.h"

Parent::Parent() : Human() {};
Parent::Parent(string name, int age, char sex) : Human(name,age,sex) {};

void Parent::set_child(Child child) {
    this->children.push_back(child);
}
void Parent::get_child() {
    for (int i = 0; i < 2; ++i) {
        cout << this->children.pop_off();
    }
}

void Parent::set_work(string w) {
    this->work = w;
}
