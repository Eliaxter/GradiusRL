#include "GamePlay.h"


#include "Global/Global.h"


namespace RlGraJB
{

	void StartGame()
	{
		InitWindow(screenWidth, screenHeight, "sample game: Gradius");
		SetTargetFPS(60);
		Player player1;
		Player player2;
		int currentScreen = 1;
		InitGame(player1, player2); //(player1, player2, ball, currentScreen)

		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			// Update and Draw
			//----------------------------------------------------------------------------------
			UpdateDrawFrame(player1, player2);
			//----------------------------------------------------------------------------------
		}
		//UnloadGame();         // Unload loaded data (textures, sounds, models...)

		CloseWindow();
	}

	void InitGame(Player &player1, Player &player2)
	{
		player1 = InitPlayer(screenWidth / 2, screenHeight * 7 / 8, screenWidth / 10, 20); ///////////// Cambiar a statics como playerwith, etc

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
				if (IsKeyDown(KEY_LEFT)) player1.position.x -= 5;
				if ((player1.position.x - player1.size.x / 2) <= 0) player1.position.x = player1.size.x / 2;
				if (IsKeyDown(KEY_RIGHT)) player1.position.x += 5;
				if ((player1.position.x + player1.size.x / 2) >= screenWidth) player1.position.x = screenWidth - player1.size.x / 2;
				
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