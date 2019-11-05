#include "Draw.h"
#include "raylib.h"
#include "Screens/Menu.h"
#include "Screens/GamePlay.h"
#include "Global/Global.h"
#include "Animation/Animations.h"
#include "Objects/Bullets/Bullet.h"
#include "Objects/Bullets/BulletEnemy.h"
#include "Objects/Bullets/Bomb.h"
#include <iostream>
namespace RlGraJB
{
	void DrawGame(Texture2D tank, Texture2D tank2)
	{
		ClearBackground(GRAY);

		if (!gameOver)
		{
			DrawRectangle(player.rec.x, player.rec.y + player.rec.height / (2 / 5), player.rec.width, player.rec.height, BLUE);

			for (int i = 0; i < MaxEnemies; i++)
			{
				DrawRectangle(enemies[i].rec.x - enemies[i].rec.width / 2, enemies[i].rec.y - enemies[i].rec.height / 2, enemies[i].rec.width, enemies[i].rec.height, enemies[i].EnColor);
			}
			if (tankAnimationTimer <= 1)
			{
				DrawTexture(tank, player.rec.x - player.rec.width / 2, player.rec.y - player.rec.height, WHITE);

			}
			if (tankAnimationTimer >= 1)
			{
				DrawTexture(tank2, player.rec.x - player.rec.width / 2, player.rec.y - player.rec.height, WHITE);
				if (tankAnimationTimer >= 2)
				{
					tankAnimationTimer = 0;
				}
			}
			if (bullets.Alive == true)
			{
				DrawBullet();
			}
			if (bomb.Alive == true)
			{
				DrawBomb();
			}
			if (enemyBullet.Alive == true)
			{

				DrawBulletEnemy();

			}
			DrawText(TextFormat("Points: %i", player.points), MeasureText("Points: %i", 40) / 2, 0 + 30, 20, WHITE);
			DrawText(TextFormat("Lifes: %i", player.life), MeasureText("Lifes: %i", 40) * 2, 0 + 30, 20, WHITE);
			DrawText(TextFormat("Bullets: %i", player.bullets), MeasureText("Bullets: %i", 40) * 3, 0 + 30, 20, WHITE);

			if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
		}
		else DrawText("PRESS [ENTER] TO PLAY AGAIN", screenWidth / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, screenHeight / 2 - 50, 20, GRAY);
	}



	void DrawMenu(bool play, bool exit)
	{
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
	}

	void BackGroundDraw(int InitPoint)
	{
		DrawRectangle(0, 0, screenWidth, screenHeight / 6, BROWN);
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
		ClearBackground(WHITE);

		DrawText("Press M to go to menu", screenWidth / 2 - MeasureText("Press M to go to menu", 40) / 2, screenHeight / 2 - 120, 30, BLACK);
		DrawText("Press Esc to leave the game", screenWidth / 2 - MeasureText("Press Esc to leave the game", 40) / 2, screenHeight / 2 - 40, 30, BLACK);
		DrawText("Game created by Julian Bega", screenWidth / 2 - MeasureText("Game created by Julian Bega", 40) / 2, screenHeight / 2 + 80, 30, BLACK);
		DrawText("Tank created by Joaquin Italiano", screenWidth / 2 - MeasureText("Tank created by Joaquin Italiano", 40) / 2, screenHeight / 2 + 120, 30, BLACK);
	}

	void DrawBullet()
	{

		DrawRectangle(static_cast<int>(bullets.rec.x), static_cast<int>(bullets.rec.y), static_cast<int>(bullets.rec.width), static_cast<int>(bullets.rec.height), BLACK);

	}

	void DrawBomb()
	{
		DrawRectangle(static_cast<int>(bomb.rec.x), static_cast<int>(bomb.rec.y), static_cast<int>(bomb.rec.width), static_cast<int>(bomb.rec.height), BLACK);
	}

	void DrawBulletEnemy()
	{
		DrawRectangle(static_cast<int>(enemyBullet.rec.x), static_cast<int>(enemyBullet.rec.y), static_cast<int>(enemyBullet.rec.width), static_cast<int>(enemyBullet.rec.height), BLACK);
	}

}