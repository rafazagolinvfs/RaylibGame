#include "Player.h"

void Player::Move(Vector2 dir)
{
	//Screen boundaries
	/*if (GetPosition().x + dir.x > 0 && GetPosition().x + dir.x + shape.width < SCREEN_X)
	{
		shape.x += dir.x * movSpeed * GetFrameTime();
	}*/

	if (GetPosition().x + dir.x > 25.f && GetPosition().x + dir.x + shape.width < SCREEN_X - 25.f)
	{
		shape.x += dir.x * movSpeed * GetFrameTime();
	}

}
