#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int diceGame()
{
	int rand();
	double rollOfDieOne, rollOfDieTwo, totalDiceScore;
	string userChoice;

	do{
		cout << "|--------------------------------------|" << endl;
		cout << "|Welcome To The BEST CASINO EVER!!!!!!!|" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << "Would you like to roll a dice? >>>" << endl;
		cin >> userChoice;
		rollOfDieOne = rand() % 6 + 1;
		rollOfDieTwo = rand() % 6 + 1;
		//random numbers for the the two dice
		if (userChoice == "Yes" || userChoice == "yes")
		{
			totalDiceScore = rollOfDieOne + rollOfDieTwo;
			cout << "The number of the first die is  " << rollOfDieOne << endl;
			cout << "The number of the second die is  " << rollOfDieTwo << endl;
			cout << "Your total score is " << totalDiceScore << endl;
		}
		//If the user says no the the question on the top
		else if (userChoice == "NO" || userChoice == "no")
		{
			cout << "Ok have a nice day then" << endl;
		}
	} while (userChoice != "yes");


	system("Pause");
	return 0;
}