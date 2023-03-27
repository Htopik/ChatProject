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

void User::setAdmin(bool isAdmin) {
	this->permission = isAdmin;
}

bool User::isAdmin() {
	return permission == 1;
}

bool User::isUserExist(vector<User> Users, string log) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetLogin() == log)
			return true;
	}
	return false;
}

int User::checkUser(vector<User> Users, string log, string pass) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetLogin() == log && Users[i].GetPassword() == pass)
			return i;
	}
	return -1;
}

int User::getIndexByName(vector<User> Users, string nameOfAddressee) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetName() == nameOfAddressee)
			return i;
	}
	return -1;
}

int User::getIndexByLogin(vector<User> Users, string loginOfAddressee) {
	for (int i = 0; i < Users.size(); ++i) {
		if (Users[i].GetLogin() == loginOfAddressee)
			return i;
	}
	return -1;
}