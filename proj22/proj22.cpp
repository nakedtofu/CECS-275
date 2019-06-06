#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include<stack>
//#include "proj22listnode.h"

using namespace std;


/*

stack class
@param stackList = stack of string type

*/

class stackClass
{

public:

	stack<string> stackList;

	/*

	insert to bottom function
	@param message = string data, stackTemp = temporary stack

	*/

	void insertFirst(string message)
	{

		stack<string> stackTemp;

		while(!stackList.empty())
		{

			stackTemp.push(stackList.top());
			stackList.pop();

		}

		cout<<"Inserting element: "<<message<<" to the front of stack."<<endl;
		stackTemp.push(message);

		while(!stackTemp.empty())
		{

			stackList.push(stackTemp.top());
			stackTemp.pop();

		}

	}

	/*

	print stack contents function
	@param stackTemp = temporary stack

	*/

	void printAll()
	{

		stack <string> stackTemp;

		try
		{

			if(stackList.empty())
			{

				throw(1);

			}

			cout<<"Printing all elements from bottom to top: ";

			while(!stackList.empty())
			{

				stackTemp.push(stackList.top());
				cout<<stackList.top()<<" ";
				stackList.pop();

			}

			while(!stackTemp.empty())
			{

				stackList.push(stackTemp.top());
				stackTemp.pop();

			}

			cout<<endl;

		}

		catch(int x)		
		{

			cout<<"Error, you cannot print from an empty stack."<<endl;

		}

	}

	/*

	delete bottom function
	@param stackTemp = temporary stack

	*/

	void deleteFirst()
	{

		stack<string> stackTemp;

		try
		{

			if(stackList.empty())
			{

				throw(1);

			}

			while(!stackList.empty())
			{

				stackTemp.push(stackList.top());
				stackList.pop();

			}

			cout<<"Deleting first element: "<<stackTemp.top()<<endl;
			stackTemp.pop();

			while(!stackTemp.empty())
			{

				stackList.push(stackTemp.top());
				stackTemp.pop();

			}

		}
		catch(int x)

		{

			cout<<"Error, you cannot delete from an empty stack."<<endl;

		}

	}

};

/*

main method
@param stackC = stack class

*/

int main()
{

	stackClass stackC;

	stackC.insertFirst("1");
	stackC.insertFirst("2");
	stackC.insertFirst("3");
	stackC.insertFirst("4");
	stackC.insertFirst("5");
	stackC.insertFirst("6");
	stackC.insertFirst("7");
	stackC.insertFirst("8");
	stackC.insertFirst("9");
	stackC.insertFirst("10");

	cout<<"Printing stack size: "<<stackC.stackList.size()<<endl;

	stackC.printAll();

	for(int i=0; i<11; i++)
	{
		stackC.deleteFirst();

		cout<<"Printing stack size: "<<stackC.stackList.size()<<endl;

		stackC.printAll();
	}
	system("pause");

	return 0;

}