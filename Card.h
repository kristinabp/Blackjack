#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cstdlib>
#include <time.h>

class Card
{
private:
	char* suit;
	char* rank;
	char* serialNumber;

	void del();
	void copy(const Card& other);

public:
	Card();
	Card(int suits, int ranks);
	Card(const Card& other);
	~Card();

	Card& operator=(const Card& other);

	void createCard(int suits, int ranks);

	int getCardValue()const;

	char* getRank()const;
	char* getSuit()const;

	//void setSeariaWithSerialNumber(const char* seria);

	void print()const;
};
#endif // !CARD_H

