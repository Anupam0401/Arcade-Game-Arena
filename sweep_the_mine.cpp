#include<bits/stdc++.h> 
using namespace std; 
int SIDE ; 
int MINES ; 
  
bool isValid(int row, int col) 
{ 
    return (row >= 0) && (row < SIDE) && 
           (col >= 0) && (col < SIDE); 
}  
bool isMine (int row, int col, char board[][MAXSIDE]) 
{ 
    if (board[row][col] == '*') 
        return (true); 
    else
        return (false); 
} 
void makeMove(int *x, int *y) 
{   printf("Enter your move, (row (space) column) -> "); 
    scanf("%d %d", x, y); 
    return; 
} 
//printboard function
int countAdjacentMines(int row, int col, int mines[][2],  
                      char rBoard[][MAXSIDE]) 
{   int i; 
    int count = 0; 
        if (isValid (row-1, col) == true) 
        { 
               if (isMine (row-1, col, rBoard) == true) 
               count++; 
        } 
        if (isValid (row+1, col) == true) 
        { 
               if (isMine (row+1, col, rBoard) == true) 
               count++; 
        } 
        if (isValid (row, col+1) == true) 
        { 
            if (isMine (row, col+1, rBoard) == true) 
               count++; 
        } 
        if (isValid (row, col-1) == true) 
        { 
               if (isMine (row, col-1, rBoard) == true) 
               count++; 
        } 
        if (isValid (row-1, col+1) == true) 
        { 
            if (isMine (row-1, col+1, rBoard) == true) 
               count++; 
        } 
        if (isValid (row-1, col-1) == true) 
        { 
             if (isMine (row-1, col-1, rBoard) == true) 
               count++; 
        } 
        if (isValid (row+1, col+1) == true) 
        { 
               if (isMine (row+1, col+1, rBoard) == true) 
               count++; 
        } 
        if (isValid (row+1, col-1) == true) 
        { 
            if (isMine (row+1, col-1, rBoard) == true) 
               count++; 
        } 
    return (count); 
} 
bool play_SMUtil(char mBoard[][MAXSIDE], char rBoard[][MAXSIDE], 
            int mines[][2], int row, int col, int *movesLeft) 
{ 
    if (mBoard[row][col] != '-') 
        return (false); 
    int i, j; 
    if (rBoard[row][col] == '*') 
    { 
        mBoard[row][col]='*'; 
  
        for (i=0; i<MINES; i++) 
            mBoard[mines[i][0]][mines[i][1]]='*'; 
  
        printBoard (mBoard); 
        printf ("\nYou lost!\n"); 
        return (true) ; 
    } 
  
    else
     { 
        int count = countAdjacentMines(row, col, mines, rBoard); 
        (*movesLeft)--; 
        mBoard[row][col] = count + '0'; 
        if (!count) 
        { 
            if (isValid (row-1, col) == true) 
            { 
                   if (isMine (row-1, col, rBoard) == false) 
                   play_SMUtil(mBoard, rBoard, mines, row-1, col, movesLeft); 
            } 
            if (isValid (row+1, col) == true) 
            { 
                   if (isMine (row+1, col, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row+1, col, movesLeft); 
            } 
            if (isValid (row, col+1) == true) 
            { 
                if (isMine (row, col+1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row, col+1, movesLeft); 
            } 
            if (isValid (row, col-1) == true) 
            { 
                   if (isMine (row, col-1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row, col-1, movesLeft); 
            } 
            if (isValid (row-1, col+1) == true) 
            { 
                if (isMine (row-1, col+1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row-1, col+1, movesLeft); 
            } 
            if (isValid (row-1, col-1) == true) 
            { 
                 if (isMine (row-1, col-1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row-1, col-1, movesLeft); 
            } 
            if (isValid (row+1, col+1) == true) 
            { 
                 if (isMine (row+1, col+1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row+1, col+1, movesLeft); 
            } 
            if (isValid (row+1, col-1) == true) 
            { 
                if (isMine (row+1, col-1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row+1, col-1, movesLeft); 
            } 
        } 
        return (false); 
    } 
} 
void placeMines(int mines[][2], char rBoard[][MAXSIDE]) 
{ 
    bool mark[MAXSIDE*MAXSIDE]; 
    memset (mark, false, sizeof (mark));  
    for (int i=0; i<MINES; ) 
     { 
        int random = rand() % (SIDE*SIDE); 
        int x = random / SIDE; 
        int y = random % SIDE; 
        if (mark[random] == false) 
        { 
            mines[i][0]= x; 
            mines[i][1] = y; 
            rBoard[mines[i][0]][mines[i][1]] = '*'; 
            mark[random] = true; 
            i++; 
        } 
    } 
    return; 
} 

//Function for intiallising
void C_SM (char rBoard[][MAXSIDE]) 
{ 
    printf ("The mines locations are-\n"); 
    printBoard (rBoard); 
    return; 
} 
void replaceMine (int row, int col, char board[][MAXSIDE]) 
{ 
    for (int i=0; i<SIDE; i++) 
    { 
        for (int j=0; j<SIDE; j++) 
            { 
                if (board[i][j] != '*') 
                { 
                    board[i][j] = '*'; 
                    board[row][col] = '-'; 
                    return; 
                } 
            } 
    } 
    return; 
} 
void play_SM () 
{ 
    bool gameOver = false; 
    char rBoard[MAXSIDE][MAXSIDE], mBoard[MAXSIDE][MAXSIDE];
    int movesLeft = SIDE * SIDE - MINES, x, y; 
    int mines[MAXMINES][2]; 
      initialise (rBoard, mBoard); 
    placeMines (mines, rBoard); 
    int currentMoveIndex = 0; 
    while (gameOver == false) 
     { 
        printf ("Current Status of Board : \n"); 
        printBoard (mBoard); 
        makeMove (&x, &y); 
        if (currentMoveIndex == 0) 
        { 
            if (isMine (x, y, rBoard) == true) 
                replaceMine (x, y, rBoard); 
        } 
        currentMoveIndex ++; 
        gameOver = play_SMUtil (mBoard, rBoard, mines, x, y, &movesLeft); 
        if ((gameOver == false) && (movesLeft == 0)) 
         { 
            printf ("\nYou won !\n"); 
            gameOver = true; 
         } 
    } 
    return; 
} 
// Choose_DL function
int main() 
{ printf("Play and Enjoy this game, instructions are same as that of classic Minesweeper game\n");
    choose_DL (); 
    play_SM (); 
    return (0); 
}
