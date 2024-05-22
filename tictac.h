#include <iostream>
#include <string>

#ifndef TICTAC_H
#define TICTAC_H

void symbol(int val);
void print_board(int *b);
bool check_win_conditions(int *b);
void make_move_server(int *b, bool is_circle);
int make_move_client(int *b, bool is_circle, std::string received);
void clear_board(int *b);

#endif