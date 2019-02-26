//
// Created by tlinkey on 5/15/18.
//

#ifndef MIDTERM_HUMAN_H
#define MIDTERM_HUMAN_H

#include <string>

using namespace std;

class Human {
    friend class Child;
    friend class Parent;
private:
    string name;
    int age;
    char sex;
    Human();

protected:
    string work;
    Human(string name,int age, char sex);

public:
    void set_name(string);
    void set_age(int);
    void set_sex(char);

    string get_name();
    int get_age();
    char get_sex();

    virtual void set_work();
    virtual string get_work();
};


#endif //MIDTERM_HUMAN_H
