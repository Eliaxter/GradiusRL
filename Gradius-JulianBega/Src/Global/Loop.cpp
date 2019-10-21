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
		Player player1;
		Player player2;
		Enemies[MaxEnemies];
		Enemy enemy1;
		int currentScreen = 1;
		InitGame(player1, player2, enemy1); 

		while (ActualScreen != ENDING)    
		{
			switch (ActualScreen)
			{
			case MENUSCREEN:
				UpdateMenu();
				break;

			case GAMEPLAYSCREEN:
				UpdateDrawFrame(player1, player2, enemy1);
				UpdateEnemy(enemy1);
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