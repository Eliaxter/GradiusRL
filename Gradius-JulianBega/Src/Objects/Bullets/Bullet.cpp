#include "Bullet.h"
#include "Draw/Draw.h"
#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"
#include "Global/Global.h"

#include "raylib.h"

namespace RlGraJB
{
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