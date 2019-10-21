#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{
	
	struct Enemy {
		Vector2 position;
		Vector2 size;
		bool Alive = true;
		float Speed = 500;
	};
	extern const int MaxEnemies;
	extern int TotalEnemies;
	extern Enemy Enemies[20];

	Enemy InitEnemy(int posX, int posY, int width, int height);
	void MoveEnemy(Enemy &enemy);
	void UpdateEnemy(Enemy &enemy);
	//void CheckBulletColission(Enemy &enemy);
	void CheckOutOfScreen(Enemy &enemy);
}
#endif

