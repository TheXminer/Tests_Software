#pragma once
#include <string>

class User
{
protected:
	bool isAdmin = false;
	bool isAccessAvailable = false;
public:
	bool logIn(std::string user);
	bool checkAccess();
	bool Exit();
};

