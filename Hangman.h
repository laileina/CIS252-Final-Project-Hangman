#pragma once
#include <string>
using namespace std;

const int MAXWORDS = 100;
const int MAXGUESSES = 5;

//Uses classes from Chapter 13
class Hangman
{
private:
	//Private variables
	string wordList[MAXWORDS];
	int numWords = 0;
	int numWins = 0;
	int numLosses = 0;

	//Private member functions
	void displayWord(string word);
	bool checkGuess(char guess, string word, string & unknownWord);
public:
	Hangman();
	~Hangman();
	void ReadInWords(string filename);
	void Play();
};

