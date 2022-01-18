#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Walls {
public:
	Walls(sf::Vector2f size) {
		wall.setSize(size);
		wall.setFillColor(sf::Color::Red);
	}

	std::vector<sf::RectangleShape> walls;

	void draw() {
		int scene[10][10] = { {0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,0,0,0,0,0,0},
{0,1,0,1,0,0,0,0,0,0},
{0,1,1,1,0,0,1,1,0,0},
{0,1,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,1,1,1,1,0,0,0},
{1,1,1,1,1,1,1,1,1,1} };

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
			{
				if (scene[j][i] == 1) {
					wall.setFillColor(sf::Color::Red);
					wall.setSize(sf::Vector2f(80.f, 80.f));
					wall.setPosition(i * 80.0f, j * 80.0f);
					walls.push_back(wall);
				}
			}
		}
	}

	void draw(sf::RenderWindow& window) {
		for (auto& i : walls)
		{
			window.draw(i);
		}
	}

	void checkColl(Player player) {
		FloatRect nextPos;
		for (auto& wall : walls)\
		{
			FloatRect playerBounds = player.getGlobalBounds();
			FloatRect wallBounds = wall.getGlobalBounds();

			nextPos = playerBounds;
			nextPos.left += velocity.x;
			nextPos.top += velocity.y;


			if (wallBounds.intersects(nextPos))
			{
				//Right collision
				if (playerBounds.left < wallBounds.left
					&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top)

				{
					velocity.x = 0.f;
					player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
				}

				//Left collision
				if (playerBounds.left > wallBounds.left
					&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top)

				{
					velocity.x = 0.f;
					player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
				}

				//bot
				if (playerBounds.top < wallBounds.top
					&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left)

				{
					velocity.y = 0.f;
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						velocity.y = -90.f;
					}
					player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);

				}


				//top
				if (playerBounds.top > wallBounds.top
					&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left)

				{
					velocity.y = 0.f;
					player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);


				}
			}
		}
	}



private:
	sf::RectangleShape wall;
};
