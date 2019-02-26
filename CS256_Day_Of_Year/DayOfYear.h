//
// Created by travis on 5/2/18.
//

#ifndef IN_CLASS_1_DAYOFYEAR_H
#define IN_CLASS_1_DAYOFYEAR_H

#include <string>
#include <iostream>

class DayOfYear {
private:
    int currentday;
    int input;
    std::string currentmonth;
    static int Days[];
    static std::string Months[];

public:
    DayOfYear(int day);
    void setMonth(int);
    void print();
    bool outsideRange(int day);
};

#endif //IN_CLASS_1_DAYOFYEAR_H
