#pragma once
#include "Player.h"

#include <SFML/Graphics.hpp>

class Bullet {
public:
	Bullet(sf::Texture* texture, Player* player, float speed);
	~Bullet();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	void SetPosition() { body.setPosition(1234.0f, 1234.0f); }

	int getBulletX() { body.getPosition().x; }
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	sf::Vector2f velocity;

	float speed;
};