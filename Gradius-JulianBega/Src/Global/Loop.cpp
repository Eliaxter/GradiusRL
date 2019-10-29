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

		Image tank = LoadImage("../Res/Assets/Tank1.png");
		ImageResize(&tank, 96 , 61);
		Texture2D tanke = LoadTextureFromImage(tank);
		Image tank2 = LoadImage("../Res/Assets/Tank2.png");
		ImageResize(&tank2, 96, 61);
		Texture2D tanke2 = LoadTextureFromImage(tank2);

		UnloadImage(tank);
		UnloadImage(tank2);
	   	
		while (ActualScreen != ENDING && !WindowShouldClose())    
		{
			switch (ActualScreen)
			{
			case MENUSCREEN:
				UpdateMenu();
				break;

			case GAMEPLAYSCREEN:
				UpdateGame(player1, tanke, tanke2);
				
				break;
				
			case GAMEOVERSCREEN:

				break;

			case CREDITSSCREEN:
				UpdateCredits(player1);
				break;
			
			case ENDING:
			
				break;

			default:
				break;
			}	
			
		}
		UnloadTexture(tanke);
		UnloadTexture(tanke2);
		CloseWindow();
	}
}