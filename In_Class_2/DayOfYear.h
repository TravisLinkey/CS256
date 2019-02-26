//
// Created by travis on 5/3/18.
//

#ifndef IN_CLASS_2_DAYOFYEAR_H
#define IN_CLASS_2_DAYOFYEAR_H

#include <string>
#include <iostream>

class DayOfYear {
private:
    int currentday;
    int input;
    std::string currentmonth;
    static const int Days[];
    static const std::string Months[];

public:
    // Constructors
    DayOfYear(int day);
    DayOfYear(std::string month, int day);

    // Overloaded functions
    DayOfYear & operator -- (); // Prefix
    DayOfYear operator -- (int); // Postfix
    DayOfYear & operator ++ (); // Prefix
    DayOfYear operator ++ (int); // Postfix

    // Setters
    void setMonth(int);

    // Print Functions
    void print();
    void print2();

    // Check Functions
    bool outsideRange(int day);
    bool outsideRange2(int day);
    bool checkFebruary(std::string,int);
    bool checkShortMonth(std::string,int);
    bool checkLongMonth(std::string,int);

    // Misc Functions
    int returnPreviousMonth(std::string month);
    bool checkEdgeCase(int day);
    void setEdgeDate(int day);

    int returnNextMonth(std::string basic_string);
};

#endif //IN_CLASS_2_DAYOFYEAR_H
