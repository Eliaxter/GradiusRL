#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"


namespace RlGraJB
{
	const int pointsToWin = 2;


	void InitGame(Player &player1);
	void UpdateGame(Player &player1);
	void UnloadGame();


}

#endif