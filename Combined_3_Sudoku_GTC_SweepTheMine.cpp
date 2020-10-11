#include<bits/stdc++.h>
#include <cstdio>
#include<cstdlib>
#include<ctime>
#define BEGINNER 0 
#define INTERMEDIATE 1 
#define ADVANCED 2 
#define MAXSIDE 25 
#define MAXMINES 99 
#define MOVESIZE 526

using namespace std; 
int SIDE ; 
int MINES ; 

int checkSmall(int a[][9],int i,int j, int k)
{
 i=(i/3)*3;
 j=(j/3)*3;
 int i1=i,j1=j;
 for(i=i1;i<(i1+3);i++){
 	for(j=j1;j<(j1+3);j++){
 		if(k==a[i][j]){
 			return 0;
 			}
 		}
 	}
 return 1;
}
void print(int a[][9]){
 int i,j;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		printf("%2d ",a[i][j]%10);
 		if((j+1)%3==0)
 		printf("|");
 		}
 	if((i+1)%3==0){
 		printf("\n");
 		for(j=0;j<15;j++)
 			printf("_ ");
 		printf("\n");
 		}
 	printf("\n");
 }
}
int check(int a[][9],int i,int j, int k)
{
 int i1=0,j1=0;
 for(;i1<9;i1++){
 	if(k==a[i1][j])
 		return 0;
 	}
 for(;j1<9;j1++){
 	if(k==a[i][j1])
 		return 0;
 	}
 return 1;
}

int solve(int a[][9])
{
 int i,j,k;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		if(i==8&&j==8&&a[i][j]!=0){
 			return 1;
 			print(a);
 		}
 		if(a[i][j]!=0)
 			continue;
 		for(k=1;k<=10;k++){
 			if(k==10)
 				{a[i][j]=0;
 				 return -1;
 				}
 			if(checkSmall(a,i,j,k)==0)
 				continue;
 			if(check(a,i,j,k)==0)
 				continue;
 			a[i][j]=k;
 			if(solve(a)==1)
 				return 1;
 			}
 		}
 	}
 return 2;
}
int Sudoku_pass(int a[][9], int b[][9])
{
int i,j,k=0,flag=0;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		if(a[i][j]==0)
 			k=1;
 		}
 	}
 if(k==1){
 	return 0;
 }
 if(k==0){
 	for(i=0;i<9;i++){
 		for(j=0;j<9;j++){
 			k=a[i][j];
 			a[i][j]=0;
 			if(checkSmall(a,i,j,k)==0)
 				flag=1;
 			if(check(a,i,j,k)==0)
 				flag=1;
 			a[i][j]=k;
 		}
 	}
 	if(flag==0){
 		printf("You solved!!!\n");
 		print(a);
 		return 1;
 	}
 }
 if(k==0){
 	printf("Try again\nSolution of this Sudoku is\n\n");
 	solve(b);
 	print(b);
 	return 1;
 	}
 return 0;
}


void sudoku(int a[][9],int n)
{
printf("Sudoku_created\n");
	int i,b,c,d;
 srand(time(0));
 	if(n==1)n=61;
 	else if(n==2) n=55;
 	else n=40;
   for( i = 0 ; i < n ; i++ ) {
   	b=rand()%9;
   	c=rand()%9;
   	d=(rand()%9)+1;
   	if(checkSmall(a,b,c,d)==0)
 		continue;
 	if(check(a,b,c,d)==0)
 		continue;
      a[b][c]=(d);
   }
   for( i = 0 ; i < n ; i++ ) {
   	b=rand()%9;
   	c=rand()%9;
   	
    //  a[b][c]=0;
   }
   
   print(a);
}


void playsudoku(int a[][9], int b[][9])
{
	int r,c,n;
	printf("Enter row (space) column (space) number:\n");
	scanf("%d",&r);
	r%=10;
	r--;
	scanf("%d",&c);
	c%=10;
	c--;
	scanf("%d",&n);
	n%=10;
	n;
	a[r][c]=n;
	print(a);
	if(Sudoku_pass(a,b)==0)
		playsudoku(a,b);
}


