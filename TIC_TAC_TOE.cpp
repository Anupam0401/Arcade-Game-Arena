#include<iostream>

using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

//func. prototypes

int winner();                  //to find who wins the match

void board();                  // to create tic-toe board display

int main()
{
	int player = 1,i,choice;

    char mark;

    do
    {
        board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;                                                  // to choose the gird by respective player 1 & 2

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=winner();

        player++;
    }while(i==-1);
    board();
    if(i==1)

        cout<<"=>\aPlayer "<<--player<<" win ";
    else
        cout<<"=>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}


   /* FUNCTION FOR GAME STATUS -
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT */


//add winner() func here



//FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK




//add board() func here

