#include "Bullet.h"
#include "Draw/Draw.h"
#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"
#include "Global/Global.h"

#include "raylib.h"

namespace RlGraJB
{
	Bullet bullets;

	void InitBullet()
	{
		bullets.rec.x = player.rec.x;
		bullets.rec.y = player.rec.y;
		bullets.rec.width= 10.0f;
		bullets.rec.height = 10.0f;
		bullets.Alive = false;
	}

	void MoveBullet()
	{
		bullets.rec.x += bulletSpeed * GetFrameTime();
	}

	void MoveBulletDown()
	{
		bullets.rec.y += bulletSpeed * GetFrameTime();
	}

	void CheckBulletOutOfScreen()
	{
		if (bullets.Alive == true)
		{
			if (bullets.rec.x >= screenWidth)
			{
				InitBullet();
			}
		}
	}

	void CollisionBulletEnemy()
	{
		for (int i = 0; i < MaxEnemies; i++)
		{
			if (CheckCollisionRecs(bullets.rec, enemies[i].rec))
			{
				enemies[i].rec.x = -500.0f;
				enemies[i].rec.y = -500.0f;
			}
		}
		
	}
}