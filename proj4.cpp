/*

Greatest Common Divisor
CECS 275
Made by Naoaki Takatsu
9/6/16

=Algorithm=
-Prompt user to input either 1, to find the greatest common denominator, or 2, to exit. Else, display error message.
-Prompt user to input two integers which are greater than 0 and less than 1,000,000. Else, display error message.
-Calculate the greatest common denominator of the two integers.
-Loop until user enters menu option 2.

*/

#include <iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include <time.h>

using namespace std;

int no_1Getter()//gets the first gcd
{

	int no_1;
	string junk;

	cout<<"Please enter the first GCD that is greater than 0 and less than 1,000,000 in numeric format: ";
	cin>>no_1;

	while(cin.fail() || no_1 < 1 || no_1 > 1000000)
	{

		cout<<"Please enter the first GCD that is greater than 0 and less than 1,000,000 in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>no_1;

	}

	return no_1;
}

int no_2Getter()//gets the second gcd
{

	int no_2;
	string junk;

	cout<<"Please enter the second GCD that is greater than 0 and less than 1,000,000 in numeric format: ";
	cin>>no_2;

	while(cin.fail() || no_2 < 1 || no_2 > 1000000)
	{

		cout<<"Please enter the second GCD that is greater than 0 and less than 1,000,000 in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>no_2;

	}

	return no_2;

}

int gcdCalculator(int no_1, int no_2) //calculates the gcd of the two numbers
{

	int noGreater, noLess, noGreaterPass, noLessPass, gcd;

	if(no_1 > no_2)
	{
		noGreater = no_1;
		noLess = no_2;
		gcd = no_2;
	}
	else
	{
		noGreater = no_2;
		noLess = no_1;
		gcd = no_1;
	}

	do //loop until it finds the gcd of the two numbers
	{

		noLessPass = noLess % gcd;
		noGreaterPass = noGreater % gcd;
		gcd--;

	}while(noLessPass!=0 || noGreaterPass!=0);
	

	return gcd+1;

}

void menuGetter()
{

	int no_1, no_2, menu;
	string junk;
	bool optionFlag = false;

	do //loop until user enters 0
	{

		cout<<"Please enter '1' to find the greatest common denominator for two numbers of your choice. Otherwise, please enter '0' to exit."<<endl;
		cout<<"Menu Option: ";

		cin>>menu;

		switch(menu) //switch statement. 1 to execute program, 0 to quit, else display error message.
		{

		case 1:

			no_1 = no_1Getter();
			no_2 = no_2Getter();
			cout<<"The greatest common denominator of "<<no_1<<" and "<<no_2<<" is "<<gcdCalculator(no_1, no_2)<<"."<<endl;
			break;

		case 0:

			optionFlag=true;
			break;

		default:

			cout<<"Please enter one of the following options in numeric format."<<endl;
			cin.clear();
			getline(cin, junk);
			break;

		}

	}while(optionFlag==false);

	cout<<"See you next time!"<<endl;
	system("pause");
	exit(0);

}

int main()
{

	menuGetter();

	return 0;

}