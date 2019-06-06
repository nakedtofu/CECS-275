#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

/*
String class
@param noElements = number of elements in array, arraySize = array size, *stringPointer = pointer to a string, resizeIfNecessary = resize function;
*/

class String
{

private:

	int noElements, arraySize;
	string *stringPointer;

	/*
	resizeIfNecessary function	
	*/

	void resizeIfNecessary()
	{

		if(noElements == arraySize)
		{

			if(arraySize==0)
			{

				int arrays[10];

			}
			else
			{

				arraySize *= 2;

			}

			for(int i=0; i<arraySize; i++)
			{

				//copy data to new array

			}

		}

	}

public:

	/*
	String constructor
	@param noElements = number of elements in array, arraySize = array size, *stringPointer = pointer to a string;
	*/

	String()
	{

		noElements = 0;
		arraySize = 0;
		*stringPointer = nullptr;

	}

	/*
	getElement function
	@param n = nth integer; elementNo = nth element in array;
	@return dereferenced element;
	*/

	string getElement(int elementNo)
	{

		int n=0;

		for(int n; n<elementNo; n++)
		{

			stringPointer->//nth element;

		}

		return stringPointer->//nth element;

	}

	/*
	number of elements getter function
	@return noElements;
	*/

	int getNoElements()
	{

		return noElements;

	}

	/*
	array size getter function
	@return arraySize;
	*/

	int getArraySize()
	{

		return arraySize;

	}

	/*
	array size getter function
	@param element = string input to add;
	*/

	void add(string element)
	{

		resizeIfNecessary();
		//arrays[noElements] = element;
		noElements++;

	}

	/*
	array size getter function
	@param size = array size;
	*/

	void setString(int size)
	{

		arraySize = size;

	}

	/*
	array size getter function
	@param index = index number;
	@return indexOutOfBounds error;
	*/

	String operator [] (int index)
	{

		string message = "index is out of bounds";

		if(index<0||index>noElements-1)
		{

			throw indexOutOfBounds(index, message);			

		}

	}

	/*
	indexOutOfBounds class
	@param oobIndex = out of bound index, errorMessage = error message string;
	*/

	class indexOutOfBounds
	{
	private:

		int oobIndex;
		string errorMessage;

	public:

		/*
		indexOutOfBounds constructor
		@param oobIndex = out of bound index, errorMessage = error message string;
		*/

		indexOutOfBounds(int index, string error)
		{

			oobIndex = index;
			errorMessage = error;

		}

		/*
		out of bound index getter constructor
		@return oobIndex = out of bound index;
		*/

		int getIndex()
		{

			return oobIndex;

		}

		/*
		error message getter constructor
		@return errorMessage = error message;
		*/

		string getMessage()
		{

			return errorMessage;

		}

	};

};