#pragma once
#include <string>
#include <iostream>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetCurrentTry() const;
	int32 GetMaxTry() const;
	int32 GetCurrentWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); // TODO develop more rich return value
	void SetCurrentTry(int32);
	void SetGameWon(bool);
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTry;
	bool bIsGameWon;

	FString MyHiddenWord;
};