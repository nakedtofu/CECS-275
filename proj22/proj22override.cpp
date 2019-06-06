#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<stack>
#include<cctype>
#include <cstdlib>
#include<ostream>
#include "proj22listnode.h"

using namespace std;

ostream &operator << (ostream &outputStream, const stackClass &obj) {
	obj.printAll();

}