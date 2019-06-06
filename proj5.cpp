/*

Greatest Common Divisor
CECS 275
Made by Naoaki Takatsu
9/6/16

=Algorithm=
-Prompt the user to input one of the following options to calculate the area/volume for a:
	1: Circle
	2: Rectangel
	3: Triangle
	4: Sphere
	5: Box
	6: Cylinder
	7: Exit
-Display error message if format/criteria doesn't match.
-Prompt user to input the dimensions for the geometric figure he/she has chosen.
-Display what kind of geometric figure the user has chosen and the area/volume for it as well.
-Loop until user enters 7 to exit.
-Display how many times the calculation was executed for each of the geometric figures as well as the total area/volume.
*/

#include <iostream>
#include<cmath>
#include<string>
#include <iomanip>

using namespace std;

const double pi = 3.14159265359;

double radiusGetter()//gets the radius
{

	double radius;
	string junk;

	cout<<"Please enter a non-zero positive value for the radius of this geometric figure in numeric format: ";
	cin>>radius;

	while(cin.fail() || radius <= 0)
	{

		cout<<"Please enter a non-zero positive value for the radius of this geometric figure in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>radius;

	}

	return radius;
}

double widthGetter()//gets the width
{

	double width;
	string junk;

	cout<<"Please enter a non-zero positive value for the width of this geometric figure in numeric format: ";
	cin>>width;

	while(cin.fail() || width <= 0)
	{

		cout<<"Please enter a non-zero positive value for the width of this geometric figure in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>width;

	}

	return width;
}

double lengthGetter()//gets the length
{

	double length;
	string junk;

	cout<<"Please enter a non-zero positive value for the length of this geometric figure in numeric format: ";
	cin>>length;

	while(cin.fail() || length <= 0)
	{

		cout<<"Please enter a non-zero positive value for the length of this geometric figure in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>length;

	}

	return length;

}

double heightGetter()//gets the height
{

	double height;
	string junk;

	cout<<"Please enter a non-zero positive value for the height of this geometric figure in numeric format: ";
	cin>>height;

	while(cin.fail() || height <= 0)
	{

		cout<<"Please enter a non-zero positive value for the height of this geometric figure in numeric format: ";
		cin.clear();
		getline(cin, junk);
		cin>>height;

	}

	return height;

}

double rectangleAreaCalculator(double width, double length) //calculates the gcd of the two numbers
{

	return width*length;

}

double triangleAreaCalculator(double base, double height)
{

	return (base*height) / (2);

}

double circleAreaCalculator(double radius) //calculates the gcd of the two numbers
{

	return pi*pow(radius,2);

}

double sphereVolumeCalculator(double radius) //calculates the gcd of the two numbers
{

	return (4/3)*pi*pow(radius,3);

}

double boxVolumeCalculator(double width, double length, double height) //calculates the gcd of the two numbers
{

	return width*length*height;

}

double cylinderVolumeCalculator(double radius, double height) //calculates the gcd of the two numbers
{

	return pi*pow(radius, 2)*height;

}

