#include "Menu.h"
#include "Draw/Draw.h"
namespace RlGraJB
{
	bool Play = false;
	bool Exit = false;
	void UpdateMenu()
	{
		if (IsKeyDown('W'))
		{
			Play = true;
			Exit = false;
		}
		if (IsKeyDown('S'))
		{
			Exit = true; 
			Play = false;
		}
		if (IsKeyDown(KEY_ENTER))
		{
			if (Play) ActualScreen = 1;
			if (Exit) ActualScreen = 4;
		}
		DrawMenu(Play, Exit);
	}

}