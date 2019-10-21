#include "Enemy.h"

namespace RlGraJB
{
	extern const int MaxEnemies = 20;
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

	void MoveEnemy(Enemy &enemy)
	{
		enemy.position.x = enemy.position.x  - enemy.Speed * GetFrameTime();
		for (int i = 0; i < MaxEnemies; i++)
		{
			Enemies[i].position.x = Enemies[i].position.x - Enemies[i].Speed * GetFrameTime();
		}
	}

	void UpdateEnemy(Enemy &enemy)
	{
		if (enemy.Alive)
		{
			MoveEnemy(enemy);
			CheckOutOfScreen(enemy);
			//CheckBulletColission(enemy);
		}
	}

	void CheckOutOfScreen(Enemy &enemy)
	{
		if (enemy.position.x <= 0 - enemy.size.x)
		{
			enemy.position.x = screenWidth;
			enemy.position.y = GetRandomValue(0 + enemy.size.y, screenHeight-enemy.size.y);

			
		}
		for (int i = 0; i < MaxEnemies; i++)
		{
			if (Enemies[i].position.x <= 0 - Enemies[i].size.x)
			{
				Enemies[i].position.x = screenWidth + GetRandomValue(0, enemy.size.x*2);
				Enemies[i].position.y = GetRandomValue(0 + Enemies[i].size.y, screenHeight - Enemies[i].size.y);
			}
		}
	}
}