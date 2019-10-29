#include "Bullet.h"
#include "Draw/Draw.h"

namespace RlGraJB
{

	extern const int MaxBullets = 5;
	Bullet bullets[MaxBullets] = { 0 };

	Bullet InitBullet(int posX, int posY, int width, int height)
	{
		Bullet bullet;
		bullet.position.x = posX;
		bullet.position.y = posY;
		bullet.size.x = width;
		bullet.size.y = height;
		bullet.BuColor = BROWN;
		return bullet;
	}

	void MoveBullet()
	{

		for (int i = 0; i < MaxBullets; i++)
		{
			if (bullets[i].Alive == true)
			{
				bullets[i].position.x = bullets[i].position.x + bullets[i].Speed * GetFrameTime();
			}
		}
	}

	void UpdateBullet()
	{
		MoveBullet();
		CheckBulletOutOfScreen();
		DrawBullet();
	}

	void CheckBulletOutOfScreen()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			if (bullets[i].Alive == true)
			{
				if (bullets[i].position.x >= screenWidth)
				{
					bullets[i].Alive = false;
				}
			}
		}
	}
}