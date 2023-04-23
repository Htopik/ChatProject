#include "Message.h"

Message::Message(const string& text, User* user) : text(text), user(user) {}

string Message::getMessage() {
	return this->text;
}

User* Message::getUser() {
	return this->user;
}