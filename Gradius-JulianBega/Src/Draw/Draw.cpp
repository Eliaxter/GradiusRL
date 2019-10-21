#include "Draw.h"
#include "raylib.h"
#include "Screens/Menu.h"
#include "Screens/GamePlay.h"
#include "Global/Global.h"

namespace RlGraJB
{
	void DrawGame(Player &player1, Player &player2, Enemy &enemy)
	{
		BeginDrawing();

		ClearBackground(GREEN);

		if (!gameOver)
		{
			// Draw player bar
			DrawRectangle(player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y / 2, player1.size.x, player1.size.y, BLACK);

			DrawRectangle(enemy.position.x - enemy.size.x / 2, enemy.position.y - enemy.size.y / 2, enemy.size.x, enemy.size.y, RED);
			for (int i = 0; i < MaxEnemies; i++)
			{
				DrawRectangle(Enemies[i].position.x - Enemies[i].size.x / 2, Enemies[i].position.y - Enemies[i].size.y / 2, Enemies[i].size.x, Enemies[i].size.y, RED);
			}
		

			if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
		}
		else DrawText("PRESS [ENTER] TO PLAY AGAIN", screenWidth / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, screenHeight / 2 - 50, 20, GRAY);

		EndDrawing();
	}

	void UpdateDrawFrame(Player &player1, Player &player2, Enemy &enemy)
	{
		UpdateGame(player1, player2, enemy);
		DrawGame(player1, player2,enemy);
	}

	void DrawMenu(bool play, bool exit)
	{
		BeginDrawing();

		ClearBackground(GREEN);

		if (play)
		{
			DrawText("PLAY", screenWidth / 2 - MeasureText("PLAY", 40) / 2, screenHeight / 2 - 40, 40, YELLOW);
			DrawText("EXIT", screenWidth / 2 - MeasureText("PLAY", 40) / 2, screenHeight / 2 + 40, 40, GRAY);
		}	
		else if (exit)
		{
			DrawText("PLAY", screenWidth / 2 - MeasureText("PLAY", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
			DrawText("EXIT", screenWidth / 2 - MeasureText("PLAY", 40) / 2, screenHeight / 2 + 40, 40, YELLOW);
		}
		else 
		{
			DrawText("PLAY", screenWidth / 2 - MeasureText("PLAY", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
			DrawText("EXIT", screenWidth / 2 - MeasureText("PLAY", 40) / 2, screenHeight / 2 + 40, 40, GRAY);
		}
		EndDrawing();
	}

}