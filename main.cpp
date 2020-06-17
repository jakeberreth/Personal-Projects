/********************************************************
Name:            Jake Berreth, Reece Menzel
Class:           Cpt_S 122; Fall, 2019; Lab Section 02
PA 8:            Graphics: Galaga
Date Completed:  12/05/2019
*********************************************************/

#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Blast.h"
#include "Frame.h"
#include "BattleShip.h"
#include "Galaga.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
#include <time.h>
#include <random>
#include <math.h>
#include <chrono>
#include <fstream>
using namespace chrono;

//Galaga Game Implementation

int main()
{
	ofstream outFile;
	char outFileName[] = "GameTimes.txt";
	outFile.open(outFileName, ios::out);

	auto beginGame = high_resolution_clock::now();

	display_rules();
	system("pause");

	//Render the window
	sf::RenderWindow window(sf::VideoMode(920, 640), "Galaga!");
	window.setFramerateLimit(60);

	//Create player ship
	PlayerShip pShip(40.f, 3, sf::Vector2f(350, 500));

	//Create enemy ships
	EnemyShip eShip1(sf::Vector2f(20.f, 20.f), sf::Vector2f(100, 25), sf::Color::Blue);
	EnemyShip eShip2(sf::Vector2f(20.f, 20.f), sf::Vector2f(200, 25), sf::Color::Blue);
	EnemyShip eShip3(sf::Vector2f(20.f, 20.f), sf::Vector2f(300, 25), sf::Color::Blue);
	EnemyShip eShip4(sf::Vector2f(20.f, 20.f), sf::Vector2f(400, 25), sf::Color::Blue);
	EnemyShip eShip5(sf::Vector2f(20.f, 20.f), sf::Vector2f(500, 25), sf::Color::Blue);
	EnemyShip eShip6(sf::Vector2f(20.f, 20.f), sf::Vector2f(600, 25), sf::Color::Blue);
	EnemyShip eShip7(sf::Vector2f(20.f, 20.f), sf::Vector2f(700, 25), sf::Color::Blue);
	EnemyShip eShip8(sf::Vector2f(20.f, 20.f), sf::Vector2f(800, 25), sf::Color::Blue);
	EnemyShip eShip9(sf::Vector2f(20.f, 20.f), sf::Vector2f(150, 75), sf::Color::Yellow);
	EnemyShip eShip10(sf::Vector2f(20.f, 20.f), sf::Vector2f(250, 75), sf::Color::Yellow);
	EnemyShip eShip11(sf::Vector2f(20.f, 20.f), sf::Vector2f(350, 75), sf::Color::Yellow);
	EnemyShip eShip12(sf::Vector2f(20.f, 20.f), sf::Vector2f(450, 75), sf::Color::Yellow);
	EnemyShip eShip13(sf::Vector2f(20.f, 20.f), sf::Vector2f(550, 75), sf::Color::Yellow);
	EnemyShip eShip14(sf::Vector2f(20.f, 20.f), sf::Vector2f(650, 75), sf::Color::Yellow);
	EnemyShip eShip15(sf::Vector2f(20.f, 20.f), sf::Vector2f(750, 75), sf::Color::Yellow);
	EnemyShip eShip16(sf::Vector2f(20.f, 20.f), sf::Vector2f(850, 75), sf::Color::Yellow);
	EnemyShip eShip17(sf::Vector2f(20.f, 20.f), sf::Vector2f(50, 75), sf::Color::Yellow);
	EnemyShip eShip18(sf::Vector2f(20.f, 20.f), sf::Vector2f(100, 200), sf::Color::Green);
	EnemyShip eShip19(sf::Vector2f(20.f, 20.f), sf::Vector2f(200, 200), sf::Color::Green);
	EnemyShip eShip20(sf::Vector2f(20.f, 20.f), sf::Vector2f(300, 200), sf::Color::Green);
	EnemyShip eShip21(sf::Vector2f(20.f, 20.f), sf::Vector2f(400, 200), sf::Color::Green);
	EnemyShip eShip22(sf::Vector2f(20.f, 20.f), sf::Vector2f(500, 200), sf::Color::Green);
	EnemyShip eShip23(sf::Vector2f(20.f, 20.f), sf::Vector2f(600, 200), sf::Color::Green);
	EnemyShip eShip24(sf::Vector2f(20.f, 20.f), sf::Vector2f(700, 200), sf::Color::Green);
	EnemyShip eShip25(sf::Vector2f(20.f, 20.f), sf::Vector2f(800, 200), sf::Color::Green);

	BattleShip battleShip(sf::Vector2f(50.f, 20.f), sf::Vector2f(20, 130), sf::Color::Magenta);

	//Create player projectile
	Blast blast(sf::Vector2f(385, 475), sf::Color::Cyan, 5.f);
	//(need const in constructor for color)

	//Create enemy projectile
	Blast blast2(sf::Vector2f(200, 300), sf::Color::Red, 30.f);

	//Create screen boundary
	Frame lowerBoundary(sf::Vector2f(2000, 2), sf::Vector2f(-1000, 570));
	Frame upperBoundary(sf::Vector2f(2000, 2), sf::Vector2f(-1000, 1));

	cout << "TEST CASES: " << endl;
	if (pShip.getFillColor() == sf::Color::White)
	{
		cout << "pShip color assignment successful." << endl;
	}
	else {
		cout << "pShip color assignment unsuccessful." << endl;
	}
	if (eShip14.getFillColor() == sf::Color::Yellow)
	{
		cout << "eShip color assignment successful. " << endl;
	}
	else {
		cout << "eShip color assignment unsuccessful." << endl;
	}
	if (blast.getFillColor() == sf::Color::Cyan)
	{
		cout << "blast color assignment successful. " << endl;
	}
	else {
		cout << "blast color assignment unsuccessful." << endl;
	}
	if (lowerBoundary.getFillColor() == sf::Color::Black)
	{
		cout << "lower boundary color assignment successful. " << endl;
	}
	else {
		cout << "lower boundary color assignment unsuccessful." << endl;
	}
	if (blast2.getFillColor() == sf::Color::Red)
	{
		cout << "blast2 color assignment successful. " << endl;
	}
	else {
		cout << "blast2 color assignment unsuccessful." << endl;
	}

		

	//Variables
	int fire = 0, draw1 = 0, draw2 = 0, draw3 = 0, draw4 = 0,
		draw5 = 0, draw6 = 0, draw7 = 0, draw8 = 0, draw9 = 0,
		draw10 = 0, draw11 = 0, draw12 = 0, draw13 = 0, draw14 = 0,
		draw15 = 0, draw16 = 0, draw17 = 0, draw18 = 0, draw19 = 0,
		draw20 = 0, draw21 = 0, draw22 = 0, draw23 = 0,
		draw24 = 0, draw25 = 0, i = 0, direction = 0,
		move = 0, randValue = 0, x = 0, y = 0, j = 0, lives = 3, leftOrRight = 0,
		timesUsedJump = 0, timesUsedQuickBlast = 0, hits = 0, k = 1;
	bool drawPlayerShip = true;
	string title = "Galaga";

	//Random number generator
	srand(time(0));

	//Game loop
	while (window.isOpen())
	{
		//////////////////////INPUT HANDLING//////////////////////////
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;
			case sf::Event::EventType::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Right)
				{
					pShip.move(10, 0);
					blast.move(10, 0);
				}
				else if (event.key.code == sf::Keyboard::Key::Left)
				{
					pShip.move(-10, 0);
					blast.move(-10, 0);
				}
				else if (event.key.code == sf::Keyboard::Key::Space)
				{
					fire = 1;
				}
				else if (event.key.code == sf::Keyboard::Key::D && timesUsedJump <= 10)
				{
					timesUsedJump++;
					leftOrRight = 1; //right
					pShip.teleport(leftOrRight);
					blast.move(100, 0);
				}
				else if (event.key.code == sf::Keyboard::Key::S && timesUsedJump <= 10)
				{
					timesUsedJump++;
					leftOrRight = 2; //left
					pShip.teleport(leftOrRight);
					blast.move(-100, 0);
				}
				else if (event.key.code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
				break;
			default:
				break;
			}
		}

		///////////////////UPDATE FRAME/////////////////////
		if (draw1 == 1 && draw2 == 1 && draw3 == 1 && draw4 == 1 && draw5 == 1 && draw6 == 1
			&& draw7 == 1 && draw8 == 1 && draw9 == 1 && draw10 == 1 && draw11 == 1 && draw12 == 1
			&& draw13 == 1 && draw14 == 1 && draw15 == 1 && draw16 == 1 && draw17 == 1 && draw18 == 1
			&& draw19 == 1 && draw20 == 1 && draw21 == 1 && draw22 == 1 && draw23 == 1 && draw24 == 1
			&& draw25 == 1)
		{
			auto endGame = high_resolution_clock::now();;
			cout << "Game Time: " << duration_cast<seconds>(endGame - beginGame).count() << '\n';
			window.close();
			int time = duration_cast<seconds>(endGame - beginGame).count();
			outFile << time << " seconds" << endl;
		}
		//move enemy ships
		if (direction == 60)
		{
			eShip1.moveShip(5);
			eShip3.moveShip(5);
			eShip5.moveShip(5);
			eShip7.moveShip(5);
			eShip2.moveShip(-5);
			eShip4.moveShip(-5);
			eShip6.moveShip(-5);
			eShip8.moveShip(-5);
			eShip9.moveShip(20);
			eShip10.moveShip(20);
			eShip11.moveShip(20);
			eShip12.moveShip(20);
			eShip13.moveShip(20);
			eShip14.moveShip(20);
			eShip15.moveShip(20);
			eShip16.moveShip(20);
			eShip17.moveShip(20);
			eShip18.move(0, 50);
			eShip19.move(0, 50);
			eShip20.move(0, 50);
			eShip21.move(0, 50);
			eShip22.move(0, 50);
			eShip23.move(0, 50);
			eShip24.move(0, 50);
			eShip25.move(0, 50);
			direction = 61;
		}
		else if (direction == 120) {
			eShip2.moveShip(5);
			eShip4.moveShip(5);
			eShip6.moveShip(5);
			eShip8.moveShip(5);
			eShip1.moveShip(-5);
			eShip3.moveShip(-5);
			eShip5.moveShip(-5);
			eShip7.moveShip(-5);
			eShip9.moveShip(-20);
			eShip10.moveShip(-20);
			eShip11.moveShip(-20);
			eShip12.moveShip(-20);
			eShip13.moveShip(-20);
			eShip14.moveShip(-20);
			eShip15.moveShip(-20);
			eShip16.moveShip(-20);
			eShip17.moveShip(-20);
			eShip18.move(0, 50);
			eShip19.move(0, 50);
			eShip20.move(0, 50);
			eShip21.move(0, 50);
			eShip22.move(0, 50);
			eShip23.move(0, 50);
			eShip24.move(0, 50);
			eShip25.move(0, 50);

			direction = 0;
		}
		else {
			direction++;
		}


		//manage player projectile
		if (fire == 1)
		{
			//if (i > 20)
			//{
			//	blast.setPosition(sf::Vector2f(pShip.getPosition()));
			//	blast.move(35, 25);
			//	i = 0;
			//}
			if (blast.getGlobalBounds().intersects(upperBoundary.getGlobalBounds()))
			{
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			if (blast.getGlobalBounds().intersects(eShip1.getGlobalBounds()))
			{
				draw1 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip2.getGlobalBounds()))
			{
				draw2 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip3.getGlobalBounds()))
			{
				draw3 = 1;
				
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip4.getGlobalBounds()))
			{
				draw4 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip5.getGlobalBounds()))
			{
				draw5 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip6.getGlobalBounds()))
			{
				draw6 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip7.getGlobalBounds()))
			{
				draw7 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip8.getGlobalBounds()))
			{
				draw8 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip9.getGlobalBounds()))
			{
				draw9 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip10.getGlobalBounds()))
			{
				draw10 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip11.getGlobalBounds()))
			{
				draw11 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip12.getGlobalBounds()))
			{
				draw12 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip13.getGlobalBounds()))
			{
				draw13 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip14.getGlobalBounds()))
			{
				draw14 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip15.getGlobalBounds()))
			{
				draw15 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip16.getGlobalBounds()))
			{
				draw16 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip17.getGlobalBounds()))
			{
				draw17 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip18.getGlobalBounds()))
			{
				draw18 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip18.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip19.getGlobalBounds()))
			{
				draw19 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip19.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip20.getGlobalBounds()))
			{
				draw20 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip20.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip21.getGlobalBounds()))
			{
				draw21 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip21.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip22.getGlobalBounds()))
			{
				draw22 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip22.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip23.getGlobalBounds()))
			{
				draw23 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip23.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip24.getGlobalBounds()))
			{
				draw24 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip24.setPosition(sf::Vector2f(0, -156000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(eShip25.getGlobalBounds()))
			{
				draw25 = 1;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				eShip25.setPosition(sf::Vector2f(0, -1000));
				fire = 0;
			}
			else if (blast.getGlobalBounds().intersects(battleShip.getGlobalBounds()))
			{
				hits++;
				blast.setPosition(sf::Vector2f(pShip.getPosition()));
				blast.move(35, 25);
				fire = 0;
			}
			else {
				blast.move(0, -25);
				i++;
			}
		}

		//manage enemy projectile
		//create a random number generator for the movement of the enemy projectile, have it reset in different
		//positions while still moving downward at a steady pace, (920, 640)

		if (blast2.getGlobalBounds().intersects(lowerBoundary.getGlobalBounds()))
		{
			x = rand() % 800 + 20;
			blast2.setPosition(x, 150);
		}
		else {
			blast2.move(0, 6);
		}

		//Manage player ship
		if (eShip18.getGlobalBounds().intersects(lowerBoundary.getGlobalBounds()))
		{
			eShip18.setPosition(sf::Vector2f(100, 200));
			eShip19.setPosition(sf::Vector2f(200, 200));
			eShip20.setPosition(sf::Vector2f(300, 200));
			eShip21.setPosition(sf::Vector2f(400, 200));
			eShip22.setPosition(sf::Vector2f(500, 200));
			eShip23.setPosition(sf::Vector2f(600, 200));
			eShip24.setPosition(sf::Vector2f(700, 200));
			eShip25.setPosition(sf::Vector2f(800, 200));
		}
		else if(blast2.getGlobalBounds().intersects(pShip.getGlobalBounds()))
		{
			drawPlayerShip = false;
		}
		else if (eShip18.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw18 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip19.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw19 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip20.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw20 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip21.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw21 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip22.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw22 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip23.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw23 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip24.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw24 == 0)
		{
			drawPlayerShip = false;
		}
		else if (eShip25.getGlobalBounds().intersects(pShip.getGlobalBounds()) && draw25 == 0)
		{
			drawPlayerShip = false;
		}

		//Manage battleship
		if (k < 120)
		{
			battleShip.moveShip(5, battleShip);
			k++;
		}
		if (k >= 120 && k <= 240)
		{
			battleShip.moveShip(-5, battleShip);
			k++;
		}
		if (k == 240)
		{
			k = 0;
		}

		/////////////////////////RENDER FRAME////////////////////////////
		window.clear();
		if (draw1 == 0)
			window.draw(eShip1);
		if (draw2 == 0)
			window.draw(eShip2);
		if (draw3 == 0)
			window.draw(eShip3);
		if (draw4 == 0)
			window.draw(eShip4);
		if (draw5 == 0)
			window.draw(eShip5);
		if (draw6 == 0)
			window.draw(eShip6);
		if (draw7 == 0)
			window.draw(eShip7);
		if (draw8 == 0)
			window.draw(eShip8);
		if (draw9 == 0)
			window.draw(eShip9);
		if (draw10 == 0)
			window.draw(eShip10);
		if (draw11 == 0)
			window.draw(eShip11);
		if (draw12 == 0)
			window.draw(eShip12);
		if (draw13 == 0)
			window.draw(eShip13);
		if (draw14 == 0)
			window.draw(eShip14);
		if (draw15 == 0)
			window.draw(eShip15);
		if (draw16 == 0)
			window.draw(eShip16);
		if (draw17 == 0)
			window.draw(eShip17);
		if (draw18 == 0)
			window.draw(eShip18);
		if (draw19 == 0)
			window.draw(eShip19);
		if (draw20 == 0)
			window.draw(eShip20);
		if (draw21 == 0)
			window.draw(eShip21);
		if (draw22 == 0)
			window.draw(eShip22);
		if (draw23 == 0)
			window.draw(eShip23);
		if (draw24 == 0)
			window.draw(eShip24);
		if (draw25 == 0)
			window.draw(eShip25);

		if (hits <= 10)
		{
			window.draw(battleShip);
		}
		else {
			battleShip.move(0, -1000);
		}

		window.draw(blast2);
		if (drawPlayerShip)
		{
			window.draw(pShip);
			window.draw(blast);
		}
		else if (!drawPlayerShip && j < 120) //have to not draw blast2
		{
			j++;
		}
		else if (!drawPlayerShip && j >= 120)
		{
			j = 0;
			drawPlayerShip = true;
		}
			window.draw(lowerBoundary);
			window.draw(upperBoundary);

			window.display();
		}
	return 0;
}

