#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{
	struct Enemy {
		Rectangle rec;
		bool Alive = true;
		float Speed;
		bool alreadyPoint = false;
		Color EnColor = RED;
	};
	extern const int MaxEnemies;
	extern int TotalEnemies;
	extern const int MaxEnemies;
	extern Enemy enemies[20];

	void InitEnemy();

	void MoveEnemy();
	void UpdateEnemy();
	//void CheckBulletColission(Enemy &enemy);
	void CheckOutOfScreen();
}
#endif

