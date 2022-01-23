#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBullet.h"
//#include "Textures.h"

class Engine
{
public:
	Engine(int screenWidth, int screenHeight, std::string windowTitle);
	~Engine();

	/**Inicjalizacja silnika gry**/
	int init();

	/**�adowanie tekstur**/
	void LoadTextures();//
	/**Rysowanie mapy**/
	void DrawMap();
	/*Zapobieganie rozci�ganiu tekstur
	*@param window
	*  okno gry
	*@param view
	*  widok
	*
	*/
	void ResizeView(const sf::RenderWindow& window, sf::View& view);
	/**Strza� gracza
	*@param player
	*  obiekt gracza
	**/
	void PlayerShot(Player& player);
	/**Strza� przeciwnika
	*@param enemy
	*  obiekt przeciwnika**/
	void EnemyShot(Enemy& enemy);
	/**W tej funkcji ustalane s� regu�y kolizji mi�dzy obiektami(czyli to co si� dzieje w przypadku ich wyst�pienia)**/
	void Collisions(Player& player, Enemy& enemy);

	/**Zawiera warunki dotycz�ce regu� gry**/
	void Interactions(Player& player);


private:
	sf::RenderWindow window;//okno gry
	sf::View view;//widok gry

	float dt = 0.0f;//deltaTime
	sf::Clock clock;
	sf::Time time;

	bool isFiring = false;//ustawienie warto�ci kt�ra decyduje o tym czy w danym momencie gracz strzela
	bool enemyisFiring = false;//ustawienie warto�ci kt�ra decyduje o tym czy w danym momencie przeciwnik strzela
	int hit = 0;//uderzenia przyj�te przez gracza
	int shootTimer = 0;//odpowiada za odst�p czasu mi�dzy wykonaniem strza�u gracza
	int enemyshootTimer = 0;//odpowiada za odst�p czasu mi�dzy wykonaniem strza�u rywala

	sf::Vector2f direction;//kierunek w kt�rym odzia�owywuje kolizja
	int coinCollected = 0;//zebrane monety

	/*Tekstury wykorzystane w grze*/
	sf::Texture background;
	sf::Texture background2;
	sf::Texture playerTexture;
	sf::Texture mapTexture;
	sf::Texture bounds;
	sf::Texture bulletTexture;
	sf::Texture enemyTexture;
	sf::Texture enemy1Texture;
	sf::Texture pokeballTexture;
	sf::Texture dzialkoTexture;
	sf::Texture winTexture;
	sf::Texture winScreenTexture;
	sf::Texture loseScreenTexture;

	/*banery w momencie wygranej i przegranej*/
	sf::Sprite spriteWin;
	sf::Sprite spriteLose;

	/*wektory przechowywuj�ce poszczeg�lne elementy planszy*/
	std::vector<Platform> platforms;
	std::vector<Enemy> coins;
	std::vector<Enemy> doors;
	std::vector<Enemy> nextLevel;
	std::vector<Enemy> melees;
	std::vector<Enemy> shooters;
	std::vector<Map> maps;
	std::vector<Bullet> bullets;
	std::vector<EnemyBullet> enemyBullets;
	std::vector<Enemy> enemies;

	/*tablice kt�re odpowiadaj� za rysowanie naszej mapy*/
	int scene[16][38];
	int scene2[16][11];

	int screenWidth = 0;//szeroko�� okna
	int screenHeight = 0;//wysoko�c okna
	std::string windowTitle;//nazwa okna

};


