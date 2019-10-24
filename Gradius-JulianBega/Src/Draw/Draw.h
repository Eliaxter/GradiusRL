#ifndef DRAW_H
#define DRAW_H

#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"

namespace RlGraJB
{
	void DrawGame(Player &player1);
	void BackGroundDraw(int InitPoint);
	void DrawMenu(bool play, bool exit);
}
#endif
