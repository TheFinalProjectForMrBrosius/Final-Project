#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <Windows.h>

#include "fileController.h"
#include "logController.h"

namespace ShopControl // Setting namespace so we can do ShopControl::functionname
{
	void ShowShop(int userCurrencyAmount)
	{
		system("cls");
		std::cout << "You currently have $" << userCurrencyAmount << "\n" << std::endl;
		SetConsoleTitle(TEXT("Bobby's Shop"));

		int userItemChoice;
		std::string userConfirmation;

		for (int x = 0; x < itemNamesCount; x++)
		{
			std::cout << "[" << x + 1 << "] Item: " << itemNames[x] << " | Price: " << itemPrices[x] << std::endl; // shows all the items and their prices in their array
		}

		std::cout << "\nWhat would you like to buy: ";
		std::cin >> userItemChoice; // getting user input

		switch (userItemChoice)
		{
		case 1:
			if (userCurrencyAmount >= itemPrices[0] && DoubleEarnings != true)
			{
				std::cout << itemPrices[1];
				userCurrencyAmount = userCurrencyAmount - itemPrices[0];
				DoubleEarnings = true;
				std::cout << "\nSuccessfully bought DoubleEarnings!" << std::endl;
				FileController::SaveStatsToFile(userCurrencyAmount);
			}
			else
				std::cout << "\nYou do not have enough money to purchase DoubleEarnings or you already have it!" << std::endl;
			break;
		case 2:
			if (userCurrencyAmount >= 50 && MoreTextColors != true)
			{
				userCurrencyAmount = userCurrencyAmount - 50;
				MoreTextColors = true;
				std::cout << "\nSuccessfully bought MoreTextColors" << std::endl;
				FileController::SaveStatsToFile(userCurrencyAmount);
			}
			else
				std::cout << "\nYou do not have enough money to purchase MoreTextColors or you already have it!" << std::endl;
			break;
		default:
			std::cout << "Please enter a valid number 1-" << itemNamesCount << "!" << std::endl;
			ShopControl::ShowShop(userCurrencyAmount);
		}
	}
}