void menuGetter()
{

	double width=0, length=0, height=0, radius=0, area=0, volume=0, totalCircleArea=0, totalRectangleArea=0, totalTriangleArea=0, totalSphereVolume=0, totalBoxVolume=0, totalCylinderVolume=0;
	int option, circleCount=0, rectangleCount=0, triangleCount=0, sphereCount=0, boxCount=0, cylinderCount=0;
	string junk;
	bool optionFlag = false;

	cout<<"Welcome to Geometry Calculator Program."<<endl;

	do //loop until user enters 0
	{

		cout<<"Input one of the following options to calculate the area/volume for a:"<<endl;
		cout<<"1: Circle"<<endl;
		cout<<"2: Rectangle"<<endl;
		cout<<"3: Triangle"<<endl;
		cout<<"4: Sphere"<<endl;
		cout<<"5: Box"<<endl;
		cout<<"6: Cylinder"<<endl;
		cout<<"7: Exit"<<endl;
		cout<<"Menu Option: ";

		cin>>option;

		switch(option) //switch statement. 1 to execute program, 0 to quit, else display error message.
		{

		case 1:

			cin.clear();
			getline(cin, junk);
			radius = radiusGetter();
			area = circleAreaCalculator(radius);
			totalCircleArea += area;
			circleCount++;

			cout<<"The area of a circle with radius "<<fixed<<setprecision(4)<<radius<<" is "<<area<<"."<<endl;
			break;

		case 2:

			cin.clear();
			getline(cin, junk);
			width = widthGetter();
			length = lengthGetter();
			area = rectangleAreaCalculator(width, length);
			totalRectangleArea += area;
			rectangleCount++;

			cout<<"The area of a rectangle with width "<<width<<" and length "<<length<<" is "<<fixed<<setprecision(4)<<area<<"."<<endl;
			break;

		case 3:

			cin.clear();
			getline(cin, junk);
			width = widthGetter();
			height = heightGetter();
			area = triangleAreaCalculator(width, height);
			totalTriangleArea += area;
			triangleCount++;

			cout<<"The area of a triangle with width "<<width<<" and height "<<height<<" is "<<fixed<<setprecision(4)<<area<<"."<<endl;
			break;

		case 4:

			cin.clear();
			getline(cin, junk);
			radius = radiusGetter();
			volume = sphereVolumeCalculator(radius);
			totalSphereVolume += volume;
			sphereCount++;

			cout<<"The volume of a sphere with radius "<<radius<<" is "<<fixed<<setprecision(4)<<volume<<"."<<endl;
			break;

		case 5:

			cin.clear();
			getline(cin, junk);
			width = widthGetter();
			length = lengthGetter();
			height = heightGetter();
			volume = boxVolumeCalculator(width, length, height);
			totalBoxVolume += volume;
			boxCount++;

			cout<<"The volume of a box with width "<<width<<", length "<< length <<", and height "<< height<< " is "<<fixed<<setprecision(4)<<volume<<"."<<endl;
			break;

		case 6:

			cin.clear();
			getline(cin, junk);
			radius = radiusGetter();
			height = heightGetter();
			volume = cylinderVolumeCalculator(radius, height);
			totalCylinderVolume += volume;
			cylinderCount++;

			cout<<"The volume of a sphere with radius "<<radius<<" and height "<<height<<" is "<<fixed<<setprecision(4)<<volume<<"."<<endl;
			break;

		case 7:

			optionFlag=true;
			break;

		default:

			cout<<"Please enter one of the following options in numeric format."<<endl;
			cin.clear();
			getline(cin, junk);
			break;

		}

	}while(optionFlag==false);

	cout<<endl<<setw(38)<<right<<setfill('=')<<"End Results"<<setw(27)<<"="<<setfill(' ')<<endl;

	cout<<endl<<setw(20)<<left<<"Geometry Figure:"	<<setw(25)<<right<<"# of times calculated:"	<<setw(20)<<"Total area:";
	cout<<endl<<setw(20)<<left<<"Circle"			<<setw(25)<<right<<circleCount				<<setw(20)<<fixed<<setprecision(4)<<totalCircleArea;
	cout<<endl<<setw(20)<<left<<"Rectangle"			<<setw(25)<<right<<rectangleCount			<<setw(20)<<fixed<<setprecision(4)<<totalRectangleArea;
	cout<<endl<<setw(20)<<left<<"Triangle"			<<setw(25)<<right<<triangleCount			<<setw(20)<<fixed<<setprecision(4)<<totalTriangleArea;
	cout<<endl<<setw(20)<<left<<"Sphere"			<<setw(25)<<right<<sphereCount				<<setw(20)<<fixed<<setprecision(4)<<totalSphereVolume;
	cout<<endl<<setw(20)<<left<<"Box"				<<setw(25)<<right<<boxCount					<<setw(20)<<fixed<<setprecision(4)<<totalBoxVolume;
	cout<<endl<<setw(20)<<left<<"Cylinder"			<<setw(25)<<right<<cylinderCount			<<setw(20)<<fixed<<setprecision(4)<<totalCylinderVolume<<endl<<endl;

	cout<<left<<"See you next time!"<<endl;
	system("pause");
	exit(0);

}

int main()
{

	menuGetter();

	return 0;

}