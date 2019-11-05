#include "Bomb.h"
#include "Global/Global.h"
#include "Objects/Player/Player.h"

#include "raylib.h"

namespace RlGraJB
{
	Bomb bomb;

	static float speedBomb = 100.0f;

	void InitBomb()
	{
		bomb.rec.x = player.rec.x;
		bomb.rec.y = player.rec.y;
		bomb.rec.width = 20.0f;
		bomb.rec.height = 20.0f;
		bomb.Alive = false;
	}

	void MoveBomb()
	{
		bomb.rec.y += speedBomb * GetFrameTime();
	}

	void CheckBombOutOfScreen()
	{
		if (bomb.Alive == true)
		{
			if (bomb.rec.y >= screenHeight)
			{
				InitBomb();
			}
		}
	}

	void CollisionBombEnemy()
	{
		if (CheckCollisionRecs(bomb.rec, enemies[0].rec))
		{
			enemies[0].rec.x = -500.0f;
			enemies[0].rec.y = -500.0f;
		}

	}
}