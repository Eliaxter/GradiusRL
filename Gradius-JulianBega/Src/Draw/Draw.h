#ifndef DRAW_H
#define DRAW_H

#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"

namespace RlGraJB
{
	void DrawGame(Texture2D tank, Texture2D tank2);
	void BackGroundDraw(int InitPoint);
	void DrawMenu(bool play, bool exit);
	void DrawCredits();
	void DrawBullet();
	void DrawBomb();
	void DrawBulletEnemy();
}
#endif
