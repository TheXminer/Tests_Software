#pragma once
#include "Editor.h"
#include "User.h"
#include "StudentAnswers.h"

class Test
{
	status status = NonAuthorized;
	StudentAnswers studentAnswers;
	Editor editor;
	User user;
	void authorize();
	void startTest(std::string testName);
	int* randomizeNumbers(int size);
	bool deleteTest(std::string testName);
	bool* editTest(std::string testName, int questionNumber);
public:
	void startApplication();
};
