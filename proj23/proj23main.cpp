#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include<stack>
#include "proj23.h"

using namespace std;

/*

main function
@param BLT = binary tree string vector;

*/

int main()
{

	BinaryTree <string> BLT;

	BLT.insertNode("Larry Doering");

	cout<<"Maximum width: "<<BLT.getWidth()<<endl;

	BLT.insertNode("Grant Stoltz");
	BLT.insertNode("Randy Kerdun");

	cout<<"Maximum width: "<<BLT.getWidth()<<endl;

	BLT.insertNode("Dennis Miller");
	BLT.insertNode("Kerry Tomei");
	BLT.insertNode("Nancy Reagan");
	BLT.insertNode("Veronica Mars");
	BLT.insertNode("Bianca Bjorn");

	cout<<"Maximum width: "<<BLT.getWidth()<<endl;

	BLT.insertNode("Francine Hoffman");
	BLT.insertNode("Helene Black");
	BLT.insertNode("Kooper Sloan");
	BLT.insertNode("Monica Faber");
	BLT.insertNode("Oprah Winnona");
	BLT.insertNode("Paula Abdul");
	BLT.insertNode("Sandra Day O'Conner");

	cout<<"Maximum width: "<<BLT.getWidth()<<endl;

	cout<<"Program executed successfully."<<endl;

	system("pause");

	return 0;

}