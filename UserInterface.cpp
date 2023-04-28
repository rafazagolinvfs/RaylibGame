#include "UserInterface.h"
#include "Utils.h"

UserInterface::UserInterface()
{
	menuScreen = LoadTexture("resources/ui/MenuScreen.png");
	gameOverScreen = LoadTexture("resources/ui/GameOverScreen.png");
	gameScoreBar = LoadTexture("resources/ui/top-main-bar.png");

	score = 0;
	playerScoreText = "0";
	scoreIterationAmount = 5;
	textPositionX = 5;
	textPositionY = 5;
	textSize = 15;
	textColor = WHITE;
	currentScreen = EScreen::Menu; //initial screen	
};

UserInterface::~UserInterface()
{
	
};

void UserInterface::IncreaseScore()
{
	score += scoreIterationAmount;
	//playerScoreText = std::format("Score\n{}\n", score);
	playerScoreText = score;
};

void UserInterface::DecreaseScore()
{
	score -= scoreIterationAmount;
	//playerScoreText = std::format("Score\n{}\n", score);
	playerScoreText = score;

};

void UserInterface::DrawGameUIScreen()
{
	//draw score bar
	DrawTexture(gameScoreBar, SCREEN_X / 2 - gameScoreBar.width / 2, 0.f, WHITE);

	//output score
	DrawText("SCORE", 10, 5, 20, RED);
	DrawText(playerScoreText.c_str(), 35, 25, 18, textColor);

	//output level
	DrawText("LEVEL", SCREEN_X / 2 - 35, 5, 20, RED);
	DrawText(playerScoreText.c_str(), (SCREEN_X / 2 - 35) + 25, 25, 18, textColor);

	//output lives
	DrawText("LIVES", SCREEN_X - 100, 5, 20, RED);
	DrawText(playerScoreText.c_str(), SCREEN_X - 100 + 35, 25, 18, textColor);

}

void UserInterface::DrawMenuUIScreen()
{
	DrawTexture(menuScreen, SCREEN_X / 2 - menuScreen.width / 2, 0, WHITE);
}

void UserInterface::DrawGameOverUIScreen()
{
	DrawTexture(gameOverScreen, 0, 0, WHITE);
}

EScreen UserInterface::GetCurrentScreen() const
{
	return currentScreen;
}

void UserInterface::SetScreen(EScreen screen)
{
	currentScreen = screen;
}