#include "Draw.h"

#include "Screens/Menu.h"
#include "Screens/GamePlay.h"
#include "Global/Global.h"

namespace RlGraJB
{
	void DrawGame(Player &player1, Player &player2)
	{
		BeginDrawing();

		ClearBackground(GREEN);

		if (!gameOver)
		{
			// Draw player bar
			DrawRectangle(player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y / 2, player1.size.x, player1.size.y, BLACK);
		

			if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
		}
		else DrawText("PRESS [ENTER] TO PLAY AGAIN", screenWidth / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, screenHeight / 2 - 50, 20, GRAY);

		EndDrawing();
	}

	void UpdateDrawFrame(Player &player1, Player &player2)
	{
		UpdateGame(player1, player2);
		DrawGame(player1, player2);
	}

}