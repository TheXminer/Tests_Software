#pragma once
#include <random>
#include "StudentAnswers.h"
#include "Editor.h"
#include "User.h"

enum studentActions {
	Nothing = -1,
	Return = 2,
	Exit = 1,
	StartTest,
	ViewMyMarks,
};
//enum actionStudent {
//	Exit,
//	StartTest,
//	ViewMarks,
//	ViewNamesOfTests
//};
class Student
{
	void swap(int* a, int* b);
	int* randomizeNumbers(int size);
	std::vector<int>* transformOrder(std::vector<int>* currentMarks, int* key);

protected:
	User* user;
	Editor* editor;
	StudentAnswers* studentAnswers;
	int sumOfMarks(std::vector<int>* marks);
	int chooseTest();
	void printMarks(std::vector<int>* marks) const;
	void startTest(std::string testName);
	virtual void viewMarks();
	virtual void showActions() const;
	virtual void chooseAction(int action);

public:
	void activate(Editor* editor, StudentAnswers* studentAnswers, User* user);
};

