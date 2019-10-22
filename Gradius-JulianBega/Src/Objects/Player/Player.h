#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Global/Global.h"
#include "Objects/Enemy/Enemy.h"

namespace RlGraJB
{
	const int PLAYER_MAX_LIFE = 5;
	const int PLAYER_REGULAR_SPEED = 300;

	struct Player {
		Vector2 position;
		Vector2 size;
		int life;
		float speed = 0;
	};

	Player InitPlayer(int posX, int posY, int width, int height);
	void MovePlayer(Player &player);
	void CheckCollisionWithEnemies(Player &player);
}
#endif
