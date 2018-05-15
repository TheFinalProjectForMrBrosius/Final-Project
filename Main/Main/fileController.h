#pragma once

#include <sstream>
#include <fstream>

double userCurrencyAmount = 0;
int resetAmount = 500;

namespace FileController
{
	void ClearFile(std::string fileName);
	void GetStatsFromFile(std::string fileName);
	void GiveCash(std::string fileName);

	void ClearFile(std::string fileName)
	{
		std::ofstream file_;
		file_.open(fileName);
		file_ << "";
		file_.close();
	}
	void GetStatsFromFile(std::string fileName)
	{
		std::string currentLine;

		std::ifstream file_(fileName);

		if (file_.is_open())
		{
			while (std::getline(file_, currentLine))
			{
				std::stringstream convert(currentLine);
				if (!(convert >> userCurrencyAmount))
				{
					userCurrencyAmount = 500;
				}
			}
			file_.close();
		}
	}

	void SaveStatsToFile(std::string fileName, int userCurrency)
	{
		ClearFile(fileName);
		std::string currentLine, textToAdd;
		std::fstream file_;
		file_.open(fileName, std::fstream::app);
		file_ << userCurrency << std::endl;
		file_.close();
	}

	void GiveCash()
	{
		GetStatsFromFile("userStats.txt");
		double amountToAdd = 0;
		std::cout << "\nHow much cash would you like to add: ";
		std::cin >> amountToAdd;
		userCurrencyAmount = userCurrencyAmount + amountToAdd;
		SaveStatsToFile("userStats.txt", userCurrencyAmount);
	}

	void ResetCash()
	{
		GetStatsFromFile("userStats.txt");
		userCurrencyAmount = resetAmount;
		SaveStatsToFile("userStats.txt", userCurrencyAmount);
	}
}
