#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

#include <cstring>
#include <iostream>
#include <cstring>

class Player
{
private:
	char* name;
	int age;
	int wins;
	double coef;
	int playedGames;

public:
	Player();
	Player(const char* name, const int age, const int wins, const double coef);
	Player(const char* name, const int age);
	Player(const Player& other);
	~Player();

	Player& operator=(const Player& other);

	char* getName()const;
	void setName(const char* name);

	int getAge()const;
	void setAge(int age);

	int getWins()const;
	void updateWins();

	double getCoef()const;

	void updatePlayedGames();

	void read(std::istream& = std::cin);
	void write(std::ostream& = std::cout) const;

	void print(std::ostream& os);
};

#endif // !PLAYER_H

