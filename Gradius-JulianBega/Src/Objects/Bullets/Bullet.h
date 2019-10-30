#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{

	struct Bullet {
		Rectangle rec;
		bool Alive;
		bool alreadyKill;
	};
	extern const int MaxBullets;
	extern Bullet bullets[5];

	void InitBullet(int posX, int posY, int width, int height, bool alive, bool alreadyKill);
	void MoveBullet();
	void UpdateBullet();
	//void CheckBulletColission(Enemy &enemy);
	void CheckBulletOutOfScreen();
}
#endif