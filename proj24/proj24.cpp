#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>
#include "proj24.h";

using namespace std;

int main()
{

	void play(hand, hand);

	hand handDeck, hand1, hand2;

	handDeck.deck();

	for(int i=0; i<handDeck.sizeOf(); i++)
		handDeck.toString();

	handDeck.shuffle();

	handDeck.deal(hand1, hand2);

	play(hand1, hand2);

	system("pause");

	return 0;

}

void play(hand hand1, hand hand2)
{

	//while hand1.sizeOf() and/or hand2.sizeOf() == 0, execute game;

}