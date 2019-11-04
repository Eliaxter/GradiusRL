#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"


namespace RlGraJB
{
	const int pointsToWin = 2;
	const int backGroundSpeed = 400;

	void InitGame();
	void UpdateGame(Texture2D tank, Texture2D tank2);
	void UpdateBackGround(int &backGrowndPos, int InitPoint);
}

#endif