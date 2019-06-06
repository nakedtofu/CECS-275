/*
Project IO
CECS 275
Made by Naoaki Takatsu
9/20/16

=Algorithm=
-Prompt user to enter either 1(no input file) or 2(have input file)
-Prompt user to input file name
-Prompt user to input:
1: Change statistics of a country (prompt user to input which info he/she wants to edit)
2: Add a new counrty
3: Delete a country
4: List countries in alphabetical order
5: exit
-Prompt user to enter file name he/she wants to save in when he/she exits
-Check for any errors
*/

#include<string>
#include<cmath>
#include<fstream>
#include<iomanip>
#include <iostream>

const int maxSize=50;

using namespace std;

string countryName[maxSize], junk;
int countrySize[maxSize], countryPopulation[maxSize];

void readFile(ifstream &fin, int &size)
{

	string file;
	int i=0;

	//	getline(cin,junk);
	//	cin.clear();

	cin.ignore();

	cout<<"Please input file name: ";
	getline(cin, file);

	fin.open(file.c_str());

	if(fin.fail())
	{

		cout<<endl<<"File error."<<endl;
		system("pause");
		exit(0);

	}

	getline(fin, countryName[i]);

	if(fin.eof())
	{

		cout<<"File empty. Please check file name."<<endl;
		exit(0);

	}

	fin>>countrySize[i];

	fin>>countryPopulation[i];

	i++;

	while(!fin.eof())
	{

		if(i<maxSize)
		{
			fin.ignore(100,'\n');
			getline(fin, countryName[i]);		
			fin>>countrySize[i];
			fin>>countryPopulation[i];
			i++;

		}

		else
		{

			cout<<"Array is full. Please resize array."<<endl;
			system("pause");
			exit(0);

		}

	}

	size=i;

	fin.close();
}

void addCountry(int &size)
{

	int z=0;
	bool countryError=false;

	if(size<maxSize)
	{

		cout<<endl<<"Please enter the country's name you wish to add: ";
		//		cin.ignore(1000, '\n');
		getline(cin, countryName[size]);

		for(z=0; z<size; z++)
		{

			if(countryName[size]==countryName[z])
			{

				cout<<endl<<"The country you have entered already exists."<<endl;
				countryError=true;

			}

		}

		if(countryError==false)
		{

			cout<<endl<<"Please enter the country's size in square miles: ";
			cin>>countrySize[size];

			while(countrySize[size]<0)
			{

				cout<<"Please enter a positive non-zero integer."<<endl;
				getline(cin, junk);
				cin.clear();
				cin>>countrySize[size];

			}

			cout<<endl<<"Please enter the country's population: ";
			cin>>countryPopulation[size];

			while(countryPopulation[size]<0)
			{

				cout<<"Please enter a positive non-zero integer."<<endl;
				getline(cin, junk);
				cin.clear();
				cin>>countrySize[size];

			}

			size++;

		}

	}

		else
			cout<<"Data  storage is full. Please Resize array."<<endl;

}

void removeCountry(int &size)
{
	string cName;
	int removeNumber;
	bool flag;

	cout<<endl<<"Please enter country's name: ";
	getline(cin, cName);

	flag=false;

	for(int i=0; i<size; i++)
	{

		if(cName==countryName[i])
		{

			removeNumber=i;

			while(removeNumber+1<maxSize)
			{

				countryName[removeNumber]=countryName[removeNumber+1];
				countrySize[removeNumber]=countrySize[removeNumber+1];
				countryPopulation[removeNumber]=countryPopulation[removeNumber+1];

				removeNumber++;

			}

			size--;
			flag=true;

		}

	}

	if(flag!=true)
		cout<<endl<<"Country not found. Please check for any spelling errors."<<endl;

}

void editStatistics(int &size)
{
	int cSize=1, cPopulation=1, switchMenu;
	string countryNameTemp;
	bool flag, defaultFlag;

	cout<<endl<<"Please enter the name of the country you'd like to edit:";
	getline(cin, countryNameTemp);
	flag=false;
	defaultFlag=false;

	for(int i=0; i<size; i++)
	{

		if(countryNameTemp==countryName[i])
		{

			cout<<"Please enter one of the following options:"<<endl;
			cout<<"1: Edit the country's size"<<endl;
			cout<<"2: Edit the country's population"<<endl;
			cout<<"Option: ";

			cin>>switchMenu;

			do
			{

				switch(switchMenu)
				{

				case 1:

					cout<<endl<<"Please enter the new size in square miles: ";
					cin>>cSize;

					while(cSize < 0)
					{

						cout<<endl<<"Please enter the new size in positive non-zero integer format: ";
						cin.clear();
						cin.ignore();
						cin>>cSize;

					}

					countrySize[i]=cSize;
					flag=true;
					defaultFlag=false;
					break;

				case 2:

					cout<<endl<<"Please enter the new population: ";
					cin>>cPopulation;
					//cin.ignore(1000, '\n');

					while(cPopulation < 0)
					{

						cout<<endl<<"Please enter the new population in positive non-zero integer format: ";
						cin>>cPopulation;
						cin.ignore(1000, '\n');

					}

					countryPopulation[i]=cPopulation;
					flag=true;
					defaultFlag=false;
					break;

				default:

					cout<<"Please enter either '1' to edit size or '2' to edit population: ";
					defaultFlag=true;

				}

			}while(defaultFlag==true);

		}
	}

	if(flag!=true)
		cout<<"Country not found. Please check for any spelling errors."<<endl;
}

