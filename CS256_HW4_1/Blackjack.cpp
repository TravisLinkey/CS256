//
// Created by travis on 5/8/18.
//

#include "Blackjack.h"

Blackjack::Blackjack() {

    int ans = ask_user_to_play();
    while(ans == 1 && !game_over)
    {
        take_turn();
        ans = ask_user_continue();
    }

    if(ans == 2)
        std::cout<< "Quitting game! \n";

    std::cout << "Thank you for playing! \n";
}

// Game mechanics
void Blackjack::take_turn() {
    bool stop = false;
    bool user_bust = false;
    int die1, die2;

    cpu_total = cpu_turn();
    std::cout << "Your turn..." << std::endl;

    while(!stop && !user_bust) {
        std::cout << "Rolling Dice!" << std::endl;
        delay_time(200);
        delay_time(200);
        die1 = dice1.roll();
        die2 = dice2.roll();
        std::cout << "You rolled a " << die1 << " and a " << die2 << std::endl;
        user_total += die1 + die2;
        std::cout << "User TOTAL = " << user_total << std::endl;

        if(user_total > 21)
        {
            std::cout << "You busted!" << std::endl;
            user_bust = true;
            user_total = 0;
            break;
        }

        if(user_total != 21)
        {
            if(ask_user_roll_again() == 2)
                stop = true;
        }
        else
        {
            std::cout << "You rolled BLACKJACK!" << std::endl;
            break;
        }

    }

    // 1 = user, 2 = cpu
    int winner = check_winner(user_total, cpu_total);
    output_cpu_total();
    output_winner(winner);
    zero_totals();
}
int Blackjack::cpu_turn() {
    int current_roll = 0;
    int first_dice = 0, second_dice = 0;
    bool dealer_busted = false;

    std::cout << "House's Turn!" << std::endl;
    delay_time(200);
    delay_time(200);
    delay_time(100);

    while(current_roll <= 17 && !dealer_busted)
    {
        first_dice = dice1.roll();
        second_dice = dice2.roll();

        current_roll += first_dice + second_dice;
        if(current_roll > 21)
        {
            dealer_busted = true;
            current_roll = 0;
        }
    }

    return current_roll;
}

// I/O
int Blackjack::ask_user_to_play() {
    int ans;
    bool valid_ans = false;

    while(!valid_ans)
    {
        std::cout << "Would you like to roll the dice to accumulate points?\n";
        std::cout << "1 - Roll Dice!\n";
        std::cout << "2 - Quit\n";
        std::cin >> ans;

        valid_ans = check_valid_ans(1, 2, ans);
        if(!valid_ans)
        {
            std::cout << "Incorrect response... Input must be 1 or 2\n";
        }
    }

    return ans;
}
int Blackjack::ask_user_roll_again() {
    bool valid_ans = false;
    int ans;

    while(!valid_ans)
    {
        std::cout << "Roll Again?\n";
        std::cout << "1 - Hit!\n";
        std::cout << "2 - Stay\n";
        std::cin >> ans;

        valid_ans = check_valid_ans(1, 2, ans);
    }

    return ans;
}
int Blackjack::ask_user_continue() {
    bool valid_ans = false;
    int ans;

    while(!valid_ans)
    {
        std::cout << "Play Again?\n";
        std::cout << "1 - Yes\n";
        std::cout << "2 - No\n";
        std::cin >> ans;

        valid_ans = check_valid_ans(1, 2, ans);
    }

    return ans;
}

void Blackjack::output_cpu_total() {
    std::cout << "HOUSE ROLL: "<< cpu_total << std::endl;
}
void Blackjack::output_winner(int winner) {
    switch(winner)
    {
        case 1:
        {
            std::cout << "You win!\n";
            break;
        }
        case 2:
        {
            std::cout << "The House Wins!\n";
            break;
        }
        case 3:
        {
            std::cout << "It's a tie!\n";
            break;
        }
    }

}

// Misc Functions
bool Blackjack::check_valid_ans(int lower, int upper, int user_ans) {
    if(user_ans <= upper && user_ans >= lower)
        return true;

    return false;
}
int Blackjack::check_winner(int total, int cpu_total) {
    std::cout << "Checking Rolls. . ." << std::endl;
    delay_time(1000);

    if(cpu_total == 0)
        std::cout << "The House BUSTED!" << std::endl;


    if(total > cpu_total)
        return 1;
    else if(total == cpu_total)
        return 3;
    else
        return 2;
}
void Blackjack::zero_totals() {
    user_total = 0;
    cpu_total = 0;
}
void Blackjack::delay_time(int i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(i));
    std::cout << ". \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(i));

}
