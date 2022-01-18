#pragma once
#include <SFML/Graphics.hpp>
class Map
{
public:
	Map(sf::Texture* texture, sf::Vector2f position);
	~Map();

	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
};

