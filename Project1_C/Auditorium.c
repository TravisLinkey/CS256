//
// Created by travis on 4/24/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <tgmath.h>
#include "Auditorium.h"

struct Seat {
    bool taken;
    double current_price;
};
const int num_of_rows = 15;
const int num_of_col = 30;
struct Seat seating[15][30];
int tickets_sold = 0;
double total_revenue;


/*Misc Functions*/
bool get_symbol(int row, int col) {
    if (seating[row][col].taken)
        return true;
    else
        return false;
}
bool  input_correct(int lower, int upper, int user_input) {
    if(lower <= user_input && user_input <= upper)
        return true;
    else
        return false;
}

/* User Input Functions*/
int  get_menu_input() {
    int ans;
    bool correct;

    do{
        correct = true;
        scanf("%d",&ans);

        if(!input_correct(1,6,ans))
        {
            printf(  "Input must be from 1 - 6\n");
            correct = false;
        }

    }while(!correct);

    return ans;
}
int  get_input_row() {
    int row;
    bool correct;
    do{
        correct = true;
        printf(  "Row = ");
        scanf("%d",&row);
        if(!input_correct(1,15,row))
        {
            printf(  "Rows must be between 1 - 15\n");
            correct = false;
        }
    }while(!correct);
    return row-1;
}
int  get_input_seat() {
    int seat;
    bool correct;
    do{
        correct = true;
        printf(  "Seat# = ");
        scanf("%d",&seat);
        if(!input_correct(1,30,seat))
        {
            printf(  "Seat# must be between 1 - 30\n");
            correct = false;
        }
    }while(!correct);

    return seat-1;
}

/* Seating Price Functions */
void input_seats_manually() {
    int ans;

    printf("Please enter prices for: \n");
    int i;
    for (i = 0; i <num_of_rows; ++i) {
        printf("Row# %d",i+1);
        printf("\n");
        int j;
        for (j = 0; j <num_of_col; ++j) {
            j+1;
            printf("\tCollumn# %d",j);
            printf(" =");
            scanf("%d\n",&ans);
            input_correct(0,1000,ans);
        }
    }
}
void  get_from_file() {
    FILE* file = fopen("../seating_prices.txt", "r");
    int value;
    int row,col;

    row = 0;
    col = 0;

    // read file line by line
    while(!feof(file))
    {
        if(fscanf(file,"%d",&value) !=1)
            break;
        if(col == 30)
        {
            row++;
            col = 0;
        }
        seating[row][col++].current_price = value;
    }

    fclose(file);
}
void  check_prices() {
    int row, seat;

    printf("Enter row and seat number of the seat you would like to check. \n");
    row = get_input_row();
    seat = get_input_seat();


    printf(" Ticket price: $%f", seating[row][seat].current_price);
    printf("\n");
}
void  purchase_seat() {
    int row, seat;
    int ans;
    bool still_interested;
    int group_price = 0;

    do{
        printf(  "Enter row and seat number of the seat you would like to purchase. \n");
        row = get_input_row();
        seat = get_input_seat();

        if(seating[row][seat].taken)
        {
            printf("Sorry, that seat is taken!\n");
            printf("Would you like to purchase a different seat?\n");
        }
        else
        {
            seating[row][seat].taken = true;
            tickets_sold ++;
            group_price += seating[row][seat].current_price;
            total_revenue += seating[row][seat].current_price;
            printf("Success! You Purchased Row %d",row+1);
            printf(" Seat# %d", seat+1);
            printf("\n");
            printf("Ticket price: $%f",seating[row][seat].current_price);
            printf("\n");
            printf("Would you like to make another purchase?\n");

            printf("\n");
        }

        printf(  "\t 1.Yes\n");
        printf(  "\t 2.No\n");
        scanf("%d",&ans);

        if(ans == 1)
            still_interested = true;
        else
            still_interested = false;

    }while(still_interested);

    printf(  "Total Purchase Price:  $%d",group_price);
    printf("\n");
}
void  get_seat_prices() {
    int ans;
    printf(  "How are seat prices going to be entered? \n");
    printf(  "1. Manually enter seat prices \n");
    printf(  "2. Read from file \n");
    scanf("%d",&ans);

    if(ans == 1)
        input_seats_manually();
    else if (ans == 2)
        get_from_file();


}

void  view_ticket_sales() {
    printf(  "Total tickets sold: %d",tickets_sold);
    printf("\n");
    printf(  "Total revenue: $%f",total_revenue);
    printf("\n");
}
void  print_seats_sold() {
    printf(  "The following seats have been sold: \n");
    // scan each row and col, print info of seats taken
    int i,j;
    for (i = 0; i < num_of_rows; ++i) {
        for (j = 0; j < num_of_col; ++j) {
            if(seating[i][j].taken)
            {
                printf(  "Row %d",i+1);
                printf(" Seat# %d",j+1);
                printf("\n");
            }
        }
    }
}
void  print_available_seats_by_row() {
    int seat_count;
    printf(  "The following seats have been sold: \n");
    // scan each row and col, print number of available seats
    for (int i = 0; i < num_of_rows; ++i) {
        seat_count = 0;
        printf(  "Row %d",i+1);
        for (int j = 0; j < num_of_col; ++j) {
            if(!seating[i][j].taken)
                seat_count++;
        }
        printf(  " Available Seats: %d",seat_count);
        printf("\n");
    }
}
void  print_num_seats_left() {
    int total_seats_left = (15*30) - tickets_sold;

    printf(  "Total Tickets in Theater Left: %d", total_seats_left);
    printf("\n");
}
void  view_seat_info() {
    bool quit;

    do{
        quit = false;

        printf(  "Seating Info MENU :\n");
        printf(  "\t1.View Seats Sold\n");
        printf(  "\t2.Check Available Seats By Row\n");
        printf(  "\t3.Auditorium Seats Available\n");
        printf(  "\t4.Exit MENU\n");

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

/* Printing Functions */
void  print_seating() {
    // print seating scale
    printf("\t\t");
    int k;
    for (k = 0; k < 10; ++k)
    {
        printf("%d",k);
    }
    for (k = 0; k < 10; ++k)
    {
        printf("%d",k);
    }
    for (k = 0; k < 10; ++k)
    {
        printf("%d",k);
    }
    printf("\n");

    int i;
    for (i = 0; i < num_of_rows; ++i) {
        printf("Row %d",i+1);
        printf("\t");
        for (int j = 0; j < num_of_col; ++j) {
            if(get_symbol(i,j))
                printf("*");
            else
                printf("#");

        }
        printf("\n");
        i++;
    }
}
void  display_menu() {
    bool quit;

    do{
        quit = false;

        printf(  "Main MENU :\n");
        printf(  "\t1.Print Seating Chart\n");
        printf(  "\t2.Check Seat Price\n");
        printf(  "\t3.Purchase Seat\n");
        printf(  "\t4.View Ticket Sales\n");
        printf(  "\t5.View Seat List\n");
        printf(  "\t6.Quit\n");

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



