#ifndef BULLETENEMY_H
#define BULLETENEMY_H
#include "raylib.h"

namespace RlGraJB
{
	struct BulletEnemy {
		Rectangle rec;
		bool Alive;
		bool alreadyKill;
	};
	extern BulletEnemy enemyBullet;

	void InitEnemyBullet();
	void ActiveBulletEnemy();
	void MoveBulletsEnemy();
	void CheckBulletEnemyOutOfScreen();
}

#endif