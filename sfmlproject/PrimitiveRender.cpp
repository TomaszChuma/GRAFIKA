#include "PrimitiveRender.h"


void PrimitiveRender::drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
	sf::Vertex line2[] = {
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2,y2))
	};
	line2->color = sf::Color::White;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color) {
	sf::Vertex line2[] = {
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2,y2))
	};
	line2->color = color;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawLine(sf::RenderWindow& window, LineSegment line) {
	sf::Vertex line2[] = {
	sf::Vertex(sf::Vector2f(line.getPoint1X(),line.getPoint1Y())),
	sf::Vertex(sf::Vector2f(line.getPoint2X(),line.getPoint2Y()))
	};
	line2->color = sf::Color::White;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawLine(sf::RenderWindow& window, LineSegment line, sf::Color color) {
	sf::Vertex line2[] = {
	sf::Vertex(sf::Vector2f(line.getPoint1X(),line.getPoint1Y())),
	sf::Vertex(sf::Vector2f(line.getPoint2X(),line.getPoint2Y()))
	};
	line2->color = color;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawCircle(sf::RenderWindow& window, int size, int x, int y) {
	sf::CircleShape circle(size);
	circle.setPosition(sf::Vector2f(x, y));
	window.draw(circle);
}
void PrimitiveRender::drawCircle(sf::RenderWindow& window, int size, int x, int y, sf::Color color) {
	sf::CircleShape circle(size);
	circle.setPosition(sf::Vector2f(x, y));
	circle.setFillColor(color);
	window.draw(circle);
}
void PrimitiveRender::drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y) {
	sf::RectangleShape rectangle(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	window.draw(rectangle);
}
void PrimitiveRender::drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y, sf::Color color) {
	sf::RectangleShape rectangle(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
	window.draw(rectangle);
}
void PrimitiveRender::drawTriangle(sf::RenderWindow& window, int size, int x, int y) {
	sf::CircleShape triangle(size, 3);
	triangle.setPosition(sf::Vector2f(x, y));
	window.draw(triangle);
}
void PrimitiveRender::drawTriangle(sf::RenderWindow& window, int size, int x, int y, sf::Color color) {
	sf::CircleShape triangle(size, 3);
	triangle.setPosition(sf::Vector2f(x, y));
	triangle.setFillColor(color);
	window.draw(triangle);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, int x, int y) {
	sf::Vertex point(sf::Vector2f(x, y));
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color) {
	sf::Vertex point(sf::Vector2f(x, y), color);
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, Point2D point2D) {
	sf::Vertex point(sf::Vector2f(point2D.getX(), point2D.getY()));
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, Point2D point2D, sf::Color color) {
	sf::Vertex point(sf::Vector2f(point2D.getX(), point2D.getY()), color);
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
	int x;
	float dy = y2 - y1;
	float dx = x2 - x1;
	float m = dy / dx;
	float y = y1;
	if ((m > -1) || (m < 1)) {
		for (x = x1; x <= x2; x++) {
			drawPoint(window, x, floor(0.5 + y));
			y += m;
		}
	}
	else {
		for (x = y1; x <= y2; x++) {
			drawPoint(window, x, floor(0.5 + y));
			x += 1 / m;
		}
	}
}
void PrimitiveRender::incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color) {
	int x;
	float dy = y2 - y1;
	float dx = x2 - x1;
	float m = dy / dx;
	float y = y1;
	if ((m > -1) || (m < 1)) {
		for (x = x1; x <= x2; x++) {
			drawPoint(window, x, floor(0.5 + y), color);
			y += m;
		}
	}
	else {
		for (x = y1; x <= y2; x++) {
			drawPoint(window, x, floor(0.5 + y), color);
			x += 1 / m;
		}
	}
}
void PrimitiveRender::drawPolyline(sf::RenderWindow& window, std::vector<LineSegment> lineVector) {
	std::vector<LineSegment>::iterator it = lineVector.begin();

	for (LineSegment& x : lineVector) {
		drawLine(window, x);
	}
}


Point2D::Point2D(int x, int y) {
	this->x = x;
	this->y = y;
}
Point2D::Point2D() {
	x = y = 0;
}
int Point2D::getX() {
	return this->x;
}
int Point2D::getY() {
	return this->y;
}
void Point2D::changeX(int x) {
	this->x = x;
}
void Point2D::changeY(int y) {
	this->y = y;
}


LineSegment::LineSegment() {
	point1.changeX(0);
	point1.changeY(0);
	point2.changeX(0);
	point2.changeY(0);
}
LineSegment::LineSegment(Point2D point1, Point2D point2) {
	this->point1.changeX(point1.getX());
	this->point1.changeY(point1.getY());
	this->point2.changeX(point2.getX());
	this->point2.changeY(point2.getY());
}
LineSegment::LineSegment(int x1, int y1, int x2, int y2) {
	this->point1.changeX(x1);
	this->point1.changeY(y1);
	this->point2.changeX(x2);
	this->point2.changeY(y2);
}
void LineSegment::changePoint1(Point2D point1) {
	this->point1.changeX(point1.getX());
	this->point1.changeY(point1.getY());
}
void LineSegment::changePoint2(Point2D point2) {
	this->point2.changeX(point2.getX());
	this->point2.changeY(point2.getY());
}
void LineSegment::changePoint1(int x1, int y1) {
	this->point1.changeX(x1);
	this->point1.changeY(y1);
}
void LineSegment::changePoint2(int x2, int y2) {
	this->point2.changeX(x2);
	this->point2.changeY(y2);
}
int LineSegment::getPoint1X() {
	return point1.getX();
}
int LineSegment::getPoint1Y() {
	return point1.getY();
}
int LineSegment::getPoint2X() {
	return point2.getX();
}
int LineSegment::getPoint2Y() {
	return point2.getY();
}

