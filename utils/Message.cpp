#include "Message.h"

namespace utils {

void Message::printOkMessage(std::string message, std::string windowName) {
	MessageBox(HWND(), "test", "test", MB_OK);
}

Message::YesNoOptions Message::printYesNoMessage(std::string message, std::string windowName) {
	if (IDYES == MessageBox(HWND(), "xxx", "xxx", MB_YESNO)) {
		return Message::YesNoOptions::YES;
	} else {
		return Message::YesNoOptions::NO;
	}
}

}
