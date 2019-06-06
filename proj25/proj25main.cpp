/*

Naoaki Takatsu
December 8, 2016
Purpose: Create a binary search tree program utilizing templates;
Inputs: binary tree vector, object name;
Output: object names in stack, error message if name not found in stack;

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include<stack>
#include "proj25.h"

using namespace std;

/*

main function
@param BLT = binary tree string vector;

*/

int main()
{

	BinaryTree <string> BLT;

	BLT.insertNode("Larry Doering");
	BLT.insertNode("Grant Stoltz");
	BLT.insertNode("Randy Kerdun");
	BLT.insertNode("Dennis Miller");
	BLT.insertNode("Kerry Tomei");
	BLT.insertNode("Nancy Reagan");
	BLT.insertNode("Veronica Mars");
	BLT.insertNode("Bianca Bjorn");
	BLT.insertNode("Francine Hoffman");
	BLT.insertNode("Helene Black");
	BLT.insertNode("Kooper Sloan");
	BLT.insertNode("Monica Faber");
	BLT.insertNode("Oprah Winnona");
	BLT.insertNode("Paula Abdul");
	BLT.insertNode("Sandra Day O'Conner");

	BLT.getPath("Paula Abdul");
	BLT.getPath("Bozo the clone");

	cout<<"Program executed successfully."<<endl;

	system("pause");

	return 0;

}