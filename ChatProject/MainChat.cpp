#include "User.h"


void registration(vector<User>& Users) {
	string log, pass, nam;
	do {
		cout << "Enter rhe login: ";
		cin >> log;
		if (isUserExist(Users, log)) {
			cout << "This login already has been taken. Please enter other login: \n";
		}
	} while (isUserExist(Users, log));
	cout << "Enter the password: ";
	cin >> pass;
	cout << "Enter the name: ";
	cin >> nam;
	User New(log, pass, nam);
	Users.push_back(New);
}

int login(vector<User> Users) {
	string log, pass;
	cout << "Enter your login: ";
	cin >> log;
	int indexOfUser;
	if (!isUserExist(Users, log)) {
		char ans;
		cout << "User with such login doesn't exist. Do you want sign in? (Y/N): ";
		cin >> ans;
		if (ans == 'Y') {
			registration(Users);
			return -1;
		}
		else {
			do {
				cout << "Enter your login: ";
				cin >> log;
				if (log == "#")
					return -2;
				if (!isUserExist(Users, log)) {
					cout << "User with such login doesn't exist. Please enter other login or press \"#\" to exit the chat\n";
				}
			} while (!isUserExist(Users, log));
			do {
			cout << "Enter the password: ";
			cin >> pass;
			if (pass == "#")
				return -2;
			indexOfUser = checkUser(Users, log, pass);
			if (indexOfUser == -1) {
				cout << "Wrong password. Please, try again or press \"#\" to exit the chat\n";
			}
			} while (indexOfUser == -1);
			return indexOfUser;
		}
	}
	else {
		do {
			cout << "Enter password: ";
			cin >> pass;
			if (pass == "#")
				return -2;
			indexOfUser = checkUser(Users, log, pass);
			if (indexOfUser == -1) {
				cout << "Wrong password. Please, try again or press \"#\" to exit\n";
			}
		} while (indexOfUser == -1);
		return indexOfUser;
	}
	
}

int main() {
	char ans;
	setlocale(LC_ALL, "");
	vector <User> UsersList;
	cout << " Welcome to our chat, wanderer! Please, sign in because you are the first today!\n";
	registration(UsersList);
	string logchoice, logchoice2;
	do {
		do {
			cout << "Please, make a choice - register a new user or log in or exit chat (R/L/E): ";
			cin >> logchoice;
			if(logchoice == "R")
				registration(UsersList);
			if (logchoice == "L") {
				int logIndex = login(UsersList);
				if (logIndex == -1) {//-1 возвращаетс€, если аккаунта с указанным логином не существует, но пользователь решил его зарегистрировать
					continue;
				}
				else if (logIndex == -2) {//-2 возвращаетс€, если попытка в аккаунт неудачна и пользователь решил покинуть чат
					logchoice = "E";
				}
				else {
					cout << "\n\nWelcome, " + UsersList[logIndex].GetName() + "!\n" + UsersList[logIndex].showChat();
					do {
						do {
							cout << "Hello, " + UsersList[logIndex].GetName() + ", please make a choice what do you wonna do:\n";
							cout << "1 - send a message to everyone\n2 - send a message to the certain user\n3 - log out\nE - close the chat\n";
							cin >> logchoice2;
						} while (!(logchoice2 == "1" or logchoice2 == "2" or logchoice2 == "3" or logchoice2 == "E"));
						if (logchoice2 == "1") {
							string Message;
							cout << "Please, enter the message you want send to everyone: ";
							cin >> Message;
							for (int i = 0; i < UsersList.size(); ++i) {
								if (i != logIndex) //„тобы не послать соощение самому себе
									UsersList[i].sendMessage(UsersList[logIndex], Message);
							}
						}
						else if (logchoice2 == "2") {

							string Message, nameOfAddressee;
							cout << "Please, enter the name of user you want send message: ";
							cin >> nameOfAddressee;
							int indexOfAdresseee = getIndexByName(UsersList, nameOfAddressee);
							if (indexOfAdresseee != -1) { //¬озвращаетс€ -1, если пользователь был не найден
								cout << "Please, enter the message you want send " + nameOfAddressee + ": ";
								cin >> Message;
								UsersList[indexOfAdresseee].sendMessage(UsersList[logIndex], Message);
							}
							else {
								cout << "Wrong name!";
							}
						}
						else if (logchoice2 == "3" || logchoice2 == "E") { //¬ первом случае мы выходим из аккаунта, во втором - программа завершает работу
							logchoice = "E";
							break;
						}
					} while (logchoice2 != "E" || logchoice2 != "3");
				}
			}
		} while (logchoice != "E");
	} while (logchoice != "E");
	return 0;
}