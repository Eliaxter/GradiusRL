#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

#include "Menu.h"


namespace RlGraJB
{
	const int pointsToWin = 2;


	void InitGame(Player &player1, Player &player2);
	void StartGame();
	void UpdateGame(Player &player1, Player &player2);
	void UnloadGame(Player &player1, Player &player2);


}

#endif