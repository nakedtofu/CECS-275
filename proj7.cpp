/*

Lab Array
CECS 275
Made by Naoaki Takatsu
9/13/16

=Algorithm=
-prompt user for number of random values and tries
-record the number of hits a certain value obtains
-find the average deviation between the number of hits and the mean for each value
-display number of hits each count gets as well as the mean and deviation for those values
*/

#include <iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include <time.h>

using namespace std;

int errorChecker(int value, string message, int code) // checks for format errors
{

	string junk;

	if(code==0)
	{
		while(cin.fail() || value<=0)
		{

			cout<<message;
			cin.clear();
			getline(cin, junk);
			cin>>value;

		}
	}

	else
	{
		while(cin.fail() || value<=0 || value>1000)
		{

			cout<<message;
			cin.clear();
			getline(cin, junk);
			cin>>value;

		}
	}
	return value;

}

void program()// bulk of the program
{

	srand(time(0));

	const int size=1000;
	int numberOfTries, hitCountInd, hitCountArray[size]={0}, remainder, hitConc=0, bound=0, errorCode=0;
	double mean, aveDeviation, denominator=0;
	string message, junk;

	cout<<"How many random numbers would you like to generate?"<<endl;

	message="Please input a positive non-zero integer in numeric format: ";
	cout<<message;
	cin>>numberOfTries;

	numberOfTries=errorChecker(numberOfTries, message, errorCode); //check for any error

	cin.clear();
	getline(cin, junk);

	errorCode=1;

	cout<<"What is the number of values for each random draw?"<<endl;

	message="Please input a positive non-zero integer which is less than or equal to 1000 in numeric format: ";
	cout<<message;
	cin>>hitCountInd;

	hitCountInd=errorChecker(hitCountInd, message, errorCode);


	mean=(double(numberOfTries) / double(hitCountInd)); //calculate mean

	for(hitConc=0; hitConc<numberOfTries; hitConc++)//obtains hit count for each random numbers and store the data into an array
	{

		remainder = (rand() % (numberOfTries*10) + 1) % hitCountInd;

		hitCountArray[remainder]++;

	}

	for(hitConc=0; hitConc<hitCountInd; hitConc++)// print out all hit counts and calculate the denominator part for the average deviation 
	{

		cout<<"Hits for "<<hitConc+1<<" was: "<<hitCountArray[hitConc]<<endl;

		denominator+=abs(hitCountArray[hitConc]-mean);

	}


	aveDeviation=(denominator/numberOfTries); //calculates average deviation


	cout<<"Mean: "<<mean<<endl;
	cout<<"Average deviation % of these values: "<<aveDeviation<<endl;

}

int main()
{

	program();

	system("pause");

	return 0;

}