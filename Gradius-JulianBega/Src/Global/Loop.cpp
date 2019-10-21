#include "Loop.h"
#include "raylib.h"
#include "Screens/GamePlay.h"

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
}