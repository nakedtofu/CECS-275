/* 
Naoaki Takatsu
October 4, 2016
Purpose: Create a sorting program
Inputs: Amount and highest possible value for the random numbers as well as how many to print out per line
Output: Print out unsorted and sorted list of random numbers 
*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<iterator>
#include<cctype>
#include<cstdlib>
#include <time.h>

using namespace std;

/*

Merge method
@param leftLimitNT = left vector bound, rightLimitNT = right vector bound, mergedVectorNT = result;
@return mergedVectorNT;

*/

vector <int> mergeProcess(vector <int> leftVectorNT, vector <int> rightVectorNT)
{

	int leftLimitNT=0, rightLimitNT=0;
	vector <int> mergedVectorNT;

	while(leftLimitNT<leftVectorNT.size() || rightLimitNT<rightVectorNT.size())
	{

		if(leftLimitNT<leftVectorNT.size() && rightLimitNT<rightVectorNT.size())
		{

			if(leftVectorNT.at(leftLimitNT) <= rightVectorNT.at(rightLimitNT))
			{

				mergedVectorNT.push_back(leftVectorNT.at(leftLimitNT));
				leftLimitNT++;

			}
			else
			{

				mergedVectorNT.push_back(rightVectorNT.at(rightLimitNT));
				rightLimitNT++;

			}

		}

		else if (leftLimitNT<leftVectorNT.size())
		{

			mergedVectorNT.push_back(leftVectorNT.at(leftLimitNT));
			leftLimitNT++;

		}

		else
		{

			mergedVectorNT.push_back(rightVectorNT.at(rightLimitNT));
			rightLimitNT++;

		}

	}

	return mergedVectorNT;

}

/*

Merge sort divide method
@param leftVectorNT = left vector, rightVectorNT = right vector, mergeVectorNT = result;
@return mergeVectorNT;

*/

vector <int> mergeSort(vector <int> sortVectorNT)
{

	vector <int> leftVectorNT, rightVectorNT, mergeVectorNT;

	for(int i=0; i < sortVectorNT.size() / 2; i++)
	{

		leftVectorNT.push_back(sortVectorNT.at(i));

	}

	for(int p = (sortVectorNT.size()/2); p < sortVectorNT.size(); p++)
	{

		rightVectorNT.push_back(sortVectorNT.at(p));

	}

	mergeVectorNT = mergeProcess(leftVectorNT, rightVectorNT);

	return mergeVectorNT;

}

/*

Main method
@param amountOfRandomNumberNT = # of random #s to generate, maxRandomNumberNT = highest possible value for random #, randomNumberPerLineNT = maximum random #s to print per line;
@param originalVectorNT = unsorted vector, resultVectorNT = sorted vector;

*/

int main()
{

	srand(time(0));

	int amountOfRandomNumberNT, maxRandomNumberNT, randomNumberPerLineNT;
	vector <int> originalVectorNT, resultVectorNT;

	cout<<"Enter the number of random numbers to generate: ";
	cin>>amountOfRandomNumberNT;
	cout<<"Enter the maximum random number to generate: ";
	cin>>maxRandomNumberNT;
	cout<<"Enter the maximum number of integers to display per line: ";
	cin>>randomNumberPerLineNT;

	cout<<endl<<"Before sorting:"<<endl;

	for(int i=0; i<amountOfRandomNumberNT; i++)
	{

		originalVectorNT.push_back(rand() % (maxRandomNumberNT+1));

		if((i+1)%randomNumberPerLineNT == 0)
		{
			
			cout<<originalVectorNT.at(i)<<", "<<endl;
		
		}

		else
		{
			
			cout<<originalVectorNT.at(i)<<", ";
		
		}

	}

	cout<<endl<<"in sorted order:"<<endl;
	
	resultVectorNT = mergeSort(originalVectorNT);

	for(int z=0; z<resultVectorNT.size(); z++)
	{
	
		if((z+1) % randomNumberPerLineNT == 0)
		{
		
			cout<<resultVectorNT.at(z)<<", "<<endl;
		
		}

		else
		{

			cout<<resultVectorNT.at(z)<<", ";

		}
	
	}
	
	system("pause");

	return 0;

}