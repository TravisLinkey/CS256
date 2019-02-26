//
// Created by travis on 5/2/18.
//

#include "DayOfYear.h"

// Constructors
DayOfYear::DayOfYear(int day){
    input = day;
    setMonth(day);
}
DayOfYear::DayOfYear(std::string month, int day) {
    if(checkFebruary(month,day))
    {
        input = day;
        currentday = day;
        currentmonth = month;
        print2();
    }
    else if (month == "February"){
        std::cout << "Date outside of range!\n";
        std::cout << month <<" has 28 days" << ", you input " << day << "\n";
        std::cout << "Please input a day between 0 - 28\n";
        std::cout << "\n";
    }

    if(checkShortMonth(month,day))
    {
        input = day;
        currentday = day;
        currentmonth = month;
        print2();
    } else if(month == "April" ||
            month =="June" ||
            month == "September" ||
            month =="November") {
        std::cout << "Date outside of range!\n";
        std::cout << month <<" has 30 days" << ", you input " << day << "\n";
        std::cout << "Please input a day between 0 - 30\n";
        std::cout << "\n";
    }

    if(checkLongMonth(month,day))
    {
        input = day;
        currentday = day;
        currentmonth = month;
        print2();
    }
    else if (month=="January" ||
            month=="March" ||
            month=="May" ||
            month=="July" ||
            month=="August" ||
            month=="October" ||
            month=="December" ) {
        std::cout << "Date outside of range!\n";
        std::cout << month <<" has 31 days" << ", you input " << day << "\n";
        std::cout << "Please input a day between 0 - 31\n";
        std::cout << "\n";
    }
}

// Overloaded Operations
DayOfYear& DayOfYear::operator++() {
    if(this->currentmonth == "December" && this->currentday == 31)
    {
        std::cout << "Resetting Year!\n";
        setMonth(1);
    }
    else
    {
        if(checkEdgeCase(this->currentday))
        {
            int date = returnNextMonth(this->currentmonth);
            input = currentday;
            setMonth(date);
        }
        else
        {
            std::cout << "After Pre-Increment ";
            input = currentday;
            setMonth(currentday+1);
        }
    }
}
DayOfYear DayOfYear::operator++(int) {
    if(this->currentmonth == "December" && this->currentday == 31)
    {
        std::cout << "Resetting Year!\n";
        setMonth(1);
    }
    else
    {
        if(checkEdgeCase(this->currentday))
        {
            int date = returnNextMonth(this->currentmonth);
            input = currentday;
            setMonth(date);
        }
        else
        {
            std::cout << "After Post-Increment ";
            input = currentday;
            setMonth(currentday+1);
        }
    }
    return input;
}
DayOfYear& DayOfYear::operator--() {
    if(this->currentmonth == "January" && this->currentday == 1)
    {
        std::cout << "Resetting Year!\n";
        setMonth(365);
    }
    else
    {
        if(checkEdgeCase(this->currentday))
        {
            int date = returnPreviousMonth(this->currentmonth);
            input = currentday;
            setMonth(date+currentday-1);
        }
        else
        {
            std::cout << "After Pre-Decrement ";
            input = currentday;
            setMonth(currentday-1);
        }

    }
}
DayOfYear DayOfYear::operator--(int) {
    int oldValue;

    if(this->currentmonth == "January" && this->currentday == 1)
    {
        std::cout << "Resetting Year!\n";
        setMonth(365);
    }
    else
    {
        if(checkEdgeCase(this->input))
        {
            int date = returnPreviousMonth(this->currentmonth);
            std::cout << "After Post-Decrement ";
            oldValue = currentday;
            setMonth(date+currentday-1);
        }
        else
        {
            std::cout << "After Post-Decrement ";
            oldValue = currentday;
            setMonth(input-1);
        }
    }
    return oldValue;
}

// Setters
void DayOfYear::setMonth(int day) {
    static const int Days[] = {31,59,120,151,181,212,243,273,304,334,365};
    static const std::string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if(checkEdgeCase(day))
        setEdgeDate(day);
    else{
        if(day <= Days[0])
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
            currentmonth = Months[3];
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
        else if(day > Days[10])
        {
            std::cout << "Sorry, input greater than 365 is rejected.\n\n";
            return;
        }
    }
}

