#include<iostream>
#include<limits>
#include<fstream>
#include "Card.h"
#include "Blackjack.h"

int main()
{
	Player ivan("Ivan Ivanov", 20, 5, 0.8);
	Player petar("Petar Popov", 18, 4, 1);
	Player kiril("Kiril Petkov", 21,2, 0.5);
	std::fstream os("players.data", std::ios::binary | std::ios::out | std::ios::trunc);
	if (!os)
	{
		std::cout << "ERROR";
		return 1;
	}
	ivan.write(os);
	petar.write(os);
	kiril.write(os);
	os.close();
	Player p1,p2,p3;
	std::fstream is("players.data", std::ios::binary | std::ios::in);
	if (!is)
	{
		std::cout << "ERROR";
		return 1;
	}
	p1.read(is);
	p2.read(is);
	p3.read(is);
	is.close();

	p1.print(std::cout);
	p2.print(std::cout);
	p3.print(std::cout);

	char* name=new char[20];
	int sizeOfDeck;
	int age;
	std::cout << "Chose a player or enter a new player: \n";
	std::cin.getline(name, 256);
	if (strcmp(name, p1.getName()) == 0)
	{
		std::cout << "You will play as " << p1.getName() << ". Choose the size of the deck:  \n";
		std::cin >> sizeOfDeck;
		std::cin.ignore();
		Blackjack b(p1, sizeOfDeck);
		b.play();
	}
	else if (strcmp(name, p2.getName()) == 0)
	{
		std::cout << "You will play as " << p2.getName() << ". Choose the size of the deck:  \n";
		std::cin >> sizeOfDeck;
		std::cin.ignore();
		Blackjack b(p2, sizeOfDeck);
		b.play();
	}
	else if (strcmp(name, p3.getName()) == 0)
	{
		std::cout << "You will play as " << p3.getName() << ". Choose the size of the deck:  \n";
		std::cin >> sizeOfDeck;
		std::cin.ignore();
		Blackjack b(p3, sizeOfDeck);
		b.play();
	}
	else
	{
		std::cout << "You will play as " << name << ". Enter your age:  \n";
		std::cin >> age;
		std::cout<< "Choose the size of the deck:  \n";
		std::cin >> sizeOfDeck;
		std::cin.ignore();
		Blackjack b(name, age, sizeOfDeck);
		b.play();
	}
	return system("pause");
}
