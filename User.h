#pragma once
#include <string>
#include <fstream>


using namespace std;


class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User(string name, string login, string pass): _name(name), _login(login), _pass(pass) {}
	friend fstream& operator >>(fstream& is, User& obj);
	friend ostream& operator <<(ostream& os, const User& obj);
};


fstream& operator >>(fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}


ostream& operator <<(ostream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}


