#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>

using namespace std;

/*

Person class
@param lastName = last name, firstName = first name, heightFeet = feet height , heightInch = inch height;

*/

class Person
{

private:

	string lastName, firstName;		
	int heightFeet, heightInch;

public:

	/*

	Person constructor
	@param lastN = last name, firstN = first name, heightF = feet height , heightI = inch height;

	*/

	Person(string lastN = "N/A", string firstN = "N/A", int heightF = 0, int heightI = 0)
	{ 

		lastName = lastN;
		firstName = firstN;
		heightFeet = heightF;
		heightInch = heightI;

	}

	/*

	Person setter method
	@param lastN = last name, firstN = first name, heightF = feet height , heightI = inch height;

	*/

	void setPerson(string lastN, string firstN, int heightF, int heightI)
	{

		lastName = lastN;
		firstName = firstN;
		heightFeet = heightF;
		heightInch = heightI;

	}

	/*

	last name setter method
	@param lastN = last name;

	*/

	void setLastName(string lastN)
	{

		lastName = lastN;

	}

	/*

	first name setter method
	@param firstN = first name;

	*/

	void setFirstName(string firstN)
	{

		firstName = firstN;

	}

	/*

	feet setter method
	@param heightF = feet height;

	*/

	void setHeightFeet(int heightF)
	{

		heightFeet = heightF;

	}

	/*

	inch setter method
	@param heightI = inch height;

	*/

	void setHeightInch(int heightI)
	{

		heightInch = heightI;

	}

	/*

	last name getter method
	@return lastName;

	*/

	string getLastName()
	{

		return lastName;

	}

	/*

	first name getter method
	@return firstName;

	*/

	string getFirstName()
	{

		return firstName;

	}

	/*

	feet getter method
	@return heightFeet;

	*/

	int getHeightFeet()
	{

		return heightFeet;

	}

	/*

	inch getter method
	@return heightInch;

	*/

	int getHeightInch()
	{

		return heightInch;

	}

	/*

	last name compare method
	@param PersonArgument = person class
	@return 1 if <, 0 if ==, else -1;

	*/

	int compLastName(Person PersonArgument)
	{

		if(lastName<PersonArgument.getLastName())
			return 1;
		else if(lastName == PersonArgument.getLastName())
			return 0;
		else
			return -1;

	}

	/*

	first name compare method
	@param PersonArgument = person class
	@return 1 if <, 0 if ==, else -1;

	*/

	int compFirstName(Person PersonArgument)
	{

		if(firstName<PersonArgument.getFirstName())
			return 1;
		else if(lastName == PersonArgument.getFirstName())
			return 0;
		else
			return -1;

	}

	/*

	full name compare method
	@param PersonArgument = person class
	@return 1 if <, 0 if ==, else -1;

	*/

	int compFullName(Person PersonArgument)
	{

		int compareResultL, compareResultF;

		compareResultL = compLastName(PersonArgument);

		if(compareResultL == 0)
		{

			compareResultF = compFirstName(PersonArgument);

			return compareResultF;

		}

		else
			return compareResultL;

	}

	/*

	feet compare method
	@param PersonArgument = person class
	@return 1 if <, 0 if ==, else -1;

	*/

	int compHeightFeet(Person PersonArgument)
	{

		if(heightFeet<PersonArgument.getHeightFeet())
			return 1;
		else if(heightFeet == PersonArgument.getHeightFeet())
			return 0;
		else
			return -1;

	}

	/*

	inch compare method
	@param PersonArgument = person class
	@return 1 if <, 0 if ==, else -1;

	*/

	int compHeightInch(Person PersonArgument)
	{

		if(heightInch<PersonArgument.getHeightInch())
			return 1;
		else if(heightInch == PersonArgument.getHeightInch())
			return 0;
		else
			return -1;

	}

	/*

	total height compare method
	@param PersonArgument = person class
	@return 1 if <, 0 if ==, else -1;

	*/

	int compHeight(Person PersonArgument)
	{

		int compareResultFeet, compareResultInch;

		compareResultFeet = compHeightFeet(PersonArgument);

		if(compareResultFeet == 0)
		{

			compareResultInch = compHeightInch(PersonArgument);

			return compareResultInch;

		}

		else
			return compareResultFeet;

	}

	/*

	to string method

	*/

	void to_string()
	{

		cout << "last name: " << getLastName() << ", first name: " << getFirstName() << ", height: " << getHeightFeet() << "'" << getHeightInch() << endl;

	}

};