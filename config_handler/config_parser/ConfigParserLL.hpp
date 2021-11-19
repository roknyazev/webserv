#ifndef CONFIG_PARSERLL_HPP
#define CONFIG_PARSERLL_HPP

#include <iostream>
#include <vector>
#include <exception>
#include "Logger.hpp"
#include "LocationConfObj.hpp"
#include "ServerConfObj.hpp"

class ConfigParserLL
{
	public:
		ConfigParserLL();
		~ConfigParserLL();

		// TODO(dkenchur): output errors logger
		class ConfigException : public std::exception
		{
			public:
				ConfigException(const std::string& msg) : msg_(msg) {}
				~ConfigException() throw() {}

				const char* what() const throw()
				{
					return msg_.c_str();
				}

			private:
				std::string msg_;
		};

		void parse(const std::string& pathToConfig, std::vector<ServerConfObj*>& serverObjs);

	private:
		bool loadConfig(const std::string& pathToConfig);
		AConfigObject* createConfigObject(const std::string& configObjectName);
		size_t parseConfigObject(AConfigObject* confObject, size_t dataIdx);// bool objHasArgs);
		// TODO(dkenchur): need?
		// bool isValidConfigExtension(const std::string& pathToConfig);
		size_t cutNextToken(std::string& token, const char separator);
		size_t getObjectEndIdx(size_t currentIdx, const std::string& openBracket,
								const std::string& closeBracket);

		static const std::string kConfigExtension;
		Log::Logger logger_;
		std::string pathToConfig_;
		std::vector<std::string> configData_;
};

#endif // CONFIG_PARSERLL_HPP
