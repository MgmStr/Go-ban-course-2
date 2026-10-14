#pragma once
#include <SFML/Graphics.hpp>

class Stone
{
public:
	sf::Vector2f pos;
	bool onTable;
	Stone() : pos({ 0.0 }, { 0.0 }), onTable(false) {}
	void setPos(int x, int y)
	{
		pos = { float(x+7.5),float(y+7.5) };
	}
	sf::Vector2f getPos() {
		return pos;
	}
	bool compareCoords(sf::Vector2i externalCoords)
	{
		return ((pos.x == externalCoords.x + 7.5) && (pos.y == externalCoords.y + 7.5));
	}
};
class whiteStone : public Stone
{
	sf::CircleShape whtre;
public:
	whiteStone() : whtre() {
		sf::CircleShape circle(20.0);
		circle.setFillColor(sf::Color::White);
		circle.setOutlineThickness(2.0);
		circle.setOutlineColor(sf::Color(250, 150, 100));
		whtre = circle;
	}
	sf::CircleShape getFigure()
	{
		whtre.setPosition(pos);
		return whtre;
	}
};
class blackStone : public Stone
{
	sf::CircleShape blck;
public:
	blackStone() : blck() {
		sf::CircleShape circle(20.0);
		circle.setFillColor(sf::Color::Black);
		circle.setOutlineThickness(2.0);
		circle.setOutlineColor(sf::Color::White);
		blck = circle;
	}
	sf::CircleShape getFigure()
	{
		blck.setPosition(pos);
		return blck;
	}
};
struct Move 
{
	int fromX, fromY;
	int toX, toY;
};
struct Combination 
{
	int color;
	int stones[5][2];

	Combination(int c, int s[5][2]) : color(c) 
	{
		for (int i = 0; i < 5; i++) 
		{
			stones[i][0] = s[i][0];
			stones[i][1] = s[i][1];
		}
	}
};

