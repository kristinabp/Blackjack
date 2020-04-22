#include "card.h"

void Card::createCard(int suits, int ranks)
{
	switch (suits) {
	case 0:
		this->suit = new char[strlen("Diamonds") + 1];
		strcpy_s(this->suit, strlen("Diamonds") + 1, "Diamonds");
		break;
	case 1:
		this->suit = new char[strlen("Hearts") + 1];
		strcpy_s(this->suit, strlen("Hearts") + 1, "Hearts");
		break;
	case 2:
		this->suit = new char[strlen("Clubs") + 1];
		strcpy_s(this->suit, strlen("Clubs") + 1, "Clubs");
		break;
	case 3:
		this->suit = new char[strlen("Spades") + 1];
		strcpy_s(this->suit, strlen("Spades") + 1, "Spades");
		break;
	}

	switch (ranks)
	{
	case 1:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "2");
		break;
	case 2:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "3");
		break;
	case 3:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "4");
		break;
	case 4:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "5");
		break;
	case 5:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "6");
		break;
	case 6:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "7");
		break;
	case 7:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "8");
		break;
	case 8:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "9");
		break;
	case 9:
		this->rank = new char[3];
		strcpy_s(this->rank, 3, "10");
		break;
	case 10:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "J");
		break;
	case 11:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "Q");
		break;
	case 12:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "K");
		break;
	case 0:
		this->rank = new char[2];
		strcpy_s(this->rank, 2, "A");
		break;
	}

	this->serialNumber = new char[strlen(this->rank) + strlen(this->suit) + 1];
	strcpy_s(this->serialNumber, strlen(this->rank) + strlen(this->suit)+1, this->rank);
	strcat_s(this->serialNumber,strlen(this->rank)+ strlen(this->suit) + 1, this->suit);
}

void Card::del()
{
	delete[] this->rank;
	delete[] this->suit;
	delete[] this->serialNumber;
}

void Card::copy(const Card& other)
{
	this->rank = new char[strlen(other.rank) + 1];
	strcpy_s(this->rank, strlen(other.rank) + 1, other.rank);
	this->suit = new char[strlen(other.suit) + 1];
	strcpy_s(this->suit, strlen(other.suit) + 1, other.suit);
	this->serialNumber = new char[strlen(other.serialNumber) + 1];
	strcpy_s(this->serialNumber, strlen(other.serialNumber) + 1, other.serialNumber);
}

Card::Card()
{
	srand(time(NULL));
	int ranks = rand() % 13 + 1;
	int suits = rand() % 4;
	createCard(suits, ranks);
}

Card::Card(int suits, int ranks)
{
	createCard(suits, ranks);
}

Card::Card(const Card& other)
{
	copy(other);
}

Card::~Card()
{
	del();
}

Card & Card::operator=(const Card & other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

int Card::getCardValue() const
{
	if (strcmp(rank, "2") == 0)
	{
		return 2;
	}
	else if (strcmp(rank, "3") == 0)
	{
		return 3;
	}
	else if (strcmp(rank, "4") == 0)
	{
		return 4;
	}
	else if (strcmp(rank, "5") == 0)
	{
		return 5;
	}
	else if (strcmp(rank, "6") == 0)
	{
		return 6;
	}
	else if (strcmp(rank, "7") == 0)
	{
		return 7;
	}
	else if (strcmp(rank, "8") == 0)
	{
		return 8;
	}
	else if (strcmp(rank, "9") == 0)
	{
		return 9;
	}
	else if (strcmp(rank, "10") == 0 || strcmp(rank, "J") == 0 || strcmp(rank, "Q") == 0 || strcmp(rank, "K") == 0)
	{
		return 10;
	}
	else return 11;
}

char * Card::getRank() const
{
	return this->rank;
}

char * Card::getSuit() const
{
	return this->suit;
}

//void Card::setSeariaWithSerialNumber(const char * seria)
//{
//	char* temp = new char[strlen(seria) + strlen(serialNumber) + 1];
//	for (int i = 0; i < strlen(seria); i++)
//	{
//		temp[i] = seria[i];
//	}
//	int k = 0;
//	for (int i = strlen(seria); i < strlen(seria) + strlen(serialNumber); i++)
//	{
//		temp[i] = serialNumber[k++];
//	}
//	temp[strlen(seria) + strlen(serialNumber)] = '\0';
//	delete[]this->serialNumber;
//	this->serialNumber = new char[strlen(temp)+1];
//	for (int i = 0; i < strlen(temp); i++)
//	{
//		serialNumber[i]=temp[i];
//	}
//	this->serialNumber[strlen(temp)] = '\0';
//	delete[]temp;
//}

void Card::print() const
{
	std::cout <<this->rank << "(" << this->suit << ") ";
}
