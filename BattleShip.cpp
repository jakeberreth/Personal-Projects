#include "BattleShip.h"
#include "EnemyShip.h"
#include "Blast.h"
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//Move the battleship
void BattleShip::moveShip(int change, BattleShip battleShip)
{
	int x = rand() % 5 + 1;
	move(change, 0);
	if (x == 1)
	{
		setFillColor(sf::Color::Red);
	}
	else if (x == 2)
	{
		setFillColor(sf::Color::Green);
	}
	else if (x == 3)
	{
		setFillColor(sf::Color::Blue);
	}
	else if (x == 4)
	{
		setFillColor(sf::Color::Magenta);
	}
	else if (x == 5)
	{
		setFillColor(sf::Color::Yellow);
	}
}

BattleShip::~BattleShip()
{
	//destructor
}