#pragma once
#include "Editor.h"
#include "User.h"
class Test
{
	bool isTestStarted = false;
	//std::unordered_map<std::string,std::vector<SingleChoiseTest>> answers;
public:
	Editor editor;
	User user;
//Student
	int startTest(int nTest = 1);
	int endTest();
	Answer* getTest(int i);
	int giveAnswer(int answers);
//Teacher
	bool createNewTest(std::vector<Answer*>);
	std::vector<Answer> viewTest(std::string testName);
	Answer* editTest(std::string testName, int questionNumber);
	//std::vector<SingleChoiseTest> viewUserAnswers(std::string testName);
};
