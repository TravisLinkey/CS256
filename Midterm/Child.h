//
// Created by tlinkey on 5/15/18.
//

#ifndef MIDTERM_CHILD_H
#define MIDTERM_CHILD_H


#include "Human.h"
#include "Parent.h"

class Child : public Human {
private:
    Human *Mom, *Dad;
    Child();

public:
    Child(Human&, Human&);
    void set_work(string);
};


#endif //MIDTERM_CHILD_H
