#pragma once
#include <SFML/Graphics.hpp>

//PLAYERSHIP CLASS
class PlayerShip : public sf::CircleShape
{
public:
	PlayerShip(float radius, int vertices, sf::Vector2f &pos)
		{
			this->setRadius(radius);
			this->setPointCount(vertices);
			this->setFillColor(sf::Color::White);
			this->setOutlineColor(sf::Color::Red);
			this->setOutlineThickness(3);
			this->setPosition(pos);
		}
	void teleport(int direction);
};
