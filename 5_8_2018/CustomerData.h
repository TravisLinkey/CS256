//
// Created by travis on 5/8/18.
//

#ifndef INC_5_8_2018_CUSTOMERDATA_H
#define INC_5_8_2018_CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData: public PersonData {
    int customerNumber;
    bool mailingList;

public:
    // Setters
    void set_customerNumber(int);
    void set_mailingList(bool);

    // Getters
    int get_customerNumber();
    bool get_mailingList();

};


#endif //INC_5_8_2018_CUSTOMERDATA_H
