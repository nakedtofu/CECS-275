/*

Naoaki Takatsu
November 1, 2016
Purpose: Create a program that fills up a five gallon container with three pots of different sizes.
Inputs: PotA = first pot, PotB = second pot, PotC = third pot, Container = five gallon container, FiveGallon = five gallon mark;
Output: How many times and which pots were used to fill up the five gallon container.

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include "proj18header.h"

using namespace std;

/*

to_string function
@param Container = five gallon container;

*/

void to_string(Pots Container)
{

	cout<<"The container now has: "<<endl<<Container.toOunce()<<" ounce"<<endl;
	cout<<"==In simplified version=="<<endl;
	cout<<"The container now has: "<<endl<<Container.getGallon()<<" gallon"<<endl<<Container.getQuart()<<" quart"<<endl<<Container.getCup()<<" cup"<<endl<<Container.getOunce()<<" ounce"<<endl;

}

/*

main function
@param PotA = first pot, PotB = second pot, PotC = third pot, Container = five gallon container, FiveGallon = five gallon mark;

*/

int main()
{

	Pots PotA;
	Pots PotB;
	Pots PotC;
	Pots Container;
	Pots FiveGallon;

	PotA.setGallon(0);
	PotA.setQuart(3);
	PotA.setCup(2);
	PotA.setOunce(0);

	PotB.setGallon(0);
	PotB.setQuart(2);
	PotB.setCup(3);
	PotB.setOunce(0);

	PotC.setGallon(0);
	PotC.setQuart(2);
	PotC.setCup(0);
	PotC.setOunce(0);

	FiveGallon.setGallon(5);
	FiveGallon.setQuart(0);
	FiveGallon.setCup(0);
	FiveGallon.setOunce(0);

	do{

		if(((FiveGallon - Container) >= PotC) && ((FiveGallon - Container) < PotB))
		{

			Container = Container + PotC;
			cout<<"Poured Pot C content into the container."<<endl;
			to_string(Container);

		}

		else if(((FiveGallon - Container) >= PotB) && ((FiveGallon - Container) < PotA))
		{

			Container = Container + PotB;
			cout<<"Poured Pot B content into the container."<<endl;
			to_string(Container);

		}

		else if(((FiveGallon - Container) >= PotA) && ((FiveGallon - Container) < (PotB + PotC)))
		{

			Container = Container + PotA;
			cout<<"Poured Pot A content into the container."<<endl;
			to_string(Container);

		}

		else if(((FiveGallon - Container) >= (PotB + PotC)) && ((FiveGallon - Container) < (PotA + PotC)))
		{

			Container = Container + PotB + PotC;
			cout<<"Poured Pot B and Pot C content into the container."<<endl;
			to_string(Container);

		}

		else if(((FiveGallon - Container) >= (PotA + PotC)) && ((FiveGallon - Container) < (PotA + PotB)))
		{

			Container = Container + PotA + PotC;
			cout<<"Poured Pot A and Pot C content into the container."<<endl;
			to_string(Container);

		}

		else if(((FiveGallon - Container) >= (PotA + PotB)) && ((FiveGallon - Container) < (PotA + PotB + PotC)))
		{

			Container = Container + PotA + PotB;
			cout<<"Poured Pot A and Pot B content into the container."<<endl;
			to_string(Container);

		}

		else if((FiveGallon - Container) >= (PotA + PotB + PotC))
		{

			Container = Container + PotA + PotB + PotC;
			cout<<"Poured Pot A, Pot B, and Pot C content into the container."<<endl;
			to_string(Container);

		}

	}while(Container < FiveGallon);

	cout<<"Program successfully executed."<<endl;

	system("pause");

	return 0;

}