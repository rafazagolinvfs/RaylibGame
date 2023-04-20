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
	void OutputScore();
	EScreen GetCurrentScreen() const;
	void SetScreen(EScreen screen);
	Texture2D menuScreen;
	Texture2D gameOverScreen;

private:
	int score;
	int scoreIterationAmount;	
	int textPositionX;
	int textPositionY;
	std::string playerScoreText = "Score: 0";
	Color textColor;
	int textSize;
	EScreen currentScreen;
};