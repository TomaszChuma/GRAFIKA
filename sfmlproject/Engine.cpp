#include "Engine.h"
#include <iostream>

const float MAP_WIDTH = 1920.0f;
const float MAP_HEIGHT = 1080.0f;

using namespace sf;

Vector2f velocity;

static const float VIEW_HEIGHT = 700.0f;

Engine::Engine(int screenWidth, int screenHeight, std::string windowTitle) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->windowTitle = windowTitle;
}


Engine::~Engine()
{

}

int Engine::init() {
	sf::RenderWindow window(sf::VideoMode(800.0f, VIEW_HEIGHT), "XD");
	View view(sf::Vector2f(0.0f, 0.0f), Vector2f(800.0f, VIEW_HEIGHT));

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("POKEMON.wav"))
		return -1;

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	LoadTextures();
	DrawMap();

	Player player(&playerTexture, sf::Vector2u(0, 0), 0.5f, 300.0f, 800.0f);
	Enemy enemy(&enemy1Texture, 35.0f, sf::Vector2f(160.0f, 160.0f), sf::Vector2f(900.0f, 300.0f), 1);

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

		PlayerShot(player);
		EnemyShot(enemy);


		player.Update(dt);
		enemy.Update(dt, &player);

		Collisions(player, enemy);
		Interactions(player);

		for (int i = 0; i < enemies.size(); i++) {
			enemies[i].Update(dt, &player);
		}




		if (player.GetPosition().y > 860.0f)
		{
			view.setCenter(player.GetPosition().x, 860.0f);
		}

		else
			view.setCenter(player.GetPosition());

		window.clear(sf::Color(53, 122, 171));


		window.setView(view);
		player.Draw(window);
		enemy.Draw(window);


		for (Enemy enemy : enemies)
		{
			enemy.Draw(window);
		}

		for (Enemy coin : coins)
		{
			coin.Draw(window);
		}

		for (Enemy door : doors)
		{
			door.Draw(window);
		}

		for (Enemy shooter : shooters)
		{
			shooter.Draw(window);
		}


		for (Platform& platform : platforms)
		{
			platform.Draw(window);
		}

		for (Bullet& bullet : bullets)
		{
			bullet.Draw(window);
		}

		for (EnemyBullet& bullet : enemyBullets)
		{
			bullet.Draw(window);
		}

		if (coinCollected == 6)
		{
			spriteWin.setPosition(player.GetPositionX() - 760.0f, player.GetPositionY() - 450.0f);
			window.draw(spriteWin);
		}

		

		if (hit > 0)
		{
			player.SetPosition(7120.0f, 1020.0f);
			spriteLose.setPosition(6850.0f, 800.0f);

			window.draw(spriteLose);
			Engine engine(1024, 768, "GAME");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				window.close();
				engine.init();
			}
		}

		window.display();
	}

	return 0;
}




void Engine::LoadTextures() {
	background.loadFromFile("tlo.png");
	background2.loadFromFile("XD.jpg");
	playerTexture.loadFromFile("bulb.png");
	mapTexture.loadFromFile("grass.png");
	bounds.loadFromFile("square.png");
	bulletTexture.loadFromFile("square.png");
	enemyTexture.loadFromFile("enemy.png");
	enemy1Texture.loadFromFile("char.png");
	pokeballTexture.loadFromFile("coin.png");
	dzialkoTexture.loadFromFile("dzialko.png");
	winTexture.loadFromFile("5.png");
	winScreenTexture.loadFromFile("win2.png");
	loseScreenTexture.loadFromFile("lose.png");
	spriteWin.setTexture(winScreenTexture);
	spriteLose.setTexture(loseScreenTexture);
	spriteWin.setScale(1.5, 1);

}

