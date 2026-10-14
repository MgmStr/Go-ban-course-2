#include "prototypes.h"

void findCurrentCombinations(int field[10][10],std::vector<Combination>& result, std::set<std::string>& usedCombinationKeys, std::vector<Combination>& allCombinations, bool addNew )
{
    result.clear();
    for (int y = 0; y < 10; y++) 
    {
        for (int x = 0; x <= 5; x++) 
        {
            bool blackLine = true;
            bool whiteLine = true;
            int stones[5][2];

            for (int i = 0; i < 5; i++) 
            {
                stones[i][0] = x + i;
                stones[i][1] = y;

                if (field[x + i][y] != 1) blackLine = false;
                if (field[x + i][y] != 2) whiteLine = false;
            }

            if (blackLine) {
                Combination newComb(1, stones);
                result.push_back(newComb);
                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
            if (whiteLine) 
            {
                Combination newComb(2, stones);
                result.push_back(newComb);
                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
        }
    }
    for (int x = 0; x < 10; x++) 
    {
        for (int y = 0; y <= 5; y++) 
        {
            bool blackLine = true;
            bool whiteLine = true;
            int stones[5][2];
            for (int i = 0; i < 5; i++) 
            {
                stones[i][0] = x;
                stones[i][1] = y + i;
                if (field[x][y + i] != 1) blackLine = false;
                if (field[x][y + i] != 2) whiteLine = false;
            }
            if (blackLine) 
            {
                Combination newComb(1, stones);
                result.push_back(newComb);

                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
            if (whiteLine) 
            {
                Combination newComb(2, stones);
                result.push_back(newComb);
                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
        }
    }
    for (int x = 0; x <= 5; x++) 
    {
        for (int y = 0; y <= 5; y++) 
        {
            bool blackLine = true;
            bool whiteLine = true;
            int stones[5][2];
            for (int i = 0; i < 5; i++) 
            {
                stones[i][0] = x + i;
                stones[i][1] = y + i;
                if (field[x + i][y + i] != 1) blackLine = false;
                if (field[x + i][y + i] != 2) whiteLine = false;
            }
            if (blackLine) 
            {
                Combination newComb(1, stones);
                result.push_back(newComb);
                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
            if (whiteLine) 
            {
                Combination newComb(2, stones);
                result.push_back(newComb);
                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
        }
    }
    for (int x = 4; x < 10; x++) 
    {
        for (int y = 0; y <= 5; y++) 
        {
            bool blackLine = true;
            bool whiteLine = true;
            int stones[5][2];
            for (int i = 0; i < 5; i++) 
            {
                stones[i][0] = x - i;
                stones[i][1] = y + i;
                if (field[x - i][y + i] != 1) blackLine = false;
                if (field[x - i][y + i] != 2) whiteLine = false;
            }

            if (blackLine) 
            {
                Combination newComb(1, stones);
                result.push_back(newComb);
                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
            if (whiteLine) 
            {
                Combination newComb(2, stones);
                result.push_back(newComb);

                if (addNew) 
                {
                    std::string key = getKey(newComb);
                    if (usedCombinationKeys.find(key) == usedCombinationKeys.end()) 
                    {
                        usedCombinationKeys.insert(key);
                        allCombinations.push_back(newComb);
                    }
                }
            }
        }
    }
}
int getscore(std::vector<Combination> allCombinations, int color)
{
    int whiteCombinationCount = 0;
    for (const auto& comb : allCombinations)
    {
        if (comb.color == 2)
            whiteCombinationCount++;
    }
    if (color == 2)
        return whiteCombinationCount;

    int blackCombinationCount = 0;
    for (const auto& comb : allCombinations)
    {
        if (comb.color == 1)
            blackCombinationCount++;
    }
    if (color == 1)
        return blackCombinationCount;
}