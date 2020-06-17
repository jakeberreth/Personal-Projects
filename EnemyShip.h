#pragma once
#include <SFML/Graphics.hpp>

//ENEMYSHIP CLASS
class EnemyShip : public sf::RectangleShape
{
public:
	EnemyShip();
	EnemyShip(sf::Vector2f &size, sf::Vector2f &pos, const sf::Color &myColor)
	{
		this->setFillColor(myColor);
		this->setOutlineColor(sf::Color::Red);
		this->setOutlineThickness(3);
		this->setSize(sf::Vector2f(10.f, 20.f));
		this->setPosition(pos);
	}
	virtual void moveShip(int direction);
};


