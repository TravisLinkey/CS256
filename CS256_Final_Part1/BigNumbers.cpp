//
// Created by tlinkey on 5/23/18.
//

#include <iostream>
#include <algorithm>
#include "BigNumbers.h"

/// Constructor function without arguments
BigNumbers::BigNumbers() { numbers_vector = {0}; };
/// Constructor function with vector argument
BigNumbers::BigNumbers(std::vector<int> vec) {
    this->numbers_vector = vec;
}

/// Operator overloading plus
void BigNumbers::operator+(BigNumbers& rhs) {
//    BigNumbers bigNumbers3;
    int carry = 0;
    BigNumbers* ptr = &rhs;
    BigNumbers* min_ptr = nullptr;
    BigNumbers* max_ptr = nullptr;

    if(is_smaller(ptr))
        min_ptr = this;
    else
        min_ptr = &rhs;

    if(is_larger(ptr))
        max_ptr = this;
    else
        max_ptr = &rhs;


//    bigNumbers3.numbers_vector.resize(max_ptr->numbers_vector.size());
    int size_difference = max_ptr->numbers_vector.size() - min_ptr->numbers_vector.size();
    min_ptr->fill_front(size_difference);

    std::vector<int>::reverse_iterator r_it1 = this->numbers_vector.rbegin();
    std::vector<int>::reverse_iterator r_it2 = rhs.numbers_vector.rbegin();
//    std::vector<int>::reverse_iterator r_it3 = bigNumbers3.numbers_vector.rbegin();

    while(r_it1 != this->numbers_vector.rend())
    {
        int first = *r_it1;
        int second = *r_it2;
        int ans = *r_it1 + *r_it2 + carry;
        carry = 0;
        if(ans >= 10)
        {
            int rem = ans%10;
            carry = 1;
//            *r_it3 = rem;
            *r_it1 = rem;
        }
        else {
//            *r_it3 = ans;
            *r_it1 = ans;
        }
        r_it1++;
        r_it2++;
//        r_it3++;
    }

    if(carry == true)
        this->numbers_vector.insert(this->numbers_vector.begin(),1);
//        bigNumbers3.numbers_vector.insert(bigNumbers3.numbers_vector.begin(),1);

//    return bigNumbers3;
}
/// Operator overloading minus
std::vector<int> BigNumbers::operator-(BigNumbers& rhs) {
    BigNumbers quotient;

    // declare iterators
    std::vector<int>::reverse_iterator lrg_begin;
    std::vector<int>::reverse_iterator lrg_ptr1;
    std::vector<int>::reverse_iterator lrg_ptr2;
    std::vector<int>::reverse_iterator sml_ptr;

    this->trim_vector();
    rhs.trim_vector();

    int difference = get_difference(&rhs);

    // if same - same; ans = 0
    if(difference == 0 && is_equal(&rhs))
    {
        numbers_vector = {0};
        return numbers_vector;
    }


    // if smaller - larger; ans = negative
    // swap lhs <=> rhs
    if(is_smaller(&rhs)) {
        this->negative = true;
        this->fill_front(difference);
        sml_ptr = this->numbers_vector.rbegin();
        lrg_begin = rhs.numbers_vector.rend();
        lrg_ptr1 = rhs.numbers_vector.rbegin();
        lrg_ptr2 = lrg_ptr1;
    }
    // larger - smaller
    else {
        rhs.fill_front(difference);
        sml_ptr = rhs.numbers_vector.rbegin();
        lrg_begin = this->numbers_vector.rend();
        lrg_ptr1 = this->numbers_vector.rbegin();
        lrg_ptr2 = lrg_ptr1;
    }


    while(lrg_ptr1 != lrg_begin)
    {
        if(*lrg_ptr1 < *sml_ptr)
        {
            // single borrow
            if(*lrg_ptr2 < *sml_ptr)
                lrg_ptr2++;

            // many borrows
            while(*lrg_ptr2 == 0)
            {
                *lrg_ptr2 = 9;
                lrg_ptr2++;
            }
            *lrg_ptr2 = *lrg_ptr2 - 1;
            *lrg_ptr1 += 10;
        }
        int ans = *lrg_ptr1 - *sml_ptr;
        quotient.numbers_vector.insert(quotient.numbers_vector.begin(),ans);

        lrg_ptr1++;
        lrg_ptr2 = lrg_ptr1;
        sml_ptr++;
    }

    std::vector<int>::iterator last = quotient.numbers_vector.end();
    quotient.numbers_vector.erase(--last);

    return quotient.numbers_vector;
}
/// Operator overloading multiplication
void BigNumbers::operator*(BigNumbers& rhs) {
    BigNumbers original = *this;

    if(is_zero(rhs.numbers_vector))
        this->numbers_vector = {0};

    rhs--;
    while(!is_zero(rhs.numbers_vector)) {
        *this + original;
        rhs--;
    }

}
/// Operator overloading division
void BigNumbers::operator/(BigNumbers& rhs) {
    BigNumbers bigNumbers3 = *this;
    int quotient = 0;

    if(is_zero(rhs.numbers_vector))
        throw DivideByZeroException();

    this->trim_vector();
    rhs.trim_vector();

    int difference = get_difference(&rhs);
    if(this->is_larger(&rhs))
        rhs.fill_front(difference);
    else
        this->fill_front(difference);

    while(bigNumbers3.is_larger(&rhs)) {
        bigNumbers3.numbers_vector = bigNumbers3 - rhs;
        quotient++;
        rhs.trim_vector();
    }

    bigNumbers3.print_from_front();
    rhs.print_from_front();

    if(bigNumbers3.is_equal(&rhs))
    {
        bigNumbers3.numbers_vector = bigNumbers3 - rhs;
        quotient++;
        rhs.trim_vector();
    }

    this->numbers_vector = vectorify(quotient);
}

