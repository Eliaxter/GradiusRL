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
		if ((player.position.y - player.size.y / 2) <= 0) player.position.y = player.size.y / 2;
		if (IsKeyDown('S')) player.position.y += player.speed  * GetFrameTime();
		if ((player.position.y + player.size.y / 2) >= screenHeight) player.position.y = screenHeight - player.size.y / 2;
	}
	void CheckCollisionWithEnemies()
	{
	}
}