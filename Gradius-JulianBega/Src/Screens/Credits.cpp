#include "Credits.h"
#include "Draw/Draw.h"
#include "GamePlay.h"
#include "Objects/Player/Player.h"

namespace RlGraJB
{
	void UpdateCredits(Player &player)
	{
		DrawCredits();
		if (IsKeyPressed('M'))
		{
			InitGame(player);
			ActualScreen = MENUSCREEN;
		}
	}
}