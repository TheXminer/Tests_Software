#include "Test.h"

void Test::startTest(std::string testName)
{
	std::vector<Question*>* tests = editor.getSetOfTests(testName);
	std::string answer;
	int size = tests->size();
	int* numbersOrder = randomizeNumbers(size);
	for (int i = 0; i < size; i++) {
		tests->at(*numbersOrder)->display();
		std::cout << "Enter your answer: ";
		std::cin >> answer;
		if (answer == "exit") {
			user.Exit();
			return;
		}
		tests->at(*numbersOrder)->checkAnswer(answer[0]);
	}
}

void Test::authorize()
{
	while (user.checkAccess() == NonAuthorized) 
	{
		std::cout << "Log in. Enter your usernme (admin/user): ";
		std::string username;
		std::cin >> username;
		user.logIn(username);
	}
}

void Test::startApplication()
{
	while (true) {
		authorize();

		if (user.checkAccess() == AuthorisedAsStudent) {
			std::string nameofTest;
			std::cout << "Choose stack of tests:";
			std::cin >> nameofTest;
			if (nameofTest == "exit")
				user.Exit();
			else startTest(nameofTest);
		}

		if (user.checkAccess() == AuthorisedAsAdmin) {
			
		}
	}
}
