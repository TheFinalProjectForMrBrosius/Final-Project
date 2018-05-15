/*
Press CTRL+F and search for what ever you're looking for.

	Betting Game
	Dice Game
	Number Guessing Game

*/

#include "consoleControls.h"

int CasinoCash = RandomNumberGenerator(250000000);

bool CasinoRobbed = false;
bool Debugging = true;

namespace CasinoGames
{
	void BettingGame();
	void DiceGame();
	void NumberGuessingGame();

	// Betting Game
	void BettingGame()
	{
		SetConsoleTitle(TEXT("Betting Game"));
		std::string userStringChoice = "y";
		int userNumberChoice;
		int userBettingAmount;

		do{
			int randomNumber = RandomNumberGenerator(10); // Getting random number 1 through 10
			system("cls");
			std::cout << "You currently have $" << userCurrencyAmount << "!\n\nHow much would you like to bet: ";
			std::cin >> userBettingAmount;

			if (userBettingAmount <= 0) // seeing if the user input is less than or equal to zero
			{
				std::cout << "You can't bet below $1!" << std::endl;
			}
			else if (userBettingAmount > userCurrencyAmount) // checking to see if the betting amount is over their limit
			{
				std::cout << "You can't bet more than you have!" << std::endl;
			}
			else if (userBettingAmount <= userCurrencyAmount && userBettingAmount >= 1) // checking to see if the betting amount is less than their limit and >= 1
			{
				if (Debugging == true) { std::cout << randomNumber << std::endl; };
				std::cout << "Pick a number between 1 and 10: ";
				std::cin >> userNumberChoice;
				if (userNumberChoice == randomNumber) // checking to see if they choose randomNumber
				{
					if (DoubleEarnings == true) // seeing if they bought double earnings and if so get x4 their betting amount
					{
						userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 4);
						FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
						std::cout << "You won $" << userBettingAmount * 4 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
					}
					else // if DoubleEarnings isn't true then this happens
					{
						userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 2);
						FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
						std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
					}
				}
				else // checking to see if they lost
				{
					userCurrencyAmount = userCurrencyAmount - userBettingAmount;
					FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
					std::cout << "\nYou lost $" << userBettingAmount << "!\nThe number was " << randomNumber << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
				}
			}

			std::cout << "Would you like to continue [y|n]: "; // v
			std::cin >> userStringChoice; // seeing if they would like to continue playing this section
			TransformTextCasing("lower", userStringChoice); // transforming string to lower so there isn't multiple or statements
		} while (userStringChoice == "y" || userStringChoice == "yes");
	}

	// Dice Game 
	void DiceGame()
	{
		SetConsoleTitle(TEXT("Dice Game"));
		std::string userStringChoice = "y";
		int userNumberChoice;
		int userBettingAmount;

		do
		{
			system("cls");
			int randomNumber = RandomNumberGenerator(6);
			std::cout << "You currently have $" << userCurrencyAmount << "!\n\nHow much would you like to bet : ";
			std::cin >> userBettingAmount;
		
			if (userBettingAmount <= 0)
			{
				std::cout << "You can't bet below $1!" << std::endl;
			}
			else if (userBettingAmount > userCurrencyAmount)
			{
				std::cout << "You can't bet more than you have!" << std::endl;
			}
			else if (userBettingAmount <= userCurrencyAmount && userBettingAmount >= 1)
			{
				if (Debugging == true) { std::cout << randomNumber << std::endl; };
				std::cout << "Pick a number between 1 and 6: ";
				std::cin >> userNumberChoice;
			
				if (userNumberChoice == randomNumber)
				{
					if (DoubleEarnings == true)
					{
						userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 4);
						FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
						std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
					}
					else
					{
						userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 2);
						FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
						std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
					}
				}
				else
				{
					userCurrencyAmount = userCurrencyAmount - userBettingAmount;
					FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
					std::cout << "You lost $" << userBettingAmount << "!\nThe number was " << randomNumber << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
				}
			}

			std::cout << "Would you like to continue [y|n]: ";
			std::cin >> userStringChoice;
			TransformTextCasing("lower", userStringChoice);
		} while (userStringChoice == "y" || userStringChoice == "yes");
	}

	// Number Guessing Game
	void NumberGuessingGame()
	{
		SetConsoleTitle(TEXT("Number Guessing Game"));
		std::string userStringChoice = "y";
		int userNumberChoice;
		int userBettingAmount;

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
			else if (userBettingAmount > userCurrencyAmount)
			{
				std::cout << "You can't bet more than you have!" << std::endl;
			}
			else if (userBettingAmount <= userCurrencyAmount && userBettingAmount >= 1)
			{
				if (Debugging == true) { std::cout << randomNumber << std::endl; };
				std::cout << "Pick a number between 1 and 10: ";
				std::cin >> userNumberChoice;

				if (userNumberChoice == randomNumber)
				{
					if (DoubleEarnings == true)
					{
						userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 4);
						FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
						std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
					}
					else
					{
						userCurrencyAmount = userCurrencyAmount + (userBettingAmount * 2);
						FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
						std::cout << "You won $" << userBettingAmount * 2 << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
					}
				}
				else
				{
					userCurrencyAmount = userCurrencyAmount - userBettingAmount;
					FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
					std::cout << "You lost $" << userBettingAmount << "!\nThe number was " << randomNumber << "!\nYou currently have $" << userCurrencyAmount << "!" << std::endl;
				}
			}

			std::cout << "Would you like to continue [y|n]: ";
			std::cin >> userStringChoice;
			TransformTextCasing("lower", userStringChoice);
		} while (userStringChoice == "y" || userStringChoice == "yes");
	}

	void RobCasino()
	{
		if (CasinoRobbed == false)
		{
			int successNumber = RandomNumberGenerator(10);
			int chanceNumber = RandomNumberGenerator(successNumber);
			
			if (chanceNumber == successNumber)
			{
				system("cls");
				FileController::GetStatsFromFile("userStats.txt");
				std::cout << "You successfully robbed the bank of $" << CasinoCash << "!" << std::endl;
				userCurrencyAmount = userCurrencyAmount + CasinoCash;
				FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
				Sleep(1500);
				CasinoRobbed = true;
			}
		}
	}
}

