#pragma once
#include <string>
enum status {
	NonAuthorized,
	AuthorisedAsStudent,
	AuthorisedAsAdmin
};

class User
{
	status authorizeStatus = NonAuthorized;
public:
	status logIn(std::string user);
	status checkAccess();
	status Exit();
};

