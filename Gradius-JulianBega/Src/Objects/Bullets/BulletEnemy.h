#ifndef BULLETENEMY_H
#define BULLETENEMY_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{
	struct Bullet {
		Rectangle rec;
		bool Alive;
		bool alreadyKill;
	};
	extern Bullet enemyBullet;

	void InitEnemyBullet();
	void MoveBulletsEnemy();
	void CheckBulletEnemyOutOfScreen();
}

#endif