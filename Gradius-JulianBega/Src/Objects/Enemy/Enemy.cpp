#include "Enemy.h"

namespace RlGraJB
{

	Enemy InitEnemy(int posX, int posY, int width, int height)
	{
		Enemy enemy;
		enemy.position.x = posX;
		enemy.position.y = posY;
		enemy.size.x = width;
		enemy.size.y = height;
		return enemy;
	}

}