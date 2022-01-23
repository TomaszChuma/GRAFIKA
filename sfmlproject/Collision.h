#pragma once
#include <SFML/Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	/**Przesuwanie obiektu z którym zachodzi kolizja**/
	void Move(float dx, float dy) { body.move(dx, dy); }

	/**Sprawdzanie czy zachodzi kolizja miêdzy obiektami
	*
	*@param other
	*obiekt z którym zachodzi kolizja
	*
	* @param direction
	* kierunek w którym zachodzi kolizja
	* 
	* @param push
	* wartoœæ przesuniêcia obiektu
	*/
	bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
	/**Pobranie aktualnych wspó³rzêdnych obiektu**/
	sf::Vector2f GetPosition() { return body.getPosition(); }
	/**Pobranie wielkoœci obiektu**/
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;//cia³o obiektu
};

