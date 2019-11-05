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
	extern Bullet bullets;

	void InitBullet();
	void MoveBullet();
	void CheckBulletOutOfScreen();
	void CollisionBulletEnemy();
}
#endif