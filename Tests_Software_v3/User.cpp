#include "User.h"

status User::logIn(std::string user) {
	if (user == "admin") {
		authorizeStatus = AuthorisedAsAdmin;
		return authorizeStatus;
	}
	if (user == "user") {
		authorizeStatus = AuthorisedAsStudent;
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