#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//initialises all values to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); //Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const;

	void Reset();//TODO make a more rich return value
	FBullCowCount SubmitGuess(FString);

//Please ignore this for now
private:
	//values are set in the constructor.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};