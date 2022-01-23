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

	/**Zapobieganie rozci¹ganiu tekstur
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
	/**Funkcja odpowiadaj¹ca za zachowanie obiektu w przypadku wyst¹pienia kolizji
	*
	*@param direction
	* kierunek w którym dzia³a kolizja
	* 
	*/
	void OnCollision(sf::Vector2f direction);
	
	/*Zwracanie aktualnych wspó³rzêdnych gracza*/
	sf::Vector2f GetPosition() { return body.getPosition(); }
	/*Zwracanie wspó³rzêdnej X gracza*/
	float GetPositionX() { return body.getPosition().x; }
	/*Zwracanie wspó³rzêdnej y gracza*/
	float GetPositionY() { return body.getPosition().y; }

	/*Kolizja z innymi obiektami*/
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;//cia³o gracza
	float speed;//prêdkoœæ gracza

	sf::Vector2f velocity;//prêdkoœæ gracza wektorowo
	bool canJump;//decyzja o mo¿liwoœci wykonania skoku
	float jumpHeight;//wysokoœæ skoku
};