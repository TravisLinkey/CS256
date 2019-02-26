//
// Created by tlinkey on 5/26/18.
//

#include <iostream>
#include "IO.h"

/** Method to set the input BigNumbers into private variables */
void IO::set_numbers() {
    bool inputvalid = false;


    printf("Please enter an integer value for Number 1: \n");
    do{
        try {
            number1 = BigNumbers(get_numbers());
            inputvalid = false;
        } catch (NonIntegerValue) {
            printf("Input must be integer value. Removing character. \n");
            inputvalid = true;
        } catch (NegativeValue) {
            printf("Input must be positive \n");
            inputvalid = true;
        }
    }while(inputvalid);


    printf("Please enter an integer value for Number 2: \n");
    do{
        try {
            number2 = BigNumbers(get_numbers());
            inputvalid = false;
        } catch (NonIntegerValue) {
            printf("Input must be integer value. Removing character. \n");
            inputvalid = true;
        } catch (NegativeValue) {
            printf("Input must be positive \n");
            inputvalid = true;
        }
    }while(inputvalid);


}
/** Method to get the input BigNumbers */
std::vector<int> IO::get_numbers() {
    char current;
    char input[10000];
    int size = 0;

    while((std::cin.peek()) != '\n') {
        scanf("%c", &current);
        if(not_int(current))
            throw NonIntegerValue();
        input[size] = current;
        size++;
    }

    std::cin.ignore(10000, '\n');

    return vectorify(input,size);
}
/** Method to take integer array and return it as a vector */
std::vector<int> IO::vectorify(char ints[], int size) {
    vector<int> newvector;

    for (int i = 0; i < size; ++i) {
        int newint = int(ints[i])-48;
        newvector.insert(newvector.end(),newint);
    }

    newvector.resize(size);

    return newvector;
};
/** Method to return private vector from class */
std::vector<int> IO::get_vector(int num) {
    if (num ==1)
        return number1.numbers_vector;
    else if(num == 2)
        return number2.numbers_vector;
    else
        throw InvalidVector();
}

// Misc
/** Method to check if input character is an integer */
bool IO::not_int(char current) {
    if(current >= 48 && current <= 57)
        return false;
    return true;
}

/** Method to get user input operation */
int IO::get_operation() {
    int ans;
    printf("Please select what operation you would like to perform. \n");
    printf("[1] Addition \n");
    printf("[2] Subtraction \n");
    printf("[3] Multiplication \n");
    printf("[4] Division \n");
    printf("[5] Modulus \n");
    printf("[0] Quit \n");

    cin >> ans;

    if(cin.fail())
        throw NonIntegerValue();
    if(ans < 0 || ans > 5)
        throw InvalidRange();

    std::cin.ignore(10000, '\n');

    return ans;
}


