#include "Hangman.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>

void Hangman::displayWord(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		cout << word[i];
		if (i + 1 < word.length())
		{
			cout << ' ';
		}
	}
	cout << endl;
	return;
}

bool Hangman::checkGuess(char guess, string word, string & unknownWord)
{
	bool found = false;
	guess = char(tolower(guess));
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == guess)
		{
			found = true;
			unknownWord[i] = guess;
		}
	}
	return found;
}

Hangman::Hangman()
{
}


Hangman::~Hangman()
{
}

//This function uses fstream from chapter 12
//and strings from Chapter 10
void Hangman::ReadInWords(string filename)
{
	ifstream file(filename);
	string s;
	while (getline(file, s))
	{
		wordList[numWords] = s;
		numWords++;
		if (numWords == MAXWORDS)
		{
			cout << "Maximum amount of words reached.\n";
			break;
		}
	}
	file.close();
}

void Hangman::Play()
{
	//Select a word
	srand(time(NULL));
	int randNum = rand() % numWords;
	string word = wordList[randNum];
	string unknownWord(word.length(), '_');
	
	int numGuesses = 0;
	while (numGuesses < MAXGUESSES)
	{
		displayWord(unknownWord);
		cout << "Number of wrong guesses left: " << MAXGUESSES - numGuesses << endl;
		cout << "Enter your guess: ";
		char guess;
		string input;
		getline(cin, input);
		if (stringstream(input) >> guess)
		if (checkGuess(guess, word, unknownWord) == true)
		{
			if (unknownWord == word)
			{
				displayWord(word);
				cout << "Congratulations! You guessed the word!" << endl;
				break;
			}
		}
		else
		{
			numGuesses++;
		}
	}
	if (numGuesses == MAXGUESSES)
	{
		cout << "You lost. The word was: " << word << endl;
		numLosses++;
	}
	else
	{
		cout << "You win!" << endl;
		numWins++;
	}
	cout << "Your record is " << numWins << " wins and " << numLosses << " losses.\n";
	return;
}
