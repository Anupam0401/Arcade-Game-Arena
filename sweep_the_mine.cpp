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

void printBoard(char mBoard[][MAXSIDE]) 
{  int i, j; 
    printf ("    "); 
    for (i=0; i<SIDE; i++) 
        printf ("%d ", i); 
    printf ("\n\n"); 
    for (i=0; i<SIDE; i++) 
    {     printf ("%d   ", i); 
        for (j=0; j<SIDE; j++) 
            printf ("%c ", mBoard[i][j]); 
        printf ("\n"); 
    } 
    return; 
}

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
//  Function to be retyped for error

// Choose_DL function
int main() 
{ printf("Play and Enjoy this game, instructions are same as that of classic Minesweeper game\n");
    choose_DL (); 
    play_SM (); 
    return (0); 
}
