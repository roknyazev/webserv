#ifndef CONFIGHANDLER_HPP
#define CONFIGHANDLER_HPP

#include <iostream>
#include <vector>
#include "Logger.hpp"
#include "ConfigParserLL.hpp"

class ConfigHandler
{
	public:
		ConfigHandler();
		~ConfigHandler();

		void parse(const std::string& pathToConfig);

	private:
		Log::Logger logger_;
		ConfigParserLL parserLL_;
		std::vector<ServerConfObj*> serverObjects_;
};

#endif // CONFIGHANDLER_HPP
