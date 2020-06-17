#pragma once
#include <SFML/Graphics.hpp>

class Blast : public sf::CircleShape
{
public:
	Blast(sf::Vector2f &pos, const sf::Color &myColor, float radius)
	{
		this->setRadius(radius);
		this->setFillColor(myColor);
		this->setOutlineColor(sf::Color::Green);
		this->setOutlineThickness(3);
		this->setPosition(pos);
	}
};
