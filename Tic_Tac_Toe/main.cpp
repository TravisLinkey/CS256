#include <iostream>
#include <stdlib.h>

static char board[3][3];
void display_board();
void initialize_board();
void take_turns();
void player1_turn();
void player2_turn();
int check_board();
bool out_of_bounds(int row);
void mark_location(int row, int col, int i);
int diagonal_win();
int verticle_win();
int horizontal_win();
bool valid_move(int i, int i1);

int main() {
    bool game_over = false;
    initialize_board();

    do{
        take_turns();
    }while(!game_over);

    return 0;
}
void take_turns() {
    printf("Player1's turn!\n");
    player1_turn();
    check_board();

    printf("Player2's turn!\n");
    player2_turn();
    check_board();
}
int check_board() {
    if(diagonal_win() == 1 || verticle_win() == 1 || horizontal_win() == 1)
        return 1;
    else if(diagonal_win() == 2 || verticle_win() == 2 || horizontal_win() == 2)
        return 2;
}
int horizontal_win() {
    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
        (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
        (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'))
        return 1;

    else if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
        (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
        (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'))
        return 2;
}
int verticle_win() {
    if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
        (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
        (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'))
        return 1;
    else if ((board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
        (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
        (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'))
        return 2;
}
int diagonal_win() {
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
            (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
        return 1;
    else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
        (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
        return 2;
}
void player1_turn() {
    int row, col;

    do{
        printf("Please enter row and collumn number\n");
        printf("row=");
        scanf("%d",&row);
        printf("collumn=");
        scanf("%d",&col);
    }while(out_of_bounds(row) || out_of_bounds(col) && !valid_move(row, col));

    mark_location(row,col,1);

    printf("Player1 has moved!\n");
    display_board();
}
bool valid_move(int i, int i1) {
    if(board[i][i1] == '*')
        return true;
    else
    {
        printf("Move Invalid!");
        return false;
    }
}
void player2_turn() {
    int row, col;

    do{
        printf("Please enter row and collumn number\n");
        printf("row=");
        scanf("%d",&row);
        printf("collumn=");
        scanf("%d",&col);
    }while(out_of_bounds(row) || out_of_bounds(col) && !valid_move(row,col));

    mark_location(row,col,2);

    printf("Player2 has moved!\n");
    display_board();
}
void mark_location(int row, int col, int i) {
    if(i == 2)
        board[row][col] = 'X';
    else
        board[row][col] = 'O';
}
bool out_of_bounds(int move) {
    if(move < 0 || move > 2)
    {
        printf("Move out of bounds!");
        return true;
    }
    else
        return false;
}
void initialize_board() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3;j++)
            board[i][j] = '*';
}
void display_board() {
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3;j++)
            printf("|%c|", board[i][j]);
        printf("\n");
    }

}
