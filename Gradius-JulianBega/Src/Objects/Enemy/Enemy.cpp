#include "Enemy.h"

namespace RlGraJB
{
	const int MaxEnemies = 20;
	int TotalEnemies = 20;
	Enemy enemies[MaxEnemies] = { 0 };

	void InitEnemy()
	{
		for (int i = 0; i < MaxEnemies; i++)
		{
			enemies[i].rec.x = GetRandomValue(screenWidth, screenWidth * 2);
			enemies[i].rec.y = GetRandomValue(screenHeight / 6, screenHeight - screenHeight / 6);
			enemies[i].rec.width = 50.0f;
			enemies[i].rec.height = 20.0f;
			enemies[i].Alive = true;
			enemies[i].Speed = 500.0f;
			enemies[i].alreadyPoint = false;
			enemies[i].EnColor = RED;
		}
	}

	void MoveEnemy()
	{
		for (int i = 0; i < MaxEnemies; i++)
		{
			enemies[i].rec.x = enemies[i].rec.x - enemies[i].Speed * GetFrameTime();
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
			if (enemies[i].rec.x <= 0 - enemies[i].rec.width)
			{
				for (int j = 0; j < MaxEnemies; j++)
				{
					while ((enemies[j].rec.width + enemies[j].rec.width / 2 >= enemies[i].rec.x - enemies[i].rec.width / 2 &&
						((enemies[j].rec.y + enemies[j].rec.height / 2 >= enemies[i].rec.y - enemies[i].rec.height / 2 &&
							enemies[j].rec.y - enemies[j].rec.height / 2 <= enemies[i].rec.y - enemies[i].rec.height / 2) ||
							(enemies[j].rec.y - enemies[j].rec.height / 2 <= enemies[i].rec.y + enemies[i].rec.height / 2 &&
								enemies[j].rec.y + enemies[j].rec.height / 2 >= enemies[i].rec.y + enemies[i].rec.height / 2))) &&
						j != i
						)
					{
						enemies[i].rec.x = screenWidth + GetRandomValue(0, enemies[i].rec.width * 2);
						enemies[i].rec.y = GetRandomValue(screenHeight / 6 + enemies[i].rec.height, screenHeight - (screenHeight / 6) - enemies[i].rec.height);
						enemies[i].alreadyPoint = false;
						enemies[i].EnColor = RED;
					}


				}

			}
			if (enemies[0].rec.x <= 0 - enemies[0].rec.width)
			{
				enemies[0].rec.x = screenWidth + GetRandomValue(0, enemies[i].rec.width * 2);
				enemies[0].rec.y = screenHeight - 20;
				enemies[0].alreadyPoint = false;
				enemies[0].EnColor = GREEN;
			}
		}
	}
}