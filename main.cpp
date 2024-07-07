#include "User.h"
#include "Message.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

const std::string user_filename = "user.txt";
const std::string message_filename = "message.txt";


namespace fs = std::filesystem;


void create_user(void) {
	if (fs::exists(user_filename))
		return;

	User user("abc", "bcd", "cde");
	std::fstream f(user_filename, std::ios::out);
	if (!f.is_open()) {
		return;
	}

	f << user;
	f.close();
	fs::permissions(user_filename, fs::perms::owner_write | fs::perms::owner_read);
}


void create_message(void) {
	if (fs::exists(message_filename))
		return;

	Message message("qwe", "rty", "zxc");
	std::fstream f(message_filename, std::ios::out);
	if (!f.is_open()) {
		return;
	}

	f << message;
	f.close();
	fs::permissions(message_filename, fs::perms::owner_write | fs::perms::owner_read);
}


User* read_user(void) {
	User * user = new User("", "", "");
	std::fstream f(user_filename, std::ios::in);
	if (!f.is_open()) {
		return user;
	}

	f >> *user;
	f.close();
	return user;
}


Message* read_message(void) {
	Message * message = new Message("", "", "");
	std::fstream f(message_filename, std::ios::in);
	if (!f.is_open()) {
		return message;
	}

	f >> *message;
	f.close();
	return message;
}


int main(void) {
	create_user();
	create_message();

	Message * message = read_message();
	if (message)
		std::cout << *message << std::endl;

	User * user = read_user();
	if (user)
		std::cout << *user << std::endl;

	delete message;
	delete user;

	return 0;
}
