#pragma once
#include <SFML/Graphics.hpp>

//FRAME CLASS
class Frame : public sf::RectangleShape
{
public:
	Frame(sf::Vector2f &size, sf::Vector2f &pos)
	{
		this->setSize(size);
		this->setPosition(pos);
		this->setFillColor(sf::Color::Black);
	}
};