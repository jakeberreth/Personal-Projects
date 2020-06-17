#include "PlayerShip.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//Player ship jumping ability
void PlayerShip::teleport(int direction)
{
	if (direction == 1)
	{
		move(100, 0);
	}
	if (direction == 2)
	{
		move(-100, 0);
	}
}