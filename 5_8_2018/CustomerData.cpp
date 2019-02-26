//
// Created by travis on 5/8/18.
//

#include "CustomerData.h"

// Setters
void CustomerData::set_customerNumber(int cN) {
    customerNumber = cN;
}
void CustomerData::set_mailingList(bool mL) {
    mailingList = mL;
}

// Getters
int CustomerData::get_customerNumber() {
    return customerNumber;
}
bool CustomerData::get_mailingList() {
    return mailingList;
}
