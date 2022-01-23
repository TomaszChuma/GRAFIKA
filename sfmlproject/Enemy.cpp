#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Texture* texture, float speed, sf::Vector2f size, sf::Vector2f position, int type)
{
	this->speed = speed;
	this->type = type;

	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

Enemy::~Enemy()
{
}



void Enemy::Update(float deltaTime, Player* player)
{
	if (type == 1) {
		if (body.getPosition().y > player->GetPosition().y)
		{
			velocity.y = -speed;
		}

		if (body.getPosition().y < player->GetPosition().y)
		{
			velocity.y = speed;
		}

		if (body.getPosition().x < player->GetPosition().x)
		{
			velocity.x = speed;
		}

		if (body.getPosition().x > player->GetPosition().x)
		{
			velocity.x = -speed;
		}
	}

	if (type == 2) {
		if (body.getPosition().x < player->GetPosition().x)
		{
			velocity.x += speed;
		}

		if (body.getPosition().x > player->GetPosition().x)
		{
			velocity.x -= speed;
		}
	}





	//velocity.y += 981.0f * deltaTime;

	body.move(velocity * deltaTime);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemy::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}
