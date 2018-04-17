#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	MyCurrentTry = 1;
	MyMaxTry = 5;
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTry() const { return MyMaxTry; }
int32 FBullCowGame::GetCurrentWordLength() const{ return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetCurrentWordLength() != Guess.length())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTry = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bIsGameWon = false;

	return;
}

void FBullCowGame::SetCurrentTry(int32 value)
{
	MyCurrentTry = value;
	return;
}

void FBullCowGame::SetGameWon(bool GameWon)
{
	bIsGameWon = GameWon;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
		// compare letters against the hidden word
	int32 HiddenWordLength = GetCurrentWordLength();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == HiddenWordLength)
	{
		SetGameWon(true);
	}
	else
	{
		SetGameWon(false);
	}

	return BullCowCount;
}
