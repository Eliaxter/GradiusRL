#include "Draw.h"
#include "raylib.h"
#include "Screens/Menu.h"
#include "Screens/GamePlay.h"
#include "Global/Global.h"
#include "Animation/Animations.h"

namespace RlGraJB
{
	void DrawGame(Player &player1, Texture2D tank, Texture2D tank2)
	{
		BeginDrawing();

		ClearBackground(GRAY);

		if (!gameOver)
		{
			
			// Draw player bar
			DrawRectangle(player1.position.x, player1.position.y + player1.size.y/(2/5) , player1.size.x, player1.size.y, BLUE);
			
			for (int i = 0; i < MaxEnemies; i++)
			{
				DrawRectangle(Enemies[i].position.x - Enemies[i].size.x / 2, Enemies[i].position.y - Enemies[i].size.y / 2, Enemies[i].size.x, Enemies[i].size.y, Enemies[i].EnColor);
			}
			if (animationTemporal == false)
			{
				DrawTexture(tank, player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y, WHITE);
				animationTemporal = true;
			}
			if (animationTemporal == true)
			{
				DrawTexture(tank2, player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y, WHITE);
				animationTemporal = false;
			}
			
			DrawText(TextFormat("Points: %i", player1.points), MeasureText("Points: %i", 40) / 2, 0 + 30, 20, GRAY);
			
			if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
		}
		else DrawText("PRESS [ENTER] TO PLAY AGAIN", screenWidth / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, screenHeight / 2 - 50, 20, GRAY);

		EndDrawing();
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

	void BackGroundDraw(int InitPoint)
	{
		DrawRectangle(0, 0, screenWidth, screenHeight/6, BROWN);
		DrawRectangle(0, screenHeight - screenHeight / 6, screenWidth, screenHeight / 6, BROWN);
		for (int i = 0; i < TotalEnemies; i++)
		{
			if (actualBackGroundPos + (i * 75) <= -screenWidth)
			{
				actualBackGroundPos = 0;
			}
			DrawRectangle(actualBackGroundPos + (i * 80) + InitPoint, screenHeight / 2, 50, 20, YELLOW);
		}
		for (int i = 0; i < 9; i++)
		{

			DrawRectangle(GetRandomValue(0, screenWidth), GetRandomValue(0, screenHeight), 3, 2, BROWN);
		}
		
		
		
	}


}