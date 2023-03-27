#include "Message.h"

Message::Message(string text, User* user) {
	this->text = text;
	this->user = user;
}

string Message::getMessage() {
	return this->text;
}

User* Message::getUser() {
	return this->user;
}