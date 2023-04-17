#include "Obstacle.h"

void Obstacle::Update()
{
	Actor::Update();

	Move({ 0.f, 1.f });
}

