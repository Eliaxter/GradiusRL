#include "Animations.h"
#include "Draw/Draw.h"
#include "raylib.h"
#include "Global/Loop.h"


namespace RlGraJB
{
	void TankAnimationUpdate(int framesCounter, int framesSpeed, int currentFrame, Rectangle frameRec, Texture2D tank)
	{
		DrawTank(framesCounter, framesSpeed, currentFrame, frameRec, tank);
	}

}

