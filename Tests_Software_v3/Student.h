#pragma once
#include <random>
#include "StudentAnswers.h"
#include "Editor.h"
#include "User.h"

//enum actionStudent {
//	Exit,
//	StartTest,
//	ViewMarks,
//	ViewNamesOfTests
//};
class Student
{
	enum studentActions {
		Nothing = -1,
		Return = 1,
		Exit = 1,
		StartTest,
		ViewMyMarks,
	};
	void swap(int* a, int* b);
	int* randomizeNumbers(int size);
	std::vector<int>* transformOrder(std::vector<int>* currentMarks, int* key);

protected:
	User* user;
	Editor* editor;
	StudentAnswers* studentAnswers;
	int sumOfMarks(std::vector<int>* marks);
	int chooseTest();
	void printMarks(std::vector<int>* marks);
	void startTest(std::string testName);
	virtual void viewMarks();
	virtual void showActions();
	virtual void chooseAction(int action);

public:
	void activate(Editor* editor, StudentAnswers* studentAnswers, User* user);
};

