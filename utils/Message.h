#ifndef UTILS_MESSAGE_H_
#define UTILS_MESSAGE_H_

#include <string>
#include <windows.h>

namespace utils {

class Message {
public:

	enum YesNoOptions {
		YES = 0,
		NO
	};

	static void printOkMessage(std::string message, std::string windowName);
	static Message::YesNoOptions printYesNoMessage(std::string message, std::string windowName);
};

}

#endif
