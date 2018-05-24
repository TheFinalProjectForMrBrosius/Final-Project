#pragma once

#include <sstream>
#include <fstream>
#include <exception>

#include "logController.h"

std::string itemNames[] = { "doubleearnings", "moretextcolors"};
int itemPrices[] =		  {      10000,             50, };
int itemNamesCount = (sizeof(itemNames) / sizeof(itemNames[0]));

bool DoubleEarnings = false;
bool MoreTextColors = false;

int userCurrencyAmount = 0;

int resetAmount = 500;

namespace FileController
{
	void ClearFile(std::string fileName);
	void SaveStatsToFile(int userCurrency);
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
		int a = 0;

		std::ifstream file_(fileName);

		if (file_.is_open())
		{
			while (std::getline(file_, currentLine))
			{
				a++;
				if (a == 1)
				{
					std::stringstream convert(currentLine);
					if (!(convert >> userCurrencyAmount))
					{
						userCurrencyAmount = 500;
					}
				}
				else if (a == 2)
				{
					std::stringstream convert(currentLine);
					if (!(convert >> MoreTextColors))
					{
						MoreTextColors = false;
					}
				}
				else if (a == 3)
				{
					std::stringstream convert(currentLine);
					if (!(convert >> DoubleEarnings))
					{
						DoubleEarnings = false;
					}
				}
			}
			file_.close();
		}
		else if (!file_.is_open())
		{
			std::ofstream newFile_("UserStats.stats");
			if (newFile_.is_open())
			{
				SaveStatsToFile(500);
			}
		}
		Log::NewLog("Loaded stats!");
	}

	void SaveStatsToFile(int userCurrency)
	{
		ClearFile("UserStats.stats");
		std::string currentLine, textToAdd;
		std::fstream file_;

		file_.open("UserStats.stats", std::fstream::app);
		file_ << userCurrency << std::endl;
		file_ << MoreTextColors << std::endl;
		file_ << DoubleEarnings << std::endl;
		file_.close();
		Log::NewLog("Saved stats!");
	}

	void GiveCash()
	{
		GetStatsFromFile("UserStats.stats");
		int amountToAdd = 0;
		std::cout << "\nHow much cash would you like to add (minimum $100): ";
		std::cin >> amountToAdd;
	 if (amountToAdd >= 100) 
		{
			userCurrencyAmount = userCurrencyAmount + amountToAdd;
			SaveStatsToFile(userCurrencyAmount);
			Log::NewLog("Gave self money!");	
		}
	}

	/*void GiveCash()
	{
		int amountToAdd = 0;
		std::cout << "\nHow much cash would you like to add (minimum $100): ";
		std::cin >> amountToAdd;
		if (amountToAdd >= 100 ? userCurrencyAmount > userCurrencyAmount + amountToAdd : userCurrencyAmount < userCurrencyAmount + amountToAdd)
		{
			std::cout << "Number too big to add!" << std::endl;
			Sleep(1500);
			Log::NewLog("Number too big to add");
		}
		else
		{
			userCurrencyAmount = userCurrencyAmount + amountToAdd;
			SaveStatsToFile(userCurrencyAmount);
			Log::NewLog("Gave self money");
		}
	}*/

	void ResetStats(bool abc)
	{
		GetStatsFromFile("UserStats.Stats");
		userCurrencyAmount = resetAmount;
		if (abc == true)
		{
			MoreTextColors = false;
			DoubleEarnings = false;
		}
		SaveStatsToFile(userCurrencyAmount);
	}
}
