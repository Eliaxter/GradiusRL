#include "GamePlay.h"
#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"

#include "Global/Global.h"


namespace RlGraJB
{


	void InitGame(Player &player1, Player &player2, Enemy &enemy1 )
	{
		player1 = InitPlayer(60 , screenHeight * 7 / 8, screenWidth / 10, 20); ///////////// Cambiar a statics como playerwith, etc

		player2 = InitPlayer(1, 1, 60, 20); ///////////// 
		// Initialize ball
		enemy1 = InitEnemy(screenWidth, GetRandomValue(0, screenHeight), 50, 20);
		for (int i = 0; i < MaxEnemies; i++)
		{
			Enemies[i] = InitEnemy(GetRandomValue(screenWidth, screenWidth + screenWidth/2), GetRandomValue(0, screenHeight), 50, 20);
		}
		

		// Initialize bricks
		int initialDownPosition = 50;

		
	}

	void UpdateGame(Player &player1, Player &player2, Enemy &enemy)
	{
		if (!gameOver)
		{
			if (IsKeyPressed('P')) pause = !pause;

			if (!pause)
			{
				MovePlayer(player1);
				
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				InitGame(player1, player2, enemy);
				gameOver = false;
			}
		}
	}

	void UnloadGame()
	{
		// TODO: Unload all dynamic loaded data (textures, sounds, models...)
	}

}