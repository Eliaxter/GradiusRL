#include "Bullet.h"
#include "Draw/Draw.h"
#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"
#include "Global/Global.h"

#include "raylib.h"

namespace RlGraJB
{

	static float bulletSpeed = 500.0f;

	const int MaxBullets = 5;
	Bullet bullets[MaxBullets] = { 0 };
	Bullet enemyBullets[MaxBullets] = { 0 };

	void InitBullet()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			bullets[i].rec.x = player.rec.x;
			bullets[i].rec.y = player.rec.y;
			bullets[i].rec.width= 10.0f;
			bullets[i].rec.height = 10.0f;
			bullets[i].Alive = false;
		}
	}

	void InitEnemyBullet()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			enemyBullets[i].rec.x = enemies[0].rec.x;
			enemyBullets[i].rec.y = enemies[0].rec.y;
			enemyBullets[i].rec.width = 10.0f;
			enemyBullets[i].rec.height = 10.0f;
			enemyBullets[i].Alive = false;
		}
	}

	void MoveBullet()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			bullets[i].rec.x += bulletSpeed * GetFrameTime();
		}
	}

	void MoveBulletDown()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			bullets[i].rec.y += bulletSpeed * GetFrameTime();
		}
	}

	void ActiveBulletEnemy()
	{
		if (time / static_cast<int>(GetFPS()) > 10)
		{
			for (int i = 0; i < MaxBullets; i++)
			{
				enemyBullets[i].Alive = true;
			}
		}
	}

	void MoveBulletsEnemy()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			if (time / static_cast<int>(GetFPS()) > 10)
			{
				if (enemyBullets[i].Alive == true)
				{
					enemyBullets[i].rec.x += bulletSpeed * GetFrameTime();
					enemyBullets[i].rec.y -= bulletSpeed * GetFrameTime();
				}
			}
			
		}
	}

	void CheckBulletOutOfScreen()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			if (bullets[i].Alive == true)
			{
				if (bullets[i].rec.x >= screenWidth)
				{
					InitBullet();
				}
			}
		}
	}
}