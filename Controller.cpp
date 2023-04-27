#include "Controller.h"
#include "UserInterface.h"
#include "ItemsManager.h"

Controller::Controller()
{
	possessedPawn = nullptr;
	desiredGridPosX = 2; //center character at begin play
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
	Actor::Update();
	//Move();
	GridMovement();
	Smash();

	//Cycle between screens
	if (!ui)
		return;

	//When the user pressess enter, change the screen
	if (!IsKeyDown(KEY_ENTER))
		return;

	switch (ui->GetCurrentScreen()) {
	case EScreen::Menu:ui->SetScreen(EScreen::Game);
		break;
	case EScreen::GameOver: ui->SetScreen(EScreen::Menu);
		break;
	}

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

	possessedPawn->Move(dir);
};

void Controller::Smash()
{
	if (!possessedPawn)
		return;
	bool pressedButton = IsKeyDown(KEY_SPACE);
	possessedPawn->Smash(pressedButton);
};

void Controller::GridMovement()
{
	if (!possessedPawn)
		return;

	if (!itemsManager)
		return;

	possessedPawn->SetPosition({ itemsManager->xPos[desiredGridPosX], possessedPawn->GetPosition().y });

	if (IsKeyPressed(KEY_A))
	{
		if (!aKeyOnce)
		{
			if (desiredGridPosX > 0)
			{
				desiredGridPosX--;
			}
			aKeyOnce = true;
		}
	}
	else if (IsKeyReleased(KEY_A))
	{
		aKeyOnce = false;
	}

	if (IsKeyPressed(KEY_D))
	{
		if (!dKeyOnce)
		{
			if(desiredGridPosX < COLUMNS_AMOUNT - 1)
				desiredGridPosX++;

			dKeyOnce = true;
		}
	}
	else if (IsKeyReleased(KEY_D))
	{
		dKeyOnce = false;
	}


}