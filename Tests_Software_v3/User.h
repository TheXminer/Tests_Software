#pragma once
#include <string>
enum status {
	NonAuthorized,
	AuthorizedAsStudent,
	AuthorizedAsAdmin
};

class User
{
	std::string userName;
	status authorizeStatus = NonAuthorized;
public:
	std::string getUserName();
	status logIn(std::string user);
	status checkAccess();
	status Exit();
};

