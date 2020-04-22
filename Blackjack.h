#ifndef BLACKJACK_h
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <fstream>

class Blackjack
{
private:
	int playerPoints;
	int dealerPoints;
	Card* playerCards;
	int countPlayerCards;
	bool playerFlag = false;
	bool dealerFlag = false;
	Card* dealerCards;
	int countDealerCards;
	Player player;
	Player dealer;
	Deck deck;
	char command[12];

	void erasePlayerCards();
	void eraseDealerCards();

	void playerDraw();
	void dealerDraw();
	void showPlayerCards();
	void showDealerCards();

	void initialize();

public:
	Blackjack(const char* name,int age,int size);
	Blackjack(const Player& other, int size);
	~Blackjack();

	void play();
	void stand();
	void probability();
	void save();

	int pPoints();
	int dPoints();
};
#endif // !BLACKJACK_h

