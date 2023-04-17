#pragma once

#include "raylib.h"
#include <string>

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
	std::string ouputText;
	Color textColor;
	int textSize;
};

