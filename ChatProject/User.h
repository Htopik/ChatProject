#pragma once
#include <iostream>
#include "vector"

using namespace std;
class User
{
private:
	string login;
	string password;
	string name;
	string poolOfMessages="";

public:
	User(string, string, string);
	string GetLogin();
	string GetPassword();
	string GetName();
	void sendMessage(User, string);
	string showChat();
};
bool isUserExist(vector<User>, string);
int checkUser(vector<User>, string, string);
int getIndexByName(vector<User>, string);