void sortCountries(int &size)
{

	string cNameTemp[1];
	int cSizeTemp[1], cPopulationTemp[1];
	bool flag;

	do
	{

		flag=false;

		for(int i=0;i<size-1;i++)
		{

			if(countryName[i]>countryName[i+1])
			{

				cNameTemp[0]=countryName[i];
				cSizeTemp[0]=countrySize[i];
				cPopulationTemp[0]=countryPopulation[i];

				countryName[i]=countryName[i+1];
				countrySize[i]=countrySize[i+1];
				countryPopulation[i]=countryPopulation[i+1];

				countryName[i+1]=cNameTemp[0];
				countrySize[i+1]=cSizeTemp[0];
				countryPopulation[i+1]=cPopulationTemp[0];

				flag=true;

			}

		}

	}while(flag==true);

	for(int i=0;i<size;i++)
	{

		cout<<endl<<setw(15)<<left<<"Country: "<<countryName[i]<<endl;
		cout<<setw(15)<<"Size: "<<countrySize[i]<<" square miles"<<endl;
		cout<<setw(15)<<"Population: "<<countryPopulation[i]<<" people"<<endl<<endl;

	}

}

void exitProgram(ofstream &fout, int &size)
{
	string savefile;

	cout<<endl<<"Please enter the name of the file you want to save your data in."<<endl;
	//cin.ignore(1000, '\n');
	getline(cin, savefile);
	fout.open(savefile.c_str());

	if(fout.fail())
	{
		cout<<"Memory is full."<<endl;
		system("pause");
		exit(0);
	}

	for(int i=0; i<size; i++)
	{

		fout<<countryName[i]<<endl;
		fout<<countrySize[i]<<endl;
		fout<<countryPopulation[i]<<endl;

	}

	fout.close();
	cout<<endl<<"Thank you for using this program. Good bye."<<endl;
}

void createFile(ofstream &fout, int &size)
{
	string savefile;

	cout<<endl<<"Please enter the name of the file you want to save your data in."<<endl;
	cin.ignore(1000, '\n');
	getline(cin, savefile);
	fout.open(savefile.c_str());

	if(fout.fail())
	{
		cout<<"Memory is full."<<endl;
		system("pause");
		exit(0);
	}

	addCountry(size);

	fout.close();
}

void mainMenu(int size, ofstream &fout)
{
	int menu;

	do
	{
		cout<<endl<<"Please enter one of the following options: "<<endl;
		cout<<"1: Edit an existing country"<<endl;
		cout<<"2: Add a new country"<<endl;
		cout<<"3: Delete a country"<<endl;
		cout<<"4: List all the counties in alphabetical order"<<endl;
		cout<<"5: Save and exit"<<endl;
		cout<<"Option: ";

		cin>>menu;
		cin.ignore(1000, '\n');

		switch(menu)
		{

		case 1:
			editStatistics(size);
			break;

		case 2:
			addCountry(size);
			break;

		case 3:
			removeCountry(size);
			break;

		case 4:
			sortCountries(size);
			break;

		case 5:
			exitProgram(fout, size);
			break;

		default:
			cout<<endl<<"Invalid menu."<<endl;
			system("pause");
			exit(0);

		}

	}while(menu!=5);

}

int main()
{

	ifstream fin;
	ofstream fout;
	int size=0, fileCode;
	bool defaultFlag=true;
	string junk;

	cout<<"Please choose and enter one of the following numbers:"<<endl;
	cout<<"1: I do not have an input file to read from."<<endl;
	cout<<"2: I have an input file to read from."<<endl;
	cout<<"Please enter 1 or 2: ";

	cin>>fileCode;

		switch(fileCode)
		{

		case 1:
			createFile(fout, size);
			defaultFlag=false;
			break;

		case 2:
			readFile(fin, size);
			defaultFlag=false;
			break;

		default:
			cout<<"Error detected"<<endl;
			system("pause");
			exit(0);

		}

	mainMenu(size, fout);

	system("pause");
	return 0;

}