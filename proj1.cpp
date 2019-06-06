/*

Interest Calculator Program
CECS 275
Made by Naoaki Takatsu
8/25/16

=Algorithm=
Make a compound interest calculator.
Ask user to input the accured balance amount.
Give error message if data type doesn't match.
Calculate the number of years it will take to get to the accured balance amount.
Ask user if he/she wants to try again with a different acurred balance amount.
Close the program after the user has finished.

*/

#include <iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{

	double balance /*Accured Balance*/ , deposit = 50000 /*Original Principle on Deposit*/, compoundedTimes = 12 /*Number of Times Interest Compoundeds in a Year*/;
	const double rate = 0.03 /*Interest Rate*/;
	int period /*Number of Years it Will Take*/;
	char answer /*Continue Again?*/;

	do /*A do while loop for calculating the time it takes to get the balance you want*/
	{

		cout<<"You currently have $"<<deposit<<" in your savings account."<<endl;
		cout<<"By typing in the amount you want to end up with, you can find out how much years it will take."<<endl;
		cin>>balance;

		if(cin.fail()) //Give an error message if data type doesn't match.
		{

			cout<<"Please enter amount in numerical format."<<endl;
			system("pause");
			exit(0);

		}

		period = ((log(balance/deposit))/(compoundedTimes*(log(1+(rate/compoundedTimes)))));

		/*I Started off with the original equation "A=P(1+r/n)^(n*t)." Shown below is the work on how I got the equation for this calculation. 
		A=P(1+r/n)^(n*t)
		A/P=(1+r/n)^(n*t)
		ln(A/P)=(n*t)*ln(1+r/n)
		t=[ln(A/P)]/[n*ln(1+r/n)]
		*/

		cout<<"It will take "<<period<<" years for your balance to get to $"<<balance<<'.'<<endl;
		cout<<"Would you like to find how long it will take for another amount?"<<endl;
		cout<<"If so, please type in 'y' and if not, please type in any other letter:";
		cin>>answer;	

	}
	while(answer=='y');

	cout<<"Thank you, please come again!"<<endl;
	system("pause");
	return 0;

}