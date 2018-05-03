// This program implements a game of hangman.
// It incorporates strings from Chapter 10,
// Advanced File Operations from Chapter 12,
// and Classes from Chapter 13.

// Ashley Kennedy

#include <iostream>
#include <sstream>
#include "Hangman.h"

int main()
{
	Hangman hangman;
	hangman.ReadInWords("WordList.txt");
	cout << "Welcome to Hangman." << endl << endl;
	int choice = 0;
	string input = "";
	while (choice != 2)
	{
		cout << "Type 1 to play.\nType 2 to exit.\n";
		getline(cin, input);
		if (stringstream(input) >> choice)
		{
			if (choice == 1)
			{
				hangman.Play();
			}
			else if (choice == 2)
			{
				break;
			}
		}
	}
    return 0;
}

