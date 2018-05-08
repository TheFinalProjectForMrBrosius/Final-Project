#include "CasinoGames.h"

int main()
{
	SetConsoleTitle(TEXT("That One Casino"));
	system("cls");
	int userSwitchChoice;
	
	WelcomeMessage();

	std::cout << "\n\n[1] Switch Text Color\n[2] Betting Game\n[3] Dice Game\n\nWhat would you like to do: ";
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
	default:
		system("cls");
		std::cout << "Invalid number!" << std::endl;
		Sleep(1500);
		main();
	}
	return 0;
}