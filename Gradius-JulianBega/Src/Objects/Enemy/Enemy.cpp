#include "Enemy.h"

namespace RlGraJB
{
	extern const int MaxEnemies = 20;
	int TotalEnemies = 20;
	Enemy Enemies[MaxEnemies] = { 0 };

	Enemy InitEnemy(int posX, int posY, int width, int height, Color color)
	{
		Enemy enemy;
		enemy.position.x = posX;
		enemy.position.y = posY;
		enemy.size.x = width;
		enemy.size.y = height;
		enemy.EnColor = color;
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
		for (int i = 1; i < MaxEnemies; i++)
		{
			if (Enemies[i].position.x <= 0 - Enemies[i].size.x)
			{
				for (int j = 0; j < MaxEnemies; j++)
				{
					while ((Enemies[j].position.x + Enemies[j].size.x / 2 >= Enemies[i].position.x - Enemies[i].size.x / 2 &&
						((Enemies[j].position.y + Enemies[j].size.y / 2 >= Enemies[i].position.y - Enemies[i].size.y / 2 &&
							Enemies[j].position.y - Enemies[j].size.y / 2 <= Enemies[i].position.y - Enemies[i].size.y / 2) ||
							(Enemies[j].position.y - Enemies[j].size.y / 2 <= Enemies[i].position.y + Enemies[i].size.y / 2 &&
								Enemies[j].position.y + Enemies[j].size.y / 2 >= Enemies[i].position.y + Enemies[i].size.y / 2))) &&
						j != i
						)
					{
						Enemies[i].position.x = screenWidth + GetRandomValue(0, Enemies[i].size.x * 2);
						Enemies[i].position.y = GetRandomValue(screenHeight / 6 + Enemies[i].size.y, screenHeight - (screenHeight / 6) - Enemies[i].size.y);
						Enemies[i].alreadyPoint = false;
						Enemies[i].EnColor = RED;
					}


				}

			}
			if (Enemies[0].position.x <= 0 - Enemies[0].size.x)
			{
				Enemies[0].position.x = screenWidth + GetRandomValue(0, Enemies[i].size.x * 2);
				Enemies[0].position.y = screenHeight - 20;
				Enemies[0].alreadyPoint = false;
				Enemies[0].EnColor = GREEN;
			}
		}
	}
}