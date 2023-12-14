#pragma once
#include <string>
enum status {
	NonAuthorized,
	AuthorizedAsStudent,
	AuthorizedAsAdmin
};

class User
{
	status authorizeStatus = NonAuthorized;
public:
	status logIn(std::string user);
	status checkAccess();
	status Exit();
};

