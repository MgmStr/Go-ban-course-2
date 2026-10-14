#pragma once
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "stones.h"
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <sstream>
#include <set>
#include <algorithm>

void drowTable(sf::RenderWindow& window);
void start(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[]);
bool nearcell(sf::Vector2f current, sf::Vector2i target);
void playerTurn1(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[], bool& gamestate, int field[10][10]);
int playerTurn2(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[]);
bool changePos(sf::RenderWindow& window, blackStone Bstone[], whiteStone Wstone[], int i, int field[10][10]);
void drowStones(sf::RenderWindow& window, whiteStone Wstone[], blackStone Bstone[]);
void printscore(sf::RenderWindow& window, sf::Font font, int num, int color);
void botTurn1(whiteStone Wstone[], bool& gamestate, int field[10][10]);
void logic1(whiteStone Wstone[], int field[10][10]);
int evaluateNextTurn(int field[10][10], int distanceMatrix[10][10], int key); 
void botTurn2(whiteStone Wstone[], bool& gamestate, int field[10][10], const std::set<std::string>& usedKeys, const std::vector<Combination>& allCombs);
int evaluateField(int field[10][10], int key);
int evaluateStone(int field[10][10], int x, int y, int key);
std::vector<Move> generateMoves(const int field[10][10], int playerColor);
Move findBestMove(int field[10][10], const std::set<std::string>& usedKeys, const std::vector<Combination>& allCombs);
void applyMove(int field[10][10], const Move& move, int playerColor);
int minimax(int field[10][10], int depth, int alpha, int beta, bool ismaximizaing, int key); 
std::string getKey(const Combination& comb);
void findCurrentCombinations(int field[10][10], std::vector<Combination>& result, std::set<std::string>& usedCombinationKeys, std::vector<Combination>& allCombinations, bool addNew = false);
int getscore(std::vector<Combination> allCombinations, int color);