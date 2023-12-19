#include "User.h"

std::string User::getUserName()
{
	return userName;
}

status User::logIn(std::string user) {
	if (user == "admin") {
		userName = user;
		authorizeStatus = AuthorizedAsAdmin;
		return authorizeStatus;
	}
	if (user.find("user") != std::string::npos) {
		userName = user;
		authorizeStatus = AuthorizedAsStudent;
		return authorizeStatus;
	}
	return authorizeStatus;
}

status User::checkAccess() {
	return authorizeStatus;
}

status User::Exit() {
	authorizeStatus = NonAuthorized;
	return authorizeStatus;
}