// Printing Functions
void DayOfYear::print() {
    std::cout << "Day " << input << " would be "<< currentmonth << " " <<  currentday << std::endl << std::endl;
}
void DayOfYear::print2() {
    std::cout << "Date is: "<< currentmonth << " " <<  currentday << std::endl << std::endl;
}

// Check Functions
bool DayOfYear::outsideRange(int day) {
    if(day < 0 || day > 30)
        return true;
    return false;
}
bool DayOfYear::outsideRange2(int day) {
    if(day < 0 || day > 31)
        return true;
    return false;
}
bool DayOfYear::checkFebruary(std::string month, int day) {
    // returns true if the date is okay
     if(month =="February" && (day > 0 && day < 29))
         return true;
    return false;
}
bool DayOfYear::checkShortMonth(std::string month, int day) {
    // returns true if the date is okay
    if((month == "April" ||
            month =="June" ||
            month == "September" ||
            month =="November") &&
            !outsideRange(day))
        return true;
    return false;
}
bool DayOfYear::checkLongMonth(std::string month, int day) {
    // returns true if the date is okay
    if((month=="January" ||
            month=="March" ||
            month=="May" ||
            month=="July" ||
            month=="August" ||
            month=="October" ||
            month=="December" )&&!outsideRange2(day))
        return true;
    return false;
}

// Misc Functions
int DayOfYear::returnPreviousMonth(std::string month) {
    static const int Days[] = {31,59,120,151,181,212,243,273,304,334,365,90};
    static const std::string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // return previous month
    if(month == Months[0])
        return Days[10];
    else if(month == Months[1])
        return 0;
    else if(month == Months[2])
        return Days[11];
    else if(month == Months[3])
        return Days[1];
    else if(month == Months[4])
        return Days[2];
    else if(month == Months[5])
        return Days[3];
    else if(month == Months[6])
        return Days[4];
    else if(month == Months[7])
        return Days[5];
    else if(month == Months[8])
        return Days[6];
    else if(month == Months[9])
        return Days[7];
    else if(month == Months[10])
        return Days[8];
}
int DayOfYear::returnNextMonth(std::string month) {
    static const int Days[] = {31,59,120,151,181,212,243,273,304,334,365,90};
    static const std::string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // return previous month
    if(month == Months[0])
        return Days[0]+1;
    else if(month == Months[1])
        return Days[1]+1;
    else if(month == Months[2])
        return Days[11]+1;
    else if(month == Months[3])
        return Days[2]+1;
    else if(month == Months[4])
        return Days[3]+1;
    else if(month == Months[5])
        return Days[4]+1;
    else if(month == Months[6])
        return Days[5]+1;
    else if(month == Months[7])
        return Days[6]+1;
    else if(month == Months[8])
        return Days[7]+1;
    else if(month == Months[9])
        return Days[8]+1;
    else if(month == Months[10])
        return Days[9]+1;
}
bool DayOfYear::checkEdgeCase(int day) {
    static const int Days[] = {31,59,120,151,181,212,243,273,304,334,365,90};

    if(day == Days[0] || day == Days[1] || day == Days[2] || day == Days[3] || day == Days[4] || day == Days[5] || day == Days[6] ||
            day == Days[7] || day == Days[8] || day == Days[9] || day == Days[10] || day == Days[11])
        return true;
    return false;
}
void DayOfYear::setEdgeDate(int day) {

    switch(day)
    {
        case 31:
        {
            currentday = 31;
            currentmonth = "January";
            break;
        }
        case 59:
        {
            currentday = 28;
            currentmonth = "February";
            break;
        }
        case 90:
        {
            currentday = 31;
            currentmonth = "March";
            break;
        }
        case 120:
        {
            currentday = 30;
            currentmonth = "April";
            break;

        }
        case 151:
        {
            currentday = 31;
            currentmonth = "May";
            break;
        }
        case 181:
        {
            currentday = 30;
            currentmonth = "June";
            break;
        }
        case 212:
        {
            currentday = 31;
            currentmonth = "July";
            break;
        }
        case 243:
        {
            currentday = 31;
            currentmonth = "August";
            break;
        }
        case 273:
        {
            currentday = 30;
            currentmonth = "September";
            break;
        }
        case 304:
        {
            currentday = 31;
            currentmonth = "October";
            break;
        }
        case 334:
        {
            currentday = 30;
            currentmonth = "November";
            break;
        }
        case 365:
        {
            currentday = 31;
            currentmonth = "December";
            break;
        }
    }

}

