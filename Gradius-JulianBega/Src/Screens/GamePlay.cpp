#include "GamePlay.h"
#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"
#include "Draw/Draw.h"
#include "Global/Global.h"


namespace RlGraJB 
{


	void InitGame(Player &player1)
	{
		player1 = InitPlayer(60 , screenHeight * 7 / 8, screenWidth / 10, 20); ///////////// Cambiar a statics como playerwith, etc

		
		
		for (int i = 0; i < MaxEnemies; i++)
		{
			Enemies[i] = InitEnemy(GetRandomValue(screenWidth, screenWidth + screenWidth/2), GetRandomValue(0, screenHeight), 50, 20);
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
				CheckCollisionWithEnemies(player1);
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

}