#include "Credits.h"
#include "Draw/Draw.h"
#include "GamePlay.h"
#include "Objects/Player/Player.h"

namespace RlGraJB
{
	void UpdateCredits()
	{
		DrawCredits();
		if (IsKeyPressed('M'))
		{
			InitGame();
			ActualScreen = MENUSCREEN;
		}
	}
}