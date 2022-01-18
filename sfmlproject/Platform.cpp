#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(sf::Vector2f(80.0f, 80.0f));
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
