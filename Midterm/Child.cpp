//
// Created by tlinkey on 5/15/18.
//

#include "Child.h"

Child::Child(Human& mom, Human& dad) {
    this->Mom = mom;
    this->Dad = dad;
};

void Child::set_work(string w) {
    this->work = w;
}

