#pragma once
#include "Student.h"
#include "SingleChoiseQuestion.h"
#include "MultipleChoiseQuestion.h"
//enum actionTeacher {
//	ViewTest = 4,
//	Edit,
//	Delete,
//	Add,
//	DeleteSet
//};
enum teacherActions {
	Nothing = -1,
	CreateTest = 4,
	EditTest,
	DeleteTest,
	ViewTest
};
class Teacher :
    public Student
{
	void addTest();
	void addTestSet();
	void viewTest(std::string testName);
	void editTestSet(std::string testName);
	void deleteTestSet(std::string testName);
	void showActions();
	void showTestTypes();
	void chooseAction(int action);
	void viewMarks();
};

