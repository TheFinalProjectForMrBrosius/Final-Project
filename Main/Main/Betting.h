#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int userAmount;
	int secret;
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
	system("pause");
	return 0;
}
