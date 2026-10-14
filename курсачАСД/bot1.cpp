#include "prototypes.h"
void calculateMatrix(int field[10][10], int distanceMatrix[10][10], int key)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == key)
				distanceMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			if (distanceMatrix[i][j] != 0)
			{
				if (i > 0 && distanceMatrix[i - 1][j] + 1 < distanceMatrix[i][j])
					distanceMatrix[i][j] = distanceMatrix[i - 1][j] + 1;
				if (j > 0 && distanceMatrix[i][j - 1] + 1 < distanceMatrix[i][j])
					distanceMatrix[i][j] = distanceMatrix[i][j - 1] + 1;
			}
		}
	}
	for (int i = 9; i >= 0; i--) 
	{
		for (int j = 9; j >= 0; j--) 
		{
			if (distanceMatrix[i][j] != 0)
			{
				if (i < 9 && distanceMatrix[i + 1][j] + 1 < distanceMatrix[i][j])
					distanceMatrix[i][j] = distanceMatrix[i + 1][j] + 1;
				if (j < 9 && distanceMatrix[i][j + 1] + 1 < distanceMatrix[i][j])
					distanceMatrix[i][j] = distanceMatrix[i][j + 1] + 1;
			}
		}
	}
}

void botTurn1(whiteStone Wstone[], bool& gamestate, int field[10][10])
{
	int count = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (field[i][j] == 1)
					count++;
				else count = 0;
				if (count == 3)
				{
					j++;
					if ((j<10)&&(field[i][j] == 0))
					{
						for (int l = 0; l < 12; l++)
						{
							if (Wstone[l].onTable == false)
							{
								Wstone[l].setPos(i * 50, j * 50 + 50);
								gamestate = 0;
								Wstone[l].onTable = true;
								field[i][j] = 2;
								return;
							}
						}
					}
					else if (((field[i][j] == 1) || (j >= 10))&&(field[i][j - 4] == 0))
					{
						for (int l = 0; l < 12; l++)
						{
							if (Wstone[l].onTable == false)
							{
								Wstone[l].setPos(i * 50, (j -4) * 50 + 50);
								gamestate = 0;
								Wstone[l].onTable = true;
								field[i][j-4] = 2;
								return;
							}
						}
					}
				}
			}
		}
	count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[j][i] == 1)
				count++;
			else count = 0;
			if (count == 3)
			{
				j++;
				if ((j < 10) && (field[j][i] == 0))
				{
					for (int l = 0; l < 12; l++)
					{
						if (Wstone[l].onTable == false)
						{
							Wstone[l].setPos(j * 50, i * 50 + 50);
							gamestate = 0;
							Wstone[l].onTable = true;
							field[j][i] = 2;
							return;
						}
					}
				}
				else if (((field[j][i] == 1) || (j >= 10)) && (field[j-4][i] == 0))
				{
					for (int l = 0; l < 12; l++)
					{
						if (Wstone[l].onTable == false)
						{
							Wstone[l].setPos((j-4) * 50, i * 50 + 50);
							gamestate = 0;
							Wstone[l].onTable = true;
							field[j-4][i] = 2;
							return;
						}
					}
				}
			}
		}
	}
	count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((field[i][j] == 1) && (field[i + 1][j + 1] == 1) && (field[i + 2][j + 2] == 1))
			{
				if ((i + 3 < 10) && (j + 3 < 10) && (field[i + 3][j + 3] == 0))
				{
					for (int l = 0; l < 12; l++)
					{
						if (Wstone[l].onTable==false)
						{
							Wstone[l].setPos((i + 3) * 50, (j + 3) * 50 + 50);
							Wstone[l].onTable = true;
							field[i + 3][j + 3] = 2;
							gamestate = 0;
							return;
						}
					}
				}
				else if (i - 1 >= 0 && j - 1 >= 0 && field[i - 1][j - 1] == 0)
				{
					for (int l = 0; l < 12; l++)
					{
						if (Wstone[l].onTable==false)
						{
							Wstone[l].setPos((i - 1) * 50, (j - 1) * 50 + 50);
							Wstone[l].onTable = true;
							field[i - 1][j - 1] = 2;
							gamestate = 0;
							return;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 2; j < 10; j++)
		{
			if ((field[i][j] == 1) && (field[i + 1][j - 1] == 1) && (field[i + 2][j - 2] == 1))
			{
				if ((i + 3 < 10) && (j - 3 >= 0) && (field[i + 3][j - 3] == 0))
				{
					for (int l = 0; l < 10; l++)
					{
						if (Wstone[l].onTable==false)
						{
							Wstone[l].setPos((i + 3) * 50, (j - 3) * 50 + 50);
							Wstone[l].onTable = true;
							field[i + 3][j - 3] = 2;
							gamestate = 0;
							return;
						}
					}
				}
				else if ((i - 1 >= 0) && (j + 1 < 10) && (field[i - 1][j + 1] == 0) && (field[i + 2][j - 2] != 2))
				{
					for (int l = 0; l < 10; l++)
					{
						if (Wstone[l].onTable==false)
						{
							Wstone[l].setPos((i - 1) * 50, (j + 1) * 50 + 50);
							Wstone[l].onTable = true;
							field[i - 1][j + 1] = 2;
							gamestate = 0;
							return;
						}
					}
				}
			}
		}
	}
	logic1(Wstone, field);
	gamestate = 0;
}

void logic1(whiteStone Wstone[], int field[10][10])
{
	int check = 0;
	for (int i = 11; i >=0; i--)
	{
		if (!Wstone[i].onTable)
			check++;
	}
	if (check == 12)
	{
		srand(int(time(0)));
		int x = rand() % 10;
		int y = rand() % 10;
		field[x][y] = 2;
		Wstone[11].setPos(x*50, y*50+50);
		Wstone[11].onTable = true;
		return;
	}
	int distanceMatrix[10][10];
	int* p = &distanceMatrix[0][0];
	for (int i = 0; i < 100; i++) 
		p[i] = 100;
	calculateMatrix(field, distanceMatrix, 1);
	int bestX = -1, bestY = -1;
	int bestScore = -99999;
	for (int i1 = 0; i1 < 10; i1++) 
	{
		for (int j1 = 0; j1 < 10; j1++) 
		{
			if (field[i1][j1] == 0) 
			{
				field[i1][j1] = 2;
				int worstScoreForWhite = 99999;
				for (int i2 = 0; i2 < 10; i2++) 
				{
					for (int j2 = 0; j2 < 10; j2++) 
					{
						if (field[i2][j2] == 0) 
						{
							field[i2][j2] = 1;
							int bestScoreForWhite = -99999;
							for (int i3 = 0; i3 < 10; i3++) 
							{
								for (int j3 = 0; j3 < 10; j3++) 
								{
									if (field[i3][j3] == 0) 
									{
										field[i3][j3] = 2;
										int worstScoreForWhite2 = 99999;
										for (int i4 = 0; i4 < 10; i4++) 
										{
											for (int j4 = 0; j4 < 10; j4++) 
											{
												if (field[i4][j4] == 0) 
												{
													field[i4][j4] = 1;
													int finalScore = evaluateNextTurn(field,distanceMatrix,2);
													if (finalScore < worstScoreForWhite2) 
														worstScoreForWhite2 = finalScore;
													field[i4][j4] = 0;
												}
											}
										}
										if (worstScoreForWhite2 > bestScoreForWhite) 
											bestScoreForWhite = worstScoreForWhite2;
										field[i3][j3] = 0;
									}
								}
							}
							if (bestScoreForWhite < worstScoreForWhite)
								worstScoreForWhite = bestScoreForWhite;
							field[i2][j2] = 0;
						}
					}
				}
				if (worstScoreForWhite > bestScore) {
					bestScore = worstScoreForWhite;
					bestX = i1;
					bestY = j1;
				}
				field[i1][j1] = 0;
			}
		}
	}
	for (int l = 0; l < 12; l++)
	{
		if (Wstone[l].onTable == false)
		{
			Wstone[l].setPos(bestX * 50, bestY * 50 + 50);
			Wstone[l].onTable = true;
			field[bestX][bestY] = 2;
			return;
		}
	}
}

int evaluateNextTurn(int field[10][10], int distanceMatrix[10][10], int key)
{
	int negative = 0;
	key == 1 ? negative=2 : negative=1;
	int totalScore = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == negative)
			{
				int toCenter = abs(i - 5) + abs(j - 5);
				totalScore -= (10 - toCenter);
				int nearby = 0;
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
					{
						int x = i + dx;
						int y = j + dy;
						if (x >= 0 && x < 10 && y >= 0 && y < 10 && field[x][y] == negative)
							nearby++;
					}
				}
				totalScore -= nearby * 3;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == key)
				totalScore += (10 - distanceMatrix[i][j]) * 2;
		}
	}
	return totalScore;
}