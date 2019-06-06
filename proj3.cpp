/*

Guessing Game
CECS 275
Made by Naoaki Takatsu
9/1/16

=Algorithm=
Make a guessing game
Prompt user to input maximum number he/she wants to guess
Generate a positive random number within the maximum number boundary 
Calculate the number of guesses it should take to get to that number (log base 2 n)
Tell the user if his/her guess is either lower, higher, or equal to the random number
Do not let the user input numbers that are out of the boundaries
Make a while/ do while loop until user guesses the right number
Tell the user how many guesses it took him/her and if he/she got the right answer quickly or not


*/

#include <iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include <time.h>

using namespace std;

string junk;

int guessErrorCheck(int maxNo) //checks answer for format error and boundaries
{

	int guess;

	cout<<"Please guess a number: ";

	cin>>guess;

	while(cin.fail() || guess<0 || guess>maxNo)
	{

		cout<<"Please guess a positive integer that is less than or equal to the maximum number in numerical format."<<endl;
		cout<<"Guess a number: ";
		cin.clear();
		getline(cin, junk);
		cin>>guess;

	}

	return guess;

}

int maxNoErrorCheck() // checks if max number is greater than 0 and checks for format errors
{

	int maxNo;

	cin>>maxNo;

	while(cin.fail() || maxNo < 0)
	{

		cout<<"Please enter a non-zero positive integer in numerical format: ";
		cin.clear();
		getline(cin, junk);
		cin>>maxNo;

	}

	return maxNo;

}

bool compareGuess(int guess, int randNo) //checks if guess matches and send feedback
{

	bool correct=false;

	if(guess==randNo)
	{

		cout<<"Congratulations! "<<randNo<<" is the right answer!"<<endl;
		return correct = true;

	}

	else if(guess<randNo)
	{

		cout<<"Your guess is lower than the right answer."<<endl;
		return correct = false;

	}

	else
	{

		cout<<"Your guess is higher than the right answer."<<endl;
		return correct = false;

	}

}

void compareGuessTimes(int userGuessTimes, int calcGuessTimes) //compares number of tries used vs number of tries needed
{

	if(userGuessTimes<calcGuessTimes)
	{

		cout<<"Great job! You took "<<userGuessTimes<<" guess(es) which is "<<calcGuessTimes - userGuessTimes<<" guess(es) less than the maximum possible tries calculated."<<endl;
	
	}

	else if(userGuessTimes == calcGuessTimes)
	{

		cout<<"Nice job! You took "<<userGuessTimes<<" guess(es) which is the maximum possible tries calculated."<<endl;
	
	}

	else
	{

		cout<<"You took "<<userGuessTimes<<" guess(es) which is "<<userGuessTimes - calcGuessTimes<< " guess(es) more than the maximum possible tries calculated."<<endl;
		cout<<"Hint: you should keep on guessing numbers that are right in the middle of the lowest and highest number possible.";

	}

}

int main()
{

	int maxNo, randNo, userGuessTimes = 0, guess;
	double calcGuessTimes;
	bool loopFlag = false;

	srand (time(0));

	cout<<"Welcome to the Guessing Game Program!"<<endl;
	cout<<"Please type in the maximum poitive integer you want to guess within: ";

	maxNo = maxNoErrorCheck();
	randNo = rand() % (maxNo+1);
	calcGuessTimes = (log10(double(maxNo)))/(log10(2.00));

	cout<<"Log base 2 of your maximum number("<<maxNo<<") is: "<<calcGuessTimes<<"."<<endl;
	cout<<"The maximum number of guess(es) you should need will be: "<<int(ceil(calcGuessTimes))<<'.'<<endl;

	do //loop until guess matches random number
	{		

		guess = guessErrorCheck(maxNo);

		loopFlag = compareGuess(guess, randNo);

		userGuessTimes++;

	}while(loopFlag == false);

	compareGuessTimes(userGuessTimes, int(calcGuessTimes));

	cout<<"Thanks for playing! See you next Time!"<<endl;

	system("pause");

	return 0;

}