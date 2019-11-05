#ifndef BOMB_H
#define BOMB_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlGraJB
{
	struct Bomb {
		Rectangle rec;
		bool Alive;
		bool alreadyKill;
	};
	extern Bomb bomb;

	void InitBomb();
	void MoveBomb();
	void CheckBombOutOfScreen();
	void CollisionBombEnemy();
}
#endif