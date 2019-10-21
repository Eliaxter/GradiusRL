#ifndef DRAW_H
#define DRAW_H

#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"

namespace RlGraJB
{
	void DrawGame(Player &player1, Player &player2, Enemy &enemy);
	void UpdateDrawFrame(Player &player1, Player &player2, Enemy &enemy);
	void DrawMenu(bool play, bool exit);
}
#endif
