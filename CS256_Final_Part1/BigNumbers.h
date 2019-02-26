/**
 * \class BigNumbers
 *
 * \brief Class to hold very large number
 *
 * \author $Author:Travis Linkey $
 *
 * \date $Date: 2018/05/31 $
 *
 */

#ifndef PART1_BIGNUMBERS_H
#define PART1_BIGNUMBERS_H


#include <random>
#include <functional>
#include <vector>

using namespace std;

class BigNumbers {
public:
    bool negative = false; ///< is number negative
    vector<int> numbers_vector; ///< Holds the number vector

    /// Exception Class : Divide by zero
    class DivideByZeroException {};

    /// Constructor
    BigNumbers();
    /**
     * /param Input vector
     */
    BigNumbers(vector<int>);

    /// Operator overloading plus
    void operator+(BigNumbers &);
    /// Operator overloading minus
    vector<int> operator-(BigNumbers &);
    /// Operator overloading multiplication
    void operator*(BigNumbers &);
    /// Operator overloading division
    void operator/(BigNumbers &);
    /// Operator overloading mod
    void operator%(BigNumbers &);
    /// Operator overloading greater than
    bool operator>(BigNumbers &);
    /// Operator overloading unary minus
    void operator--(int);
    /// Operator overloading unary plus
    void operator++(int);

    // IO
    /**
     * Function to print a BigNumber from front to back
     */
    void print_from_front();

    // Misc
    /**
     * Function to check if a BigNumber is smaller
     * @param ptr
     * @return bool
     */
    bool is_smaller(BigNumbers* ptr);
    /**
     * Function to check if a BigNumber is smaller
     * @param ptr
     * @return bool
     */
    bool is_larger(BigNumbers* ptr);
    /**
     * Function to check if a BigNumber is equal to zero
     * @param ptr
     * @return bool
     */
    bool is_zero(vector<int> vector);
    /**
     * Function to check if two BigNumbers are equal
     * @param ptr
     * @return bool
     */
    bool is_equal(BigNumbers *pNumbers);
    /**
     * Function to fill the front of a BigNumber with zeros
     * @param size
     */
    void fill_front(int size);
    /**
     * Gets the difference in digit count between two BigNumbers
     * @param pNumbers
     * @return
     */
    int get_difference(BigNumbers *pNumbers);
    /**
     * Turns the input parameter into a vector
     * @param input
     * @return vector
     */
    std::vector<int> vectorify(int input);
    /**
     * Function to trim the zero's from the front of a BigNumber
     */
    void trim_vector();
    /**
     * Extra function to generate random a vector of input size
     * @param size
     * @return vector
     */
    std::vector<int> generate_random(int size);

    void drop_leading_zeros();
};


#endif //PART1_BIGNUMBERS_H
