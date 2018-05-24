#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <time.h>

#include "shopControl.h"
#include "fileController.h"

bool loggedIn = false;
bool Debugging = false;

std::string Username = "Admin";
std::string Password = "Password";

// Declaring functions before hand
std::string TransformTextCasing(std::string type, std::string text);
void TransformTextColor();
void WelcomeMessage();
int RandomNumberGenerator(int maxNumber);


std::string TransformTextCasing(std::string type, std::string text)
{
	std::transform(type.begin(), type.end(), type.begin(), ::tolower); // lowers the type so if they do "loWeR" it will become "lower"
	if (type == "lower")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::tolower); // transforms the string text to lower "aBCdEfgHijKlmnOP" to "abcdefghijlmnop"
	}
	else if (type == "upper")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	}
	return text;
}

void TransformTextColor()
{
	SetConsoleTitle(TEXT("Text Color Changer"));
	system("cls");
	int userNumberChoice;
	std::cout << "Avaliable colors below:\n\n";
	
	if (MoreTextColors == true)
	{
		// Outputing every possible combination if the user HAS MoreTextColors
		for (int x = 1; x < 255; x++)
		{
			// Changes text color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			std::cout << x << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\n\nWhat number would you like: ";
		std::cin >> userNumberChoice;

		if (userNumberChoice <= 255 && userNumberChoice >= 1)
		{
			// Changes text color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), userNumberChoice);
			std::cout << "Successfully changed text color!" << std::endl;
		}
	}
	else if (MoreTextColors == false)
	{
		// Outputing every possible combination if the user DOESNT have MoreTextColor
		for (int x = 1; x < 16; x++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			std::cout << x << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\n\nWhat number would you like: ";
		std::cin >> userNumberChoice;

		if (userNumberChoice <= 16 && userNumberChoice >= 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), userNumberChoice);
			std::cout << "Successfully changed text color!" << std::endl;
		}
	}
}

void WelcomeMessage() // Displays welcome message 
{
	std::cout << "|************************************|" << std::endl;
	std::cout << "||||||Welcome to That one Casino||||||" << std::endl;
	std::cout << "|************************************|" << std::endl;
}

// Little RNG
int RandomNumberGenerator(int maxNumber)
{
	srand(time(NULL));
	return rand() % maxNumber + 1;
}

void AdminLogin()
{
	system("cls");
	std::string attemptUsername, attemptPassword;

	std::cout << "Username: ";
	std::cin >> attemptUsername;
	std::cout << "Password: ";
	std::cin >> attemptPassword;


	if (attemptUsername == Username && attemptPassword == Password)
	{
		loggedIn = true;
		int userSwitchChoice;
		system("cls");
		std::cout << "Enter a number that's not valid to go back to main menu\n\n[1] Give Cash\n[2] Toggle Debug\n\nWhat would you like to do: ";
		std::cin >> userSwitchChoice;

		switch (userSwitchChoice)
		{
		case 1:
			FileController::GiveCash();
			break;
		case 2:
			if (Debugging == true)
			{
				Debugging = false;
			}
			else if (Debugging == false)
			{
				Debugging = true;
			}
			break;
		default:
			break;
		}
	}
}