#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Global/Global.h"
#include "Objects/Enemy/Enemy.h"

namespace RlGraJB
{
	const int PLAYER_MAX_LIFE = 10;
	const int PLAYER_REGULAR_SPEED = 300;

	struct Player {
		Rectangle rec;
		int life;
		float speed = 0;
		int points = 0;
		int bullets = 5;
	};

	extern Player player;

	void InitPlayer();
	void MovePlayer();
	void CheckCollisionWithEnemies();
	void CheckPoint();
	void Shoot();
}
#endif
