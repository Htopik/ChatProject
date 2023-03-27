#include "Message.h"
#include <string>

static vector <User> RegisteredUsersList; //Массив зарегистрированных пользователей
static vector <Message> Messages; //Массив сообщений
static vector <vector<Message>> Ls; //Массив личных сообщений
static User* loggedUser; //Указатель на текущего пользователя, зашедшего в чат

void registration() {
	string log, pass, nam;
	do {
		cout << "Enter the login: ";
		cin >> log;
		if (User::isUserExist(RegisteredUsersList, log)) {
			cout << "This login already has been taken. Please enter other login: \n";
		}
	} while (User::isUserExist(RegisteredUsersList, log));
	cout << "Enter the password: ";
	cin >> pass;
	cout << "Enter the name: ";
	cin >> nam;
	User New(log, pass, nam);
	vector <Message> newls;
	RegisteredUsersList.push_back(New);
	Ls.push_back(newls);
}

int login() {
	string log, pass;
	cout << "Enter your login: ";
	cin >> log;
	int indexOfUser;
	if (!User::isUserExist(RegisteredUsersList, log)) {
		cout << "\nThis user is not exists!";
		return -1;
	}
	cout << "Enter your password: ";
	cin >> pass;
	indexOfUser = User::checkUser(RegisteredUsersList, log, pass);
	if (indexOfUser == -1) {
		cout << "\nWrong password!";
		return -1;
	}
	return indexOfUser;
}

void logged() {
	cout << "\nWelcome to chat room.";
	do {
		cout << "\n";
		for (int i = 0; i < Messages.size(); i++) {
			cout << "\n" << Messages[i].getUser()->GetName() << "> ";
			cout << Messages[i].getMessage();
		}
		cout << "\nUse /help for commands list\n";
		cout << ">";
		string command;
		getline(cin, command);
		cout << "\n";
		if (command == "/help") {
			cout << "/logout - Logout\n";
			cout << "/ls list - your LS messages\n";
			cout << "/ls send - send LS message\n";
			if (loggedUser->isAdmin()) cout << "/admin help - admin commands list.";
			continue;
		}
		else if (command == "/admin help") {
			if (!loggedUser->isAdmin()) continue;
			if (command == "help") {
				cout << "/admin clear - Delete all messages.";
			}
			continue;
		}
		else if (command == "/admin clear") {
			if (!loggedUser->isAdmin()) continue;
			Messages.clear();
			continue;
		}

		else if (command == "/logout") {
			loggedUser = nullptr;
			cout << "\nLogged out.";
			break;
		}
		else if (command == "/ls list") {
			cout << "\nLS:";
			cout << "\n________________________________________________________________________________\n";
			int loggedIndex = User::getIndexByLogin(RegisteredUsersList, loggedUser->GetLogin());
			if (Ls[loggedIndex].size() == 0) {
				cout << "No LS messages.";
				cout << "\n________________________________________________________________________________\n";
				continue;
			}
			for (int i = 0; i < Ls[loggedIndex].size(); i++) {
				cout << "\n" << Ls[loggedIndex][i].getUser()->GetName() << "> ";
				cout << Ls[loggedIndex][i].getMessage();
			}
			cout << "\n________________________________________________________________________________\n";
			continue;
		}
		else if (command == "/ls send") {
			string login;
			string lsmsgstr;
			cout << "User login: ";
			cin >> login;
			int indexOfUser;
			if (!User::isUserExist(RegisteredUsersList, login)) {
				cout << "\nThis user is not exists!";
				continue;
			}
			indexOfUser = User::getIndexByLogin(RegisteredUsersList, login);
			cout << "Your message: ";
			cin.ignore();
			getline(cin, lsmsgstr);
			Message lsmsg(lsmsgstr, loggedUser);
			Ls[indexOfUser].push_back(lsmsg);
			continue;
		}
		else {
			Message msg(command, loggedUser);
			Messages.push_back(msg);
			continue;
		}
	} while (true);
}

void notLogged() {
	do {
		cout << "\n________________________________________________________________________________\n";
		cout << "Use /help for commands list\n";
		cout << ">";
		string command;
		cin >> command;
		cout << "\n";
		if (command == "/help") {
			cout << "/login - Login to chat\n";
			cout << "/register - Register new account\n";
			cout << "/exit - Close chat\n";
		}
		else if (command == "/login") {
			int indexOfUser = login();
			if (indexOfUser == -1) {
				cout << "\nNot logged!";
				continue;
			}
			loggedUser = &RegisteredUsersList[indexOfUser];
			cin.ignore();
			logged();
			continue;
		}
		else if (command == "/register") {
			registration();
			continue;
		}
		else if (command == "/exit") {
			cout << "\nClosing program...";
			break;
		}
		else {
			cout << "Wrong command! Try again.";
			continue;
		}
	} while (true);
}

int main() {
	char ans;
	setlocale(LC_ALL, "");
	cout << " Welcome to our chat, wanderer! Please, sign in because you are the first today! First user is admin permanently\n";
	registration();//В начале был Первый. Этот Первый стал началом всему
	RegisteredUsersList[0].setAdmin(true);//и админом чата по совместительству
	notLogged();
	return 0;
}