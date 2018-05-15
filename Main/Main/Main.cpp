/*	Authors:
	Brady Heston
	Daniel McGlasson
*/

#include "CasinoGames.h"
#include <conio.h>

bool FirstLoad = true;

int main()
{
	SetConsoleTitle(TEXT("That One Casino")); // Changing the console title to whatever is in the quotes
	system("cls");
	int userSwitchChoice;
	
	FileController::GetStatsFromFile("userStats.txt");
	
	WelcomeMessage(); // Displays WelcomeMessage in consoleControls.h


	std::cout << "\n\nDouble Earnings: " << DoubleEarnings << "\nMore Text Colors: " 
		<< MoreTextColors << "\n\nYou currently have $" << 
		userCurrencyAmount << "\n\n[1] Switch Text Color\n[2] Betting Game\n[3] Dice Game\n[4] Number Guessing Game\n[5] Shop\n[6] Rob Casino\n[7] Reset Cash\n[8] Admin Login\n\nWhat would you like to do: ";

	std::cin >> userSwitchChoice;

	switch (userSwitchChoice)
	{
	case 1:
		TransformTextColor();
		Sleep(1500);
		main();
	case 2:
		CasinoGames::BettingGame();
		main();
	case 3:
		CasinoGames::DiceGame();
		main();
	case 4:
		CasinoGames::NumberGuessingGame();
		main();
	case 5:
		ShopControl::ShowShop(userCurrencyAmount);
		system("Pause");
		main();
	case 6:
		CasinoGames::RobCasino();
		main();
	case 7:
		FileController::ResetCash();
		main();
	case 8:
		AdminLogin();
		main();
	default: // If the input isn't an option
		system("cls");
		std::cout << "Invalid number!" << std::endl;
		Sleep(1500);
		main();
	}
	return 0;
}