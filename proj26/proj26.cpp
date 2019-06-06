/*

Naoaki Takatsu
December 8, 2016
Purpose: Create a queue program utilizing templates;
Inputs: queue, object names;
Output: various functions from template;

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include<stack>
#include "proj26.h"

using namespace std;

int main()
{

	Queue <string> LineQueue;

	cout<<"Line before we got here: "<<endl;

	LineQueue.add("Boris Karloff");
	LineQueue.add("Harrison Ford");
	LineQueue.add("Muhatma Ghandi");
	LineQueue.add("Vincent Price");
	LineQueue.add("Diane Keaton");

	//for loop int i
	cout<<LineQueue[i]<<endl;

	cout<<"After me and my friends arrive: "<<endl;

	LineQueue.add("Michael Rutz");
	LineQueue.add("Rod Caveness");
	LineQueue.add("Dave Brown");

	//for loop int i
	cout<<LineQueue[i]<<endl;

	cout<<"The queue is now closed."<<endl;

	//try LineQueue.add();

	cout<<"Sorry, no more additions to the line."<<endl;

	//try LineQueue.add();

	cout<<"Sorry, line is still closed."<<endl;

	if(LineQueue.peek()==0)
		cout<<"Store clerk relieved to see that "<< LineQueue[0] <<" is still at the front of the line."<<endl;

	cout<<"Everyone gets in for a phone."<<endl;

	//for loop int i
	{
	cout<<"Next person in line is: "<<LineQueue[i]<<endl;
	LineQueue.remove();
	}

	cout<<"Queue is empty"<<endl;

	system("pause");

	return 0;

}