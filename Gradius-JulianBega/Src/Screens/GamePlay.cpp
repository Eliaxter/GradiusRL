#include "GamePlay.h"
#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"
#include "Objects/Bullets/Bullet.h"
#include "Draw/Draw.h"
#include "Global/Global.h"
#include "Animation/Animations.h"


namespace RlGraJB
{
	void InitGame(Player &player1)
	{
		player1 = InitPlayer(60, screenHeight * 7 / 8, screenWidth / 20, 30); ///////////// Cambiar a statics como playerwith, etc

		actualBackGroundPos = 0;

		for (int i = 1; i < MaxEnemies ; i++)
		{
			Enemies[i] = InitEnemy(GetRandomValue(screenWidth, screenWidth * 2), GetRandomValue(screenHeight / 6, screenHeight - screenHeight / 6), 50, 20, RED);
			Enemies[0] = InitEnemy(GetRandomValue(screenWidth, screenWidth * 2), screenHeight - 20, 50, 20, GREEN);
		}

		InitBullet(player1.position.x, player1.position.y, 10, 10, false, false);

	}

	void UpdateGame(Player &player1, Texture2D tank, Texture2D tank2)
	{
		if (!gameOver)
		{
			DrawGame(player1, tank, tank2);
			MovePlayer(player1);
			UpdateEnemy();
			UpdateBackGround(actualBackGroundPos, 0);
			UpdateBackGround(actualBackGroundPos2, screenWidth);
			CheckCollisionWithEnemies(player1);
			CheckPoint(player1);
			CheckBulletOutOfScreen();
			for (int i = 0; i < MaxBullets; i++)
			{
				if (bullets[i].Alive == true)
				{
					MoveBullet();
				}
			}
			tankAnimationTimer += GetFrameTime();
			if (IsKeyPressed(KEY_SPACE))
			{
				bullets[player1.bullets].Alive = true;
				//player1.bullets--;
				Shoot(player1);
			}

			if (player1.life <= 0)
			{
				ActualScreen = CREDITSSCREEN;

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
		//DrawBullet();
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