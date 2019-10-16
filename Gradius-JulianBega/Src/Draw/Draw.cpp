#include "Draw.h"

#include "Screens/Menu.h"
#include "Screens/GamePlay.h"
#include "Global/Global.h"

namespace RlGraJB
{
	void DrawGame(Player &player1, Player &player2)
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (!gameOver)
		{
			// Draw player bar
			DrawRectangle(player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y / 2, player1.size.x, player1.size.y, BLACK);

			// Draw player lives
			for (int i = 0; i < player1.life; i++) DrawRectangle(20 + 40 * i, screenHeight - 30, 35, 10, LIGHTGRAY);

			// Draw ball

			// Draw bricks
			

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