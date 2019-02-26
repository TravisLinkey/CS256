/**
 * \class IO
 *
 * \brief IO Class
 *
 * \author $Author:Travis Linkey $
 *
 * \date $Date: 2018/05/31 $
 *
 */

#ifndef PART1_IO_H
#define PART1_IO_H

#include "BigNumbers.h"

class IO {
    BigNumbers number1;
    BigNumbers number2;

public:
    /// Exception Class : catch NonInteger Values
    class NonIntegerValue {};
    /// Exception Class : catch Negative Values
    class NegativeValue {};
    /// Exception Class : catch Invalid Vector input
    class InvalidVector {};
    /// Exception Class : catch Invalid Integer Range
    class InvalidRange {};

    /** Method to set the input BigNumbers into private variables */
    void set_numbers();
    /** Method to get the input BigNumbers */
    std::vector<int> get_numbers();
    /**
     * \brief Method to take integer array and return it as a vector
     * \param input
     * \param size
     * \return vector
     * */
    std::vector<int> vectorify(char input[], int size);
    /**
     * \brief Method to return private vector from class
     * \param num
     * \return vector
     * */
    std::vector<int> get_vector(int num);

    // Misc
    /**
     * \brief Method to check if input character is an integer
     * \param current
     * \return boolean
     * */
    bool not_int(char current);
    /**
     * Method to get user input operation
     * @return user selection
     */
    int get_operation();
};


#endif //PART1_IO_H
