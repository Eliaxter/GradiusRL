#include "Player.h"
#include "Global/Global.h"
#include "Objects/Bullets/Bullet.h"
#include "Objects/Enemy/Enemy.h"
#include "Draw/Draw.h"
#include "raylib.h"

namespace RlGraJB
{
	Player player;

	void InitPlayer()
	{
		player.rec.x = 60.0f;
		player.rec.y = screenHeight * 7 / 8;
		player.rec.width = 40.0f;
		player.rec.height = 30.0f;
		player.life = PLAYER_MAX_LIFE;
		player.speed = PLAYER_REGULAR_SPEED;
		player.points = 0;
		player.bullets = 5;
	}
	void MovePlayer()
	{
		if (IsKeyDown(KEY_W)) player.rec.y -= player.speed  * GetFrameTime();
		if ((player.rec.y - player.rec.height/ 2) <= 0 + screenHeight / 6) player.rec.y = player.rec.height / 2 + screenHeight / 6;
		if (IsKeyDown(KEY_S)) player.rec.y += player.speed  * GetFrameTime();
		if ((player.rec.y + player.rec.height / 2) >= screenHeight - screenHeight / 6) player.rec.y = screenHeight - screenHeight / 6 - player.rec.height / 2;
	}
	void CheckCollisionWithEnemies()
	{
		for (int i = 0; i < TotalEnemies; i++)
		{
			if (player.rec.x + player.rec.width / 2 >= enemies[i].rec.x - enemies[i].rec.width / 2 &&
				((player.rec.y + player.rec.height / 2 >= enemies[i].rec.y - enemies[i].rec.height / 2 &&
					player.rec.y - player.rec.height / 2 <= enemies[i].rec.y - enemies[i].rec.height / 2) ||
					(player.rec.y - player.rec.height / 2 <= enemies[i].rec.y + enemies[i].rec.height / 2 &&
						player.rec.y + player.rec.height / 2 >= enemies[i].rec.y + enemies[i].rec.height / 2)))
			{
				if (enemies[i].alreadyPoint == false)
				{
					player.points - 10;
					enemies[i].alreadyPoint = true;
					enemies[i].EnColor = BLUE;
					player.life--;
				}
			}
		}

	}

	void CheckPoint()
	{
		for (int i = 0; i < TotalEnemies; i++)
		{

			if (player.rec.x - player.rec.width / 2 >= enemies[i].rec.x + enemies[i].rec.width / 2)
			{
				if (enemies[i].alreadyPoint == false)
				{
					player.points++;
					enemies[i].alreadyPoint = true;
				}
			}
		}
	}

	void Shoot()
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			for (int i = 0; i < MaxBullets; i++)
			{
				bullets[i].Alive = true;
			}
		}
	}
}