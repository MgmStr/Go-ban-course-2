#include "prototypes.h"

void botTurn2(whiteStone Wstone[], bool& gamestate, int field[10][10],const std::set<std::string>& usedKeys, const std::vector<Combination>& allCombs)
{
	Move turn2 = findBestMove(field,usedKeys,allCombs);
	if (turn2.fromX == -1) 
	{
		gamestate = 0;
		return;
	}
	for (int l = 0; l < 12; l++)
	{
		int x = int(Wstone[l].getPos().x / 50);
		int y = int(Wstone[l].getPos().y / 50-1);
		if (x == turn2.fromX && y == turn2.fromY)
		{
			Wstone[l].setPos(turn2.toX * 50, turn2.toY * 50+50);
			field[turn2.fromX][turn2.fromY] = 0;  
			field[turn2.toX][turn2.toY] = 2;
			gamestate = 0;
			return;
		}
	}
	
}
int evaluateField(int field[10][10], int key)
{
	int totalScore = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == key)
				totalScore += evaluateStone(field, i, j, key);
		}
	}
	int opponent = (key == 2) ? 1 : 2;
	int opponentScore = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == opponent) {
				opponentScore += evaluateStone(field, i, j, opponent);
			}
		}
	}
	return totalScore - opponentScore;
}

int evaluateStone(int field[10][10], int x, int y, int key)
{
	int opponent;
	key == 1 ? opponent = 2 : opponent = 1;
	int totalscore = 0;
	int free = 0;
	if (x + 1 >= 0 && x + 1 < 10 && field[x + 1][y] == 0)
		free++;
	if (x - 1 >= 0 && x - 1 < 10 && field[x - 1][y] == 0) 
		free++;
	if (y + 1 >= 0 && y + 1 < 10 && field[x][y + 1] == 0)
		free++;
	if (y - 1 >= 0 && y - 1 < 10 && field[x][y - 1] == 0) 
		free++;
    totalscore += free * 4;
	int countRight = 0;
	int deadrow=0;
	int totals[4][2];
	for (int i = 1; i <= 4; i++) 
	{ 
		if (x + i >= 10 || field[x + i][y] != key)
		{
			if (field[x + i][y] == opponent||x+i>=10)
				deadrow++;
			break;
		}
		countRight++;
	}
	int countLeft = 0;
	for (int i = 1; i <= 4; i++) 
	{  
		if (x - i < 0 || field[x - i][y] != key) 
		{
			if (field[x -i][y] == opponent||x-i<0)
				deadrow++;
			break;
		}
		countLeft++;
	}
	totals[0][0] = 1 + countRight + countLeft;
	totals[0][1] = deadrow;
	deadrow = 0;
	int countUp = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (y + i >= 10 || field[x][y+i] != key)
		{
			if (y + i >= 10 || field[x][y+i] == opponent)
				deadrow++;
			break;
		}
		countUp++;
	}
	int countDown = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (y - i < 0 || field[x][y-i] != key)
		{
			if (y - i <0 || field[x][y - i] == opponent)
				deadrow++;
			break;
		}
		countDown++;
	}
	totals[1][0] = 1 + countUp + countDown;
	totals[1][1] = deadrow;
	deadrow = 0;
	int diagTop = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (y + i >= 10 || x + i >= 10 || field[x + i][y + i] != key)
		{
			if (y + i >= 10 || x + i >= 10 || field[x + i][y + i] == opponent)
				deadrow++;
			break;
		}
		diagTop++;
	}
	int diagBot=0;
	for (int i = 1; i <= 4; i++)
	{
		if (y - i <0 || x - i < 0 || field[x - i][y - i] != key)
		{
			if (y - i < 0 || x - i < 0 || field[x - i][y - i] == opponent)
				deadrow++;
			break;
		}
		diagBot++;
	}
	totals[2][0] = 1 + diagBot + diagTop;
	totals[2][1] = deadrow;
	deadrow = 0;
	int reverseDiagTop = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (x - i < 0 || y + i >= 10 || field[x - i][y + i] != key)
		{
			if (x - i < 0 || y + i >= 10 || field[x - i][y + i] == opponent)
				deadrow++;
			break;
		}
		reverseDiagTop++;
	}
	int reverseDiagBot = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (x + i >= 10 || y - i <0 || field[x + i][y - i] != key)
		{
			if (x + i >= 10 || y - i < 0 || field[x + i][y - i] == opponent)
				deadrow++;
			break;
		}
		reverseDiagBot++;
	}
	totals[3][0] = 1 + reverseDiagBot + reverseDiagTop;
	totals[3][1] = deadrow;
	int linescore=0;
	int currentscore;
	for (int i = 0; i < 4; i++)
	{
		currentscore = 0;
		int Weights[6][3] = 
		{	{0, 0, 0},      
			{0, 0, 0},      
			{5, 3, 0},      
			{15, 10, 3},    
			{30, 20, -10},  
			{1000, 1000, 1000} };
		int length = totals[i][0];
		int blocked = totals[i][1];
		if (length >= 5) 
			currentscore = Weights[5][0];
		else if (length >= 1 && length <= 4 && blocked >= 0 && blocked <= 2) 
			currentscore = Weights[length][blocked];
		if (length > 1 && length < 5) 
			currentscore = currentscore / length;
		linescore += currentscore;
	}
	totalscore += linescore;
	double centerX = abs(x - 4.5);
	double centerY = abs(y - 4.5);
	int centrality = (100 - int((centerX + centerY)*10))/10;
	totalscore += centrality * 2;
	if ((x == 0 || x == 9) && (y == 0 || y == 9)) 
		totalscore -= 5;
	else if (x == 0 || x == 9 || y == 0 || y == 9) 
		totalscore -= 2;
	return totalscore;
}

