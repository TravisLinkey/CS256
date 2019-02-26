
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include "Auditorium.h"

/* Seating Price Functions */
void Auditorium::input_seats_manually() {
    int ans;

    std::cout << "Please enter prices for: \n";
    for (int i = 0; i <num_of_rows; ++i) {
        std::cout << "Row# " << i+1 << std::endl;
        for (int j = 0; j <num_of_col; ++j) {
            std::cout << "\tCollumn# " << j+1 << " =";
            std::cin >> ans;
            input_correct(0,1000,ans);
        }
    }
}
void Auditorium::get_from_file() {
    std::ifstream infile("../seating_prices.txt");
    std::string line;
    std::string::size_type size;
    std::vector<double> file_contents;

    // read file line by line
    while(std::getline(infile,line))
    {
        // each line goes into a stream
        std::istringstream lines(line);

        // for every value in the line, store in the vector
        for (std::string line; lines >> line;)
            file_contents.push_back(atof(line.c_str()));
    }

    // fill the array
    for (int i = 0; i < num_of_rows; ++i) {
        for (int j = 0; j < num_of_col; ++j) {
            double cost = file_contents.at(j);
            seating[i][j].current_price = cost;
        }
    }
    }
void Auditorium::check_prices() {
    int row, seat;

    std::cout << "Enter row and seat number of the seat you would like to check. \n";
    row = get_input_row();
    seat = get_input_seat();

    std::cout << "Ticket price: $" << seating[row-1][seat-1].current_price << std::endl;
}
void Auditorium::purchase_seat() {
    int row, seat;
    int ans;
    bool still_interested;
    int group_price = 0;

    do{
        std::cout << "Enter row and seat number of the seat you would like to purchase. \n";
        row = get_input_row();
        seat = get_input_seat();

        if(seating[row-1][seat-1].taken)
        {
            std::cout << "Sorry, that seat is taken!\n";
            std::cout << "Would you like to purchase a different seat?\n";
        }
        else
        {
            seating[row-1][seat-1].taken = true;
            tickets_sold ++;
            group_price += seating[row-1][seat-1].current_price;
            total_revenue += seating[row-1][seat-1].current_price;
            std::cout << "Success! You Purchased Row " << row << " Seat# " << seat << std::endl;
            std::cout << "Ticket price: $" << seating[row-1][seat-1].current_price << std::endl;
            std::cout << "Would you like to make another purchase?\n";
        }

        std::cout << "\t 1.Yes\n";
        std::cout << "\t 2.No\n";
        std::cin >> ans;

        if(ans == 1)
            still_interested = true;
        else
            still_interested = false;

    }while(still_interested);

    std::cout << "Total Purchase Price:  $" << group_price << std::endl;
}

/* User Input Functions*/
int Auditorium::get_menu_input() {
    int ans;
    bool correct;

    do{
        correct = true;
        std::cin >> ans;

        if(!input_correct(1,6,ans))
        {
            std::cout << "Input must be from 1 - 6\n";
            correct = false;
        }

    }while(!correct);

    return ans;
}
int Auditorium::get_input_row() {
    int row;
    bool correct;
    do{
        correct = true;
        std::cout << "Row = ";
        std::cin >> row;
        if(!input_correct(1,15,row))
        {
            std::cout << "Rows must be between 1 - 15\n";
            correct = false;
        }
    }while(!correct);
    return row;
}
int Auditorium::get_input_seat() {
    int seat;
    bool correct;
    do{
        correct = true;
        std::cout << "Seat# = ";
        std::cin >> seat;
        if(!input_correct(1,30,seat))
        {
            std::cout << "Seat# must be between 1 - 30\n";
            correct = false;
        }
    }while(!correct);
    return seat;
}
void Auditorium::get_seat_prices() {
    int ans;
    std::cout << "How are seat prices going to be entered? \n";
    std::cout << "1. Manually enter seat prices \n";
    std::cout << "2. Read from file \n";

    std::cin >> ans;

    if(ans == 1)
        input_seats_manually();
    else if (ans == 2)
        get_from_file();


}

/* Printing Functions */
void Auditorium::print_seating() {
    // print seating scale
    std::cout << "\t\t";
    for (int k = 1; k < num_of_col+1; ++k)
        std::cout << (k%10);
    std::cout << std::endl;

    for (int i = 0; i < num_of_rows; ++i) {
        std::cout << "Row " << i+1 << "\t";
        for (int j = 0; j < num_of_col; ++j)
            std::cout << get_symbol(i,j);
        std::cout << std::endl;
    }
}
void Auditorium::display_menu() {
    bool quit;

    do{
        quit = false;

        std::cout << "Main MENU :\n";
        std::cout << "\t1.Print Seating Chart\n";
        std::cout << "\t2.Check Seat Price\n";
        std::cout << "\t3.Purchase Seat\n";
        std::cout << "\t4.View Ticket Sales\n";
        std::cout << "\t5.View Seat List\n";
        std::cout << "\t6.Quit\n";

        int ans = get_menu_input();

        switch(ans)
        {
            case 1:
                print_seating();
                break;
            case 2:
                check_prices();
                break;
            case 3:
                purchase_seat();
                break;
            case 4:
                view_ticket_sales();
                break;
            case 5:
                view_seat_info();
                break;
            case 6:
                quit = true;
        }

    }while(!quit);
}
void Auditorium::view_ticket_sales() {
    std::cout << "Total tickets sold: " << tickets_sold << std::endl;
    std::cout << "Total revenue: $" << total_revenue << std::endl;
}
void Auditorium::view_seat_info() {
    bool quit;

    do{
        quit = false;

        std::cout << "Seating Info MENU :\n";
        std::cout << "\t1.View Seats Sold\n";
        std::cout << "\t2.Check Available Seats By Row\n";
        std::cout << "\t3.Auditorium Seats Available\n";
        std::cout << "\t4.Exit MENU\n";

        int ans = get_menu_input();

        switch(ans)
        {
            case 1:
                print_seats_sold();
                break;
            case 2:
                print_available_seats_by_row();
                break;
            case 3:
                print_num_seats_left();
                break;
            case 4:
                quit = true;
        }

    }while(!quit);

}
void Auditorium::print_seats_sold() {
    std::cout << "The following seats have been sold: \n";
    // scan each row and col, print info of seats taken
    for (int i = 0; i < num_of_rows; ++i) {
        for (int j = 0; j < num_of_col; ++j) {
            if(seating[i][j].taken)
                std::cout << "Row " << i+1 << " Seat# " << j+1 << std::endl;
        }
    }
}
void Auditorium::print_available_seats_by_row() {
    int seat_count;
    std::cout << "The following seats have been sold: \n";
    // scan each row and col, print number of available seats
    for (int i = 0; i < num_of_rows; ++i) {
        seat_count = 0;
        std::cout << "Row " << i+1;
        for (int j = 0; j < num_of_col; ++j) {
            if(!seating[i][j].taken)
                seat_count++;
        }
        std::cout << " Available Seats: " << seat_count << std::endl;
    }
}
void Auditorium::print_num_seats_left() {
    int total_seats_left = (15*30) - tickets_sold;

    std::cout << "Total Tickets in Theater Left: " << total_seats_left << std::endl;
}

/*Misc Functions*/
char Auditorium::get_symbol(int row, int col) {
    if (seating[row][col].taken)
        return '*';
    else
        return '#';
}
bool Auditorium::input_correct(int lower, int upper, int user_input) {
    if(lower <= user_input && user_input <= upper)
        return true;
    else
        return false;
}


