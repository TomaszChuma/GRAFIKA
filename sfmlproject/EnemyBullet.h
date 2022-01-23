#pragma once
#include "Enemy.h"

#include <SFML/Graphics.hpp>

class EnemyBullet {
public:
	EnemyBullet(sf::Texture* texture, Enemy* enemy, float speed);
	~EnemyBullet();

	/**Aktualizacja pozycji pocisku w zale�no�ci od deltaTime
	*
	* @param deltaTime
	* deltaTime
	* **/
	void Update(float deltaTime);
	/**Rysowanie pocisku
	*
	* @param window
	* okno gry
	* **/
	void Draw(sf::RenderWindow& window);

	/**Aktualizacja pozycji pocisku w niekt�rych przypadkach**/
	void SetPosition() { body.setPosition(-1234.0f, -1234.0f); }

	/**Zwracanie wsp�rz�dnej x pocisku**/
	int getBulletX() { body.getPosition().x; }
	/**Kolizja pocisku z innymi obiektami**/
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;//cia�o pocisku
	sf::Vector2f velocity;//pr�dko�� pocisku wektorowo

	float speed;//pr�dko�� pocisku
};