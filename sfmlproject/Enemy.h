#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Player.h"
#include "Bullet.h"

class Enemy
{
public:
	Enemy(sf::Texture* texture, float speed);
	~Enemy();

	void Update(float deltaTime, Player* player);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	void SetPosition() { body.setPosition(4321.0f, 4321.0f); }

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	float speed;

	sf::Vector2f velocity;
};

