#include "Player.h"

void Player::Move(Vector2 dir)
{
	//Screen boundaries
	if (GetPosition().x + dir.x > 0)
	{
		shape.x += dir.x * movSpeed;
	}
}
