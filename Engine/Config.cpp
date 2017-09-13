#include "Config.h"
#include <sstream>
#include <assert.h>


std::string Config::readConfigFile(std::string fileName)
{
	std::ifstream in(fileName);
	assert(in);
	std::stringstream buffer;
	buffer << in.rdbuf();
	return buffer.str();
}

void Config::SeperateAndSetOptions(std::string fileName)
{
	std::string options = readConfigFile(fileName);
	size_t pos1;
	size_t pos2;
	size_t size;
	std::string optionsToFind[5] = { "Tile Size", "Board Size", "Speedup Rate", "Poison Amount", "Goal Amount" };
	std::string optionVal[5];
	int i = 0;
	for (std::string str : optionsToFind)
	{
		size = str.length() + 2;
		pos1 = options.find(str) + size;
		pos2 = options.find("\n", pos1);
		optionVal[i] = options.substr(pos1, pos2 - pos1);
		i++;
	}

	tileSize = std::stoi(optionVal[0]);

	pos1 = 0;
	pos2 = optionVal[1].find(" ");
	boardWidth = std::stoi(optionVal[1].substr(pos1, pos2 - pos1));
	boardHeight = std::stoi(optionVal[1].substr(pos2));

	speedupRate = std::stof(optionVal[2]);
	poisonAmount = std::stoi(optionVal[3]);
	goalAmount = std::stoi(optionVal[4]);

}

Config::Config(std::string fileName)
{
	SeperateAndSetOptions(fileName);
}

int Config::GetTileSize() const
{
	return tileSize;
}
int Config::GetBoardWidth() const
{
	return boardWidth;
}
int Config::GetBoardHeight() const
{
	return boardHeight;
}
float Config::GetSpeedupRate() const
{
	return speedupRate;
}
int Config::GetPoisonAmount() const
{
	return poisonAmount;
}
int Config::GetGoalAmount() const
{
	return goalAmount;
}
