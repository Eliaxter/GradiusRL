#include "Bomb.h"
#include "Global/Global.h"
#include "Objects/Player/Player.h"

#include "raylib.h"

namespace RlGraJB 
{
	Bomb bomb;

	static float speedBomb = 200.0f;

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
}