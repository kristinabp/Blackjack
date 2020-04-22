#ifndef DECK_H
#define DECK_H

#include "Card.h"
#define CARDS 52

class Deck
{
private:
	Card* cards;
	char* seria;
	static bool used[4][14];
	int cardsNum;
	int countDraws;

	bool created(int suits, int ranks);
	void del();
	void copy(const Deck& other);

public:
	Deck();
	Deck(int k,const char* seria="custom");
	Deck(const Deck& other);
	~Deck();

	Deck& operator=(const Deck& other);

	Card draw();
	void swap(int x, int y);
	int suit_count(const char* suit)const;
	int rank_count(const char* rank)const;

	int getSize()const;
	int leftCards()const;
	Card topCard()const;
	void print()const;
};
#endif // !DECK_H
