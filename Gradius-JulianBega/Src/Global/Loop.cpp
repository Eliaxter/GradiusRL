#include "Loop.h"
#include "raylib.h"
#include "Screens/GamePlay.h"
#include "Objects/Player/Player.h"
#include "Objects/Enemy/Enemy.h"
#include "Global/Global.h"
#include "Screens/Credits.h"
#include "Screens/Menu.h"
#include "Draw/Draw.h"

namespace RlGraJB
{
	void StartGame()
	{
		
		InitWindow(screenWidth, screenHeight, "sample game: Gradius");
		SetTargetFPS(60);
		HideCursor();
		Player player1;
		
		

		Enemies[MaxEnemies];
		int currentScreen = 1;

		InitGame(player1); 
	   	
		while (ActualScreen != ENDING && !WindowShouldClose())    
		{
			switch (ActualScreen)
			{
			case MENUSCREEN:
				UpdateMenu();
				break;

			case GAMEPLAYSCREEN:
				UpdateGame(player1);
				
				break;
				
			case GAMEOVERSCREEN:

				break;

			case CREDITSSCREEN:

				break;
			
			case ENDING:
			
				break;

			default:
				break;
			}
			
			// Update and Draw
			//----------------------------------------------------------------------------------
			
			//----------------------------------------------------------------------------------
		}
		//UnloadGame();         // Unload loaded data (textures, sounds, models...)

		CloseWindow();
	}
}