#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <exception>

#define DEFAULT_COLOR "\033[37;0m"
#define GREEN "\033[32;22m"
#define YELLOW "\033[33;22m"
#define RED "\033[31;22m"
#define WHITE "\033[37;22m"

/**
 *		Пример использования логгера:
 * 		Log::Logger logger;
 * 		
 * 		logger.log(Log::DEBUG) << LOG MESSAGE << '\n';
 * 
 */
namespace Log
{
	enum TypeLog
	{
		DEBUG = 0,
		INFO,
		WARNING,
		ERROR
	};

	class Logger
	{
		public:
			/**
			 * @brief Конструктор логгера
			 * 
			 * @param logFilePath Путь до файла логов
			 */
			Logger(const std::string& logFilePath = "log.txt");
			~Logger();

			/**
			 * @brief Класс исключение. Выбрасывается в случае ошибки открытия файла логов
			 * 
			 */
			class LogFileNotOpenException : public std::exception
			{
				public:
					LogFileNotOpenException(const std::string& logFilePath)
						: msg_(logFilePath + ": not open")
					{ }
					~LogFileNotOpenException() throw() {};

					const char* what() const throw()
					{
						return msg_.c_str();
					}

				private:
					const std::string msg_;
			};

			/**
			 * @brief Ожидает сообщение для логирования. Используется вместе с
			 * 		Logger& log(TypeLog type)
			 * 
			 * @tparam T
			 * @param message Логируемое сообщение
			 * @return Logger&
			 */
			template <typename T>
			Logger& operator<<(const T& message)
			{
				if (isConsoleOutputOn_ == true)
					std::cout << message;
				if (isLoggingToFileOn_ == true)
					fileStream_ << message;
				return *this;
			}

			/**
			 * @brief Логирует данные
			 * 
			 * @param type Тип лога (TypeLog: DEBUG, INFO, WARNING, ERROR)
			 * @return Logger& 
			 */
			Logger& log(TypeLog typeLog);

			/**
			 * @brief Включает вывод логов в консоль
			 * 
			 */
			void consoleOutputEnable();

			/**
			 * @brief Отключает вывод логов в консоль
			 * 
			 */
			void consoleOutputDisable();

			/**
			 * @brief Обновляет путь до файла с логами
			 * 
			 * @param logFilePath Путь до файла с логами
			 */
			void changeLogFilePath(const std::string& logFilePath);

			/**
			 * @brief Включение записи логов в файл. По дефолту запись отключена
			 * 
			 */
			void logFileEnable();

			/**
			 * @brief Отключает запись логов в файл
			 * 
			 */
			void logFileDisable();

		private:
			const std::string getTypeLogStr() const;
			void selectLogColor();

			std::string logFilePath_;
			std::ofstream fileStream_;
			TypeLog typeLog_;
			bool isLoggingToFileOn_;
			bool isConsoleOutputOn_;
			std::string logColor_;
	};
}

#endif // LOGGER_HPP
