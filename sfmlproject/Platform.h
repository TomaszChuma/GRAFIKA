#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	/**Rysowanie platformy**/
	void Draw(sf::RenderWindow& window);

	/**Kolizja platformy z innymi obiektami**/
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;//Cia³o platformy
};

