#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>

class Config
{
public:
	Config(std::string fileName);
	int GetTileSize() const;
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	float GetSpeedupRate() const;
	int GetPoisonAmount() const;
	int GetGoalAmount() const;
private:
	std::string readConfigFile(std::string fileName);
	void SeperateAndSetOptions(std::string fileName);
	int tileSize;
	int boardWidth;
	int boardHeight;
	float speedupRate;
	int poisonAmount;
	int goalAmount;
};
