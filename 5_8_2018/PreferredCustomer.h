//
// Created by travis on 5/8/18.
//

#ifndef INC_5_8_2018_PREFERREDCUSTOMER_H
#define INC_5_8_2018_PREFERREDCUSTOMER_H


#include "CustomerData.h"

class PreferredCustomer : public CustomerData{
    double purchaseAmount;
    double discountLevel;

public:
    void set_purchaseAmount(double);
    void set_discountLevel(double);

    double get_purchaseAmount();
    double get_discountLevel();

    bool Input_Valid(double lower, double upper, double ans);
};


#endif //INC_5_8_2018_PREFERREDCUSTOMER_H
