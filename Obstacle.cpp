#include "Obstacle.h"

void Obstacle::Update()
{
	Actor::Update();

	Move({ 0.f, 1.f });

	//ResetPosition(INITIAL_Y_POS);
}

