#pragma once
#include <iostream>
#include <vector>

using namespace std;

class User
{
private:
	string login;
	string password;
	string name;
	int permission = 0;

public:
	User(const string&, const string&, const string&);
	string getLogin();
	string getPassword();
	string getName();
	void setAdmin(bool isAdmin);
	bool isAdmin();

	static bool isUserExist(vector<User> Users, string log);
	static int checkUser(vector<User> Users, string log, string pass);
	static int getIndexByName(vector<User> Users, string nameOfAddressee);
	static int getIndexByLogin(vector<User> Users, string loginOfAddressee);

};
