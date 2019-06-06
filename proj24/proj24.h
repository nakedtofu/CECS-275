#include<string>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cctype>
#include <cstdlib>

class Card
{

private:
	enum rank {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, NO_RANK};
	enum suit {CLUBS, DIAMONDS, SPADES, HEARTS, NO_SUIT};

	struct cardProperty
	{



	};

	rank cardRank;
	suit cardSuit;	

	void to_string();


public:

	Card()
	{

		cardRank = NO_RANK;
		cardSuit = NO_SUIT;

	}

	void createCard(rank pRank, suit pSuit)
	{

		cardRank = pRank;
		cardSuit = pSuit;

	}

	bool operator > (const Card &);
	bool operator < (const Card &);
	bool operator >= (const Card &);
	bool operator <= (const Card &);
	bool operator == (const Card &);
	bool operator != (const Card &);

};

class hand
{

public:

	hand()
	{

		vector<Card> deck;

	};

	void deck()
	{

		vector<Card> deck;

	}

	void shuffle()
	{
		//use rand and srand
	}

	void give()
	{

		//pop from hand

	}

	void take()
	{

		//push to hand

	}

	void deal(hand &hand1, hand &hand2)
	{

		//push to decks

	}

	void sizeOf(hand pHand)
	{

		//find size

	}

	void move()
	{

		//use give() and take()

	}

	void toString()
	{

		//print hand

	}

};