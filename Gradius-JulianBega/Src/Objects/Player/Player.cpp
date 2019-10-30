#include "Player.h"
#include "Global/Global.h"
#include "Objects/Bullets/Bullet.h"
#include "Objects/Enemy/Enemy.h"
#include "Draw/Draw.h"
#include "raylib.h"

namespace RlGraJB
{

	Player InitPlayer(int posX, int posY, int width, int height)
	{
		Player player;
		player.position.x = posX;
		player.position.y = posY;
		player.size.x = width;
		player.size.y = height;
		player.life = PLAYER_MAX_LIFE;
		player.speed = PLAYER_REGULAR_SPEED;
		player.points = 0;
		player.bullets = 5;
		return player;
	}
	void MovePlayer(Player &player)
	{
		if (IsKeyDown('W')) player.position.y -= player.speed  * GetFrameTime();
		if ((player.position.y - player.size.y / 2) <= 0 + screenHeight / 6) player.position.y = player.size.y / 2 + screenHeight / 6;
		if (IsKeyDown('S')) player.position.y += player.speed  * GetFrameTime();
		if ((player.position.y + player.size.y / 2) >= screenHeight - screenHeight / 6) player.position.y = screenHeight - screenHeight / 6 - player.size.y / 2;
	}
	void CheckCollisionWithEnemies(Player &player)
	{
		for (int i = 0; i < TotalEnemies; i++)
		{
			if (player.position.x + player.size.x / 2 >= Enemies[i].position.x - Enemies[i].size.x / 2 &&
				((player.position.y + player.size.y / 2 >= Enemies[i].position.y - Enemies[i].size.y / 2 &&
					player.position.y - player.size.y / 2 <= Enemies[i].position.y - Enemies[i].size.y / 2) ||
					(player.position.y - player.size.y / 2 <= Enemies[i].position.y + Enemies[i].size.y / 2 &&
						player.position.y + player.size.y / 2 >= Enemies[i].position.y + Enemies[i].size.y / 2)))
			{
				if (Enemies[i].alreadyPoint == false)
				{
					player.points - 10;
					Enemies[i].alreadyPoint = true;
					Enemies[i].EnColor = BLUE;
					player.life--;
				}
			}
		}

	}

	void CheckPoint(Player &player)
	{
		for (int i = 0; i < TotalEnemies; i++)
		{

			if (player.position.x - player.size.x / 2 >= Enemies[i].position.x + Enemies[i].size.x / 2)
			{
				if (Enemies[i].alreadyPoint == false)
				{
					player.points++;
					Enemies[i].alreadyPoint = true;
				}
			}
		}
	}

	void Shoot(Player &player)
	{
		if (player.bullets >= 1)
		{
			UpdateBullet();
			player.bullets--;
			/*
			for (int i = 0; i < MaxBullets; i++)
			{
				//bullets[i].Alive = true;
				if (bullets[i].Alive == true)
				{
					//bullets[player.bullets - 1] = InitBullet(player.position.x, player.position.y, 10, 10);
					//bullets[player.bullets - 1].Alive = true;
					//player.bullets--;
 					//MoveBullet();
					//DrawBullet();
				}
			} */
			
		}
	}
}