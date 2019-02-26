//
// Created by travis on 5/8/18.
//

#include <iostream>
#include "PreferredCustomer.h"

void PreferredCustomer::set_purchaseAmount(double amount) {
    if(Input_Valid(0,10000,amount))
    {
        if(amount <= 500)
            set_discountLevel(0.05);
        else if(amount <= 1000)
            set_discountLevel(0.06);
        else if(amount <= 1500)
            set_discountLevel(0.07);
        else if(amount >= 2000)
            set_discountLevel(0.1);
    } else
        std::cout << "Incorrect purchase amount. Amount must be between [0-10000]\n";
}
void PreferredCustomer::set_discountLevel(double percent) {
    discountLevel = percent;
}
double PreferredCustomer::get_purchaseAmount() {
    return purchaseAmount;
}
double PreferredCustomer::get_discountLevel() {
    return discountLevel;
}
bool PreferredCustomer::Input_Valid(double lower, double upper, double ans) {
    if(ans >= lower && ans <= upper)
        return true;
    return false;
}
