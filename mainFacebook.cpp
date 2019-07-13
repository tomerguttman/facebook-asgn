/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#include "main_functions.h"
#include <Windows.h>
using namespace std;

void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Facebook FacebookNow;
	bool fContinue = true;
	int numAction;
	while (fContinue)
	{
		cout << endl;
		printMenu();
		cin >> numAction;
		if (numAction > 15 || numAction < 1)
			while (numAction > 15 || numAction < 1)
			{
				cout << "! ! ! WRONG INPUT ! ! !\n";
				printMenu();
				cin.clear();
				cin.ignore();
				cin >> numAction;
			}//end while
		getActionChosen(FacebookNow, fContinue, numAction);
	}//end while.
}//end main;