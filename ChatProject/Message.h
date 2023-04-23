#pragma once
#include "User.h"


class Message {
private:
	string text;
	User* user;
	int time;
public:
	Message(const string& text, User* user);
	string getMessage();
	User* getUser();
};