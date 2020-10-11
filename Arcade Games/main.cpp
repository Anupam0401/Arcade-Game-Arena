#include<SFML\Graphics.hpp>
#include<random>
#include<ctime>
#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include <cmath>
#include<bits/stdc++.h>
#include <cstdio>
#include<cstdlib>
#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526

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
void escape_the_maze();          

void tic_tac_toe();                


int winner();                  //to find who wins the match

void board();                  // to create tic-toe board display


void player_hit();             // function for when the player hits an enemy


int endfunc(int e);

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
	printf("\n ::::::::::::::::::::::::::::::::::    WELCOME to the SUDOKU game    :::::::::::::::::::::::::::::::::::::\n\n\n");
    delay(3000);
printf("\n ::::::::::::::::::::::::::::::::::    It is classic Sudoku Game   :::::::::::::::::::::::::::::::::::::\n\n\n");
    delay(3000);
printf("\n::::::::::::::::::::::::::::::::::::::::::::::  INSTRUCTIONS  ::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    delay(1500);
printf("\n::::::::::::::::::::::::::::::::Fill each and every box with number in between 1 to 9:::::::::::::::::::::::::::::::::::\n");
    delay(1500);
printf("\n:::::::::::::::::::::::::::::::Replace each 0 in matrix with another number ::::::::::::::::::::::::::::::::\n");
    delay(1500);
printf("\n:::::::::::::::::::::::::::::::Input should be like row number( space) column number (space) NUMBER (to input) ::::::::::::::::::::::::\n");
    delay(1500);
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


/*void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}*/

void Jumping_Jack()
{
    printf("\n ::::::::::::::::::::::::::::::::::    WELCOME to the JUMPING JACK game    :::::::::::::::::::::::::::::::::::::\n\n\n");
    delay(3000);
    printf("\n -- The doodle is trapped somewhere to the south of the EARTH and is jumping the platforms to reach the Earth --\n");
    delay(5000);
    printf("\n:::::::::::::  Help Doodle escape this deadly trap and escort him to EARTH by making correct moves  ::::::::::::\n\n\n");
    delay(4000);
    printf("\n::::::::::::::::::::::::::::::::::::::::::::::  INSTRUCTIONS  ::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    delay(1500);
    printf("\n ********************************   Use arrow keys to move left or right   **************************************\n");
    delay(2000);
    printf("\n *******************   The DOODLE jumps automatically after hitting the green platform   ************************\n");
    delay(3000);
    printf("\n ********************    Keep on jumping over the platforms to gain heights and score points    *****************\n");
    delay(5000);
    printf("\n XXXXXXX   WARNING : Don't miss a platform else you fall into the infinite space and get trapped there    XXXXXXX\n\n\n");
    delay(5000);
    printf("\n***************************************   GET READY.......LET'S BEGIN :)   ***************************************");
    delay(2000);
    printf("\n");

	sf::RenderWindow window(sf::VideoMode(500, 700), "Doodle Jump", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::Texture platformTexture;
	backgroundTexture.loadFromFile("images/background.jpg");
	playerTexture.loadFromFile("images/doodle.png");
	platformTexture.loadFromFile("images/platform.png");
	sf::Sprite background(backgroundTexture);
	sf::Sprite player(playerTexture);
	sf::Sprite platform(platformTexture);

	sf::RectangleShape gameoverBackground(sf::Vector2f(500, 700));
	gameoverBackground.setFillColor(sf::Color::Blue);

	sf::Font font;
	font.loadFromFile("font/EvilEmpire.ttf");
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Yellow);
	sf::Text gameoverText;
	gameoverText.setFont(font);
	gameoverText.setString(" Game Over......... '_'");
	gameoverText.setCharacterSize(50);
	gameoverText.setFillColor(sf::Color::Red);

	// initialize platforms
	sf::Vector2u platformPosition[10];
	std::uniform_int_distribution<unsigned> x(0, 500 - platformTexture.getSize().x);
	std::uniform_int_distribution<unsigned> y(100, 700);
	std::default_random_engine e(time(0));
	for (size_t i = 0; i < 10; ++i)
	{
		platformPosition[i].x = x(e);
		platformPosition[i].y = y(e);
	}

	// player's position and down velocity
	int playerX = 250;
	int playerY = 151;
	float dy = 0;
	int height = 150;
	int score = 0;

	// player's bounding box. It should modify according to the image size
	const int PLAYER_LEFT_BOUNDING_BOX = 20;
	const int PLAYER_RIGHT_BOUNDING_BOX = 60;
	const int PLAYER_BOTTOM_BOUNDING_BOX = 70;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			playerX -= 4;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			playerX += 4;
		if (playerX > 500)
			playerX = 0;
		if (playerX < -40)
			playerX = window.getSize().x - playerTexture.getSize().x;
		if (playerY == height && dy < (-1.62))
		{
			score += 1;
			scoreText.setString("Score = " + std::to_string(score));
		}

		// player's jump mechanism
		dy += 0.2;
		playerY += dy;

		if (playerY < height)
			for (size_t i = 0; i < 10; ++i)
			{
				playerY = height;
				platformPosition[i].y -= dy;  // vertical translation
				if (platformPosition[i].y > 700) // set new platform on the top
				{
					platformPosition[i].y = 0;
					platformPosition[i].x = x(e);
				}

			}
		// detect jump on the platform
		for (size_t i = 0; i < 10; ++i)
		{
			if ((playerX + PLAYER_RIGHT_BOUNDING_BOX > platformPosition[i].x) && (playerX + PLAYER_LEFT_BOUNDING_BOX < platformPosition[i].x + platformTexture.getSize().x)        // player's horizontal range can touch the platform
				&& (playerY + PLAYER_BOTTOM_BOUNDING_BOX > platformPosition[i].y) && (playerY + PLAYER_BOTTOM_BOUNDING_BOX < platformPosition[i].y + platformTexture.getSize().y)  // player's vertical   range can touch the platform
				&& (dy > 0)) // player is falling
			{
				dy = -10;
			}

		}
		player.setPosition(playerX, playerY);

		window.draw(background);
		window.draw(player);

		// set and draw platforms
		for (size_t i = 0; i < 10; ++i)
		{
			platform.setPosition(platformPosition[i].x, platformPosition[i].y);
			window.draw(platform);
		}

		// game over
		if (playerY > 700)
		{
			gameoverText.setPosition(30, 200);
			scoreText.setPosition(150, 400);
			goto gameover;
		}
		window.draw(scoreText);
		window.display();
	}

	// Game Over
gameover:
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(gameoverBackground);
		window.draw(gameoverText);
		window.draw(scoreText);
		window.display();
	}

}

