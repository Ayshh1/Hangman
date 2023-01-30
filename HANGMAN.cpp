

#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;
 
int TOTAL_TRIES=3;
int checkGuess (char, string, string&);
void main_menu();
string message = "LETS START THE GAME! ENTER A LETTER YOU THINK IS A PART OF THIS NUMBER";
 
 
int main()
{
	string NAME,MONTH;
	char letter;
	
	
 
    string MONTHS[] =
	{
	    "january",
		"feburary",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
		};
	
	srand(time(NULL));
		int n=rand()%100;
    MONTH=MONTHS[n];
    
	
	string hide_m(MONTH.length(),'X');
 
	while (TOTAL_TRIES!=0)
	{
		main_menu();
		cout << "         " << hide_m;
		cout << "     Guess a letter: ";
		cin >> letter;
		
		if (checkGuess(letter, MONTH, hide_m)==0)
		{
			message = "WHOPS ,Incorrect letter.";
			TOTAL_TRIES = TOTAL_TRIES - 1;
		}
		else
		{
			message = "NICE! You guess a letter";
		}
 
 
		
		if (MONTH==hide_m)
		{
			message = "Congratulations! YOU WONNNNN YAYYAYAYAYYAYAYAYAYYAYYYYY!!!!!!!";
			main_menu();
			cout << "\n\t\t\t\tThe day is : " << MONTH << endl;
			
		}
	}
	if(TOTAL_TRIES == 0)
	{
		message = "WHOOPSSS...YOUVE BEEN HANGED X_X.";
		main_menu();
		cout << "The day was : " << MONTH << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}
 
 
int checkGuess (char guess, string secretmonth, string &guessmonth)
{
	int i;
	int match=0;
	int x=secretmonth.length();
	for (i = 0; i< x; i++)
	{
		
		if (guess == guessmonth[i])
			return 0;
		
		if (guess == secretmonth[i])
		{
			guessmonth[i] = guess;
			match++;
		}
	}
	return match;
}
 
void main_menu()
{
	string your_name;
cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"X_X        X_X          X_X       X_X          X_X      X_X         X_X        X_X      X_X          X_X      "<<endl;
cout<<"__________________________________________________________________________________________________________________"<<endl;
cout<<"                                    H-A-N-G-M-A-N       G-A-M-E               "<<endl;
 cout<<"_________________________________________________________________________________________________________________"<<endl;
 cout<<"X_X        X_X          X_X       X_X          X_X      X_X         X_X        X_X      X_X         X_X      "<<endl;
                cout<<"-----------------------------INSTRUCTIONS---------------------------------"<<endl;
                cout<<"         YOU HAVE "<<TOTAL_TRIES<<" TRIES LEFT TO GUESS THE MONTH NAME"<<endl;
				
				cout<<"          "+message<<endl;
 cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
 
 
 
}

