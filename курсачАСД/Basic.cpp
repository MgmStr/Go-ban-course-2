#include "prototypes.h"
void drowTable(sf::RenderWindow& window)
{
    sf::RectangleShape Vline({ 5.f , 505.f });
    sf::RectangleShape Hline({ 500.f , 5.f });
    Vline.setFillColor(sf::Color::Black);
    Hline.setFillColor(sf::Color::Black);
    for (int i = 0; i <= 10; i++)
    {
        Vline.setPosition({ float(50 * i ), 50 });
        Hline.setPosition({0 , float(50 * i + 50) });
        window.draw(Vline);
        window.draw(Hline);
    }
}

void start(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[])
{
    for (int i = 0; i < 12; i++)
    {
        Wstone[i].setPos(20 * i + 50, -3);
        window.draw(Wstone[i].getFigure());
        Bstone[i].setPos(20 * i + 50, 550);
        window.draw(Bstone[i].getFigure());
    }
}

void drowStones(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[])
{
    for (int i = 0; i < 12; i++)
    {
        window.draw(Wstone[i].getFigure());
        window.draw(Bstone[i].getFigure());
    }
}

bool nearcell(sf::Vector2f current, sf::Vector2i target)
{
    int dx = abs((int)current.x - target.x);
    int dy = abs((int)current.y - target.y);
    if ((dx == 57 || dx == 43) && (dy == 57 || dy == 43))
        return 0;
    if ((dx == 7 || dx == 57 || dx == 43) && (dy == 7 || dy == 57 || dy == 43))
        return 1;
    else return 0;
}

void printscore(sf::RenderWindow& window, sf::Font font, int num, int color)
{
    sf::Text text(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    if (color == 2)
    {
        text.setPosition({ 575, 50 });
    }
    if (color == 1)
    {
        text.setPosition({ 575, 500 });
    }
    std::string score = std::to_string(num);
    text.setString(score);
    window.draw(text);
}
std::string getKey(const Combination& comb)
{
    std::pair<int, int> temp[5];
    for (int i = 0; i < 5; i++)
    {
        temp[i].first = comb.stones[i][0];
        temp[i].second = comb.stones[i][1];
    }

    std::sort(temp, temp + 5, [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });

    std::string key = std::to_string(comb.color) + ":";
    for (int i = 0; i < 5; i++) {
        if (i > 0) key += ";";
        key += std::to_string(temp[i].first) + "," + std::to_string(temp[i].second);
    }

    return key;
}
void applyMove(int field[10][10], const Move& move, int playerColor)
{
    field[move.fromX][move.fromY] = 0;
    field[move.toX][move.toY] = playerColor;
}