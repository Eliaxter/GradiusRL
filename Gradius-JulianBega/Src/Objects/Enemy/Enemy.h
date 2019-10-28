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
		bool alreadyPoint = false;
		Color EnColor = RED;
	};
	extern const int MaxEnemies;
	extern int TotalEnemies;
	extern Enemy Enemies[20];

	Enemy InitEnemy(int posX, int posY, int width, int height);
	void MoveEnemy();
	void UpdateEnemy();
	//void CheckBulletColission(Enemy &enemy);
	void CheckOutOfScreen();
}
#endif

