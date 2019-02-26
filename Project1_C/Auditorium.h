//
// Created by travis on 4/24/18.
//

#ifndef PROJECT1_C_AUDITORIUM_H
#define PROJECT1_C_AUDITORIUM_H

#include <stdbool.h>


void print_seating();
bool get_symbol(int row, int col);
void get_seat_prices();
bool input_correct(int lower, int upper, int user_input);
void input_seats_manually();
void get_from_file();
void check_prices();
int get_input_row();
int get_input_seat();
void display_menu();
int get_menu_input();
void purchase_seat();
void view_ticket_sales();
void view_seat_info();
void print_seats_sold();
void print_available_seats_by_row();
void print_num_seats_left();

#endif //PROJECT1_C_AUDITORIUM_H
