#include "Scenario.h"


void Scenario::Update()
{
	Actor::Update();

	Move({ 0.f, 1.f });

	if (GetPosition().y >= SCREEN_Y)
	{
		shape.y = -SCREEN_Y;
	}
	LOG(shape.y);
}
