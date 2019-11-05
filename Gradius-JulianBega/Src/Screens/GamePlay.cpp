#include "GamePlay.h"
#include "Objects/Enemy/Enemy.h"
#include "Objects/Player/Player.h"
#include "Objects/Bullets/Bullet.h"
#include "Objects/Bullets/BulletEnemy.h"
#include "Objects/Bullets/Bomb.h"
#include "Draw/Draw.h"
#include "Global/Global.h"
#include "Animation/Animations.h"

namespace RlGraJB
{
	void InitGame()
	{
		InitPlayer();

		actualBackGroundPos = 0;

		for (int i = 1; i < MaxEnemies ; i++)
		{
			InitEnemy();
			//enemies[0] = InitEnemy(GetRandomValue(screenWidth, screenWidth * 2), screenHeight - 20, 50, 20, GREEN);
		}

		InitBullet();
		InitBomb();
		InitEnemyBullet();

	}

	void UpdateGame(Texture2D tank, Texture2D tank2)
	{
		if (!gameOver)
		{
			MovePlayer();
			UpdateEnemy();
			UpdateBackGround(actualBackGroundPos, 0);
			UpdateBackGround(actualBackGroundPos2, screenWidth);
			DrawGame(tank, tank2);
			CheckCollisionWithEnemies();
			CheckPoint();
			Shoot();
			CheckBulletOutOfScreen();
			CheckBombOutOfScreen();
			ActiveBulletEnemy();
			CheckBulletEnemyOutOfScreen();
			for (int i = 0;  i < MaxBullets;  i++)
			{
				if (bullets[i].Alive == true)
				{
					MoveBullet();
				}
				if (bomb.Alive == true)
				{
					MoveBomb();
				}
				if (enemyBullet.Alive == true)
				{
					MoveBulletsEnemy();
				}
			}
			tankAnimationTimer += GetFrameTime();
			if (player.life <= 0)
			{
				ActualScreen = CREDITSSCREEN;
			}

		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				InitGame();
				gameOver = false;
			}
		}
	}

	void UpdateBackGround(int &backGrowndPos, int InitPoint)
	{
		backGrowndPos = backGrowndPos - backGroundSpeed * GetFrameTime();
		BackGroundDraw(InitPoint);
	}

}