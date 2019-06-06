#include<string>
#include<cmath>
#include<iomanip>
#include <iostream>
#include<vector>
#include <iterator>

const int maxSize=50;

using namespace std;

void printNames(vector<string> names)
{
	for(int i=0; i<names.size(); i++)
	{

		cout<<names[i]<<endl;

	}
}

int main()
{

	string nameTemp1, nameTemp2;

	vector<string> names;
	names.push_back("Alice");
	names.push_back("Bob");
	names.push_back("Connie");
	names.push_back("David");
	names.push_back("Edward");
	names.push_back("Fran");
	names.push_back("Gomez");
	names.push_back("Harry");

	printNames(names);

	cout<<"First name in vector: "<<names[0]<<endl;
	cout<<"Last name in vector: "<<names[names.size()-1]<<endl;

	cout<<"Vector size: "<<names.size()<<endl;

	for(int i=0; i<names.size()-1; i++)
	{

		if(names[i]=="Alice")
		{

			names[i]="Alice B. Toklas";

		}

	}

	printNames(names);

	cout<<"Enter a name to insert 'Doug' after: ";
	getline(cin, nameTemp1);

	for(int i=0; i<names.size()-1; i++)
	{

		if(names[i]==nameTemp1)
		{

			names.push_back("temp");

			for(int j=names.size()-1; j>i; j--)
			{
			
				names[j]=names[j-1];
			
			}

			names[i+1]="Doug";

		}

	}

	printNames(names);

	cout<<"Enter a name to delete: ";
	getline(cin, nameTemp1);

	for(int i=0; i<names.size(); i++)
	{

		if(names[i]==nameTemp1)
		{
			
			for(i;i<names.size()-1; i++)
			{
			
				names[i]=names[i+1];
			
			}

		}

	}

	printNames(names);

	vector<string> names2;

	names2=names;

	for(int i=0;i<names.size(); i++)
	{

		names[i]=names[i+1];
		names.pop_back();

	}

	cout<<"First vector, after removing the first name: "<<endl;

	printNames(names);

	cout<<"Copied vector, before removing the first name: "<<endl;

	printNames(names2);

	cout<<endl<<"Program Executed Successfully."<<endl;
	system("pause");
	return 0;

}