std::vector<Move> generateMoves(const int field[10][10], int key) 
{
	std::vector<Move> moves;
	for (int x = 0; x < 10; x++) 
	{
		for (int y = 0; y < 10; y++) 
		{
			if (field[x][y] == key) 
			{
				int directions[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
				for (auto& dir : directions) 
				{
					int nx = x + dir[0];
					int ny = y + dir[1];

					if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) 
					{
						if (field[nx][ny] == 0)
							moves.push_back({ x, y, nx, ny });
					}
				}
			}
		}
	}
	return moves;
}
Move findBestMove(int field[10][10], const std::set<std::string>& usedKeys, const std::vector<Combination>& allCombs)
{
	std::set<std::string> tempUsedKeys = usedKeys;
	std::vector<Combination> tempAllCombs = allCombs;
	std::vector<Move> moves = generateMoves(field, 2);
	if (moves.empty())
		return Move{ -1, -1, -1, -1 };
	Move bestMove = moves[0];
	int bestValue = -9999;
	for (const Move& move : moves) 
	{
		int newField[10][10];
		for (int i = 0; i < 10; i++) 
		{
			for (int j = 0; j < 10; j++)
				newField[i][j] = field[i][j];
		}
		applyMove(newField, move, 2);
		int moveValue = minimax(newField, 4, -9999, 9999, false, 1);
		for (const Move& move : moves) 
		{
			std::vector<Combination> newCombs;
			findCurrentCombinations(newField, newCombs, tempUsedKeys, tempAllCombs, false);
			for (const auto& comb : newCombs) 
			{
				if (comb.color == 2) 
				{
					std::string key = getKey(comb);
					if (usedKeys.find(key) != usedKeys.end()) 
						moveValue -= 500;
				}
			}
		}
		if (moveValue > bestValue) 
		{
			bestValue = moveValue;
			bestMove = move;
		}
	}
	return bestMove;
}

int minimax(int field[10][10], int depth, int alpha, int beta, bool ismaximizaing, int key)
{
	int opponent;
	key == 1 ? opponent = 2 : opponent = 1;
	if (depth == 0)
		return evaluateField(field, 2);
	std::vector<Move> moves = generateMoves(field, key);
	if(moves.empty())
		return evaluateField(field, 2);
	if (ismaximizaing)
	{
		int maxEval = -9999;
		for (const Move& move : moves)
		{
			int newField[10][10];
			for (int i = 0; i < 10; i++) 
			{
				for (int j = 0; j < 10; j++) 
				{
					newField[i][j] = field[i][j];
				}
			}
			applyMove(newField, move, key);
			int eval = minimax(newField, depth - 1, alpha, beta, false, opponent);
			maxEval = max(maxEval, eval);
			alpha = max(alpha, eval);
			if (beta <= alpha)
				break;
		}
		return maxEval;
	}
	else
	{
		int minEval = 9999;
		for (const Move& move : moves)
		{
			int newField[10][10];
			for (int i = 0; i < 10; i++) 
			{
				for (int j = 0; j < 10; j++) 
				{
					newField[i][j] = field[i][j];
				}
			}
			applyMove(newField, move, key);
			int eval = minimax(newField, depth - 1, alpha, beta, true, opponent);
			minEval = min(minEval, eval);
			beta = min(beta, eval);
			if (beta <= alpha) break;
		}
		return minEval;
	}
}

