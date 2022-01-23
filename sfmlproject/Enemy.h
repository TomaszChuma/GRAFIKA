#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Player.h"
#include "Bullet.h"

class Enemy
{
public:
	Enemy(sf::Texture* texture, float speed, sf::Vector2f size, sf::Vector2f position, int type);
	~Enemy();

	/**Aktualizacja pozycji rywala
	*
	*@param deltaTime
	* 
	* @param player
	* obiekt gracza
	*/
	void Update(float deltaTime, Player* player);
	/**Rysowanie rywala
	*
	*@param window
	*okno gry
	*
	*/
	void Draw(sf::RenderWindow& window);
	/**Funkcja odpowiadaj¹ca za zachowanie obiektu w przypadku wyst¹pienia kolizji
	*@param direction
	*kierunek w którym dziala kolizja
	*
	*/
	void OnCollision(sf::Vector2f direction);

	/**Ustawienie pozycji**/
	void SetPosition() { body.setPosition(50021.0f, 50001.0f); }

	/**Pobranie aktualnych wspó³rzêdnych**/
	sf::Vector2f GetPosition() { return body.getPosition(); }

	/**Kolizja z innymi obiektami**/
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;//cia³o
	float speed;//prêdkoœæ
	int type;//typ przeciwnika
	sf::Vector2f size;//rozmiar
	sf::Vector2f position;//pozycja

	sf::Vector2f velocity;//prêdkoœæ wektorowo
};

