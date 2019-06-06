#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include "Person.h"

using namespace std;

/*

array printing method
@param set[] = array of person class, noMembers = number of people;

*/

void showArray (class Person set [], int noMembers) {
	for (int i = 0; i < noMembers; i++) {
		set[i].to_string();
	}
}

/*

swap method
@param Person1 = 1st person class, Person2 = 2nd person class, temp = temporary person class;

*/

void swap (class Person * Person1, class Person * Person2) {
	Person * temp = Person1;
	Person1 = Person2;
	Person2 = temp;
}

/*

partition by full name method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index, mid = midpoint;
@return pivotIndex;

*/

int partitionByFullName (class Person set [], int start, int end) {
	int pivotIndex, mid;
	Person pivotValue;
	mid = (start + end) / 2;

	swap(set[start], set[mid]);
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++) {
		if (set[scan].compFullName(pivotValue) == 1) {
			pivotIndex++;
			swap(set[pivotIndex], set[scan]);
		}
	}

	swap(set[start], set[pivotIndex]);
	return pivotIndex;

}

/*

partition by full name method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index, mid = midpoint;
@return pivotIndex;

*/

void quickSortByFullName(class Person * set[], int start, int end)
{
	int pivotPoint;
	if (start < end) {
		pivotPoint = partitionByFullName(*set, start, end);
		quickSortByFullName(set, start, pivotPoint - 1);
		quickSortByFullName(set, pivotPoint + 1, end);
	}
}

/*

partition by height method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index, mid = midpoint;
@return pivotIndex;

*/

int partitionByHeight (class Person set [], int start, int end) {
	int pivotIndex, mid;
	Person pivotValue;
	mid = (start + end) / 2;

	swap(set[start], set[mid]);
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++) {
		if (set[scan].compHeight(pivotValue) == 1) {
			pivotIndex++;
			swap(set[pivotIndex], set[scan]);
		}
	}

	swap(set[start], set[pivotIndex]);
	return pivotIndex;

}

/*

quick sort by height method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index;

*/

void quickSortByHeight(class Person * set[], int start, int end)
{
	int pivotPoint;
	if (start < end) {
		pivotPoint = partitionByHeight(*set, start, end);
		quickSortByHeight(set, start, pivotPoint - 1);
		quickSortByHeight(set, pivotPoint + 1, end);
	}
}

/*

partition by last name method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index, mid = midpoint;
@return pivotIndex;

*/

int partitionByLastName (class Person set [], int start, int end) {
	int pivotIndex, mid;
	Person pivotValue;
	mid = (start + end) / 2;

	swap(set[start], set[mid]);
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++) {
		if (set[scan].compLastName(pivotValue) == 1)
		{
			pivotIndex++;
			swap(set[pivotIndex], set[scan]);
		}
	}

	swap(set[start], set[pivotIndex]);
	return pivotIndex;

}

/*

quick sort by last name method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index;

*/

void quickSortByLastName(class Person * set[], int start, int end)
{
	int pivotPoint;
	if (start < end) {
		pivotPoint = partitionByLastName(*set, start, end);
		quickSortByLastName(set, start, pivotPoint - 1);
		quickSortByLastName(set, pivotPoint + 1, end);
	}
}

/*

partition by first name method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index, mid = midpoint;
@return pivotIndex;

*/

int partitionByFirstName (class Person set [], int start, int end) {
	int pivotIndex, mid;
	Person pivotValue;
	mid = (start + end) / 2;

	swap(set[start], set[mid]);
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++)
	{
		if (set[scan].compFirstName(pivotValue) == 1)
		{
			pivotIndex++;
			swap(set[pivotIndex], set[scan]);
		}
	}

	swap(set[start], set[pivotIndex]);
	return pivotIndex;

}

/*

quick sort by first name method
@param set[] = array of person class, start = start of array, end = end of array, pivotIndex = pivot index;

*/

void quickSortByFirstName(class Person * set[], int start, int end)
{
	int pivotPoint;
	if (start < end) {
		pivotPoint = partitionByFirstName(*set, start, end);
		quickSortByFirstName(set, start, pivotPoint - 1);
		quickSortByFirstName(set, pivotPoint + 1, end);
	}
}

/*

main method
@param noPeople = number of people, longList = array of people;

*/

int main()
{

	int noPeople = 8;
	Person * longList = new Person [noPeople];

	longList[0].setPerson("Brown", "Justin", 6, 2);
	longList[1].setPerson("Rutz", "Michael", 6, 0);
	longList[2].setPerson("Brown", "David", 5, 10);
	longList[3].setPerson("Brown", "Mary", 5, 6);
	longList[4].setPerson("Canavan", "Jean", 5, 5);
	longList[5].setPerson("Burris", "Danial", 6, 0);
	longList[6].setPerson("Rutz", "Mary", 5, 5);
	longList[7].setPerson("Canavan", "Rod", 6, 3);

	cout<<"In original order";
	showArray(longList, noPeople);
	quickSortByFullName(&longList, 0, noPeople - 1);

	cout << "Sorted by last name / first name order: " << endl;
	showArray(longList, noPeople);
	quickSortByHeight(&longList, 0, noPeople - 1);

	cout << "Sorted by height order: " << endl;
	showArray(longList, noPeople);
	quickSortByLastName(&longList, 0, noPeople - 1);

	cout << "Sorted by last name  order: " << endl;
	showArray(longList, noPeople);
	quickSortByFirstName(&longList, 0, noPeople - 1);

	cout << "Sorted by first name order: " << endl;
	showArray(longList, noPeople);
	cout << "Completed satisfactorily." << endl;

	delete [] longList;

	system("pause");

	return 0;

}