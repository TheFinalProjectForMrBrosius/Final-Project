
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int casinoGame1()
{
	int userAmount;
	int secret;
	int userchoice;
	double totalBet = 0, maxBet = 500;

	srand(time(NULL));

	secret = rand() % 100 + 1;

	cout << "|--------------------------------------|" << endl;
	cout << "|Welcome To The BEST CASINO EVER!!!!!!!|" << endl;
	cout << "|--------------------------------------|" << endl;

	cout << "How much do you want bet? >>>" << endl;
	cout << "You can't go over $500 on you bet" << endl;
	cin >> userAmount;

	cout << "Ok, you are betting " << userAmount << " dollars." << endl;

	if (userAmount > maxBet)
	{
		cout << "Your bet is to HIGH kick it down a little" << endl;
	}
	if (userAmount > maxBet)
	{
		cout << "Your bet is to HIGH kick it down a little" << endl;
	}
	system("pause");
	return 0;
}



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


int numberGuessing()
{
	int numberChoice;
	int secret;
	int count = 0;

	srand(time(NULL));

	secret = rand() % 100 + 1;
	do{
		cout << "|--------------------------------------|" << endl;
		cout << "|Welcome To The BEST CASINO EVER!!!!!!!|" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << "Please pick a number between 1 - 10" << endl;
		cin >> numberChoice;
		if (numberChoice > secret)
		{
			cout << "The number you chose is to high!, guess agian loser" << endl;
			count = count + 1;
			//count++//
		}
		else if (numberChoice < secret)
		{
			cout << "The number you have chose is to low!, guess again loser" << endl;
			count = count + 1;
		}
	} while (numberChoice != secret);
	cout << "Congrats! " << endl;

	system("pause");
	return 0;
}
