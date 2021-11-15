#ifndef CONFIG_PARSERLL_HPP
#define CONFIG_PARSERLL_HPP

#include <iostream>

class ConfigParserLL
{
	public:
		ConfigParserLL();
		ConfigParserLL(const ConfigParserLL& other);
		~ConfigParserLL();

		ConfigParserLL& operator=(const ConfigParserLL& other);

	private:
		std::string configName_;
};

#endif // CONFIG_PARSERLL_HPP
