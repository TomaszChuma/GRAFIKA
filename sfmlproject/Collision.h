#pragma once
#include <SFML/Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	/**Przesuwanie obiektu z kt�rym zachodzi kolizja**/
	void Move(float dx, float dy) { body.move(dx, dy); }

	/**Sprawdzanie czy zachodzi kolizja mi�dzy obiektami
	*
	*@param other
	*obiekt z kt�rym zachodzi kolizja
	*
	* @param direction
	* kierunek w kt�rym zachodzi kolizja
	* 
	* @param push
	* warto�� przesuni�cia obiektu
	*/
	bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
	/**Pobranie aktualnych wsp�rz�dnych obiektu**/
	sf::Vector2f GetPosition() { return body.getPosition(); }
	/**Pobranie wielko�ci obiektu**/
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;//cia�o obiektu
};

