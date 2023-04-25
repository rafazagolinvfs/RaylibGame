#include "Scenario.h"


void Scenario::Update()
{
	Actor::Update();

	Move({ 0.f, 1.f });

	ResetPosition();
}
