/* 
Naoaki Takatsu
September 27, 2016
Purpose: Print a certain number of fibonacci numbers by iterative and recursive method.
Inputs: Amount of fibonacci numbers to generate
Output: Return and print fibonacci numbers as well as how many times the function was called for the recursive method.
*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<iterator>
#include<cctype>

using namespace std;

/*

Recursive method to find fibonacci numbers
@param n = fibonacci number; hits = hits vector;
@return fibonacci number;

*/
long double fibRecursive(int n, vector<int> &hits)
{

	if (n <= 0)
	{
		
		hits[0]++;

		return 0;

	}

	else if (n == 1)
	{
		
		hits[1]++;

		return 1;

	}

	else
	{
		
		hits[n]++;

		return fibRecursive(n-1, hits) + fibRecursive(n-2, hits);

	}

}

/*

Iterative method to find fibonacci numbers
@param fibAmountIterative = number of fibonacci numbers to generate;

*/

void fibIterative(long double fibAmountIterative)
{

	long double fibNumberLow = 0, fibNumberHigh =1, fibNumberTemp;

	cout<<"Using the Iterative Method"<<endl;

	for(int i=0; i<fibAmountIterative; i++)
	{

		if (i <= 0)
		{

			cout<<"Fibonacci number: 0 = "<<fibNumberLow<<endl;

		}

		else if (i == 1)
		{

			cout<<"Fibonacci number: 1 = "<<fibNumberHigh<<endl;

		}

		else
		{

			fibNumberTemp = fibNumberLow+fibNumberHigh;

			cout<<"Fibonacci number: "<<i<<" = "<<setprecision(30)<<fibNumberTemp<<endl;

			fibNumberLow = fibNumberHigh;
			fibNumberHigh = fibNumberTemp;

		}

	}

}

int main()
{

	vector<int> hits; //hit vector

	long double fibAmountIterative = 92, fibAmountRecursive=20; //initialize amount of fibonacci numbers to generate

	fibIterative(fibAmountIterative);//calls iterative method

	system("pause");

	cout<<endl<<"Using the Recursive Method"<<endl;

	for(int i=0; i<fibAmountRecursive; i++) // recursive approach
	{

		for(int z=0; z<=i; z++)// expands vector
		{
	
			hits.push_back(0);

		}

		cout<<"Fibonacci Number: "<<i<<" = "<<setprecision(20)<<fibRecursive(i, hits)<<endl; //print fibonacci number

		for(int c=0; c<=i; c++)// print number of hits
		{
		
			cout<<"Hit fibonacci number: "<<c<<" = "<<hits[c]<<endl;

		}

		hits.clear(); //resets vector

	}

	cout<<"Program successfully executed."<<endl;

	system("pause");

	return 0;

}