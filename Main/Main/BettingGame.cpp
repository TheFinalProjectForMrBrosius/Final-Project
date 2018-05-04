#include <iostream>
#include <string>
using namespace std;

int main()
{
	int userAmount;
	string userChoice;
	double totalBet = 0, maxBet = 500;

	cout << "|--------------------------------------|" << endl;
	cout << "|Welcome To The BEST CASINO EVER!!!!!!!|" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << "Are you ready to play this betting game? >>>" << endl;
	cin >> userChoice;
	if (userChoice == "Yes")
	{
		cout << "How much do you want bet? >>>" << endl;
		cout << "You can't go over $500 on you bet" << endl;
		cin >> userAmount;
	}
	if (userChoice == "No")
	{
		cout << "Ok have a wonderfull day then!" << endl;
	}
	system("pause");
	return 0;
}
