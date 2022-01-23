#include "Map.h"

Map::Map(sf::Texture* texture, sf::Vector2f position)
{
	body.setSize(sf::Vector2f(2100.0f, 1200.0f));
	body.setPosition(position);
	body.setTexture(texture);


}

Map::~Map()
{

}

void Map::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
