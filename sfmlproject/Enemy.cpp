#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, float speed)
{
	this->speed = speed;

	body.setSize(sf::Vector2f(120.0f, 120.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(1000.0f, 1000.0f);
	body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, Player* player)
{

	if (body.getPosition().x < player->GetPosition().x)
	{
		//velocity.x += speed;
	}

	else if (body.getPosition().x > player->GetPosition().x)
	{
		//velocity.x -= speed;
	}


	velocity.y += 981.0f * deltaTime;

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
