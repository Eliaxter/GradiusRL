#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include "Objects/Player/Player.h"


namespace RlGraJB
{

	void DrawGame(Player &player1, Player &player2);
	void UpdateDrawFrame(Player &player1, Player &player2);

}
#endif
