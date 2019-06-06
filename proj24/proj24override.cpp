#include <cstdlib>
#include "proj24.h"

/*

> operator overide
@param &right = pass by reference Card class;
@param status = boolean value;
@return status = boolean value;

*/

bool Card::operator > (const Card &right)
{

	bool status;

	if (cardRank > right.cardRank)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference Card class;
@param status = boolean value;
@return status = boolean value;

*/

bool Card::operator >= (const Card &right)
{

	bool status;

	if (cardRank >= right.cardRank)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference Card class;
@param status = boolean value;
@return status = boolean value;

*/

bool Card::operator < (const Card &right)
{

	bool status;

	if (cardRank < right.cardRank)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference Card class;
@param status = boolean value;
@return status = boolean value;

*/

bool Card::operator <= (const Card &right)
{

	bool status;

	if (cardRank <= right.cardRank)
		status = true;
	else
		status = false;

	return status;

}

/*

> operator overide
@param &right = pass by reference Card class;
@param status = boolean value;
@return status = boolean value;

*/

bool Card::operator == (const Card &right)
{

	bool status;

	if (cardRank == right.cardRank)
		status = true;
	else
		status = false;

	return status;

}