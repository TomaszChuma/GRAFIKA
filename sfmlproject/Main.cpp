#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h"

const float MAP_WIDTH = 1920.0f;
const float MAP_HEIGHT = 1080.0f;



using namespace sf;

Vector2f velocity;

static const float VIEW_HEIGHT = 500.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(800.0f, VIEW_HEIGHT), "XD");
	View view(sf::Vector2f(0.0f, 0.0f), Vector2f(800.0f, VIEW_HEIGHT));

	float dt = 0.0f;
	sf::Clock clock;

	int i, j;
	bool isFiring = false;

	int shootTimer = 0;

	sf::Vector2f direction;


	sf::Texture background;
	background.loadFromFile("tlo.png");



	sf::Texture playerTexture;
	playerTexture.loadFromFile("bulb.png");

	sf::Texture mapTexture;
	mapTexture.loadFromFile("grass.png");

	sf::Texture bounds;
	bounds.loadFromFile("square.png"); 

	sf::Texture bulletTexture;
	bulletTexture.loadFromFile("square.png");

	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("ninja.png");

	sf::Texture nextLevel;


	Player player(&playerTexture, sf::Vector2u(0, 0), 0.5f, 300.0f, 800.0f);

	Enemy enemy(&enemyTexture, 2.0f);


	std::vector<Platform> platforms;
	std::vector<Map> maps;
	std::vector<Bullet> bullets;

	for (i = -1; i < 3; i++)
	{
		maps.push_back(Map(&background, sf::Vector2f(i * 1920.0f, 0.0f)));
	}
	

	int columns = 48;
	int rows = 14;
	int scene[14][48] = { {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, };

	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++)
		{
			if (scene[j][i] == 1) {
				platforms.push_back(Platform(&mapTexture, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f)));

			}
			if (scene[j][i] == 2) {
				platforms.push_back(Platform(&bounds, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f)));

			}

		}
	}



	while (window.isOpen())
	{
		dt = clock.restart().asSeconds();
		if (dt > 1.0f / 20.0f)
			dt = 1.0f / 20.0f;

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}



		}

		if (shootTimer < 500)
			shootTimer++;

	
		if (sf::Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >=500)
		{
			//bullets.push_back(Bullet(&bulletTexture, &player, 2.0f));
			isFiring = true;
			shootTimer = 0;
		}

		if (isFiring == true)
		{
			Bullet newBullet(&bulletTexture, &player, 800.0f);
			bullets.push_back(newBullet);
		}

		for (int i = 0; i < bullets.size(); i++) {
			bullets[i].Update(dt);
			isFiring = false;
		}

		player.Update(dt);
		enemy.Update(dt, &player);

		for (int i = 0; i < bullets.size(); i++) {
			if (enemy.GetCollider().CheckCollision(bullets[i].GetCollider(), direction, 1.0f))
			{
				enemy.SetPosition();
				bullets[i].SetPosition();
			}
		}



		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(enemy.GetCollider(), direction, 1.0f))
				enemy.OnCollision(direction);

		if (enemy.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			break;



		if(player.GetPosition().y > 820.0f)
		{
			view.setCenter(player.GetPosition().x,820.0f);
		}

		

		else 
		view.setCenter(player.GetPosition());

		window.clear();

		for (Map& map : maps)
		{
			map.Draw(window);
		}

		window.setView(view);
		player.Draw(window);
		enemy.Draw(window);
		

		for (Platform& platform : platforms)
		{
			platform.Draw(window);
		}

		for (Bullet& bullet : bullets)
		{
			bullet.Draw(window);
		}

		


		window.display();
	}
	return 0;
}