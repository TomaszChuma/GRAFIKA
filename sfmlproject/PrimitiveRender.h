#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>

class Point2D {
	int x, y;
public:
	Point2D(int x, int y);
	Point2D();
	int getX();
	int getY();
	void changeX(int x);
	void changeY(int y);
};

class LineSegment {
	Point2D point1, point2;
public:
	LineSegment();
	LineSegment(Point2D point1, Point2D point2);
	LineSegment(int x1, int y1, int x2, int y2);
	void changePoint1(Point2D point1);
	void changePoint2(Point2D point2);
	void changePoint1(int x1, int y1);
	void changePoint2(int x2, int y2);
	int getPoint1X();
	int getPoint1Y();
	int getPoint2X();
	int getPoint2Y();
};



class PrimitiveRender
{
public:
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2); //the default color is white
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	void drawLine(sf::RenderWindow& window, LineSegment line);
	void drawLine(sf::RenderWindow& window, LineSegment line, sf::Color color);
	void drawCircle(sf::RenderWindow& window, int size, int x, int y);
	void drawCircle(sf::RenderWindow& window, int size, int x, int y, sf::Color color);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y, sf::Color color);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, int x, int y);
	void drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, Point2D point2D);
	void drawPoint(sf::RenderWindow& window, Point2D point2D, sf::Color color);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	void drawPolyline(sf::RenderWindow& window, std::vector<LineSegment> lineVector);
};




