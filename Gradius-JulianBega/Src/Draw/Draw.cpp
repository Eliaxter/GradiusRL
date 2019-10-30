#include "Draw.h"
#include "raylib.h"
#include "Screens/Menu.h"
#include "Screens/GamePlay.h"
#include "Global/Global.h"
#include "Animation/Animations.h"
#include "Objects/Bullets/Bullet.h"

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
			if (tankAnimationTimer <= 1)
			{
				DrawTexture(tank, player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y, WHITE);
				
			}
			if (tankAnimationTimer >= 1)
			{
				DrawTexture(tank2, player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y, WHITE);
				if (tankAnimationTimer >= 2)
				{
					tankAnimationTimer = 0;
				}
			}
			DrawBullet();
			DrawText(TextFormat("Points: %i", player1.points), MeasureText("Points: %i", 40) / 2, 0 + 30, 20, WHITE);
			DrawText(TextFormat("Lifes: %i", player1.life), MeasureText("Lifes: %i", 40) * 2, 0 + 30, 20, WHITE);
			DrawText(TextFormat("Bullets: %i", player1.bullets), MeasureText("Bullets: %i", 40) * 3, 0 + 30, 20, WHITE);
			
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

	void DrawCredits()
	{
		BeginDrawing();

		ClearBackground(WHITE);

		
			DrawText("Press M to go to menu", screenWidth / 2 - MeasureText("Press M to go to menu", 40) / 2, screenHeight / 2 - 120, 30, BLACK);
			DrawText("Press Esc to leave the game", screenWidth / 2 - MeasureText("Press Esc to leave the game", 40) / 2, screenHeight / 2 - 40, 30, BLACK);
			DrawText("Game created by Julian Bega", screenWidth / 2 - MeasureText("Game created by Julian Bega", 40) / 2, screenHeight / 2 + 80, 30, BLACK);
			DrawText("Tank created by Joaquin Italiano", screenWidth / 2 - MeasureText("Tank created by Joaquin Italiano", 40) / 2, screenHeight / 2 + 120, 30, BLACK);
		
		EndDrawing();
	}

	void DrawBullet()
	{
		for (int i = 0; i < MaxBullets; i++)
		{
			if (bullets[i].Alive == true)
			{ 
				DrawRectangle(bullets[i].rec.x, bullets[i].rec.y + bullets[i].rec.y / (2 / 5), bullets[i].rec.width, bullets[i].rec.height, BLACK);
			}

		}
	}


}