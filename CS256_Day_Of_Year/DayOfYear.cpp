//
// Created by travis on 5/2/18.
//

#include "DayOfYear.h"
DayOfYear::DayOfYear(int day){
    setMonth(day);
}
void DayOfYear::setMonth(int day) {
    static const int Days[] = {31,59,120,151,181,212,243,273,304,334,365};
    static const std::string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    input = day;

    if(day < Days[0])
    {
        currentmonth = Months[0];
        currentday = day;
    }
    else if(day < Days[1])
    {
        currentmonth = Months[1];
        currentday =  day - Days[0];
    }
    else if(day < Days[2])
    {
        currentmonth = Months[2];
        currentday =  day - Days[1];
    }
    else if(day < Days[3])
    {
        currentmonth = Months[4];
        currentday =  day - Days[2];
    }
    else if(day < Days[4])
    {
        currentmonth = Months[5];
        currentday =  day - Days[3];
    }
    else if(day < Days[5])
    {
        currentmonth = Months[6];
        currentday =  day - Days[4];
    }
    else if(day < Days[6])
    {
        currentmonth = Months[7];
        currentday =  day - Days[5];
    }
    else if(day < Days[7])
    {
        currentmonth = Months[8];
        currentday =  day - Days[6];
    }
    else if(day < Days[8])
    {
        currentmonth = Months[9];
        currentday =  day - Days[7];
    }
    else if(day < Days[9])
    {
        currentmonth = Months[10];
        currentday =  day - Days[8];
    }
    else if(day <= Days[10])
    {
        currentmonth = Months[11];
        currentday =  day - Days[9];
    }
    print();
}
void DayOfYear::print() {
    std::cout << "Day " << input << " would be "<< currentmonth << " " <<  currentday << std::endl << std::endl;
}
bool DayOfYear::outsideRange(int day) {
    if(day < 0 || day > 30)
        return true;
    return false;
}