void Engine::DrawMap() {

	for (int i = -1; i < 3; i++)
	{
		maps.push_back(Map(&background, sf::Vector2f(i * 1920.0f, 100.0f)));
	}

	maps.push_back(Map(&background2, sf::Vector2f(3 * 1920.0f + 200.0f, 100.0f)));


	int columns = 48;
	int rows = 16;
	int scene[16][60] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	 {0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,7,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
	 {0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
	 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,1},
	 {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,7,1,0,0,0,0,0,1,1,0,0,1},
	 {0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,0,0,1},
	 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1},
	 {0,0,0,0,0,0,1,1,0,0,0,0,0,0,3,0,0,0,5,0,0,0,0,0,0,0,0,0,7,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1},
	 {0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1},
	 {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,0,0,1},
	 {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1},
	 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,7,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, };


	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++)
		{
			if (scene[j][i] == 1) {
				platforms.push_back(Platform(&mapTexture, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f)));

			}
			if (scene[j][i] == 2) {
				platforms.push_back(Platform(&bounds, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f)));

			}

			if (scene[j][i] == 3) {
				enemies.push_back(Enemy(&enemyTexture, 2.0f, sf::Vector2f(120.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f), 2));

			}

			if (scene[j][i] == 4) {
				coins.push_back(Enemy(&pokeballTexture, 2.0f, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f), 3));

			}

			if (scene[j][i] == 5) {
				doors.push_back(Enemy(&mapTexture, 2.0f, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f), 3));

			}

			if (scene[j][i] == 6) {
				nextLevel.push_back(Enemy(&bounds, 2.0f, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f), 3));

			}

			if (scene[j][i] == 7) {
				shooters.push_back(Enemy(&dzialkoTexture, 2.0f, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f, j * 80.0f), 3));

			}

		}
	}

	int scene2[16][11] = { {1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,3,0,1},
		{1,0,0,0,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,1,1,1},
		{1,0,0,0,0,0,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1}, };


	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 16; j++)
		{
			if (scene2[j][i] == 1) {
				platforms.push_back(Platform(&mapTexture, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f + 84 * 80.0f, j * 80.0f)));

			}
			if (scene2[j][i] == 2) {
				platforms.push_back(Platform(&bounds, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(i * 80.0f + 84 * 80.0f, j * 80.0f)));

			}

			if (scene2[j][i] == 3) {
				coins.push_back(Enemy(&winTexture, 2.0f, sf::Vector2f(120.0f, 80.0f), sf::Vector2f(i * 80.0f + 84 * 80.0f, j * 80.0f), 2));

			}

		}
	}
}

void Engine::ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


void Engine::PlayerShot(Player &player) {
	if (shootTimer < 500)
		shootTimer++;


	if (sf::Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >= 500)
	{
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
}

void Engine::EnemyShot(Enemy &enemy)
{
	if (enemyshootTimer < 2300)
		enemyshootTimer++;


	if (enemyshootTimer == 2300)
	{
		enemyisFiring = true;
		enemyshootTimer = 0;
	}

	for (int i = 0; i < shooters.size(); i++) {
		if (enemyisFiring == true)
		{
			EnemyBullet newBullet2(&bulletTexture, &shooters[i], 450.0f);
			enemyBullets.push_back(newBullet2);
		}
	}



	for (int i = 0; i < enemyBullets.size(); i++) {
		enemyBullets[i].Update(dt);
		enemyisFiring = false;
	}
}

void Engine::Collisions(Player &player, Enemy &enemy){
	for (Bullet& bullet : bullets)
		for (int i = 0; i < enemies.size(); i++) {
			if (bullet.GetCollider().CheckCollision(enemies[i].GetCollider(), direction, 1.0f))
				enemies[i].SetPosition();

		}

	for (Platform& platform : platforms)
		if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			player.OnCollision(direction);


	for (Platform& platform : platforms)
		for (int i = 0; i < enemies.size(); i++) {
			if (platform.GetCollider().CheckCollision(enemies[i].GetCollider(), direction, 1.0f))
				enemies[i].OnCollision(direction);
		}


	for (Enemy& shooter : shooters)
		if (shooter.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			player.OnCollision(direction);



	for (Enemy& door : doors)
		if (door.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			player.OnCollision(direction);

	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
		{
			coins[i].SetPosition();
			coinCollected++;
		}
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
		{
			hit++;
		}
	}//kolizja z przeciwnikiem

	if (enemy.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
	{
		hit++;
	}//kolizja z bosem


	for (int i = 0; i < enemyBullets.size(); i++)
	{
		if (enemyBullets[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
		{
			hit++;
		}
	}//kolizja z pociskiem

}

void Engine::Interactions(Player& player) {

	if (coinCollected == 2) {
		for (int i = 0; i < doors.size(); i++)
		{
			doors[i].SetPosition();
		}
	}

	if (coinCollected == 4) {
		player.SetPosition(7080.0f, player.GetPositionY());
		coinCollected++;
	}

}

