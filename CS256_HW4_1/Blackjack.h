//
// Created by travis on 5/8/18.
//

#ifndef INC_1_BLACKJACK_H
#define INC_1_BLACKJACK_H


#include <thread>
#include "dice.h"

class Blackjack {
    dice dice1, dice2;
    int user_point = 0, cpu_points = 0;
    int user_total = 0, cpu_total = 0;
    bool game_over = false;

public:
    Blackjack();

    // Game Mechanics
    void take_turn();
    int cpu_turn();

    // I/O
    int ask_user_to_play();
    int ask_user_continue();
    void output_cpu_total();
    void output_winner(int winner);

    // Misc Functions
    bool check_valid_ans(int i, int i1, int i2);
    int check_winner(int total, int cpu_total);
    void zero_totals();
    void delay_time(int i);

    int ask_user_roll_again();
};


#endif //INC_1_BLACKJACK_H
