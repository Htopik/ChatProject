#include "User.h"

User::User(string log, string pass, string nam) {
	this->login = log;
	this->name = nam;
	this->password = pass;
}
string User::GetLogin() {
	return this->login;
}

string User::GetPassword() {
	return this->password;
}

string User::GetName() {
	return this->name;
}

string User::showChat() {
	if (this->poolOfMessages == "")
		return "There is no messages yet.\n";
	return this->poolOfMessages;
}

void User::sendMessage(User UsverOtpr, string Mess) {//UsverOtpr - Отправитель сообщения
	this->poolOfMessages += UsverOtpr.GetName() + "> " + Mess + '\n';
}

bool isUserExist(vector<User> Users, string log) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetLogin() == log)
			return true;
	}
	return false;
}

int checkUser(vector<User> Users, string log, string pass) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetLogin() == log && Users[i].GetPassword() == pass)
			return i;
	}
	return -1;
}

int getIndexByName(vector<User> Users, string nameOfAddressee) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetName() == nameOfAddressee)
			return i;
	}
	return -1;
}