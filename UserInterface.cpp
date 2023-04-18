#include "UserInterface.h"

UserInterface::UserInterface()
{
	// i think these guys are good
	score = 0;
	scoreIterationAmount = 5;
	// i think these guys are wrong so i left them for raf to tweek
	textPositionX = 325;
	textPositionY = 25;
	// these guys might need to be changed depending on the needs of the gam
	textSize = 20;
	textColor = WHITE;
	
};

UserInterface::~UserInterface()
{
	
};

void UserInterface::IncreaseScore()
{
	score += scoreIterationAmount;
	ouputText = std::format("Score: {}\n", score);
};

void UserInterface::DecreaseScore()
{
	score -= scoreIterationAmount;
	ouputText = std::format("Score: {}\n", score);
};

void UserInterface::OutputScore()
{
	DrawText(ouputText.c_str(), textPositionX, textPositionY, textSize, textColor);
};
