#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include "listnode.h"
#include "proj18header.h"

using namespace std;

class badIndex
{

private:

	int index, lastLink;
	string message;

public:

	badIndex(int number, int size, string text)
	{

		index = number;
		lastLink = size;
		message = text;

	}

	int getIndex()
	{

		return index;

	}

	int getLastLink()
	{

		return lastLink;

	}

	string getMessage()
	{

		return message;

	}

};

void visitor(class LiquidMeasure)
{

	LiquidMeasure LM;

	cout<<"Gallon: "<<LM.getGallon()<<", Quart: "<<LM.getQuart()<<", Cup: "<<LM.getCup()<<", Ounce: "<<LM.getOunce();

}

int main()
{

	LiquidMeasure LM1;
	LM1.setGallon(3);
	LM1.setQuart(0);
	LM1.setCup(0);
	LM1.setOunce(5);

	LiquidMeasure LM2;
	LM2.setGallon(1);
	LM2.setQuart(1);
	LM2.setCup(1);
	LM2.setOunce(1);

	ListNode<LiquidMeasure> LN();

	LinkedList<LiquidMeasure> LL;

	LL.appendNode(LM1);

	//cout<<LL.[0];

	LL.appendNode(LM2);

	LL.displayList();

	//cout<<LL.[1];

	//cout<<LL.[2];

	visitor(LM1);
	visitor(LM2);

	LL.reverseVisit();

	system("pause");

	return 0;

}