int SUDOKU() 
{
 int n,i,j,num,k,a[9][9]={0},b[9][9];
 printf("Enter \n1 for Beginner Level \nor\n 2 for Intermediate level\nor\n 3 for Advanced Level\n");
 scanf("%d",&n);
/* for(k=0;k<n;k++){scanf("%d %d",&i,&j);scanf("%d",&a[i-1][j-1]);}*/
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		a[i][j]=0;
 		b[i][j]=0;
 		}
 	}
 sudoku(a,n);
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		b[i][j]=a[i][j];
 	}
 }
 playsudoku(a,b);
return 0;
}

  
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
bool play_SMUtil(char mBoard[][MAXSIDE], char rBoard[][MAXSIDE],int mines[][2], int row, int col, int *movesLeft) 
{  if (mBoard[row][col] != '-') 
        return (false); 
    int i, j; 
    if (rBoard[row][col] == '*') 
    {  mBoard[row][col]='*'; 
   for (i=0; i<MINES; i++) 
            mBoard[mines[i][0]][mines[i][1]]='*'; 
        printBoard (mBoard); 
        printf ("\nYou lost!\n"); 
        return (true) ; 
    }
   else
     {  int count = countAdjacentMines(row, col, mines, rBoard); 
        (*movesLeft)--; 
        mBoard[row][col] = count + '0'; 
        if (!count) 
        {   if (isValid (row-1, col) == true) 
            { if (isMine (row-1, col, rBoard) == false) 
                   play_SMUtil(mBoard, rBoard, mines, row-1, col, movesLeft); 
            } 
            if (isValid (row+1, col) == true) 
            { if (isMine (row+1, col, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row+1, col, movesLeft); 
            } 
            if (isValid (row, col+1) == true) 
            { if (isMine (row, col+1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row, col+1, movesLeft); 
            } 
            if (isValid (row, col-1) == true) 
            {  if (isMine (row, col-1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row, col-1, movesLeft); 
            } 
            if(isValid (row-1, col+1) == true) 
            {  if (isMine (row-1, col+1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row-1, col+1, movesLeft); 
            } 
            if (isValid (row-1, col-1) == true) 
            {   if (isMine (row-1, col-1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row-1, col-1, movesLeft); 
            } 
            if (isValid (row+1, col+1) == true) 
            {  if (isMine (row+1, col+1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row+1, col+1, movesLeft); 
            } 
            if (isValid (row+1, col-1) == true) 
            {  if (isMine (row+1, col-1, rBoard) == false) 
                    play_SMUtil(mBoard, rBoard, mines, row+1, col-1, movesLeft); 
            } 
        } 
        return (false); 
    } 
}
void placeMines(int mines[][2], char rBoard[][MAXSIDE]) 
{  bool mark[MAXSIDE*MAXSIDE]; 
    memset (mark, false, sizeof (mark));  
    for (int i=0; i<MINES; ) 
     {  int random = rand() % (SIDE*SIDE); 
        int y = random % SIDE; 
        int x = random / SIDE; 
        if (mark[random] == false) 
        {   mines[i][1] = y; 
             mines[i][0]= x; 
            rBoard[mines[i][0]][mines[i][1]] = '*'; 
            mark[random] = true; 
            i++; 
        } 
    } 
}

void initialise(char rBoard[][MAXSIDE], char mBoard[][MAXSIDE]) 
{ 
    srand(time (NULL)); 
    for (int i=0; i<SIDE; i++) 
    { 
        for (int j=0; j<SIDE; j++) 
        { 
            mBoard[i][j] = rBoard[i][j] = '-'; 
        } 
    } 
    return; 
}
void C_SM (char rBoard[][MAXSIDE]) 
{  printf ("The mines locations are-\n"); 
    printBoard (rBoard); 
    return; 
} 
void replaceMine (int row, int col, char board[][MAXSIDE]) 
{int i,j;  
for (i=0; i<SIDE; i++) 
    {   for (j=0; j<SIDE; j++) 
            {   if (board[i][j] != '*') 
                {   board[i][j] = '*'; 
                    board[row][col] = '-'; 
                    return; 
                } 
            } 
    } 
} 

void play_SM () 
{ 
    int movesLeft = SIDE * SIDE - MINES, x, y; 
    int mines[MAXMINES][2]; 
    int currentMoveIndex = 0; 
    char rBoard[MAXSIDE][MAXSIDE], mBoard[MAXSIDE][MAXSIDE];
    bool gameOver=false; 
    initialise (rBoard, mBoard); 
    placeMines (mines, rBoard); 
    while(gameOver == false) 
     { printf ("Current Status of Board : \n"); 
        printBoard (mBoard); 
        makeMove (&x, &y); 
        if (currentMoveIndex == 0) 
        {if (isMine (x, y, rBoard) == true) 
            replaceMine (x, y, rBoard);  } 
        currentMoveIndex ++; 
        gameOver = play_SMUtil (mBoard, rBoard, mines, x, y, &movesLeft); 
        if ((gameOver == false) && (movesLeft == 0)) 
         {  printf ("\nYou won !\n"); 
            gameOver = true; } 
    } 
} 

void choose_DL () 
{ 
    int level; 
    printf ("Enter the Difficulty Level\n"); 
    printf ("Press 0 for BEGINNER \n"); 
    printf ("Press 1 for INTERMEDIATE \n"); 
    printf ("Press 2 for ADVANCED\n"); 
    scanf ("%d", &level); 
    if (level == BEGINNER) 
    { 
        SIDE = 9; 
        MINES = 10; 
    } 
    if (level == INTERMEDIATE) 
    { 
        SIDE = 16; 
        MINES = 40; 
    }
    if (level == ADVANCED) 
    { 
        SIDE = 24; 
        MINES = 99; 
    } 
    return; 
}


int SWEEPTHEMINE() 
{ printf("Play and Enjoy this game, instructions are same as that of classic Minesweeper game\n");
    choose_DL (); 
    play_SM (); 
    return (0); 
}

int maxt=20;
int lf (char, string, string&);
int  GTC()
{
	string name;
	char letter;
	int nwg=0,i;
	string word;
	string words[] ={"Afghanistan", "Albania", "Algeria", "American Samoa", "Andorra", "Angola", "Anguilla", "Antarctica", "Antigua and Barbuda", "Argentina", "Armenia", "Aruba", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bermuda", "Bhutan", "Bolivia", "Bosnia and Herzegowina", "Botswana", "Bouvet Island", "Brazil", "British Indian Ocean Territory", "Brunei Darussalam", "Bulgaria", "Burkina Faso", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape Verde", "Cayman Islands", "Central African Republic", "Chad", "Chile", "China", "Christmas Island", "Cocos (Keeling) Islands", "Colombia", "Comoros", "Congo", "Congo, the Democratic Republic of the", "Cook Islands", "Costa Rica", "Cote d'Ivoire", "Croatia (Hrvatska)", "Cuba", "Cyprus", "Czech Republic", "Denmark", "Djibouti", "Dominica", "Dominican Republic", "East Timor", "Ecuador", "Egypt", "El Salvador", "Equatorial Guinea", "Eritrea", "Estonia", "Ethiopia", "Falkland Islands (Malvinas)", "Faroe Islands", "Fiji", "Finland", "France", "France Metropolitan", "French Guiana", "French Polynesia", "French Southern Territories", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Gibraltar", "Greece", "Greenland", "Grenada", "Guadeloupe", "Guam", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Heard and Mc Donald Islands", "Holy See (Vatican City State)", "Honduras", "Hong Kong", "Hungary", "Iceland", "India", "Indonesia", "Iran (Islamic Republic of)", "Iraq", "Ireland", "Israel", "Italy", "Jamaica", "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati", "Korea, Democratic People's Republic of", "Korea, Republic of", "Kuwait", "Kyrgyzstan", "Lao, People's Democratic Republic", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libyan Arab Jamahiriya", "Liechtenstein", "Lithuania", "Luxembourg", "Macau", "Macedonia, The Former Yugoslav Republic of", "Madagascar", "Malawi", "Malaysia", "Maldives", "Mali", "Malta", "Marshall Islands", "Martinique", "Mauritania", "Mauritius", "Mayotte", "Mexico", "Micronesia, Federated States of", "Moldova, Republic of", "Monaco", "Mongolia", "Montserrat", "Morocco", "Mozambique", "Myanmar", "Namibia", "Nauru", "Nepal", "Netherlands", "Netherlands Antilles", "New Caledonia", "New Zealand", "Nicaragua", "Niger", "Nigeria", "Niue", "Norfolk Island", "Northern Mariana Islands", "Norway", "Oman", "Pakistan", "Palau", "Panama", "Papua New Guinea", "Paraguay", "Peru", "Philippines", "Pitcairn", "Poland", "Portugal", "Puerto Rico", "Qatar", "Reunion", "Romania", "Russian Federation", "Rwanda", "Saint Kitts and Nevis", "Saint Lucia", "Saint Vincent and the Grenadines", "Samoa", "San Marino", "Sao Tome and Principe", "Saudi Arabia", "Senegal", "Seychelles", "Sierra Leone", "Singapore", "Slovakia (Slovak Republic)", "Slovenia", "Solomon Islands", "Somalia", "South Africa", "South Georgia and the South Sandwich Islands", "Spain", "Sri Lanka", "St. Helena", "St. Pierre and Miquelon", "Sudan", "Suriname", "Svalbard and Jan Mayen Islands", "Swaziland", "Sweden", "Switzerland", "Syrian Arab Republic", "Taiwan, Province of China", "Tajikistan", "Tanzania, United Republic of", "Thailand", "Togo", "Tokelau", "Tonga", "Trinidad and Tobago", "Tunisia", "Turkey", "Turkmenistan", "Turks and Caicos Islands", "Tuvalu", "Uganda", "Ukraine", "United Arab Emirates", "United Kingdom", "United States", "United States Minor Outlying Islands", "Uruguay", "Uzbekistan", "Vanuatu", "Venezuela", "Vietnam", "Virgin Islands (British)", "Virgin Islands (U.S.)", "Wallis and Futuna Islands", "Western Sahara", "Yemen", "Yugoslavia", "Zambia", "Zimbabwe"}; //added country name in this array
	srand(time(NULL));
	int n=rand()% 200;
	word=words[n];
	for(i = 0; i <=word.length(); i++)
  word[i] = tolower(word[i]);

	string unknown(word.length(),'*');
	cout << "\n\nWelcome to GTC...\nGUESS THE COUNTRY\n ";
	cout << "\n\nEach letter is represented by a *.";
	cout << "\n\nYou have to type only one letter in one try, only if guess is wrong your guess count will decrease ";
	 maxt=6;
	  if( maxt>20)
	  	 maxt=4;
	  else if(word.length()>10)
	  	maxt=5;
	cout << "\n\nYou have " << maxt << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   
	while (nwg < maxt)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		if (lf(letter, word, unknown)==0)
		{
			cout << endl << "That letter isn't there!" << endl;
			nwg++;
		}
		else
		{
			cout << endl << "You found a letter" << endl;
		}
		cout << "You have " << maxt - nwg;
		cout << " guesses left." << endl;
		if (word==unknown)
		{	cout << word << endl;
			cout << "You got it!";
			break;
		}
	}
	if(nwg == maxt)
	{
		cout << "\n you lose" << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

//letter_find function here
int lf (char guess, string sw, string &gw)
{
	int i;
	int mt=0;
	int len=sw.length();
	for (i = 0; i< len; i++)
	{
		if (guess == gw[i])
			return 0;
		if (guess == sw[i])
		{
			gw[i] = guess;
			mt++;
		}
	}
	return mt;
}
//functions TO CALL TO PLAY GAMES NAME
//SUDOKU
//SWEEPTHEMINE
//GTC
int main(){
GTC();
SWEEPTHEMINE();
SUDOKU();
return 0;
}
