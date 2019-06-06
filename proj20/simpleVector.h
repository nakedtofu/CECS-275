// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template <class T>
class SimpleVector
{
private:
	T *aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	// Default constructor
	SimpleVector()
	{ aptr = 0; arraySize = 0;}

	// Constructor declaration
	SimpleVector(int);

	// Copy constructor declaration
	SimpleVector(const SimpleVector &);

	// Destructor declaration
	~SimpleVector();

	// Accessor to return the array size
	int size() const
	{ return arraySize; }

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T &operator[](const int &);

	T push_back(const SimpleVector &);

	T pop_back(const SimpleVector &);

	T extract(const SimpleVector &);

	T insert(const SimpleVector &);

	T swap(const SimpleVector &);

	T &operator<<(const int &);

};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T [s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
	// Copy the array size.
	arraySize = obj.arraySize;

	// Allocate memory for the array.
	aptr = new T [arraySize];
	if (aptr == 0)
		memError();

	// Copy the elements of obj's array.
	for(int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

template <class T>
T &SimpleVector::push_back<T>(const SimpleVector &obj)
{

	SimpleVector temp;

	temp = SimpleVector;


}

template <class T>
T &SimpleVector::pop_back(int nthItem)
{

	SimpleVector temp;

	for(int i=0; i<nthItem-1; i++)
	{

		temp[i] = obj[i];

	}

	for(int i=nthItem+1; i<nthItem-1; i++)
	{

		temp[i] = obj[i];

	}

	return temp;

}

template <class T>
T &SimpleVector::extract(const SimpleVector &obj)
{



}

template <class T>
T &SimpleVector::insert(string item, int nthItem)
{

	SimpleVector temp;

	for(int i=0; i<nthItem-1; i++)
	{

		temp[i] = obj[i];

	}
	
	temp[nthItem] = item;

	for(int i=nthItem+1; i<nthItem-1; i++)
	{

		temp[i] = obj[i];

	}

	return temp;

}

template <class T>
T &SimpleVector::swap(const SimpleVector &obj)
{



}

template <class T>
T &SimpleVector::operator<<(const int &)
{

	cout<<;

}

#endif 

int main()
{

	vector <string> shoppingList;

	shoppingList.push_back("carrots");
	shoppingList.push_back("onions");
	cout<<shoppingList;

	shoppingList.insert(0, "3 lbs lean ground beef");
	cout<<shoppingList;

	shoppingList.push_back("2 gallons of non fat milk");
	cout<<shoppingList;

	shoppingList.swap(milk, meat);
	cout<<shoppingList;

	shoppingList.insert("Captain Crunch Cereal", meat);
	cout<<shoppingList;

	shoppingList.remove(onion);
	cout<<shoppingList;

	system("pause");
	
	return 0;

}