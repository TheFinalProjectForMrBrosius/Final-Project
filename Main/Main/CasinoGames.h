/*
Press CTRL+F and search for what ever you're looking for.
-----/ Games \-----
	Betting Game
	Dice Game
	Number Game

-----/ Text Stuffs \-----
	   Text Casing
	   Text Color

-----/ User Stuff \-----
	   User Stuff
*/

#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <Windows.h>


void TransformTextColor();
std::string TransformTextCasing(std::string type, std::string text);
void WelcomeMessage();
int RandomNumberGenerator(int maxNumber);

void BettingGame();


// Text Color
void TransformTextColor()
{
	SetConsoleTitle(TEXT("Text Color Changer"));
	system("cls");
	int userNumberChoice;
	for (int x = 1; x < 16; x++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
		std::cout << x << " ";
	}
	std::cout << "\n\nWhat number would you like: ";
	std::cin >> userNumberChoice;

	if (userNumberChoice <= 15 && userNumberChoice >= 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), userNumberChoice);
		std::cout << "Successfully changed text color!" << std::endl;
	}
}

// Text Casing
std::string TransformTextCasing(std::string type, std::string text)
{
	std::transform(type.begin(), type.end(), type.begin(), ::tolower);
	if (type == "lower")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	}
	else if (type == "upper")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	}
	return text;
}

// Welcome message
void WelcomeMessage()
{
	std::cout << "|------------------------------------|" << std::endl;
	std::cout << "|     Welcome to That one Casino     |" << std::endl;
	std::cout << "|------------------------------------|" << std::endl;
}


// Random Number Generator
int RandomNumberGenerator(int maxNumber)
{
	srand(time(NULL));
	return rand() % maxNumber + 1;
}

// User Stuff
double userCurrencyAmount = RandomNumberGenerator(500);

// Betting Game
void BettingGame()
{
	SetConsoleTitle(TEXT("Betting Game"));
	std::string userStringChoice = "y";
	int userNumberChoice;
	double userBettingAmount;

	do{
		int randomNumber = RandomNumberGenerator(10);
		system("cls");
		std::cout << "You currently have $" << userCurrencyAmount << "!\n\nHow much would you like to bet: ";
		std::cin >> userBettingAmount;

		if (userBettingAmount <= 0)
		{
			std::cout << "You can't bet below $1!" << std::endl;
		}
		else if (userBettingAmount >= userCurrencyAmount)
		{
			std::cout << "You can't bet more than you have!" << std::endl;
		}
		else if (userBettingAmount <= userCurrencyAmount && userBettingAmount >= 1)
		{
			std::cout << "Pick a number between 1 and 10: ";
			std::cin >> userNumberChoice;
			if (userNumberChoice == randomNumber)
			{
				userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 2);
				std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
			}
			else
			{
				userCurrencyAmount = userCurrencyAmount - userBettingAmount;
				std::cout << "\nYou lost $" << userBettingAmount << "!\nThe number was " << randomNumber << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
			}
		}

		std::cout << "Would you like to continue [y|n]: ";
		std::cin >> userStringChoice;
		TransformTextCasing("lower", userStringChoice);
	} while (userStringChoice == "y" || userStringChoice == "yes");
}

// Dice Game
void DiceGame()
{
	SetConsoleTitle(TEXT("Dice Game"));
	std::string userStringChoice = "y";
	int userNumberChoice;
	double userBettingAmount;

	do
	{
		system("cls");
		int randomNumber = RandomNumberGenerator(10);
		std::cout << "You currently have $" << userCurrencyAmount << "!\n\nHow much would you like to bet : ";
		std::cin >> userBettingAmount;
		
		if (userBettingAmount <= 0)
		{
			std::cout << "You can't bet below $1!" << std::endl;
		}
		else if (userBettingAmount >= userCurrencyAmount)
		{
			std::cout << "You can't bet more than you have!" << std::endl;
		}
		else if (userBettingAmount <= userCurrencyAmount && userBettingAmount >= 1)
		{
			std::cout << "Pick a number between 1 and 6: ";
			std::cin >> userNumberChoice;
			
			if (userNumberChoice == randomNumber)
			{
				userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 2);
				std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
			}
			else
			{
				userCurrencyAmount = userCurrencyAmount - userBettingAmount;
				std::cout << "You lost $" << userBettingAmount << "!\nThe number was " << randomNumber << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
			}
		}

		std::cout << "Would you like to continue [y|n]: ";
		std::cin >> userStringChoice;
		TransformTextCasing("lower", userStringChoice);
	} while (userStringChoice == "y" || userStringChoice == "yes");
}