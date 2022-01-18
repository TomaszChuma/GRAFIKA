#include "Bullet.h"



Bullet::Bullet(sf::Texture* texture, Player* player, float speed)
{
	this->speed = speed;

	body.setSize(sf::Vector2f(20.0f, 20.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(player->GetPosition());
	body.setTexture(texture);
}

Bullet::~Bullet()
{
	
}

void Bullet::Update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		velocity.x = speed;
	}

	body.move(velocity * deltaTime);

}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
