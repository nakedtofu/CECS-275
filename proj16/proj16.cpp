/*

Naoaki Takatsu
October 18, 2016
Purpose: Create a vending machine program with soda class and vending machine class
Inputs: Location of the vending machine, soda name, and quantity to stock/purchase
Output: Soda name, price, quantity, and total price for every type of soda

*/

#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

int main()
{

	struct queen
	{

		int row, column;

	};

	typedef vector<queen> queenVector;

	typedef vector<queenVector> solutionVector;

	solutionVector solution(1, queenVector(8));

	solutionVector tempSolution(1, queenVector(8));

	queen temp;

	int solutionCount;

	for(int a=1; a<9; a++)
	{

		temp.row = 1;
		temp.column = a;

		tempSolution.push_back(temp);

		for(int a=1; a<9; a++)
		{

			temp.row = 2;
			temp.column = a;

			tempSolution.push_back(temp);

			for(int a=1; a<9; a++)
			{

				temp.row = 3;
				temp.column = a;

				tempSolution.push_back(temp);

				for(int a=1; a<9; a++)
				{

					temp.row = 4;
					temp.column = a;

					tempSolution.push_back(temp);

					for(int a=1; a<9; a++)
					{

						temp.row = 5;
						temp.column = a;

						tempSolution.push_back(temp);

						for(int a=1; a<9; a++)
						{

							temp.row = 6;
							temp.column = a;

							tempSolution.push_back(temp);

							for(int a=1; a<9; a++)
							{

								temp.row = 7;
								temp.column = a;

								tempSolution.push_back(temp);

								for(int a=1; a<9; a++)
								{

									temp.row = 8;
									temp.column = a;

									tempSolution.push_back(temp);


								}

							}

						}

					}

				}

			}

		}

	}

	for(int i=0; i<tempSolution.size(); i++)
	{

		cout<<endl<<"Queen position: ";

		for(int z=0; z<8; z++)
		{

			for(int t=0; t<tempSoluion.size(); t++)
			{

				for(int f=0; f<8; f++)
				{
				
					if(tempSolution[t][f] != temp[])
				
				}
			}

			if(/* use for loop to check through tempSolution vector if each queen's row != row && column != column && row+column != row+column && row-column != row-column compared to other queens*/)
			{

				//cout<<tempSolution[i][z]<<' ';

			}

		}

	}

}