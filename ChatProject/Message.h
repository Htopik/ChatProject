#pragma once
#include <iostream>
#include "vector"
#include "User.h"

using namespace std;

class Message {
private:
	string text;
	User* user;
	int time;
public:
	Message(string text, User* user);
	string getMessage();
	User* getUser();
};