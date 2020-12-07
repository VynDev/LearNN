/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-25 06:52
 */

#pragma once
#include <exception>
#include <string>

inline std::string methodName(const std::string &prettyFunction)
{
    size_t colons = prettyFunction.find("::");
    size_t begin = prettyFunction.substr(0,colons).rfind(" ") + 1;
    size_t end = prettyFunction.rfind("(") - begin;

    return prettyFunction.substr(begin,end) + "()";
}

#define __METHOD_NAME__ methodName(__PRETTY_FUNCTION__)

namespace LearNN {
	
	class MissingImplementation : public std::exception {

		private:

		std::string reason;

		public:
		
		MissingImplementation(std::string reason, std::string type) {
			this->reason = reason + " " + type;
		}

		virtual const char* what() const noexcept {
			return reason.c_str();
		}
	};
}

#define MissingImplementationException(type) MissingImplementation(__METHOD_NAME__, type)