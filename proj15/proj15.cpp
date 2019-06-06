/*

Naoaki Takatsu
October 18, 2016
Purpose: Create a vending machine program with soda class and vending machine class
Inputs: Location of the vending machine, soda name, and quantity to stock/purchase
Output: Soda name, price, quantity, and total price for every type of soda

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include "proj15header.h"

using namespace std;

/*

main method
@param sodaVector = soda vector, SC = soda class, VM = vending machine class, stockContinue = char to check if user continues stocking, vendContinue = char to check if user continues vending;

*/

int main()
{

	vector <class SodaClass::Soda> sodaVector;
	class SodaClass SC;
	class VendingMachine VM;
	char stockContinue, vendContinue;

	VM.defaultSetter();

	VM.manualSetter();

	do
	{

		VM.stock(sodaVector);

		cout<<"Continue? (y/n): ";
		cin>>stockContinue;

		while((stockContinue != 'y') && (stockContinue != 'n'))
		{

			cout<<"Please enter either y or n: ";
			cin>>stockContinue;

		}

		cin.ignore();

	}while(stockContinue == 'y');

	cout<<"Vending machine "<<VM.locationDescription<<endl;

	SC.to_string(sodaVector);

	cout<<"token count: "<<VM.tokenCount<<endl;
	cout<<"Vending now"<<endl;

	do{

		VM.vend(sodaVector);

		cout<<"Vending machine "<<VM.locationDescription<<endl;
		SC.to_string(sodaVector);
		cout<<"token count: "<<VM.tokenCount<<endl;

		cout<<"purchase another soda? (y/n): ";
		cin>>vendContinue;

		while((vendContinue != 'y') && (vendContinue != 'n'))
		{

			cout<<"Please enter either y or n: ";
			cin>>vendContinue;

		}

		cin.ignore();

	}while(vendContinue == 'y');

	cout<<"Program successfully executed."<<endl;

	system("pause");

	return 0;

}