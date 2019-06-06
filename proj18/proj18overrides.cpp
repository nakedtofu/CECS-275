#include <cstdlib>
#include "proj18header.h"

/*

simplify function
@param ounce = # ounce, cup = # cup, quart = # of quart, gallon = # of gallon;

*/

void Pots::simplify()
{

	cup = cup + ounce / 8;
	ounce = ounce % 8;

	quart = quart + cup / 4;
	cup = cup % 4;

	gallon = gallon + quart / 4;
	quart = quart % 4;

}

/*

+ operator overide
@param &right = pass by reference pot class;
@param temp = temporary pot class;
@return temp = temporary pot class;

*/

Pots Pots::operator + (const Pots &right)
{

	Pots temp;

	temp.gallon = gallon + right.gallon;
	temp.quart = quart + right.quart;
	temp.cup = cup + right.cup;
	temp.ounce = ounce + right.ounce;
	temp.simplify();

	return temp;

}

/*

- operator overide
@param &right = pass by reference pot class;
@param temp = temporary pot class;
@return temp = temporary pot class;

*/

Pots Pots::operator - (const Pots &right)
{

	Pots temp;

	temp.gallon = gallon - right.gallon;
	temp.quart = quart - right.quart;
	temp.cup = cup - right.cup;
	temp.ounce = ounce - right.ounce;
	temp.simplify();

	return temp;

}

/*

> operator overide
@param &right = pass by reference pot class;
@param status = boolean value;
@return status = boolean value;

*/

bool Pots::operator > (const Pots &right)
{

	bool status;

	if (gallon > right.gallon)
		status = true;
	else if (gallon == right.gallon && quart > right.quart)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup > right.cup)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce > right.ounce)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference pot class;
@param status = boolean value;
@return status = boolean value;

*/

bool Pots::operator >= (const Pots &right)
{

	bool status;

	if (gallon >= right.gallon)
		status = true;
	else if (gallon == right.gallon && quart >= right.quart)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup >= right.cup)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce >= right.ounce)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference pot class;
@param status = boolean value;
@return status = boolean value;

*/

bool Pots::operator < (const Pots &right)
{

	bool status;

	if (gallon < right.gallon)
		status = true;
	else if (gallon == right.gallon && quart < right.quart)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup < right.cup)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce < right.ounce)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference pot class;
@param status = boolean value;
@return status = boolean value;

*/

bool Pots::operator <= (const Pots &right)
{

	bool status;

	if (gallon <= right.gallon)
		status = true;
	else if (gallon == right.gallon && quart <= right.quart)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup <= right.cup)
		status = true;
	else if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce <= right.ounce)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference pot class;
@param status = boolean value;
@return status = boolean value;

*/

bool Pots::operator == (const Pots &right)
{

	bool status;

	if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce == right.ounce)
		status = true;
	else
		status = false;

	return status;

}