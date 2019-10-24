#ifndef GLOBAL_H
#define GLOBAL_H

#include "raylib.h"
#include "Objects/Player/Player.h"

namespace RlGraJB
{
	typedef enum GameScreen { MENUSCREEN, GAMEPLAYSCREEN, GAMEOVERSCREEN, CREDITSSCREEN, ENDING } GameScreen;
	extern int screenWidth;
	extern int screenHeight;
	extern int actualBackGroundPos;
	extern int actualBackGroundPos2;
	extern int ActualScreen;


	static bool gameOver = false;
	static bool pause = false;

}


#endif
