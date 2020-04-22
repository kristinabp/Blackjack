#include "Deck.h"

bool Deck::used[4][14] = { false };

bool Deck::created(int ranks, int suits)
{
	return used[ranks][suits];
}

void Deck::del()
{
	delete[] this->cards;
	delete[] this->seria;
}

void Deck::copy(const Deck & other)
{
	this->cardsNum = other.cardsNum;
	this->seria = new char[strlen(other.seria) + 1];
	strcpy_s(this->seria, strlen(other.seria) + 1, other.seria);
	this->countDraws = other.countDraws;
	this->cards = other.cards;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			this->used[i][j] = other.used[i][j];
		}
	}
}

Deck::Deck() : cardsNum(CARDS), countDraws(0)
{
	this->cards = new Card[cardsNum];
	srand(time(NULL));
	int ranks = rand() % 13;
	int suits = rand() % 4;
	for (int i = 0; i < cardsNum; i++)
	{
		ranks = rand() % 13;
		suits = rand() % 4;
		while (created(suits, ranks) == true) {
			ranks = rand() % 13;
			suits = rand() % 4;
		}
		cards[i].createCard(suits, ranks);
		used[suits][ranks] = true;
	}

	this->seria = new char[strlen("default") + 1];
	strcpy_s(seria, strlen("default") + 1, "default");
	/*for (int i = 0; i < cardsNum; i++)
	{
		cards[i].setSeariaWithSerialNumber(seria);
	}*/
	
}

Deck::Deck(int k, const char* seria) : countDraws(0)
{
	this->cardsNum = k;
	this->cards = new Card[cardsNum];
	srand(time(NULL));
	int ranks = rand() % 13;
	int suits = rand() % 4;
	for (int i = 0; i < cardsNum; i++)
	{
		ranks = rand() % 13;
		suits = rand() % 4;
		while (created(suits, ranks) == true) {
			ranks = rand() % 13;
			suits = rand() % 4;
		}
		this->cards[i].createCard(suits, ranks);
		used[suits][ranks] = true;
	}

	this->seria = new char[strlen(seria) + 1];
	strcpy_s(this->seria, strlen(seria) + 1, seria);
	/*for (int i = 0; i < cardsNum; i++)
	{
		cards[i].setSeariaWithSerialNumber(seria);
	}*/
	
}

Deck::Deck(const Deck & other)
{
	copy(other);
}

Deck::~Deck()
{
	del();
}

Deck & Deck::operator=(const Deck & other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

Card Deck::draw()
{
	this->countDraws++;
	Card* temp = new Card(cards[0]);
	for (int i = 0; i < cardsNum - 1; i++)
	{
		this->cards[i] = this->cards[i + 1];
	}
	this->cards[cardsNum -1] = *temp;
	return this->cards[cardsNum - 1];
}

void Deck::swap(int x, int y)
{
	Card temp = cards[x - 1];
	this->cards[x - 1] = this->cards[y - 1];
	this->cards[y - 1] = temp;
}

int Deck::suit_count(const char * suit) const
{
	int counter = 0;
	for (int i = 0; i < cardsNum; i++)
	{
		if (strcmp(cards[i].getSuit(), suit) == 0)
		{
			counter++;
		}
	}
	return counter;
}

int Deck::rank_count(const char *rank) const
{
	int counter = 0;
	for (int i = 0; i < cardsNum - countDraws; i++)
	{
		if (strcmp(cards[i].getRank(), rank) == 0)
		{
			counter++;
		}
	}
	return counter;
}

int Deck::getSize() const
{
	return this->cardsNum;
}

int Deck::leftCards() const
{
	return this->cardsNum - this->countDraws;
}

Card Deck::topCard() const
{
	return cards[0];
}

void Deck::print() const
{
	for (int i = 0; i < cardsNum; i++)
	{
		this->cards[i].print();
	}
}