#pragma once
#include "EnemyShip.h"

//BATTLESHIP CLASS
class BattleShip : public EnemyShip
{
public:
	BattleShip(sf::Vector2f &size, sf::Vector2f &pos, const sf::Color &myColor)
	{
		this->setFillColor(myColor);
		this->setOutlineColor(sf::Color::Red);
		this->setOutlineThickness(3);
		this->setSize(sf::Vector2f(300.f, 40.f));
		this->setPosition(pos);
	}
	virtual void moveShip(int change, BattleShip battleShip);
	~BattleShip();
};
