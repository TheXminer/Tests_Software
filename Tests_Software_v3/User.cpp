#include "User.h"

bool User::logIn(std::string user) {
	if (user == "admin") {
		isAdmin = true;
		isAccessAvailable = true;
		return true;
	}
	if (user == "user") {
		isAdmin = false;
		isAccessAvailable;
		return true;
	}
	return false;
}

bool User::checkAccess() {
	return isAccessAvailable;
}

bool User::Exit() {
	if (!isAccessAvailable)
		return false;
	isAdmin = false;
	isAccessAvailable = false;
	return true;
}