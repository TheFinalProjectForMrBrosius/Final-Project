#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
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