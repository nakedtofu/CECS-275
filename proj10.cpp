#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<iterator>
#include<cctype>

using namespace std;

string lowerCaseConverter(string word) 
{

	vector <char> wordVector;

	for(unsigned int i=0; i<word.size(); i++)
	{

		wordVector.push_back(word.at(i));

	}

	for(unsigned int j=0; j<wordVector.size(); j++)
	{

		wordVector[j]=tolower(wordVector[j]);

	}

	word="";

	for(unsigned int z=0; z<wordVector.size(); z++)
	{

		word+=wordVector[z];

	}

	return word;

}

bool palindromeChecker(string word, int startIndex, int endIndex)
{

	if(startIndex<endIndex)
	{

		while(startIndex<endIndex && isalpha(word.at(startIndex))==false)
		{

			startIndex++;

		}

		while(startIndex<endIndex && isalpha(word.at(endIndex))==false)
		{

			endIndex--;

		}

		if(word.at(startIndex)==word.at(endIndex))
		{

			startIndex++;
			endIndex--;
			return palindromeChecker(word, startIndex, endIndex);

		}

		else
		{

			return false;
			
		}

	}

	else
	{

		return true;

	}

}


void mainMenu()
{

	bool palindromeFlag=true;
	string originalWord, convertedWord, continueNumber="1";
	int startIndex=0, endIndex=0;

	do
	{

		cout<<"Please enter any word(s) to see if it's a palindrome: ";
		getline(cin, originalWord);

		convertedWord=lowerCaseConverter(originalWord);

		endIndex=convertedWord.size()-1;

		palindromeFlag=palindromeChecker(convertedWord, startIndex, endIndex);

		if(palindromeFlag==true)
		{

			cout<<"'"<<originalWord<<"'"<<" is a palindrome."<<endl;
			cout<<"Press 1 to continue or any other key to exit: ";
			cin>>continueNumber;

		}

		else
		{

			cout<<"'"<<originalWord<<"'"<<" is not a palindrome."<<endl;
			cout<<"Press 1 to continue or any other key to exit: ";
			cin>>continueNumber;

		}

		cin.ignore();
		cin.clear();

	}while(continueNumber=="1");

}

int main()
{

	mainMenu();

	cout<<"Program executed successfully."<<endl;

	system("pause");

	return 0;

}