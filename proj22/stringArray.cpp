#include<iostream>
#include<iomanip>
#include<cstdlib>
#include "String.h"

using namespace std;

/*
main function
@param stringArray = String class;
*/

int main()
{

	String stringArray;

	stringArray.setString(2);

	stringArray.add("Billy");
	stringArray.getArraySize();

	stringArray.add("Joel");
	stringArray.getArraySize();

	stringArray.add("concerts");
	stringArray.getArraySize();

	stringArray.add("are");
	stringArray.getArraySize();

	stringArray.add("wonderful");
	stringArray.getArraySize();

	for(int z=0; z<stringArray.getNoElements();z++)
	{

		//cout<<stringArray.getElement(z);

	}

	try
	{
		
		//access element no 10

	}
	catch(/*exception*/)
	{

		//call exception function

	}

	cout<<"Attempting to create string with negative size.";

	try
	{
		
		//create string of -5 size

	}
	catch(/*exception*/)
	{
		
		//call exception function

	}

	system("pause");

	return 0;

}