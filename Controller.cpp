#include "Controller.h"

Controller::Controller()
{
	possessedPawn = nullptr;
	LOG("spawned controller");
}

Controller::~Controller()
{
}

void Controller::Possess(Actor* pawn)
{
	possessedPawn = pawn;
}

void Controller::Update()
{
	Move();
}

void Controller::Move()
{
	if (!possessedPawn)
		return;


	Vector2 dir;
	dir.x = 0.f;
	dir.y = 0.f;


	//Input goes here
	if (IsKeyDown(KEY_A))
	{
		dir.x = -1.f;
	}
	if (IsKeyDown(KEY_D))
	{
		dir.x = 1.f;
	}

	if (IsKeyDown(KEY_W))
	{
		dir.y = -1.f;
	}
	if (IsKeyDown(KEY_S))
	{
		dir.y = 1.f;
	}

	isSmashing = IsKeyDown(KEY_E);
	possessedPawn->Move(dir);
}
