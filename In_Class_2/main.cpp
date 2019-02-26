#include "DayOfYear.h"

int main() {
    // basic checks
    DayOfYear day3("April", 15);
    DayOfYear day4("July", 31);
    DayOfYear day6("July", 32);
    DayOfYear day5("February", 32);
    DayOfYear day7("February", 28);
    DayOfYear day8(580);
    std::cout << "----------------\n";

    // Advance post-decrement checks
    DayOfYear day11(120);
    day11.print();
    day11--;
    day11.print();

    std::cout << "----------------\n";
    DayOfYear day9(256);
    day9.print();
    day9--;
    day9.print();

    std::cout << "----------------\n";
    DayOfYear day10(80);
    day10.print();
    day10--;
    day10.print();

    return 0;
}
