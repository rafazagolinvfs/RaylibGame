#pragma once

#include <iostream>
#include "raylib.h"
#include <string>
#include <format>

enum class EScreen : uint8_t
{
	Menu = 0,
	Game,
	GameOver
};

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void IncreaseScore();
	void DecreaseScore();
	void DrawGameUIScreen();
	void DrawMenuUIScreen();
	void DrawGameOverUIScreen();
	EScreen GetCurrentScreen() const;
	void SetScreen(EScreen screen);
	Texture2D menuScreen;
	Texture2D gameOverScreen;
	Texture2D gameScoreBar;

private:
	int score;
	int scoreIterationAmount;	
	int textPositionX;
	int textPositionY;
	std::string playerScoreText;
	Color textColor;
	int textSize;
	EScreen currentScreen;
};