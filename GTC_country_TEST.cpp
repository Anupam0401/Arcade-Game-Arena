#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;
int maxt=20;
int lf (char, string, string&);
int main ()
{
	string name;
	char letter;
	int nwg=0,i;
	string word;
	string words[] ={	}; //ADD country name in this array
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
// ADD letter_find function() here by the name lf()

