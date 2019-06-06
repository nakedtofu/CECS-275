#include <iostream>

using namespace std;

/*

LiquidMeasure class
@param gallon = # ofgallon, quart = # of quart, cup = # of cup, ounce = # of ounce;
@param simplify() = simplifying function;

*/

class LiquidMeasure;

class LiquidMeasure
{

private:

	int gallon;
	int quart;
	int cup;
	int ounce;
	void simplify();

public:

	LiquidMeasure(int g = 0, int q = 0, int c = 0, int o = 0)
	{ 

		gallon = g;
		quart = q;
		cup = c;
		ounce = o;
		simplify();

	}

	/*

	gallon setter function
	@param g = # ofgallon;

	*/

	void setGallon(int g)
	{

		gallon = g;

	}

	/*

	quart setter function
	@param q = # of quart;

	*/

	void setQuart(int q)
	{

		quart = q;
		simplify();

	}

	/*

	cup setter function
	@param c = # of cup;

	*/

	void setCup(int c)
	{

		cup = c;
		simplify();

	}

	/*

	ounce setter function
	@param o = # of ounce;

	*/

	void setOunce(int o)
	{

		ounce = o;
		simplify();

	}

	/*

	gallon getter function
	@return gallon = # of gallon;

	*/

	int getGallon() const
	{

		return gallon;

	}

	/*

	quart getter function
	@return quart = # of quart;

	*/

	int getQuart() const
	{

		return quart;

	}

	/*

	cup getter function
	@return cup = # ofcup;

	*/

	int getCup() const
	{

		return cup;

	}

	/*

	ounce getter function
	@return ounce = # of ounce;

	*/

	int getOunce() const
	{

		return ounce;

	}

	/*

	ounce converter function
	@param gallon = # ofgallon, quart = # of quart, cup = # of cup;
	@param tempOunce = temporary ounce;
	@return tempOunce = temporary ounce;

	*/

	double toOunce()
	{

		double tempOunce=0;
		tempOunce += cup * 8 + quart * 32 + gallon * 148;

		return tempOunce;

	}

	//operator overrides

	LiquidMeasure operator + (const LiquidMeasure &);
	LiquidMeasure operator - (const LiquidMeasure &);
	bool operator > (const LiquidMeasure &);
	bool operator < (const LiquidMeasure &);
	bool operator >= (const LiquidMeasure &);
	bool operator <= (const LiquidMeasure &);
	bool operator == (const LiquidMeasure &);
	bool operator != (const LiquidMeasure &);

};

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

ostream &operator << (ostream &outputStream, const LiquidMeasure &obj) {
	outputStream<< "Gallon: " << obj.getGallon() << "Quart: " << obj.getQuart() << "Cup: " << obj.getCup() << "Ounce: " << obj.getOunce() << endl;
	return outputStream;
}