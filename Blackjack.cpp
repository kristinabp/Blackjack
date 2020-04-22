#include "Blackjack.h"

Blackjack::Blackjack(const char * name,int age, int size): player(Player(name,age)), deck(Deck(size)), 
								dealer(Player("dealer",20)), playerCards(nullptr), dealerCards(nullptr)
{
	initialize();
}

Blackjack::Blackjack(const Player & other, int size):player(Player(other)),deck(Deck(size)), 
						dealer(Player("dealer",20)),playerCards(nullptr),dealerCards(nullptr)
{
	initialize();
}

Blackjack::~Blackjack()
{
	erasePlayerCards();
	eraseDealerCards();
}

void Blackjack::play()
{
	std::cout << "Start!\n";

	this->countPlayerCards++;
	this->playerCards = new Card[countPlayerCards];
	this->playerCards[countPlayerCards - 1] = deck.topCard();
	showPlayerCards();
	if (deck.topCard().getCardValue() == 11 && playerPoints > 10)
	{
		this->playerPoints += 1;
	}
	else
	{
		this->playerPoints += deck.topCard().getCardValue();
	}
	deck.draw();
	std::cout << "(Points:" << pPoints() << ")\n";
	std::cout << "Hit/Stand/Probability  \n";

	while (!playerFlag && !dealerFlag)
	{
		std::cout << "$ ";
		std::cin.getline(command, 12);
		if (strcmp(command, "Hit") == 0 || strcmp(command, "hit") == 0)
		{
			playerDraw();
			if (playerPoints > 21)
			{
				std::cout << "You lose!\n";
				dealerFlag = true;
		    }
		    else if (playerPoints == 21)
		    {
				std::cout << "You win!\n";
				playerFlag = true;
			}
			else
			{
				std::cout << "Hit/Stand/Probability  \n";
			}
		}
		else if (strcmp(command, "Stand") == 0 || strcmp(command, "stand") == 0)
		{
			stand();
			if (dealerPoints == 21)
			{
				std::cout << "You lose!\n";
				dealerFlag = true;
			}
			else if (dealerPoints > 21)
			{
				std::cout << "You win!\n";
				playerFlag = true;
			}
			else 
			{
				if (playerPoints == dealerPoints)
				{
					std::cout << "You win!\n";
					playerFlag = true;
				}
				else if (playerPoints > dealerPoints)
				{
					std::cout << "You win!\n";
					playerFlag = true;
				}
				else
				{
					std::cout << "You lose!\n";
					dealerFlag = true;
				}
			}
		}
		else if (strcmp(command, "Probability") == 0 || strcmp(command, "probability") == 0)
		{
			probability();
		}
	}
	if (playerFlag)
	{ 
		player.updateWins();
		save();
	}
	else {
		player.updatePlayedGames();
		save();
	}
}

void Blackjack::stand()
{
	while (dealerPoints < 17)
	{
		dealerDraw();
	}
	std::cout << "The dealer's draw :";
	showDealerCards();
	std::cout << "(Points:" << dPoints() << ")\n";
}

void Blackjack::probability()
{
	if (21-playerPoints > 11)
	{
		std::cout << 0 << "\n";
	}
	else
	{
		switch (21 - playerPoints)
		{
		case 1:
			std::cout << deck.rank_count("A")*1.0 / deck.leftCards() << "\n";
			break;
		case 2:
			std::cout << deck.rank_count("2")*1.0 / deck.leftCards() << "\n";
			break;
		case 3:
			std::cout << deck.rank_count("3")*1.0 / deck.leftCards() << "\n";
			break;
		case 4:
			std::cout << deck.rank_count("4")*1.0 / deck.leftCards() << "\n";
			break;
		case 5:
			std::cout << deck.rank_count("5")*1.0 / deck.leftCards() << "\n";
			break;
		case 6:
			std::cout << deck.rank_count("6")*1.0 / deck.leftCards() << "\n";
			break;
		case 7:
			std::cout << deck.rank_count("7")*1.0 / deck.leftCards() << "\n";
			break;
		case 8:
			std::cout << deck.rank_count("8")*1.0 / deck.leftCards() << "\n";
			break;
		case 9:
			std::cout << deck.rank_count("9")*1.0 / deck.leftCards() << "\n";
			break;
		case 10:
			std::cout << (deck.rank_count("10") + deck.rank_count("K") + deck.rank_count("Q") + deck.rank_count("J"))*1.0 / deck.leftCards() << "\n";
			break;
		case 11:
			std::cout << deck.rank_count("A")*1.0 / deck.leftCards() << "\n";
			break;
		}
	}

	std::cout << "Hit/Stand/Probability \n";
}

void Blackjack::save()
{
	std::fstream os("players.data", std::ios::binary | std::ios::out | std::ios::trunc);
	if (!os)
	{
		std::cout << "ERROR";
		return;
	}
	player.write(os);
	os.close();
	std::cout << "All changes are saved successfully in the file!\n";
	player.print(std::cout);
}

void Blackjack::erasePlayerCards()
{
	delete[] this->playerCards;
}

void Blackjack::eraseDealerCards()
{
	delete[] this->dealerCards;
}

void Blackjack::playerDraw()
{
	Card* temp = new Card[countPlayerCards + 1]; 
	for (int i = 0; i < countPlayerCards; i++)
	{
		temp[i] = this->playerCards[i];
	}

	erasePlayerCards();
	temp[countPlayerCards] = deck.topCard();
	this->playerCards = temp;
	temp = nullptr;
	this->countPlayerCards++;

	showPlayerCards();
	if (deck.topCard().getCardValue() == 11 && playerPoints>10)
	{
		this->playerPoints += 1;
	}
	else
	{
		this->playerPoints += deck.topCard().getCardValue();
	}
	deck.draw();
	std::cout << "(Points:" << pPoints() << ")\n";
}

void Blackjack::dealerDraw()
{
	Card* temp = new Card[countDealerCards + 1];
	for (int i = 0; i < countDealerCards; i++)
	{
		temp[i] = this->dealerCards[i];
	}
	eraseDealerCards();
	temp[countDealerCards] = deck.topCard();
	this->countDealerCards++;
	this->dealerCards = temp;
	temp = nullptr;
	this->dealerPoints += deck.topCard().getCardValue();
	deck.draw();
}

void Blackjack::showPlayerCards()
{
	for (int i = 0; i < countPlayerCards; i++)
	{
		this->playerCards[i].print();
	}
}

void Blackjack::showDealerCards()
{
	for (int i = 0; i < countDealerCards; i++)
	{
		this->dealerCards[i].print();
	}
}

void Blackjack::initialize()
{
	this->countPlayerCards = 0;
	this->countDealerCards = 0;
	this->playerPoints = 0;
	this->dealerPoints = 0;
}

int Blackjack::pPoints()
{
	return this->playerPoints;
}

int Blackjack::dPoints()
{
	return this->dealerPoints;
}
