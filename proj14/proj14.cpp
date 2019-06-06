/*

Naoaki Takatsu
October 11, 2016
Purpose: Create a vending machine program
Inputs: Soda name, price, and quantity
Output: Soda name, price, quantity, and total price for every type of soda

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include "SodaClass.h"

using namespace std;

//junk = string for clearing errors
string junk;

/*

Soda name checking method
@param sodaVector = soda vector, sodaName = name of the soda;
@return sodaName = soda name which passes the restrictions;

*/

string sodaNameChecker(vector <Soda> sodaVector, string sodaName)
{

	for(int p = 0; p<sodaVector.size() ;p++)
	{

		if(sodaName == sodaVector[p].name)
		{

			cout<<"Error, soda "<<sodaName<<" is already in inventory."<<endl;
			cout<<"Enter the soda name or 'N/A' to exit: ";
			getline(cin, sodaName);
			return sodaNameChecker(sodaVector, sodaName);

		}

	}

	return sodaName;

}

/*

Soda price checking method
@param sodaPrice = price of the soda;
@return sodaPrice = soda price which passes the restrictions;

*/

double sodaPriceChecker(double sodaPrice)
{

	if(sodaPrice<0.05 || sodaPrice>1.5 || cin.fail())
	{

		getline(cin, junk);
		cin.clear();

		cout<<"Error, input not in range."<<endl;
		cout<<"Please enter a value between 0.05 and 1.5: ";
		cin>>sodaPrice;

		return sodaPriceChecker(sodaPrice);

	}

	return sodaPrice;

}

/*

Soda quantity checking method
@param sodaQuantity = quantity of the soda;
@return sodaQuantity = soda quantity which passes the restrictions;

*/

int sodaQuantityChecker(int sodaQuantity)
{

	if(sodaQuantity<1 || sodaQuantity>100 || cin.fail())
	{

		getline(cin, junk);
		cin.clear();

		cout<<"Error, input not in range."<<endl;
		cout<<"Please enter a value between 1 and 100: ";
		cin>>sodaQuantity;

		return sodaPriceChecker(sodaQuantity);

	}

	return sodaQuantity;

}

/*

Main method
@param sodaVector = vector for sodas, sodaTest = temporary soda structure;

*/

int main()
{

	vector <Soda> sodaVector;
	Soda sodaTest;
	
	do
	{

		cout<<"Enter the soda name or 'N/A' to exit: ";
		getline(cin, sodaTest.name);

		sodaTest.name = sodaNameChecker(sodaVector, sodaTest.name);

		if(sodaTest.name != "N/A")
		{

			cout<<"Enter the price for each of these sodas."<<endl<<"Please enter a value between 0.05 and 1.5: ";
			cin>>sodaTest.unitPrice;

			sodaTest.unitPrice = sodaPriceChecker(sodaTest.unitPrice);

			getline(cin, junk);
			cin.clear();

			cout<<"Enter the number of sodas in inventory."<<endl<<"Please enter a value between 1 and 100: ";
			cin>>sodaTest.quantity;

			sodaTest.quantity = sodaQuantityChecker(sodaTest.quantity);

			getline(cin, junk);
			cin.clear();

			sodaVector.push_back(sodaTest);

		}

	}while(sodaTest.name != "N/A");

	for(int z=0; z<sodaVector.size(); z++)
	{

		cout<<endl<<"Name: "<<sodaVector[z].name<<endl<<"Unit price: $"<<showpoint<<fixed<<setprecision(2)<<sodaVector[z].unitPrice<<endl<<"Quantity on hand: "<<sodaVector[z].quantity<<endl<<showpoint<<fixed<<setprecision(2)<<"Worth $"<<double(sodaVector[z].unitPrice*sodaVector[z].quantity)<<endl;

	}

	cout<<endl<<"Program executed successfully."<<endl;

	system("pause");

	return 0;

}