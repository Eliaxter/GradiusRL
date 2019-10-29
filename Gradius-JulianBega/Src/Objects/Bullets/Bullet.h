#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{

	struct Bullet {
		Vector2 position;
		Vector2 size;
		bool Alive = false;
		float Speed = 500;
		bool alreadyKill = false;
		Color BuColor = BROWN;
	};
	extern const int MaxBullets;
	extern Bullet bullets[5];

	Bullet InitBullet(int posX, int posY, int width, int height);
	void MoveBullet();
	void UpdateBullet();
	//void CheckBulletColission(Enemy &enemy);
	void CheckBulletOutOfScreen();
}
#endif