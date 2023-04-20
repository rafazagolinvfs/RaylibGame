#include "UserInterface.h"

UserInterface::UserInterface()
{
	menuScreen = LoadTexture("resources/MenuScreen.png");
	gameOverScreen = LoadTexture("resources/GameOverScreen.png");

	// i think these guys are good
	score = 0;
	scoreIterationAmount = 5;

	// i think these guys are wrong so i left them for raf to tweek
	textPositionX = 325;
	textPositionY = 25;

	// these guys might need to be changed depending on the needs of the game
	textSize = 20;
	textColor = WHITE;

	currentScreen = EScreen::Menu; //initial screen
	
};

UserInterface::~UserInterface()
{
	
};

void UserInterface::IncreaseScore()
{
	score += scoreIterationAmount;
	playerScoreText = std::format("Score: {}\n", score);
};

void UserInterface::DecreaseScore()
{
	score -= scoreIterationAmount;
	playerScoreText = std::format("Score: {}\n", score);
};



void UserInterface::OutputScore()
{
	DrawText(playerScoreText.c_str(), textPositionX, textPositionY, textSize, textColor);
}
EScreen UserInterface::GetCurrentScreen() const
{
	return currentScreen;
}

void UserInterface::SetScreen(EScreen screen)
{
	currentScreen = screen;
}