void catch_your_enemy(){
    cout<<"\n\t Welcome to the 'CATCH  YOUR  ENEMY' Game\n";
    delay(3000);
    cout<<"\n\tUse arrow keys to move yourself and reach your enemy who has cloned you\n ";
    delay(4000);
    cout<<"\n\tBut as soon as you catch him he disappears and spawns at a different location , so go after him\n";
    delay(5000);
    cout<<"\n   Alert : Your Enemy has planted bombs outside the yellow boundary so, stay inside the boundary and catch your enemy.\n";
    delay(6000);
    cout<<"\n\tSO, LET'S BEGIN!!";
    delay(1000);
    int gd,gm,rx=200,ry=200,x,y,d/*dirction*/,f=1/*Food eaten*/,dir=1/*direction*/;
   // srand(time(NULL));
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    setfillstyle(8,1);//(style,color)
    x=200,y=200;

d=1;

delay(5000);
for(;;){

    setfillstyle(8,4);
    bar(0,0,640,480);
    setfillstyle(1,14);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
   // food taken?
   if(x==rx && y==ry ){

        f=f+1;
    setfillstyle(8,4);
    bar(rx,ry,rx+10,ry+10);

    //make food
   do {
	rx = (1+rand()%630);
	ry = (1+rand()%470);
    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);
    rx=rx/10;
    rx=rx*10;
    ry=ry/10;
    ry=ry*10;
    setfillstyle(8,14);

    }
    bar(rx,ry,rx+10,ry+10);

    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
   else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
   else{d=0;}
    int n;

    switch(d){
    case 0:
      if(dir==1){x=x+10;}
      else if(dir==2){x=x-10;}
      else if(dir==3){ y=y-10;}
      else if(dir==4) {y=y+10;}
      else{d=0;}
        break;
    case 1:
           x=x+10;
           dir=1;
           break;
    case 2:
         x= x-10;
         dir=2;
          break;
    case 3:
        dir=3;
        y=y-10;
        break;
    case 4:
        dir=4;
       y= y+10;
        break;
    }
bar(x,y,x+10,y+10);
delay(100);
printf("%d     %d    %d   %d   \n",x,y,rx,ry);
if(x>=640 || x<=0|| y<=0 || y>=480){
    endfunc(f);
    break;
}
}
}
int endfunc(int e){
    setfillstyle(8,5);
    e=e-2;
    bar(0,0,640,470);
    system("cls");
    printf("Alas, You died outside the boundary!!!\n");
    cout<<"Don't let this happen again!\n\n";
    printf("Your score is : %d\n", e);
    getch();
}



