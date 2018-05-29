/*	Authors:
	Brady Heston
	Daniel McGlasson
*/

#define _CRT_SECURE_NO_WARNINGS

#include "CasinoGames.h"

std::string VERSION = "1.5.0";

bool FirstLoad = true;

int main()
{
	std::string ownedDoubleEarnings = "not owned";
	std::string ownedMoreTextColors = "not owned";
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

	if (userCurrencyAmount <= 0)
	{
		Log::NewLog("Fixing stats...");
		FileController::ResetStats(NULL);
		main();
	}
	else
	{
		WelcomeMessage(); // Displays WelcomeMessage in consoleControls.h
		FileController::GetStatsFromFile("UserStats.stats");

		if (DoubleEarnings == true)
		{
			ownedDoubleEarnings = "owned";
		}

		if (MoreTextColors == true)
		{
			ownedMoreTextColors = "owned";
		}

		std::cout << "\nVersion: " << VERSION  << "\nDouble Earnings: " << ownedDoubleEarnings << "\nMore Text Colors: "
			<< ownedMoreTextColors << "\n\nYou currently have $" <<
			userCurrencyAmount << "\n\n[1] Switch Text Color\n[2] Betting Game\n[3] Dice Game\n[4] Number Guessing Game\n[5] Shop\n[6] Rob Casino\n[7] Reset Stats\n[8] Admin Login\n\n[999] Close\n\nWhat would you like to do: ";

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
			Log::NewLog("Reset Stats");
			FileController::ResetStats(true);
			main();
		case 8:
			Log::NewLog("Opened Admin Login");
			AdminLogin();
			main();
		case 999:
			system("cls");
			std::cout << "Closing...";
			Sleep(1000);
			return NULL;
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