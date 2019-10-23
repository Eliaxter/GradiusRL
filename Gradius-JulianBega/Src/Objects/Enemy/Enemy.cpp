#include "Enemy.h"

namespace RlGraJB
{
	extern const int MaxEnemies = 12;
	int TotalEnemies = 10;
	Enemy Enemies[MaxEnemies] = { 0 };

	Enemy InitEnemy(int posX, int posY, int width, int height)
	{
		Enemy enemy;
		enemy.position.x = posX;
		enemy.position.y = posY;
		enemy.size.x = width;
		enemy.size.y = height;
		return enemy;
	}

	void MoveEnemy()
	{
	
		for (int i = 0; i < MaxEnemies; i++)
		{
			Enemies[i].position.x = Enemies[i].position.x - Enemies[i].Speed * GetFrameTime();
		}
	}

	void UpdateEnemy()
	{
		MoveEnemy();
		CheckOutOfScreen();	
	}

	void CheckOutOfScreen()
	{
		for (int i = 0; i < MaxEnemies; i++)
		{
			if (Enemies[i].position.x <= 0 - Enemies[i].size.x)
			{
				Enemies[i].position.x = screenWidth + GetRandomValue(0, Enemies[i].size.x*2);
				Enemies[i].position.y = GetRandomValue(screenHeight/6 + Enemies[i].size.y, screenHeight - (screenHeight / 6) - Enemies[i].size.y);
			}
		}
	}
}