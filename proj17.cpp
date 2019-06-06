/*

Naoaki Takatsu
October 25, 2016
Purpose: Create a program that reverses an array using pointers
Inputs: array of 10 static integers
Output: display the array in original and reversed order

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

/*

reverse function
@param originalArray[] = original array, size = array size;
@return temp = pointer to originalArray;

*/

int * reverse(int originalArray[], int size)
{

	int * temp;

	temp = originalArray;

	return temp;

}

/*

main method
@param integers[10] = array of 10 integers, arraySize = array size, * reversedIntegers = dereferenced pointer to integers array;

*/

int main()
{

	int integers[10]={2,4,6,8,10,12,14,16,18,20};
	int arraySize = end(integers) - begin(integers);
	int * reversedIntegers = reverse(integers, arraySize);

	for(int n=0; n<arraySize; n++)
	{
	
		cout<<"Next element in original order: "<<integers[n]<<endl;

	}

	for(int x = arraySize-1; x >= 0; x--)
	{
	
		cout<<"Using pointer arithmetic: "<<*(reversedIntegers+x)<<endl;

	}

	system("pause");

	return 0;

}