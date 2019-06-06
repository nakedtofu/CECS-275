#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

class Integer
{
private:
	int value;
public:
	Integer();

	Integer(int newValue)
	{
		value = newValue;
	}

	int getValue()
	{
		return value;
	}

	int add(int newValue)
	{
		value+=newValue;
		return value;
	}

	int subtract(int newValue)
	{
		value-=newValue;
		return value;
	}

	int multiply(int newValue)
	{
		value*=newValue;
		return value;
	}

	int divide(int newValue)
	{
		value/=newValue;
		return value;
	}

};

int main()
{

	int(Integer::*binary_p)(int) = &Integer::add;
	Integer first = Integer(50);
	int second = 4;
	cout<<(first.*binary_p)(second)<<endl;

	system("pause");

}