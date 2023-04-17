#include "Breakable.h"



void Breakable::Update()
{
	Actor::Update();

	Move({ 0.f, 1.f });
}
