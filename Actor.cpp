#include "Actor.h"

Actor::Actor()
{
	shape.x = 0.f;
	shape.y = 0.f;
	shape.width = 0.f;
	shape.height = 0.f;
	mUID = 0;
	movSpeed = 200.f;		
}

Actor::Actor(const Actor& actor)
{
	mUID = actor.mUID;
	shape = actor.shape;
	movSpeed = 200.f;	
}

Actor::Actor(Vector2 position, Vector2 size)
{
	shape.x = position.x;
	shape.y = position.y;
	shape.width = size.x; 
	shape.height = size.y;	
	mUID = 0;
	movSpeed = 200.f;	
}

Actor::~Actor()
{

}

void Actor::Update()
{
	Render(RED);
	CollisionCheck();
}

void Actor::Move(Vector2 dir)
{
	shape.x += dir.x * movSpeed * GetFrameTime();
	shape.y += dir.y * movSpeed * GetFrameTime();
}

bool Actor::Smash(bool isSmashed)
{
	isSmashing = isSmashed;
	return isSmashing;
};

void Actor::Render(Color color)
{
#ifdef DRAW_DEBUG
	DrawRectangleLines(shape.x, shape.y, shape.width, shape.height, color);
#endif
	DrawTexture(sprite, (int)GetPosition().x, (int)GetPosition().y, WHITE);
}

Vector2 Actor::GetPosition() const
{
	return {shape.x, shape.y};
}

void Actor::CollisionCheck()
{
	//Check if func ptr is invalid, so we don't execute the code (in other words, if it was bound to some other function)
	if (!collisionOverlapBind)
	{
		return;
	}

	if (level)
	{
		for (auto item : level->entities)
		{
			if (item != this)
			{
				if (CheckCollisionRecs(this->shape, item->shape) && !IgnoreCollision && !item->IgnoreCollision)
				{
					(this->*collisionOverlapBind)(item);
				}
			}
		}
	}
}
