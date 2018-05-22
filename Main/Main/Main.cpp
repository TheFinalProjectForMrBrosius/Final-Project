/*	Authors:
	Brady Heston
	Daniel McGlasson
*/

#define _CRT_SECURE_NO_WARNINGS

#include "CasinoGames.h"
#include <conio.h>

bool FirstLoad = true;

int main()
{
	if (FirstLoad == true)
	{
		FileController::ClearFile("CurrentSession.logs");
		Log::NewLog("Initial load...");
		FirstLoad = false;
	}
	SetConsoleTitle(TEXT("That One Casino")); // Changing the console title to whatever is in the quotes
	system("cls");
	int userSwitchChoice;

	FileController::GetStatsFromFile("UserStats.stats");

	if (userCurrencyAmount < 0)
	{
		Log::NewLog("Broken userCurrencyAmount or too much money\nFixing...");
		FileController::ResetCash();
		main();
	}
	else
	{
		WelcomeMessage(); // Displays WelcomeMessage in consoleControls.h
		FileController::GetStatsFromFile("UserStats.stats");

		std::cout << "\nDebug: " << Debugging << "\nDouble Earnings: " << DoubleEarnings << "\nMore Text Colors: "
			<< MoreTextColors << "\n\nYou currently have $" <<
			userCurrencyAmount << "\n\n[1] Switch Text Color\n[2] Betting Game\n[3] Dice Game\n[4] Number Guessing Game\n[5] Shop\n[6] Rob Casino\n[7] Reset Cash\n[8] Admin Login\n\nWhat would you like to do: ";

		std::cin >> userSwitchChoice;

		switch (userSwitchChoice)
		{
		case 1:
			Log::NewLog("Transforming Text Color");
			TransformTextColor();
			Sleep(1500);
			main();
		case 2:
			Log::NewLog("Started BettingGame");
			CasinoGames::BettingGame();
			main();
		case 3:
			Log::NewLog("Started DiceGame");
			CasinoGames::DiceGame();
			main();
		case 4:
			Log::NewLog("Started NumberGuessingGame");
			CasinoGames::NumberGuessingGame();
			main();
		case 5:
			Log::NewLog("Opened Shop");
			ShopControl::ShowShop(userCurrencyAmount);
			system("Pause");
			main();
		case 6:
			Log::NewLog("Robbed bank");
			CasinoGames::RobCasino();
			main();
		case 7:
			Log::NewLog("Reset Cash");
			FileController::ResetCash();
			main();
		case 8:
			Log::NewLog("Opened Admin Login");
			AdminLogin();
			main();
		default: // If the input isn't an option
			system("cls");
			Log::NewLog("hOw dO yOU mAnAgE tO NoT pUt In A CORecT nUmBER - Bready");
			std::cout << "Invalid number!" << std::endl;
			Sleep(1500);
			main();
		}
	}
	return 0;
}