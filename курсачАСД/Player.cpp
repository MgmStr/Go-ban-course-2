#include "prototypes.h"
void playerTurn1(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[], bool& gamestate, int field[10][10])
{
    sf::Vector2i kursorPosition = sf::Mouse::getPosition(window);
    if (((kursorPosition.x > 0) && (kursorPosition.y > 50)) && ((kursorPosition.x < 500) && (kursorPosition.y < 550)))
    {
        sf::RectangleShape selection({ 50.0,50.0 });
        selection.setFillColor(sf::Color(250, 150, 100));
        kursorPosition = { kursorPosition.x / 50 * 50 , kursorPosition.y / 50 * 50 };
        selection.setPosition({ float(kursorPosition.x), float(kursorPosition.y) });
        window.draw(selection);
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
        {
            int n = kursorPosition.x / 50;
            int k = (kursorPosition.y-50) / 50;
            for (int i = 11; i >= 0; i--)
            {
                if ((field[n][k] == 0) && (Bstone[i].onTable == false))
                {
                    Bstone[i].setPos(kursorPosition.x, kursorPosition.y);
                    Bstone[i].onTable = 1;
                    gamestate = 1;
                    field[n][k] = 1;
                    return;
                }
            }
        }
    }
}
bool changePos(sf::RenderWindow& window, blackStone Bstone[], whiteStone Wstone[], int i, int field[10][10])
{
    sf::Vector2i kursorPosition = sf::Mouse::getPosition(window);
    sf::RectangleShape selection({ 50.0,50.0 });
    selection.setFillColor(sf::Color::Cyan);
    selection.setPosition(Bstone[i].getPos());
    for (int k = 0; k < 4; k++)
    {
        selection.setPosition(Bstone[i].getPos());
        switch (k)
        {
        case 0:
            selection.move({ -5,45 });
            break;
        case 1:
            selection.move({ 45,-5 });
            break;
        case 2:
            selection.move({ -5,-55 });
            break;
        case 3:
            selection.move({ -55,-5 });
            break;
        }
        window.draw(selection);
    }
    if ((kursorPosition.x > 0) && (kursorPosition.y > 50) && (kursorPosition.x < 500) && (kursorPosition.y < 550))
    {
        kursorPosition = { kursorPosition.x / 50 * 50 , kursorPosition.y / 50 * 50 };
        int n = kursorPosition.x / 50;
        int k = (kursorPosition.y - 50) / 50;
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && (field[n][k]==false) && (nearcell(Bstone[i].getPos(), kursorPosition) == 1))
        {
            field[n][k] = 1;
            n = int(Bstone[i].getPos().x) / 50;
            k = (int(Bstone[i].getPos().y)-50) / 50 ;
            field[n][k]=0;
            Bstone[i].setPos(kursorPosition.x, kursorPosition.y);
            return 1;
        }
    }
    return 0;
}
int playerTurn2(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[])
{
    sf::Vector2i kursorPosition = sf::Mouse::getPosition(window);
    if (((kursorPosition.x > 0) && (kursorPosition.y > 50)) && ((kursorPosition.x < 500) && (kursorPosition.y < 550)))
    {
        sf::RectangleShape selection({ 50.0,50.0 });
        selection.setFillColor(sf::Color(250, 150, 100));
        kursorPosition = { kursorPosition.x / 50 * 50 , kursorPosition.y / 50 * 50 };
        selection.setPosition({ float(kursorPosition.x), float(kursorPosition.y) });
        window.draw(selection);
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
        {
            for (int i = 0; i < 12; i++)
            {
                if (Bstone[i].compareCoords(kursorPosition) == true)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}