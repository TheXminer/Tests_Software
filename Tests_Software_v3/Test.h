#pragma once
#include "Editor.h"
#include "User.h"
#include "Answers.h"
class Test
{
	Editor editor;
	bool isTestStarted = false;
	std::unordered_set<std::string,std::vector<Answers>> answers;
public:
	User user;
//Student
	int startTest(int nTest = 1);
	int endTest();
	SetQA* getTest(int i);
	int giveAnswer(int answers);
//Teacher
	bool createNewTest(std::vector<SetQA*>);
	std::vector<SetQA> viewTest(std::string testName);
	SetQA* editTest(std::string testName, int questionNumber);
	std::vector<Answers> viewUserAnswers(std::string testName);
};
