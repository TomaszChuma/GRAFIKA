#pragma once

#include <SFML/Graphics.hpp>
#include "Collision.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	/**Aktualizacja pozycji gracza
	*
	*@param deltaTime
	* deltaTime
	**/
	void Update(float deltaTime);

	/**Zapobieganie rozci�ganiu tekstur
	*
	* 
	*@param x
	*  wspolrzedna x
	*@param y
	*  wspolrzedna y
	* 
	*/
	void SetPosition(float x, float y);
	/**Rysowanie gracza
	*
	* @param window
	* okno gry
	* 
	*/
	void Draw(sf::RenderWindow& window);
	/**Funkcja odpowiadaj�ca za zachowanie obiektu w przypadku wyst�pienia kolizji
	*
	*@param direction
	* kierunek w kt�rym dzia�a kolizja
	* 
	*/
	void OnCollision(sf::Vector2f direction);
	
	/*Zwracanie aktualnych wsp�rz�dnych gracza*/
	sf::Vector2f GetPosition() { return body.getPosition(); }
	/*Zwracanie wsp�rz�dnej X gracza*/
	float GetPositionX() { return body.getPosition().x; }
	/*Zwracanie wsp�rz�dnej y gracza*/
	float GetPositionY() { return body.getPosition().y; }

	/*Kolizja z innymi obiektami*/
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;//cia�o gracza
	float speed;//pr�dko�� gracza

	sf::Vector2f velocity;//pr�dko�� gracza wektorowo
	bool canJump;//decyzja o mo�liwo�ci wykonania skoku
	float jumpHeight;//wysoko�� skoku
};