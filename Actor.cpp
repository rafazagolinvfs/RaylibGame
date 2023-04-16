#include "Actor.h"

Actor::Actor()
{
	shape.x = 0.f;
	shape.y = 0.f;
	shape.width = 0.f;
	shape.height = 0.f;
	mUID = 0;
}

Actor::Actor(const Actor& actor)
{
	mUID = actor.mUID;
	shape = actor.shape;
}

Actor::Actor(Vector2 position, Vector2 size)
{
	shape.x = position.x;
	shape.y = position.y;
	shape.width = size.x; 
	shape.height = size.y;	
	mUID = 0;

}

Actor::~Actor()
{

}

void Actor::Update()
{
	Render(RED);
}

void Actor::Move(Vector2 dir)
{
	shape.x += dir.x;
	shape.y += dir.y;
}

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