/* 
Naoaki Takatsu
September 27, 2016
Purpose: Create a program that converts 2-16 base into decimal and vice-versa
Inputs: Base and value for that base
Output: Print the converted value
*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<iterator>
#include<cctype>

using namespace std;

//List of possible digits
const string DIGITS = "0123456789ABCDEF";

/*

Decimal to base conversion method
@param test = single integer, nextDig = proceeding digits, restOfOutput = remaining digits;
@return test if single integer, else return restOfOutput + nextDig;

*/

string decToBase(int decimal, int base)
{

	string test, nextDig, restOfOutput;

	if(decimal<base)
	{

		test = DIGITS.at(decimal);
		return test;

	}

	else
	{

		nextDig = DIGITS.at(decimal % base);
		restOfOutput = decToBase(decimal/base, base);
		return restOfOutput+nextDig;

	}

}

/*

base to decimal conversion method

*/


void bToD(vector <char> charVector, vector <int> convertedVector, int vectorAt, bool convertableFlag)
{

	if(vectorAt<charVector.size())
	{

		for(int z=0; z<DIGITS.length(); z++)
		{

			if(charVector[vectorAt]==DIGITS.at(z))
			{

				convertedVector.push_back(DIGITS.at(z));
				convertableFlag=true;
				vectorAt++;
				break;

			}
			else
			{

				convertableFlag=false;

			}

		}

		if(convertableFlag==false)
		{

			cout<<"Error detected, please type in appropriate values";

		}
	
		else
		{

		bToD(charVector, convertedVector, vectorAt, convertableFlag);

		}

	}

}


/*

base to decimal conversion method
@param charVector = converts input vector to string vector, convertedVector = converted vector, convertableFlag = checks if input is convertable or not, vectorAt = vector position, bToDResult = result;
@return bToDResult

*/

int nBaseToDecimal(string input, int base)
{

	vector <char> charVector;
	vector <int> convertedVector;
	bool convertableFlag=false;
	int vectorAt=0;
	int bToDResult=0;

	for(int i=0; i<input.length(); i++)
	{

		charVector.push_back(input.at(i));

	}

	bToD(charVector, convertedVector, vectorAt, convertableFlag);

	for(int p=0; p<convertedVector.size(); p++)
	{

		bToDResult += convertedVector[p]*base;

	}

	return bToDResult;

}

/*

Main method
@param base = base, input = input value for base to decimal, inputTemp = copy of input, bToDResult = result, input2 = decimal to base input, inputTemp2 = copy of input2 , junk = used for clearing junk;
@param result = resulting vector;

*/

int main()
{

	int base = 1, input = 1, inputTemp = 1, bToDResult = 1;
	string input2="1", inputTemp2="1", junk;
	vector<int> result;

	do
	{

		cout<<"Please enter the number to convert or 0 to continue on to the next program."<<endl;
		cout<<"Please enter an integer between 0 and 1000000000 to convert: ";
		cin>>input;

		if(input==0)
		{

			break;

		}

		inputTemp = input;

		cout<<"Please enter an integer between 2 and 16 for the base: ";
		cin>>base;

		cout<<"Decimal: "<<input<<" in base: "<<base<<" is: "<<decToBase(inputTemp, base);

		result.clear();
		cout<<endl;

	}while(input != 0);

	result.clear();

	getline(cin, junk);
	cin.clear();

	cout<<endl<<"Please enter a base for the first number to convert to base 10: Please enter a value between 2 and 16: ";
	cin>>base;
	getline(cin, junk);
	cin.clear();

	do{

		cout<<"Please enter a number to convert to base 10 or 0 to exit: Please enter a base "<<base<<" number: ";
		
		getline(cin, input2);

		if(input2=="0")
		{

			break;

		}		

		cout<<"Decimal equivalent of "<<input2<<" base "<<base<<" is "<<nBaseToDecimal(input2, base)<<" in decimal."<<endl;

		result.clear();

		cout<<"Please enter a base for the next number to convert to base 10: Please enter a value between 2 and 16: ";

		cin>>base;

	}while(input2!="0");

	cout<<"Program sucessfully executed."<<endl;

	system("pause");

	return 0;

}