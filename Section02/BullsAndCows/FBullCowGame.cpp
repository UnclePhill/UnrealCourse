#include "FBullCowGame.h"

using int32 = int;//just a test for changes....

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); }
int32 FBullCowGame::GetMaxTries()const{return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry()const{return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

//receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;


	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) //compare letters against the hidden word
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			if (MyHiddenWord[MHWChar] == Guess[GChar]) //if they match then
			{
				if (MHWChar == GChar) //if they match then
				{
					BullCowCount.Bulls++;//increment bulls 
					}
					else //if they are in the wrong place
					{
						BullCowCount.Cows++;//inciment cows
				}
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}
