#include "GamePlay.h"
#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"
#include "Draw/Draw.h"
#include "Global/Global.h"


namespace RlGraJB 
{


	void InitGame(Player &player1)
	{
		player1 = InitPlayer(60 , screenHeight * 7 / 8, screenWidth / 15, 20); ///////////// Cambiar a statics como playerwith, etc
		
		actualBackGroundPos = 0;
		
		
		for (int i = 0; i < MaxEnemies; i++)
		{
			Enemies[i] = InitEnemy(GetRandomValue(screenWidth, screenWidth * 2), GetRandomValue(screenHeight/6, screenHeight - screenHeight / 6), 50, 20);
		}
		

		// Initialize bricks
		int initialDownPosition = 50;

		
	}

	void UpdateGame(Player &player1)
	{
		if (!gameOver)
		{
			if (IsKeyPressed('P')) pause = !pause;

			if (!pause)
			{
				DrawGame(player1);
				MovePlayer(player1);
				UpdateEnemy();
				UpdateBackGround(actualBackGroundPos, 0);
				UpdateBackGround(actualBackGroundPos2, screenWidth);
				CheckCollisionWithEnemies(player1);
				CheckPoint(player1);

			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				InitGame(player1);
				gameOver = false;
			}
		}
		
	}

	void UnloadGame()
	{
		// TODO: Unload all dynamic loaded data (textures, sounds, models...)
	}

	void UpdateBackGround(int &backGrowndPos, int InitPoint)
	{
		backGrowndPos = backGrowndPos - backGroundSpeed * GetFrameTime();
		BackGroundDraw(InitPoint);
	}

}