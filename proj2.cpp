/*

Math Tutor
CECS 275
Made by Naoaki Takatsu
8/25/16

=Algorithm=
Make a math quiz.
Ask user to input max number he/she want to deal with.
Ask user to input which operation he/she wants to do. Either +, -, *, or /. Nothing else.
Generate and print out two random integers which are less than or equal to the max number.
Ask user to input answer for the given problem.
If correct, display congradulations message. If not, display an error message together with the corect answer.
For - and /, the first number should always be more than or equal to the second number and / must be divisible.
If input fails, display error message.

*/

#include <iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include <time.h>

using namespace std;

int answerFormatError() //checks answer for format error
{

	int guess;

	cin>>guess;

	while(cin.fail())
	{

		cout<<"Please enter the answer in numerical format."<<endl;
		cout<<"answer: ";
		cin.clear();
		cin.ignore(10000,'\n');
		cin>>guess;

	}

	return guess;

}

int maxNoErrorChecker() // checks if max number is greater than 0 and checks for format errors
{

	int maxNo;

	cin>>maxNo;

	while(cin.fail() || maxNo < 1)
	{

		cout<<"Please enter a non-zero positive integer in numerical format: ";
		cin.clear();
		cin.ignore(10000,'\n');
		cin>>maxNo;

	}

	return maxNo;

}

void retryRequest() //prompt user if he/she wants to retry
{
	char retry;

	cout<<"Would you like to try another problem? If so, please type in 'y' and if not, type in any other key: ";
	cin>>retry;

	if(retry!='y')
	{

		cout<<"Thanks for playing! See you next time!"<<endl;
		system("pause");
		exit(0);

	}

}

void answerChecker(int guess, int answer) //checks if answeris correct
{

	if(guess==answer)
	{

		cout<<"Congratulations! "<<answer<<" is the corrrect answer!"<<endl;
		retryRequest();

	}

	else
	{

		cout<<"Oops! The correct answer was "<<answer<<"."<<endl;
		retryRequest();

	}

}

int main()
{

	int maxNo, randNo1, randNo2, answer, guess;
	char operation, retry;
	bool divisibleFlag;

	srand (time(0));

	cout<<"Welcome to Math Tutor Program!"<<endl;
	do //repeat whole process until user quits
	{
		divisibleFlag = false;

		cout<<"Please type in the largest non-zero poitive integer you want to operate with: ";

		maxNo = maxNoErrorChecker();

		cout<<"What kind of operation would you like to try with?"<<endl;
		cout<<"For addition, type in '+'"<<endl;
		cout<<"For subtraction, type in '-'"<<endl;
		cout<<"For multiplication, type in '*'"<<endl;
		cout<<"For division, type in '/'"<<endl;
		cout<<"Operation type: ";
		cin>>operation;

		while(operation!='+' && operation!='-' && operation!='*' && operation!='/') //check operation
		{	
			cout<<"Please type in +, -, *, or /."<<endl;
			cout<<"Operation type: ";
			cin.clear();
			cin.ignore(10000,'\n');
			cin>>operation;
		}

		if(operation == '+')
		{

			randNo1 = rand() % maxNo;
			randNo2 = rand() % maxNo;
			answer = randNo1 + randNo2;

			cout<<"What does "<<randNo1<<" + "<<randNo2<<" = ?"<<endl;
			cout<<"(Note: Please type in answer in numerical format.)"<<endl;
			cout<<"Answer: ";

			guess = answerFormatError();

			answerChecker(guess, answer);

		}

		else if(operation == '-')
		{

			randNo1 = rand() % maxNo;
			randNo2 = rand() % maxNo;

			if(randNo1>randNo2)// prevents negative answers
			{

				answer = randNo1 - randNo2;

				cout<<"What does "<<randNo1<<" - "<<randNo2<<" = ?"<<endl;
				cout<<"(Note: Please type in answer in numerical format.)"<<endl;
				cout<<"Answer: ";

				guess =	answerFormatError();

				answerChecker(guess, answer);

			}

			else
			{

				answer = randNo2 - randNo1;

				cout<<"What does "<<randNo2<<" - "<<randNo1<<" equal to?"<<endl;
				cout<<"(Note: Please type in answer in numerical format.)"<<endl;
				cout<<"Answer: ";

				guess = answerFormatError();

				answerChecker(guess, answer);

			}

		}

		else if(operation == '*')
		{

			randNo1 = rand() % maxNo;
			randNo2 = rand() % maxNo;
			answer = randNo1 * randNo2;

			cout<<"What does "<<randNo1<<" * "<<randNo2<<" = ?"<<endl;
			cout<<"(Note: Please type in answer in numerical format.)"<<endl;
			cout<<"Answer: ";

			guess = answerFormatError();

			answerChecker(guess, answer);

		}

		else if(operation == '/')
		{

			randNo1 = rand() % maxNo;
			randNo2 = rand() % maxNo;

			if(randNo1>randNo2)//prevents decimal answers
			{

				while(divisibleFlag == false){// if all conditions pass, proceed to calculation

					while(randNo2 == 0){// prevents division by 0

						randNo2 = rand() % maxNo+1;

					}

					if(randNo1 % randNo2 != 0) // checks if the equation is divisible
					{

						randNo2 = rand() % maxNo+1;

					}

					else{

						divisibleFlag = true;

					}

				}

				answer = randNo1 / randNo2;

				cout<<"What does "<<randNo1<<" / "<<randNo2<<" = ?"<<endl;
				cout<<"(Note: Please type in answer in numerical format.)"<<endl;
				cout<<"Answer: ";

				guess = answerFormatError();

				answerChecker(guess, answer);

			}

			else
			{

				while(divisibleFlag == false){

					while(randNo1 == 0){

						randNo1 = rand() % maxNo+1;

					}

					if(randNo2 % randNo1 != 0)
					{

						randNo1 = rand() % maxNo+1;

					}

					else{

						divisibleFlag = true;

					}

				}

				answer = randNo2 / randNo1;

				cout<<"What does "<<randNo2<<" / "<<randNo1<<" equal to?"<<endl;
				cout<<"(Note: Please type in answer in numerical format.)"<<endl;
				cout<<"Answer: ";

				guess = answerFormatError();

				answerChecker(guess, answer);

			}



		}


		retry='y';

	}while(retry=='y');

	return 0;

}