#include "Logger.hpp"

Log::Logger::Logger(const std::string& logFilePath)
	: logFilePath_(logFilePath),
	  typeLog_(Log::DEBUG),
	  isLoggingToFileOn_(false),
	  isConsoleOutputOn_(true)
{ }

Log::Logger::~Logger()
{ }

Log::Logger& Log::Logger::log(Log::TypeLog typeLog)
{
	typeLog_ = typeLog;
	selectLogColor();
	return *this << logColor_ << getTypeLogStr() << DEFAULT_COLOR;
}

void Log::Logger::consoleOutputEnable()
{
	isConsoleOutputOn_ = true;
}

void Log::Logger::consoleOutputDisable()
{
	isConsoleOutputOn_ = false;
}

void Log::Logger::changeLogFilePath(const std::string& logFilePath)
{
	logFilePath_ = logFilePath;

	if (isLoggingToFileOn_ == true)
	{
		logFileDisable();
		logFileEnable();		
	}
}

void Log::Logger::logFileEnable()
{
	if (isLoggingToFileOn_ == false)
	{
		isLoggingToFileOn_ = true;
		fileStream_.open(logFilePath_.c_str(), std::ios::app);
		if (!fileStream_.is_open())
			throw LogFileNotOpenException(logFilePath_);
	}
}

void Log::Logger::logFileDisable()
{
	if (isLoggingToFileOn_ == true)
	{
		fileStream_.close();
		fileStream_.clear();
		isLoggingToFileOn_ = false;
	}
}

const std::string Log::Logger::getTypeLogStr() const
{
	std::string typeLogStr;

	switch (typeLog_)
	{
		case Log::DEBUG:
			typeLogStr = "[DEBUG] ";
			break;
		
		case Log::INFO:
			typeLogStr = "[INFO] ";
			break;

		case Log::WARNING:
			typeLogStr = "[WARNING] ";
			break;

		case Log::ERROR:
			typeLogStr = "[ERROR] ";
			break;
	}
	return typeLogStr;
}

void Log::Logger::selectLogColor()
{
	switch (typeLog_)
	{
		case Log::DEBUG:
			logColor_ = GREEN;
			break;

		case Log::INFO:
			logColor_ = WHITE;
			break;
		
		case Log::WARNING:
			logColor_ = YELLOW;
			break;

		case Log::ERROR:
			logColor_ = RED;
			break;
	}
}