/*-------------------------------------------------------------------------------------------------------------------*/


//driver function
int main()
{
    int choice;
    cout<<"\nPress 1 for Catch your enemy\n\n";
    cout<<"Press 2 for Escape the maze\n\n";
    cout<<"Press 3 for Tic-tac-toe\n\n";
    cout<<"Press 4 for sweep the mine\n\n";
    cout<<"Press 5 for sudoku\n\n";
    cout<<"Press 6 for GTC\n\n";
    cout<<"Press 7 for Jumping Jack\n\n";
    cout<<"\nEnter your choice\n\n";
    cin>>choice;
    if(choice==1)
        catch_your_enemy();
    else if(choice==2)
        escape_the_maze();
    else if(choice==3)
        tic_tac_toe();
    else if(choice==4)
        SWEEPTHEMINE();
    else if(choice==5)
        SUDOKU();
    else if(choice==6)
        GTC();
    else if(choice==7)
        Jumping_Jack();
    else
        return 0;
}

/*------------------------------------------------------------------------------------------------*/

//function for tic_tac_toe game
void tic_tac_toe()
{	
    printf("\n ::::::::::::::::::::::::::::::::::    WELCOME to the TIC-TAC-TOE game    :::::::::::::::::::::::::::::::::::::\n\n\n");
    delay(3000);
    printf("\n --------------------------------------THIS GAME REQUIRES TWO PLAYERS ------------------------------------------------\n");
    delay(5000);
    printf("\n::::::::::::::::::::::::::::::::::::::::player 1 (X) V/S player 2 (O)::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    delay(4000);
    printf("\n::::::::::::::::::::::::::::::::::::::::::::::  INSTRUCTIONS  ::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    delay(1500);
    printf("\n ***************************Use grid numbers 1 to 9 for selecting the respective grid**************************************\n");
    delay(2000);
    printf("\n ************************** The game is played on a grid that's 3 squares by 3 squares ***************************\n");
    delay(3000);
    printf("\n **************You are X, your friend is O. Players take turns putting their marks in empty squares**********************\n");
    delay(5000);
    printf("\n **********The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner**********************\n");
    delay(5000);
    printf("\n *******************************When all 9 squares are full, the game is over.**********************\n");
    delay(5000);
    printf("\n XXXXXXX   WARNING : Don't miss a platform else you fall into the infinite space and get trapped there    XXXXXXX\n\n\n");
    delay(5000);
    printf("\n***************************************   GET READY.......LET'S BEGIN :)   ***************************************");
    delay(2000);
    printf("\n");
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
{   printf("\n ::::::::::::::::::::::::::::::::::    WELCOME to the ESCAPE THE MAZE game    :::::::::::::::::::::::::::::::::::::\n\n\n");
    delay(3000);
    printf("\n::::::::::::::::::::::::::::::::::::::::::::::  INSTRUCTIONS  ::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    delay(1500);
    printf("\n **********************MISSION - you have to get out of the maze without meeting any enemies**************************************\n");
    delay(2000);
    printf("\n ************************** -player symbol is 'O' and enemies are 'H' , 'V' , 'J' ***************************\n");
    delay(3000);
    printf("\n *********************-use (d) (a) (w) or (s) to move -  right left up or down respectively**********************\n");
    delay(5000);
    printf("\n **********NOTE : 1. if you hit/meet with enemy , game again starts from starting point in maze**********************\n");
    delay(5000);
    printf("\n ******************************* 2. if hp becomes 0 ,you lose the game**********************\n");
    delay(5000);
    printf("\n ********************3. game also shows location and health when required at bottom of maze**********************\n");
    delay(5000);
    printf("\n *************************-press (d) (a) (w) or (s) and then return to start the game**********************\n");
    delay(5000);
    printf("\n *******************************-press (q) then return to quit the game**********************\n");
    delay(5000);
    printf("\n XXXXXXX   WARNING : Don't miss a platform else you fall into the infinite space and get trapped there    XXXXXXX\n\n\n");
    delay(5000);
    printf("\n***************************************   GET READY.......LET'S BEGIN :)   ***************************************");
    delay(2000);
    printf("\n");

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
