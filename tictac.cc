#include <iostream>
#include <string>
#include "tictac.h"

void symbol(int val)
{
    switch (val)
    {
    case 1:
        std::cout << "o";
        break;
    case 2:
        std::cout << "x";
        break;
    
    default:
        std::cout << " ";
        break;
    }
}

void print_board(int *b)
{
    int index = 0;
    
    for(int i=0; i<3; i++)
    {
        std::cout<<"|";
        for(int j=0; j<3; j++)
        {   
            symbol(b[index]);
            std::cout<<"|";
            index++;
        }
        std::cout << "\n";
    }
}

bool check_win_conditions(int *b)
{
    //checkin' straight lines
    for(int i=0; i<3; i++)
    {
        if( (b[0+i*3]==1 && b[1+i*3]==1 && b[2+i*3]==1) || (b[0+i]==1 && b[3+i]==1 && b[6+i]==1) )
        {
            std::cout << "Os win\n";
            return 1;
        }
        if( (b[0+i*3]==2 && b[1+i*3]==2 && b[2+i*3]==2) || (b[0+i]==2 && b[3+i]==2 && b[6+i]==2) )
        {
            std::cout << "Xs win\n";
            return 1;
        }
    }
    //checkin' diagonals
    if( (b[0]==1 && b[4]==1 && b[8]==1) || (b[2]==1 && b[4]==1 && b[6]==1) )
        {
            std::cout << "Os win / \n";
            return 1;
        } 
    if( (b[0]==2 && b[4]==2 && b[8]==2) || (b[2]==2 && b[4]==2 &&b [6]==2) )
        {
            std::cout << "Xs win / \n";
            return 1;
        }

    //checkin' if the board ain't full
    bool is_full = 1;
    for(int i=0; i<9; i++){ if(b[i]==0){is_full = 0;} }

    if(is_full)
    {
        std::cout << "It's a draw!\n";
        return 1;
    }
   
    return 0;
}

void make_move_server(int *b, bool is_circle)
{
    uint id;
    std::string pname;

    if(is_circle){pname = "O's";}
    else{pname = "X's";}

    while (true)
    {
        std::cout << pname <<" turn (enter number of a field from 1 to 9)!\n" << "I move to:";
        std::cin >> id;
        //std::cout << id;

        if(b[id-1]!=0){std::cout << "This move is anavailable. Try again!\n";}
        else if(id==0 || id > 9){std::cout << "Such field does not exist. Try again!\n";}
        else
        {
            break;
        }
    }
    //std::cout << id;
    if(is_circle == true){b[id-1] = 1;}
    else{b[id-1] = 2;}
}

int make_move_client(int *b, bool is_circle, std::string received)
{
    uint id;

    id = stoi(received);

    if(b[id-1]!=0)
    {
        std::cout << "This move is anavailable. Try again!"; // test only, should be send to client from an outer scope
        return 1; // "move unavailable" error
    } 
    else if(id==0 || id > 9){
        std::cout << "Such field does not exist. Try again!"; // test only, should be send to client from an outer scope
        return 2; // "move outa bounds" error co
    }
    if(is_circle == true){b[id-1] = 1;}
    else{b[id-1] = 2;}
    return 0; // no error
}

void clear_board(int *b)
{
    int a[9] = {0,0,0, 0,0,0, 0,0,0};
    b = a;
}