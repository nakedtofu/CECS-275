/*

Prime Number
CECS 275
Made by Naoaki Takatsu
9/11/16

=Algorithm=
-Prompt user to input how many prime numbers he/she wants to find.
-If the user inputs a number less than 1 or cin fails, display error message.
-Use the square root functio to find the limit.
-Display however many prime number the user asks for.

*/

#include <iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

int primeCountGetter()//gets total number of prime numbers
{

	int totalPrimeNumbers;
	string junk;

	cout<<"How many prime numbers do you want to find?: ";

	cin>>totalPrimeNumbers;

	while(cin.fail()||totalPrimeNumbers<1)
	{

		cout<<"Please enter a non-zero positive integer in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>totalPrimeNumbers;

	}

	return totalPrimeNumbers;

}

void squareRootDouble(double input, double &sqrtDouble)//square roots a double value
{

	double high=input, low=0, oldMid=-1, mid=input, midSquared=-1;

	while(abs(mid-oldMid) > 0.00001)
	{

		oldMid=mid;

		mid = (high+low) / 2;
		midSquared = pow(mid, 2);


		if(midSquared>input)
		{

			high=mid;

		}

		else if(midSquared<input)
		{

			low=mid;

		}

	}

	sqrtDouble=mid;

}

void squareRootInt(long long int &sqrtInt, double &sqrtDouble) //convert squared double value into int value
{

	 sqrtInt = floor(sqrtDouble);

}

void primeNumberFinder()//finds prime number
{

	int userPrimeCount, primeCount=1, value = 2;
	long long int sqrtInt;
	double sqrtDouble;
	bool primeFlag = true;

	userPrimeCount = primeCountGetter();

	while(primeCount<=userPrimeCount)//loop until it finds however many prime numbers user wants
	{

		sqrtDouble = sqrt(double(value));
		sqrtInt = long long int (sqrt(double(value)));

		for(sqrtInt;sqrtInt>1;sqrtInt--)//search if number is prime or not
		{

			if(value % sqrtInt == 0)
			{

				primeFlag = false;

			}

		}

		if(primeFlag==true)//if prime, print out message
		{

			cout<<left<<setw(4)<<primeCount<<"Prime number: "<<left<<setw(8)<<value<<" Square root of the prime number: "<<sqrtDouble<<endl;
			primeCount++;

		}

		value++;
		primeFlag = true;

	}

}

int main()
{

	primeNumberFinder();
	system("pause");
	return 0;

}