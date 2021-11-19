#include "ConfigHandler.hpp"
#include <fstream>
#include <iterator>
#include <algorithm>

#define DEBUG

ConfigHandler::ConfigHandler()
{
	
}

ConfigHandler::~ConfigHandler()
{
	for (size_t i = 0; i < serverObjects_.size(); i++)
		delete serverObjects_[i];
}

void ConfigHandler::parse(const std::string& pathToConfig)
{
	// parserLL_.parse(pathToConfig);
}
