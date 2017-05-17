/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetGuess();

FBullCowGame BCGame;//instantiate a new game (make an istance of a new game)

//the entry point for the application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}

//introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset(); //set the initial values of the current and max tries
	int32 MaxTries = BCGame.GetMaxTries();//assign the max tries to a localy accesible variable 
	int32 CurrentTry = BCGame.GetCurrentTry();//assign the current try to a locally accesible variable
	std::cout << "You have " << MaxTries << " tries.\n";
	//loop for number of turns asking for guess
	//TODO change FOR to WHILE loop once we are validating tries
	do
	{
		FText Guess = GetGuess(); //TODO make loop checking valid guess
		//Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
		CurrentTry++;
	} while (CurrentTry <= MaxTries);

	// TODO summarise game
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

//get a guess from the player and print it back
FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}