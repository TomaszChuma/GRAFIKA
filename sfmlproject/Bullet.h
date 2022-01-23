#pragma once
#include "Player.h"

#include <SFML/Graphics.hpp>

class Bullet {
public:
	Bullet(sf::Texture* texture, Player* player, float speed);
	~Bullet();

	/**Aktualizacja pozycji pocisku w zale¿noœci od deltaTime
	*
	* @param direction
	* kierunek w którym zachodzi kolizja
	* **/
	void Update(float deltaTime);

	/**Rysowanie pocisku
	*
	* @param window
	* okno gry
	* **/
	void Draw(sf::RenderWindow& window);

	/**Aktualizacja pozycji pocisku w niektórych przypadkach**/
	void SetPosition() { body.setPosition(1234.0f, 1234.0f); }

	/**Zwracanie wspó³rzêdnej x pocisku**/
	int getBulletX() { body.getPosition().x; }

	/**Kolizja pocisku z innymi obiektami**/
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body; //cia³o pocisku
	sf::Vector2f velocity; //prêdkoœæ pocisku wektorowo

	float speed;//prêdkoœæ pocisku
};