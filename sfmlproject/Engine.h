#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/WindowStyle.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
#include <cmath>

class Engine
{
private:
	int screenWidth = 0, screenHeight = 0;
	std::string windowTitle;
	sf::Clock clock;
	sf::Keyboard keyboard;
	sf::Texture square;
	sf::Sprite sprite;
	sf::Color color;
	sf::Mouse mouse;
	void paintScreen(sf::Color color);
public:
	Engine(int screenWidth, int screenHeight, std::string windowTitle);
	Engine(int screenWidth, int screenHeight);
	int init();
	//~Engine();
};

