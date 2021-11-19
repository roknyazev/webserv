#include "ConfigParserLL.hpp"
#include <fstream>
#include <iterator>

#define DEBUG_PARSER

const std::string ConfigParserLL::kConfigExtension = ".conf";

ConfigParserLL::ConfigParserLL()
{ }

ConfigParserLL::~ConfigParserLL()
{ }

bool ConfigParserLL::loadConfig(const std::string& pathToConfig)
{
	std::ifstream fileStream(pathToConfig.c_str());
	pathToConfig_ = pathToConfig;

	if (!fileStream.is_open())
	{
		throw ConfigException(pathToConfig + ": not open");
		return false;
	}

	configData_ = std::vector<std::string>(std::istream_iterator<std::string>(fileStream),
							std::istream_iterator<std::string>());

	// TODO(dkenchur): delete DEBUG after final changes
	#ifdef DEBUG_PARSER
		for (int i = 0; i < configData_.size(); i++)
			std::cout << configData_[i] << std::endl;
		// std::cout << configData_ << std::endl;
	#endif

	if (configData_.empty())
	{
		logger_.log(Log::WARNING) << "empty config\n";
		return false;
	}
	return true;
}

AConfigObject* ConfigParserLL::createConfigObject(const std::string& configObjectName)
{
	AConfigObject* obj;

	if (configObjectName == "server")
		obj = new ServerConfObj;
	else if (configObjectName == "location")
		obj = new LocationConfObj;
	else
		obj = NULL;
	return obj;
}

// TODO(dkenchur): need?
// bool ConfigParserLL::isValidConfigExtension(const std::string& pathToConfig)
// {
// 	const size_t extSize = kConfigExtension.size();
// 	const size_t configPathSize = pathToConfig.size();
// 	size_t lastDotIdx;

// 	if (extSize > configPathSize)
// 	{
// 		throw ConfigException(pathToConfig + ": config extension error");
// 		return false;
// 	}
// 	lastDotIdx = pathToConfig.find_last_of(".");
// 	if (lastDotIdx == std::string::npos ||
// 		kConfigExtension != pathToConfig.substr(lastDotIdx, configPathSize))
// 	{
// 		throw ConfigException(pathToConfig + ": config extension error");
// 		return false;
// 	}
// 	return true;
// }

void ConfigParserLL::parse(const std::string& pathToConfig, std::vector<ServerConfObj*>& serverObjs) // , std::vector<ServerConfObj>& confs
{
	size_t dataIdx;

	// if (!isValidConfigExtension(pathToConfig) || !loadConfig(pathToConfig))
	if (!loadConfig(pathToConfig))
		return ;
	#ifdef DEBUG_PARSER
		logger_.log(Log::DEBUG) << "Success reading\n";
	#endif
	dataIdx = 0;
	while (dataIdx < configData_.size())
	{
		if (configData_[dataIdx] == "server")
		{
			serverObjs.push_back(new ServerConfObj());
			dataIdx = parseConfigObject(serverObjs.back(), ++dataIdx);
		}
		else
		{
			throw ConfigException("Syntax error");
			return ;
		}
	}
}

size_t ConfigParserLL::parseConfigObject(AConfigObject* confObject, size_t dataIdx)
{
	AConfigObject* newConfObject = NULL;
	std::string token;
	size_t objectEndIdx;

	objectEndIdx = getObjectEndIdx(dataIdx, "{", "}");
	if (objectEndIdx - dataIdx == 1)
	{
		logger_.log(Log::WARNING) << "empty object detected\n";
		return objectEndIdx;
	}
	if (configData_[++dataIdx] == "location")
	{
		confObject->addLocation(new LocationConfObj, configData_[++dataIdx]);
		newConfObject = confObject->getLocations().back();
		parseConfigObject(newConfObject, dataIdx);
	}
	else
	{
		
	}
	return objectEndIdx; // ++objectEndIdx
}

size_t ConfigParserLL::cutNextToken(std::string& token, const char separator)
{

}

size_t ConfigParserLL::getObjectEndIdx(size_t currentIdx, const std::string& openBracket,
										const std::string& closeBracket)
{
	size_t endIdx = currentIdx;
	int openBracketsCount = 0;

	for ( ; endIdx < configData_.size(); endIdx++)
	{
		if (configData_[endIdx] == openBracket)
			openBracketsCount++;
		else if (configData_[endIdx] == closeBracket)
			openBracketsCount--;
		if (openBracketsCount == 0)
			break ;
	}
	if (openBracketsCount != 0)
		throw ConfigException("Syntax error");
	return endIdx;
}