/// Operator overloading for Modulus
void BigNumbers::operator%(BigNumbers& rhs) {
    BigNumbers bigNumbers3 = *this;
    int quotient = 0;

    if(is_zero(rhs.numbers_vector))
        throw DivideByZeroException();

    this->trim_vector();
    rhs.trim_vector();

    int difference = get_difference(&rhs);
    if(this->is_larger(&rhs))
        rhs.fill_front(difference);
    else
        this->fill_front(difference);

    while(bigNumbers3.is_larger(&rhs)) {
        bigNumbers3.numbers_vector = bigNumbers3 - rhs;
        quotient++;
        rhs.trim_vector();
    }

    if(bigNumbers3.is_equal(&rhs))
    {
        bigNumbers3.numbers_vector = bigNumbers3 - rhs;
        quotient++;
        rhs.trim_vector();
    }

    this->numbers_vector = bigNumbers3.numbers_vector;

}
/// Operator overloading greater than
bool BigNumbers::operator>(BigNumbers & second) {
    std::vector<int>::iterator lhs = this->numbers_vector.begin();
    std::vector<int>::iterator rhs = second.numbers_vector.begin();

    while(*lhs == *rhs)
    {
        lhs++;
        rhs++;
    }
    if(*lhs > *rhs)
        return true;
    else
        return false;
}
/// Operator overloading unary minus
void BigNumbers::operator--(int) {
    std::vector<int>::reverse_iterator first = this->numbers_vector.rbegin();
    --first;
    std::vector<int>::reverse_iterator next = ++first;

    if(*first == 0)
    {
        while(*next == 0)
            ++next;
        *next = *next-1;
        while(next != first)
        {
            --next;
            *next = 9;
        }

        *first = 9;
    } else
        *first = *first-1;
}
/// Operator overloading unary plus
void BigNumbers::operator++(int) {
    std::vector<int>::reverse_iterator first = this->numbers_vector.rbegin();

    if(*first == 9)
    {
        *first = 0;
        first++;
        *first = *first+1;
    } else
        *first = *first+1;
}

// IO

/**
 * Function to print a BigNumber from front to back
 */
void BigNumbers::print_from_front() {
    if(this->negative)
        cout << "-";

    for (std::vector<int>::iterator it = numbers_vector.begin(); it != numbers_vector.end(); ++it) {
        printf("%d,", *it);
    }
    printf("\n");
}

// Misc
/**
 * Function to fill the front of a BigNumber with zeros
 * @param size
 */
void BigNumbers::fill_front(int size) {
    for (int i = 0; i < size; ++i) {
        numbers_vector.insert(numbers_vector.begin(), 0);
    }
}
/**
 * Function to check if a BigNumber is smaller
 * @param ptr
 * @return bool
 */
bool BigNumbers::is_smaller(BigNumbers* num2) {
    std::vector<int>::iterator first = this->numbers_vector.begin();
    std::vector<int>::iterator second = num2->numbers_vector.begin();

    if(this->numbers_vector.size() == num2->numbers_vector.size())
    {
        while(*first == *second)
        {
            first++;
            second++;
        }

        if(*first < *second)
            return true;
        else
            return false;
    }

    if(this->numbers_vector.size() < num2->numbers_vector.size())
        return true;
    return false;
}
/**
 * Function to check if a BigNumber is smaller
 * @param ptr
 * @return bool
 */
