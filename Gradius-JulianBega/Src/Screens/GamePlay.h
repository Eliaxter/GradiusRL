#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"


namespace RlGraJB
{
	const int pointsToWin = 2;


	void InitGame(Player &player1, Player &player2, Enemy &enemy1);
	void UpdateGame(Player &player1, Player &player2, Enemy &enemy);
	void UnloadGame(Player &player1, Player &player2);


}

#endif