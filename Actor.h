#pragma once

#include "Utils.h"
#include <raylib.h>

class Actor
{
	friend class Controller;
	friend class FactoryActor;
public:
	~Actor();


	virtual void Update();
	virtual void Move(Vector2 dir);
	virtual void Render(Color color );

	union
	{
		Rectangle shape;

	};

protected:

private:
	Actor();
	Actor(Vector2 position, Vector2 size);
	int mUID;

};

