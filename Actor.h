#pragma once

#include "Utils.h"
#include <raylib.h>

typedef void(*CollisionAction)();

class Actor
{
	friend class Controller;
	friend class FactoryActor;
public:
	~Actor();

	virtual void Update();
	virtual void Move(Vector2 dir);
	virtual void Render(Color color );
	void Collide(CollisionAction collisionAction, std::vector<Actor> actorsToCollideWith);
	Vector2 GetPosition() const;
	Texture2D sprite;


	union
	{
		Rectangle shape;
	};

	float movSpeed;

	
protected:
	Actor();
	Actor(const Actor& actor); //copy constructor
	Actor(Vector2 position, Vector2 size); 
	int mUID;

};

