#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame FBCGame;

// Program entry point
int main ()
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());
	return EXIT_SUCCESS; // Exit application
}

void PlayGame()
{
	FBCGame.Reset();
	int32 MaxTries = FBCGame.GetMaxTry();

	// Loop for the number of turns and get guesses and print them to the consoel
	while (!FBCGame.IsGameWon() && FBCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = FBCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
	}

	// TODO show  a game summary
}

// Print intro text to the console
void PrintIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows" << std::endl;
	std::cout << "Would you guess the " << FBCGame.GetCurrentWordLength() << " letter isogram?" << std::endl;
	return;
}

// Get guess from player
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;

	do {
		// Get a guess from the player
		int32 CurrentTry = FBCGame.GetCurrentTry();
		std::cout << std::endl << "Try: " << CurrentTry << " What is your guess? ";
		getline(std::cin, Guess);


		EGuessStatus Status = FBCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << FBCGame.GetCurrentWordLength() << " letter word.\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lower case word\n";
			break;

		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain()
{
	std::cout << "Play again? ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
