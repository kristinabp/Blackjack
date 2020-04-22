#include "Player.h"

Player::Player() :age(18), wins(0), coef(1),playedGames(0)
{
	this->name = new char[strlen("") + 1];
	strcpy_s(this->name, strlen("") + 1, "");
}

Player::Player(const char * name, const int age, const int wins, const double coef) : wins(wins), coef(coef)
{
	this->setName(name);
	this->setAge(age);
	this->playedGames = this->wins / this->coef;
}

Player::Player(const char * name, const int age) :wins(0), coef(1), playedGames(0)
{
	this->setName(name);
	this->setAge(age);
}

Player::Player(const Player & other) :wins(other.wins), coef(other.coef)
{
	this->setName(other.name);
	this->setAge(other.age);
	this->playedGames = this->wins / this->coef;
}

Player::~Player()
{
	delete[]name;
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		delete[]name;
		this->setName(other.name);
		this->setAge(other.age);
		this->wins = other.wins;
		this->coef = other.coef;
		this->playedGames = this->wins / this->coef;
	}

	return *this;
}

char * Player::getName() const
{
	return this->name;
}

void Player::setName(const char * _name)
{
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

int Player::getAge() const
{
	return this->age;
}

void Player::setAge(int age)
{
	if (age >= 18 && age <= 90)
	{
		this->age = age;
	}
	this->age = 18;
}

int Player::getWins() const
{
	return this->wins;
}

void Player::updateWins()
{
	playedGames++;
	wins++;
	coef = wins * 1.0 / playedGames;
}

double Player::getCoef() const
{
	return this->coef;
}

void Player::updatePlayedGames()
{
	playedGames++;
	coef = wins*1.0 / playedGames;
}

void Player::read(std::istream &in)
{
	int nameLength;
	if (!in)
	{
		std::cout << "ERROR";
		return ;
	}

    in.read((char*)&nameLength, sizeof(int));
	name = new char[nameLength + 1];
	in.read(name, sizeof(char) * nameLength); 
	name[nameLength] = '\0';
	in.read((char*)&wins, sizeof(wins));
	in.read((char*)&coef, sizeof(coef));
	
}

void Player::write(std::ostream & out) const
{
	if (!out)
	{
		std::cout << "ERROR";
		return;
	}

	int nameLength = strlen(this->name); 
	out.write((char*)&nameLength, sizeof(int)); 
	out.write(this->name, sizeof(char) * nameLength); 
	out.write((char*)&this->wins, sizeof(int));
	out.write((char*)&this->coef, sizeof(double));
}

void Player::print(std::ostream& os) 
{
	if (!os) return;
	os << this->name << " " << this->wins << " " << this->coef << std::endl;
}

