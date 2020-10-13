#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>



using namespace std;

struct character                                  // struct for the player
    {
        int posX ;
        int posY ;
        char symbol;
        int hp;
    }player;


struct enemies                              // struct for the enemies
    {
        int posX;
        int posY;
        char enemy_symbol;
    };


char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

//function prototypes
void escape_the_maze();           //game-2

void tic_tac_toe();                 //game-1


int winner();                  //to find who wins the match

void board();                  // to create tic-toe board display


void player_hit();             // function for when the player hits an enemy





//driver function
int main()
{
    int x;

    cout<<"choose option :-"<<"\n";
    cout<<"1 : TIC-TAC-TOE"<<"\n";
    cout<<"2 : ESCAPE-THE-MAZE"<<"\n";
    cin>>x;


    switch(x)
    {
        case 1:tic_tac_toe();
        break;
        case 2:escape_the_maze();
        break;
    }



}



//function for tic_tac_toe game
void tic_tac_toe()
{
	int player = 1,i,choice;

    char mark;

    do
    {
        board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;                                                  // to choose the grid by respective player 1 & 2


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

}



//function for escape_the_maze game
void escape_the_maze()
{

    enemies enemy_horizontal = {13, 9, 'H'}; //placing enemy_horizontal at location [9][13] and gives it the sign H
    enemies enemy_vertical = { 11 , 9, 'V'};
    enemies enemy_jump = {1, 15, 'J'};


    const char HEIGHT = 18, WIDTH = 18; // the maze width and height
    bool update = false; // boolean to control when the map needs to be updated
    char move_key = 'd';

    player.posX = 1;
    player.posY = 1;
    player.symbol = 'O';

    player.hp = 3; // players different attributes(health)


    unsigned char maze[WIDTH][HEIGHT] =
    {
        '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
        '#',' ','#',' ',' ',' ','#','#','#',' ',' ','#','#',' ','#',' ','#','#',
        '#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ',
        '#',' ','#','#',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ',' ',' ',
        '#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',
        '#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ','#',' ',' ','#',
        '#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
        '#','#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',
        '#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#',
        '#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ','#','#',
        '#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#','#',
        '#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#',
        '#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ','#','#','#',' ','#',
        '#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#',
        '#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
        '#','#','#','#',' ','#','#','#','#',' ','#',' ',' ','#','#',' ','#','#',
        '#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#','#',' ','#','#',
        '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
    };
    cout << "MISSION - you have to get out of the maze without meeting any enemies\n\n";
    cout << "Instructions :\n";
    cout << "-player symbol is 'O'\n and enemies are 'H' , 'V' , 'J'\n ";
    cout << "-use (d) (a) (w) or (s) to move -  right left up or down respectively\n\n";

    cout << "NOTE : 1. if you hit/meet with enemy , game again starts from starting point in maze\n\n 2. if hp becomes 0 ,you lose the game\n\n 3. game also shows location and health when required at bottom of maze\n\n";
    cout << "-press (d) (a) (w) or (s) and then return to start the game\n";
    cout << "-press (q) then return to quit the game\n\n";
    cout << "GOOD LUCK\n";



    while (move_key !='q') // as long as move_key is not q then this loop will run and thereby everysingle little thing, which is happening in the maze
{

srand(time(NULL)); // random seed based on some time thingy
int random_move = rand() %2 +1  ; // random number between 1 and 2

cin >> move_key;
update = true;  // map updates

    if (update == true) // if map is updated, then the enemies will be printed onto the map and the player
                        // the maze will be created by a nested for loop, but the x and y are at the wrong places in order to create the map I have "painted" with #
                        // the health will be outputted, so the gamer can see the life of the "player"
                        // update stopped
    {
    system("CLS");

    maze[enemy_horizontal.posX][enemy_horizontal.posY] = enemy_horizontal.enemy_symbol;
    maze[enemy_vertical.posX][enemy_vertical.posY] = enemy_vertical.enemy_symbol;
    maze[enemy_jump.posX][enemy_jump.posY] = enemy_jump.enemy_symbol;

    maze[player.posX][player.posY] = player.symbol;


    for(int y=0;y<HEIGHT;y++)
    {
        cout << endl;
    for(int x=0;x<WIDTH;x++)
    {
        cout << maze[x][y];
    }
    }
    cout << endl << endl << "    health: " << player.hp << endl << "____________________\n \n";
    update = false;
    }

    switch (move_key) // different key pressed in order to move the player and to see if the player collides with a wall(#) or an enemy
                    // it will be printed out the "player's" location, because the game are asynchronous
                    // it will also be printed if the player hits a wall
    {
        case 'w':
            update = true;
        if (maze[player.posX][player.posY -1] != '#')
        {
            maze[player.posX][player.posY] = ' ';
            player.posY --;

            if ( maze[player.posX ][player.posY ] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                maze[player.posX ][player.posY ] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                maze[player.posX ][player.posY ] == maze[enemy_jump.posX][enemy_jump.posY])
            {
                player_hit();
            }

            cout << player.posX << " " << player.posY << endl;
       }
        else
            cout << "  you hit a wall";
        break;

        case 's':
            update = true;
        if (maze[player.posX][player.posY +1] != '#')
        {
            maze[player.posX][player.posY] = ' ';
            player.posY ++;

            if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
            {
                player_hit();
            }

            cout << player.posX << " " << player.posY << endl;
        }
        else
            cout << "  you hit a wall";
        break;

        case 'a':
            update = true;
        if (maze[player.posX -1][player.posY] != '#')
        {
            maze[player.posX][player.posY] = ' ';
            player.posX --;

            if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
            {
                player_hit();
            }

            cout << player.posX << " " << player.posY << endl;
        }
        else
            cout << "  you hit a wall";

        break;

        case 'd':
            update = true;
            if ( maze[player.posX +1][player.posY] != '#')
        {
            maze[player.posX][player.posY] = ' ';
            player.posX ++;

            if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
            {
                player_hit();
            }

            cout << player.posX << " " << player.posY << endl;
        }
        else
            cout << "  you hit a wall";
        break;
    }

        switch (random_move) // the horizontal moving enemy H moves in a random pattern do to the rand() function and thereby making him/her unpredictable.
        {
        case 1:


    if
            (maze[enemy_horizontal.posX +1][enemy_horizontal.posY] != '#')
    {
        maze[enemy_horizontal.posX][enemy_horizontal.posY] = ' ';
        enemy_horizontal.posX ++;
    }

    break;


        case 2:
    if
        (maze[enemy_horizontal.posX -1][enemy_horizontal.posY] != '#')
    {
        maze[enemy_horizontal.posX][enemy_horizontal.posY] = ' ';
        enemy_horizontal.posX --;
    }

    break;
    }

        if (maze[enemy_vertical.posX][enemy_vertical.posY +1] != '#')// the vertical moving enemy he returns to his starting point if he híts a wall, seeing that he only moves in one simple pattern (downwards) he is predictable.
    {
        maze[enemy_vertical.posX][enemy_vertical.posY] = ' ';
        enemy_vertical.posY ++;
    }
    else if
        (maze[enemy_vertical.posX][enemy_vertical.posY -5] != '#')
    {
        maze[enemy_vertical.posX][enemy_vertical.posY] = ' ';
        enemy_vertical.posY -=6;
    }


    if (maze[enemy_jump.posX +2][enemy_jump.posY] != '#')// this enemy jumps every second tile over, so you have to be aware of where he is and the location there have been printed out in order to avoid him.
                                                        // he also returns to his starting point when he can't get any further do to #
    {
        maze[enemy_jump.posX][enemy_jump.posY] = ' ';
        enemy_jump.posX += 2;
    }
    else if
        (maze[enemy_jump.posX -14][enemy_jump.posY] != '#')
    {
        maze[enemy_jump.posX][enemy_jump.posY] = ' ';
        enemy_jump.posX -= 14;
    }

    if (player.hp == 0)// when the player run out of hp the game stops and print out you have lost the game.
    {
        move_key = 'q';
        cout <<" you have lost the game \n";
    }

    if (player.posY == 17)// when the player reach the bottom line he winsd the game
    {
        cout << "\n congrats!!! you have won the game\n";
    }

}// while loop ends here.


}




//function required for tic_tac_toe
   /* FUNCTION FOR GAME STATUS -
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT */

int winner()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}




//function required for tic_tac_toe
//FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK

void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}


//function required for escape_the_maze
// function for when the player hits an enemy
void player_hit()
    {
        player.posX = 1;
        player.posY =1;
        player.hp --;
    }
