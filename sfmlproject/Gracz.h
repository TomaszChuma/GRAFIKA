#pragma once
#include <SFML\Graphics.hpp>

class Gracz
{
public:
	Gracz(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Gracz();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() {
		return body.getPosition();
	}

private:
	sf::RectangleShape body;
	unsigned int row;
	float speed;
	bool faceRight;

}

};
