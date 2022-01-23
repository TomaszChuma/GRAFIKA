#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(sf::Texture* texture, Enemy* enemy, float speed)
{
	this->speed = speed;

	body.setSize(sf::Vector2f(20.0f, 20.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(enemy->GetPosition());
	body.setTexture(texture);
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::Update(float deltaTime)
{
	
	
	velocity.x = -speed;
	

	body.move(velocity * deltaTime);

}

void EnemyBullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
