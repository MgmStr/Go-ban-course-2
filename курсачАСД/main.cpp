#include "prototypes.h"

int main()
{
    bool zerostate = 0, sekondstage = 0;
    bool gameState = 1; //0 для хода игрока, 1 для хода компьютера
    whiteStone Wstone[12];
    blackStone Bstone[12];
    std::set<std::string> usedKeys;
    std::vector<Combination> allCombinations;
	sf::RenderWindow window(sf::VideoMode({ 800, 610 }), "Go-ban");
    int i = -1;
    sf::Font font;
    std::vector<Combination> foundCombs;
    if (!font.openFromFile("arialmt.ttf"))
    {
        return 0;
    }
    int field[10][10] = {0};
    window.setFramerateLimit(20);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);
        if (Bstone[0].onTable == true)
            sekondstage = 1;
        if (zerostate == 0) {
            start(window, Wstone, Bstone);
            zerostate = 1;
        }
        if ((gameState == 0) && (sekondstage == 0))
        {
            playerTurn1(window, Wstone, Bstone, gameState, field);
            findCurrentCombinations(field, foundCombs, usedKeys, allCombinations, true);
        }
        else if ((gameState == 0) && (sekondstage == 1))
        {
            if (i != -1)
            {
                if (changePos(window, Bstone, Wstone, i, field) == 1)
                {
                    i = -1;
                    gameState = 1;
                    findCurrentCombinations(field, foundCombs, usedKeys, allCombinations, true);
                }
            }
            else i = playerTurn2(window, Wstone, Bstone);
        }
        else if ((gameState == 1) && (sekondstage == 0))
        {
            botTurn1(Wstone, gameState, field);
            findCurrentCombinations(field, foundCombs, usedKeys, allCombinations, true);
        }
        else if ((gameState == 1) && (sekondstage == 1)) {
            botTurn2(Wstone, gameState, field, usedKeys, allCombinations);
            findCurrentCombinations(field, foundCombs, usedKeys, allCombinations, true);
        }
        drowStones(window, Wstone, Bstone);
        drowTable(window);
        printscore(window, font, getscore(allCombinations, 2), 2);
        printscore(window, font, getscore(allCombinations, 1), 1);
        window.display();
    }
}
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return main();
}