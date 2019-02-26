//
// Created by tlinkey on 5/15/18.
//

#ifndef MIDTERM_PARENT_H
#define MIDTERM_PARENT_H

#include <vector>
#include "Human.h"
#include "Child.h"

class Parent : public Human {
    friend class Child;

private:
    vector<Child> children();

public:
    Parent();
    Parent(string,int,char);
    void set_name(Child &,string);
    void set_child(Child);
    void get_child();
    void set_work(string);
};


#endif //MIDTERM_PARENT_H
