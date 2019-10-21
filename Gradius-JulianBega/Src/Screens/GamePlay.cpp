#include "GamePlay.h"


#include "Global/Global.h"


namespace RlGraJB
{


	void InitGame(Player &player1, Player &player2)
	{
		player1 = InitPlayer(60 , screenHeight * 7 / 8, screenWidth / 10, 20); ///////////// Cambiar a statics como playerwith, etc

		player2 = InitPlayer(1, 1, 80, 20); ///////////// 
		// Initialize ball

		

		// Initialize bricks
		int initialDownPosition = 50;

		
	}

	void UpdateGame(Player &player1, Player &player2)
	{
		if (!gameOver)
		{
			if (IsKeyPressed('P')) pause = !pause;

			if (!pause)
			{
				// Player movement logic
				if (IsKeyDown('W')) player1.position.y -= 5;
				if ((player1.position.y - player1.size.y / 2) <= 0) player1.position.y = player1.size.y/ 2;
				if (IsKeyDown('S')) player1.position.y += 5;
				if ((player1.position.y + player1.size.y / 2) >= screenHeight) player1.position.y = screenHeight - player1.size.y / 2;
				
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				InitGame(player1, player2);
				gameOver = false;
			}
		}
	}

	void UnloadGame()
	{
		// TODO: Unload all dynamic loaded data (textures, sounds, models...)
	}

}