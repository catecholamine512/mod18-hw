#include "User.h"
#include "Message.h"
#include <filesystem>
#include <iostream>


namespace fs = std::filesystem;


void create_user(void) {
	User user("abc", "bcd", "cde");
	std::ofstream f("user.txt");
	if (!f.is_open()) {
		return;
	}

	f << user;
	f.close();
	fs::permissions("user.txt", fs::perms::owner_write | fs::perms::owner_read);
}


void create_message(void) {
	Message message("qwe", "rty", "zxc");
	std::ofstream f("message.txt");
	if (!f.is_open()) {
		return;
	}

	f << message;
	f.close();
	fs::permissions("message.txt", fs::perms::owner_write | fs::perms::owner_read);
}


User* read_user(void) {
	User * user = new User("", "", "");
	std::fstream f("user.txt");
	if (!f.is_open()) {
		return nullptr;
	}

	f >> *user;
	f.close();
	return user;
}


Message* read_message(void) {
	Message * message = new Message("", "", "");
	std::fstream f("message.txt");
	if (!f.is_open()) {
		return nullptr;
	}

	f >> *message;
	f.close();
	return message;
}


int main(void) {
	// create_user();
	// create_message();

	Message * message = read_message();
	std::cout << *message << std::endl;
	User * user = read_user();
	std::cout << *user << std::endl;

	delete message;
	delete user;

	return 0;
}
