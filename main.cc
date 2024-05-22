#include <iostream>
#include <string>
#include "tictac.h"

int main()
{
    int board[9] = {0,0,0, 0,0,0, 0,0,0};

    int turn = 0;

    while (!check_win_conditions(board))
    {
        turn++;
        print_board(board);
        make_move_server(board,turn%2);
    }


    print_board(board);

    return 0;
}