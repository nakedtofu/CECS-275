#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

/*

SodaClass = class for soda
@param name = soda name, quantity = quantity ofsoda in stock;

*/

class SodaClass
{
public:
	struct Soda
	{

		string name;
		int quantity;

	};

	/*

	getName = gets soda name;
	@param name = soda name;
	@return name = soda name;

	*/

	string getName()
	{

		string name;

		cout<<"type in soda name: ";
		getline(cin, name);

		return name;

	}

	/*

	getQuantity = gets soda quantity;
	@param quantity = soda quantity;
	@return quantity = soda quantity;

	*/

	int getQuantity(int quantity)
	{

		cin>>quantity;
		return quantity;

	}

	/*int changeQuantity(int delta)
	{

		Soda sodaStruct;

		sodaStruct.quantity += delta;

	}*/

	/*

	to_string = prints soda in stock;
	@param sodaVector = soda structure vector;

	*/

	void to_string(vector <Soda> sodaVector)
	{

		for(int p=0; p<sodaVector.size(); p++)
		{

			cout<<"Vending Machine Inventory -Soda name:"<<sodaVector[p].name<<" -Quantity in stock: "<<sodaVector[p].quantity<<endl;

		}

	}

};

/*

VendingMachine = vending machine class;
@param locationDescription = location of vending machine, SC = soda class, inventory = soda structure vector, tokenCount = amount of token in vending machine;
@return quantity = soda quantity;

*/

class VendingMachine
{
public:
	string locationDescription;
	SodaClass SC;
	vector<class SodaClass::Soda> inventory;
	int tokenCount;

	/*

	defaultSetter = initializes vending machine setting to default;

	*/

	void defaultSetter()
	{

		locationDescription = "N/A";
		tokenCount = 0;

	}

	/*

	manualSetter = initializes vending machine setting to user's preference;

	*/

	void manualSetter()
	{

		cout<<"Please enter the location of the vending machine: ";
		getline(cin,locationDescription);
		tokenCount = 0;

	}

		/*

	vend = vending program;
	@param sodaQuantity = quantity of soda, SodaClass = soda class, nameFound = bool to check if soda name is found in soda structure vector;
	@return quantity = soda quantity;

	*/

	void vend(vector <class SodaClass::Soda> &inventory)
	{

		string sodaName;
		int sodaQuantity;
		class SodaClass::Soda sodaTemp;
		bool nameFound= false;

		cout<<"Which soda would you like to purchase?: ";
		getline(cin, sodaName);

		for(int z=0; z<inventory.size(); z++)
		{

			if(inventory[z].name == sodaName)
			{

				cout<<"How many "<<sodaName<<" would you like to purchase?: ";
				cin>>sodaQuantity;

				if(sodaQuantity>inventory[z].quantity)
				{

					cout<<"Not enough "<<sodaName<<" in stock.";

				}

				else
				{

					inventory[z].quantity -= sodaQuantity;
					tokenCount += sodaQuantity;
					cout<<"Thank you for your purchase."<<endl;

					if(inventory[z].quantity <= 0)
					{

						inventory.erase(inventory.begin()+z);

					}

				}

				nameFound = true;

			}

		}

		if(nameFound == false)
		{

			cout<<"Soda: "<<sodaName<<" not found";

		}

	}

	/*

	stock = stocks soda(s) in vending machine;
	@param sodaQuantity = soda quantity, sodaTemp = temporary soda sturcture, nameFound = bool to check if soda name is found in vending machine;
	@return quantity = soda quantity;

	*/

	void stock(vector <class SodaClass::Soda> &inventory)
	{

		string sodaName, junk;
		int sodaQuantity;
		class SodaClass::Soda sodaTemp;
		bool nameFound = false;

		sodaName = SC.getName();

		for(int i = 0; i<inventory.size(); i++)
		{

			if(inventory[i].name == sodaName)
			{

				cout<<"How many to add: ";
				cin>>inventory[i].quantity;
				nameFound = true;

			}

		}

		if(nameFound == false)
		{

			cout<<"How many would you like to add?: ";
			cin>>sodaQuantity;
			sodaTemp.name = sodaName;
			sodaTemp.quantity = sodaQuantity;
			inventory.push_back(sodaTemp);

		}

	}

};