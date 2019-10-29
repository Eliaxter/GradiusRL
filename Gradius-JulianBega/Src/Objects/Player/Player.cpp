#include "Player.h"

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
		return player;
	}
	void MovePlayer(Player &player)
	{
		if (IsKeyDown('W')) player.position.y -= player.speed  * GetFrameTime();
		if ((player.position.y - player.size.y / 2) <= 0 + screenHeight / 6) player.position.y = player.size.y / 2 + screenHeight / 6;
		if (IsKeyDown('S')) player.position.y += player.speed  * GetFrameTime();
		if ((player.position.y + player.size.y / 2) >= screenHeight - screenHeight/6) player.position.y = screenHeight - screenHeight / 6 - player.size.y / 2;
	}
	void CheckCollisionWithEnemies(Player &player)
	{
		for (int i = 0; i < TotalEnemies; i++)
		{
			if ( player.position.x + player.size.x / 2 >= Enemies[i].position.x - Enemies[i].size.x/2 &&
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
}