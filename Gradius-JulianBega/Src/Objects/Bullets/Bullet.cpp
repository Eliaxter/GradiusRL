#include "Bullet.h"
#include "Draw/Draw.h"

namespace RlGraJB
{

	static float bulletSpeed = 500.0f;

	const int MaxBullets = 5;
	Bullet bullets[MaxBullets] = { 0 };

	void InitBullet(int posX, int posY, int width, int height, bool alive, bool alreadyKill)
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			bullets[i].rec.x = posX;
			bullets[i].rec.y = posY;
			bullets[i].rec.width= width;
			bullets[i].rec.height = height;
			bullets[i].Alive = alive;
			bullets[i].alreadyKill = alreadyKill;
		}
	}

	void MoveBullet()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			if (bullets[i].Alive == true)
			{
				bullets[i].rec.x += bulletSpeed * GetFrameTime();
			}
		}
	}

	void UpdateBullet()
	{
		CheckBulletOutOfScreen();
		for (int i = 0; i < MaxBullets; i++)
		{
			if (bullets[i].Alive == true)
			{
				MoveBullet();
				DrawBullet();
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
					bullets[i].Alive = false;
				}
			}
		}
	}
}