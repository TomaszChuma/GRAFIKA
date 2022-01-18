#include "Player.h"
#include "Animation.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	this->jumpHeight = jumpHeight;
	

	body.setSize(sf::Vector2f(80.0f, 80.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(200.f, 200.f);
	body.setTexture(texture);

}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 9.81 * jumpHeight * 30);
	}

	if (velocity.x == 0.0f)
	{
		row = 0;
	}

	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;

	}



	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}*/

	//body.setTextureRect(animation.uvRect);

	velocity.y += 981.0f * deltaTime;

	animation.Update(row, deltaTime, faceRight);
	//body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

	velocity.x = 0;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
	
}
