#pragma once

#include <iostream>
#include "raylib.h"
#include <string>
#include <format>

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void IncreaseScore();
	void OutputScore();

private:
	int score;
	int scoreIterationAmount;
	int textPositionX;
	int textPositionY;
	std::string ouputText = "Score: 0";
	Color textColor;
	int textSize;
};