bool BigNumbers::is_larger(BigNumbers* num2) {
    std::vector<int>::iterator first = this->numbers_vector.begin();
    std::vector<int>::iterator second = num2->numbers_vector.begin();

    if(this->numbers_vector.size() == num2->numbers_vector.size())
    {
        while(*first == *second)
        {
            first++;
            second++;
        }

        if(*first > *second)
            return true;
        else
            return false;
    }

    if(this->numbers_vector.size() > num2->numbers_vector.size())
        return true;
    return false;
}
/**
 * Function to check if two BigNumbers are equal
 * @param ptr
 * @return bool
 */
bool BigNumbers::is_equal(BigNumbers* num2) {
    std::vector<int>::iterator iterator1 = this->numbers_vector.begin();
    std::vector<int>::iterator iterator11 = this->numbers_vector.end();
    std::vector<int>::iterator iterator2 = num2->numbers_vector.begin();
    std::vector<int>::iterator iterator22 = num2->numbers_vector.end();

    if(this->numbers_vector.size() ==1 && num2->numbers_vector.size() ==1)
        if(*iterator1 == *iterator2)
            return true;


    if(this->numbers_vector.size() == num2->numbers_vector.size())
    {
        while(iterator1 != iterator11 && iterator2 != iterator22)
        {
            if(*iterator1 != *iterator2)
                return false;
            iterator1++;
            iterator2++;
        }
        if(*iterator1 == *iterator2)
            return true;
        else
            return false;
    }
    for (int i = 0; i < num2->numbers_vector.size(); ++i) {
        if(this->numbers_vector.at(i) != num2->numbers_vector.at(i))
            return false;
    }
    return true;
}
/**
 * Function to check if a BigNumber is equal to zero
 * @param ptr
 * @return bool
 */
bool BigNumbers::is_zero(vector<int> vector) {

    for (int i = 0; i < vector.size(); ++i) {
        if(vector.at(i) != 0)
            return false;
    }

    return true;
}

// Extra
/**
 * Gets the difference in digit count between two BigNumbers
 * @param pNumbers
 * @return
 */
int BigNumbers::get_difference(BigNumbers *pNumbers) {
    int diff_counter = 0;
    std::vector<int>::iterator iterator1 = this->numbers_vector.begin();
    std::vector<int>::iterator iterator2 = pNumbers->numbers_vector.begin();

    if(this->numbers_vector.size() > pNumbers->numbers_vector.size())
        return this->numbers_vector.size() - pNumbers->numbers_vector.size();
    else if(this->numbers_vector.size() == pNumbers->numbers_vector.size())
    {
        while(*iterator1 == 0 && *iterator2 == 0)
        {
            iterator1++;
            iterator2++;
        }
        // loop iterator2
        if(*iterator1 != 0)
        {
            while(*iterator2 == 0)
            {
                iterator2++;
                diff_counter++;
            }
            return diff_counter;
        }
        // loop iterator2
        if(*iterator2 != 0)
        {
            while(*iterator1 == 0)
            {
                iterator1++;
                diff_counter++;
            }
            return diff_counter;
        }
    }

    return pNumbers->numbers_vector.size()-this->numbers_vector.size();
}
/**
 * Turns the input parameter into a vector
 * @param input
 * @return vector
 */
std::vector<int> BigNumbers::vectorify(int input) {
    bool digitsleft = true;
    int rem, div;
    std::vector<int> newvector;

    do {
        rem = input % 10;
        input /= 10;
        newvector.insert(newvector.begin(), rem);

        if(input == 0)
            digitsleft = false;

    } while (digitsleft);

    return newvector;
}
/**
 * Function to trim the zero's from the front of a BigNumber
 */
void BigNumbers::trim_vector() {
    std::vector<int>::iterator iterator1 = this->numbers_vector.begin();

    while(*iterator1 == 0)
    {
        this->numbers_vector.erase(this->numbers_vector.begin());
        iterator1 = this->numbers_vector.begin();
    }
}
/**
 * Extra function to generate random a vector of input size
 * @param size
 * @return vector
 */
std::vector<int> BigNumbers::generate_random(int size) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,9);
    auto producer = std::bind(distribution, generator);

    for (int i = 0; i < size; ++i) {
        numbers_vector.push_back(producer());
    }
}
/**
 * Function to drop the leading zeros from the vector
 *
 */
void BigNumbers::drop_leading_zeros() {
    std::vector<int>::iterator iterator1 = this->numbers_vector.begin();
    if(*iterator1 == 0)
    {
        do{
            numbers_vector.erase(iterator1);
        }while(*iterator1 == 0);
    }
}


