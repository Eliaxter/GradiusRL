#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{
	struct Enemy {
		Vector2 position;
		Vector2 size;
	};

	Enemy InitEnemy(int posX, int posY, int width, int height);
	void MoveEnemy();
}
#endif

