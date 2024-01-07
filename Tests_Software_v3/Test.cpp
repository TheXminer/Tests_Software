#include "Test.h"

//void Test::studentActions()
//{
//	//std::string nameofTest;
//	//std::cout << "Choose stack of tests:";
//	//std::cin >> nameofTest;
//	int action;
//	std::cin >> action;
//	switch(action){
//	case Exit:
//		user.Exit();
//		break;
//	case StartTest:
//		int i = 0;
//		std::cout << "Choose number of the test:";
//		startTest("");
//		break;
//	case ViewMarks:
//		break;
//	}
//}
//
//void Test::teacherActions()
//{
//	showTeacherAction();
//	int action;
//	std::cin >> action;
//	switch (action) {
//	case Exit:
//		user.Exit();
//		break;
//	case ViewTest:
//		break;
//	}
//}
//userAction Test::getAction(std::string nameOfAction)
//{
//	if (nameOfAction == "Exit")
//		return Exit;
//	else if (nameOfAction == "Edit test")
//		return Edit;
//	else if (nameOfAction == "Delete test")
//		return Delete;
//	else if (nameOfAction == "View marks")
//		return ViewMarks;
//	else if (nameOfAction == "View test")
//		return ViewTest;
//	else if (nameOfAction == "Add test")
//		return Add;
//	else if (nameOfAction == "Start test")
//}

void Test::authorize()
{
	//while (user.checkAccess() == NonAuthorized) 
	//{
	//	std::cout << "Log in. Enter your usernme (admin/user): ";
	//	std::string username;
	//	std::cin >> username;
	//	user.logIn(username);
	//}
}

void Test::startApplication()
{
	ClientAction *client = new ClientAction(new AuthorizeAction, &editor, &studentAnswers);
	while (true) {
		//authorize();

		//if (user.checkAccess() == AuthorizedAsStudent) {
		//	std::cout << "Authorized as user" <<std::endl;
		//	Student student;
		//	student.activate(&editor, &studentAnswers, &user);
		//}

		//if (user.checkAccess() == AuthorizedAsAdmin) {
		//	std::cout << "Authorized as admin" << std::endl;
		//	Admin teacher;
		//	teacher.activate(&editor, &studentAnswers, &user);
		//}
		client->start();
	}
}
