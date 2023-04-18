#include "Player.h"
#include "Obstacle.h"
#include "Breakable.h"



void Player::Move(Vector2 dir)
{
	//Screen boundaries
	const float offset = 25.f;
	if (GetPosition().x + dir.x > 25.f && GetPosition().x + dir.x + shape.width < SCREEN_X - offset)
	{
		shape.x += dir.x * movSpeed * GetFrameTime();
	}
	
}

void Player::OnOverlap(Actor* collidedActor)
{
	if (!collidedActor)
		return;

	collidedActor->shape.y = 0;
	ui->DecreaseScore();

	if (Breakable* br = dynamic_cast<Breakable*>(collidedActor))
	{
		br->shape.y = 0;
		LOG(isSmashing);
	}
}