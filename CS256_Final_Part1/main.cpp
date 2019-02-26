/**
 * \class Main
 *
 * \brief Main Class
 *
 * \author $Author:Travis Linkey $
 *
 * \date $Date: 2018/05/31 $
 *
 */

#include <iostream>
#include "BigNumbers.h"
#include "IO.h"

int main() {
    IO user_input;
    bool done = false;
    BigNumbers bigNumbers1;
    BigNumbers bigNumbers2;

    do{
        bigNumbers1.negative = false;
        bigNumbers2.negative = false;
        int op;
        user_input.set_numbers();
        try{
            op = user_input.get_operation();
            bigNumbers1.numbers_vector = user_input.get_vector(1);
            bigNumbers2.numbers_vector = user_input.get_vector(2);
            printf("Vector 1: ");
            bigNumbers1.print_from_front();
            printf("Vector 2: ");
            bigNumbers2.print_from_front();
        } catch (IO::NonIntegerValue)
        {
            printf("Input must be an Integer");
        } catch (IO::InvalidRange)
        {
            printf("You must enter an integer value from 0-5");
        }

        switch(op)
        {
            // Addition
            case 1:
            {
                printf("Operation: Addition\n");
                bigNumbers1 + bigNumbers2;
                break;
            }
            // Subtraction
            case 2:
            {
                printf("Operation: Subtraction\n");
                bigNumbers1.numbers_vector = bigNumbers1 - bigNumbers2;
                break;
            }
            // Multiplication
            case 3:
            {
                printf("Operation: Multiplication\n");
                bigNumbers1 * bigNumbers2;
                break;
            }
            // Division
            case 4:
            {
                printf("Operation: Division\n");
                bigNumbers1 / bigNumbers2;
                break;
            }
            // Multiplication
            case 5:
            {
                printf("Operation: Modulus\n");
                bigNumbers1 % bigNumbers2;
                break;
            }
            // Quit
            case 0:
            {
                done = true;
                break;
            }
        }
        printf("Answer: ");
        bigNumbers1.drop_leading_zeros();
        bigNumbers1.print_from_front();

    }while(!done);

    return 0;
}
