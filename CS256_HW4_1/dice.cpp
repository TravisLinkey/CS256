//
// Created by travis on 5/8/18.
//

#include <thread>
#include "dice.h"

/* Constructor seeds the random generator */
dice::dice() {
    srand(time(NULL));
}
int dice::roll() {
    showing = rand() % MAX_VALUE + 1;
    return showing;
}
void dice::test_distribution() {
    for(int i = 0; i < 100; i++)
    {
        roll();
        switch(showing)
        {
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            case 3:
                three++;
                break;
            case 4:
                four++;
                break;
            case 5:
                five++;
                break;
            case 6:
                six++;
                break;
        }
    }

    std::cout << "Results: \n" << "1: " << one << "\n";
    std:: cout << "2: " << two << "\n";
    std:: cout << "3: " << three << "\n";
    std:: cout << "4: " << four << "\n";
    std:: cout << "5: " << five << "\n";
    std:: cout << "6: " << six << "\n";

}

