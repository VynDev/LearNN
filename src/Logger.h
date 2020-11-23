/*
 * Author: Vyn
 * Created: 2020-04-06 04:51
 * Modified: 2020-07-21 08:15
 */

#pragma once
#include <iostream>

/**
 * Generate a logger object and allow you to use the following print functions:
 * 
 * - Print(text)
 * - PrintSucess(text)
 * - PrintWarn(text)
 * - PrintError(text)
 * - PrintDebug(text)
 * 
 * @param std::string prefix The prefix of the line
 */
#define LOGGER(prefix) static LearNN::Logger logger(prefix);

#define PrintSuccess logger.Success
#define PrintWarn logger.Warn
#define PrintError logger.Error
#define PrintDebug logger.Debug
// #define Print logger.PrintLog
#define ResetColor logger.ResetConsoleColor

namespace LearNN
{
	const std::string RESET = "\033[0m";
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";
	
	class Logger
	{
		private:

		std::string prefix;

		public:

		Logger(std::string prefix) : prefix(prefix) {}

		Logger& Log(std::string colorString = "")
		{
			std::cout << colorString << "[" << prefix << "] ";
			return (*this);
		}

		Logger& PrintLog()
		{
			return (Log(RESET));
		}

		Logger& Success()
		{
			return (Log(GREEN));
		}

		Logger& Warn()
		{
			return(Log(YELLOW));
		}

		Logger& Error()
		{
			return (Log(RED));
		}

		Logger& Debug()
		{
			return (Log(BLUE));
		}

		Logger& ResetConsoleColor()
		{
			std::cout << RESET;
			return (*this);
		}

		template<typename T>
		friend std::ostream& operator<<(Logger& out, T data)
		{
			std::cout << data;
			return (std::cout);
		}
	};
}