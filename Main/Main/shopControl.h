#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

#include "fileController.h"

std::string itemNames[] = { "DoubleEarnings", "MoreTextColors"};
int itemPrices[] = { 10, 1 };

bool DoubleEarnings = false;
bool MoreTextColors = false;

namespace ShopControl // Setting namespace so we can do ShopControl::function
{
	void ShowShop(double userCurrencyAmount)
	{
		system("cls");
		SetConsoleTitle(TEXT("Bobby's Shop"));

		std::string userItemChoice;
		std::string userConfirmation;

		for (int x = 0; x < 2; x++)
		{
			std::cout << "Item: " << itemNames[x] << " | Price: " << itemPrices[x] << std::endl; // shows all the items and their prices in their array
		}

		std::cout << "What would you like to buy: ";
		std::cin >> userItemChoice; // getting user input

		for (int x = 0; x < 2; x++)
		{
			if (userItemChoice == itemNames[x]) // seeing if the user input matches the element in the itemNames array
			{
				std::cout << "Are you sure you would like to buy [" << userItemChoice << " for $" << itemPrices[x] << "]?: "; // asking if the person is sure they went to purchase that item
				std::cin >> userConfirmation;
				std::transform(userConfirmation.begin(), userConfirmation.end(), userConfirmation.begin(), ::tolower); // transform user confirmation to lower
				if (userConfirmation == "yes" || userConfirmation == "y")
				{
					if (userCurrencyAmount >= itemPrices[x])
					{
						if (userItemChoice == "DoubleEarnings" && DoubleEarnings != true) // checking to see if the user input is DoubleEarnings and the boolean DoubleEarnings isn't true
						{
							userCurrencyAmount = userCurrencyAmount - itemPrices[x]; // deducting the item price amount
							FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
							DoubleEarnings = true;
							std::cout << "\nSuccessfully bought " << userItemChoice << "!" << std::endl;
						}
						else if (userItemChoice == "MoreTextColors" && MoreTextColors != true)
						{
							userCurrencyAmount = userCurrencyAmount - itemPrices[x];
							FileController::SaveStatsToFile("userStats.txt", userCurrencyAmount);
							MoreTextColors = true;
							std::cout << "\nSuccessfully bought " << userItemChoice << "!" << std::endl;
						}
					}
				}
			}
		}
	}
}