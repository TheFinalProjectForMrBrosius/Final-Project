/*	Authors:
	Brady Heston
	Daniel McGlasson
*/


#include "CasinoGames.h"

int main()
{
	SetConsoleTitle(TEXT("That One Casino")); // Changing the console title to whatever is in the quotes
	system("cls");
	int userSwitchChoice;
	
	WelcomeMessage(); // Displays WelcomeMessage in consoleControls.h


	std::cout << "\n\nDouble Earnings: " << DoubleEarnings << "\nTesting: " << MoreTextColors << "\n\nYou currently have $" << userCurrencyAmount << "\n\n[1] Switch Text Color\n[2] Betting Game\n[3] Dice Game\n[4] Number Guessing Game\n[5] Shop\n\nWhat would you like to do: ";
	std::cin >> userSwitchChoice;

	switch (userSwitchChoice)
	{
	case 1:
		TransformTextColor();
		Sleep(1500);
		main();
	case 2:
		BettingGame();
		main();
	case 3:
		DiceGame();
		main();
	case 4:
		NumberGuessingGame();
		main();
	case 5:
		ShopControl::ShowShop(userCurrencyAmount);
		system("Pause");
		main();
	default: // If the input isn't an option
		system("cls");
		std::cout << "Invalid number!" << std::endl;
		Sleep(1500);
		main();
	}
	return 0;
}