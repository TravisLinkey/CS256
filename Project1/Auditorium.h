//
// Created by travis on 4/20/18.
//

#ifndef PROJECT1_AUDITORIUM_H
#define PROJECT1_AUDITORIUM_H


class Auditorium {
private:
    struct Seat {
        bool taken = false;
        double current_price;
    };
    const int num_of_rows = 15;
    const int num_of_col = 30;
    Seat seating[15][30];
    int tickets_sold = 0;
    double total_revenue;

public:
    void print_seating();
    char get_symbol(int row,int col);
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
};


#endif //PROJECT1_AUDITORIUM_H
