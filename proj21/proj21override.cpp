#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include "listnode.h"

/*

simplify function
@param ounce = # ounce, cup = # cup, quart = # of quart, gallon = # of gallon;

*/

void LiquidMeasure::simplify()
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

LiquidMeasure LiquidMeasure::operator + (const LiquidMeasure &right)
{

	LiquidMeasure temp;

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

LiquidMeasure LiquidMeasure::operator - (const LiquidMeasure &right)
{

	LiquidMeasure temp;

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

bool LiquidMeasure::operator > (const LiquidMeasure &right)
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

bool LiquidMeasure::operator >= (const LiquidMeasure &right)
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

bool LiquidMeasure::operator < (const LiquidMeasure &right)
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

bool LiquidMeasure::operator <= (const LiquidMeasure &right)
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

bool LiquidMeasure::operator == (const LiquidMeasure &right)
{

	bool status;

	if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce == right.ounce)
		status = true;
	else
		status = false;

	return status;

}

bool LiquidMeasure::operator != (const LiquidMeasure &right)
{

	bool status;

	if (gallon == right.gallon && quart == right.quart && cup == right.cup && ounce == right.ounce)
		status = false;
	else
		status = true;

	return status;

}


ostream &operator << (ostream &outputStream, const Integer &obj) {
	outputStream<< "Integer: " << obj.getValue();
	return outputStream;
}