#include "BulletEnemy.h"
#include "Objects/Enemy/Enemy.h"
#include "Global/Global.h"

#include "raylib.h"

namespace RlGraJB 
{
	BulletEnemy enemyBullet;

	void InitEnemyBullet() 
	{
		for (int i = 1; i < MaxEnemies; i++)
		{
			enemyBullet.rec.x = enemies[0].rec.x;
			enemyBullet.rec.y = enemies[0].rec.y;
			enemyBullet.rec.width = 20.0f;
			enemyBullet.rec.height = 20.0f;
			enemyBullet.Alive = false;
		}
		
	}

	void ActiveBulletEnemy()
	{
		if (time / static_cast<int>(GetFPS()) > 10.0f)
		{
			enemyBullet.Alive = true;
		}
	}

	void MoveBulletsEnemy() 
	{
		if (enemyBullet.Alive == true)
		{
			enemyBullet.rec.x += bulletSpeed * GetFrameTime();
			enemyBullet.rec.y -= bulletSpeed * GetFrameTime();
		}
	}

	void CheckBulletEnemyOutOfScreen()
	{
		if (enemyBullet.Alive == true)
		{
			if (enemyBullet.rec.x <= screenWidth)
			{
				InitEnemyBullet();
			}
		}
	}
}