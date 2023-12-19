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
	CreateTest = 4,
	EditTest,
	DeleteTest,
	ViewTest
};
class Teacher :
    public Student
{
	Question* addTest();
	void addTestSet();
	void viewTest(std::string testName);
	void editTestSet(std::string testName);
	void deleteTestSet(std::string testName);
	void showActions() const;
	void showTestTypes() const;
	void showEditSetActions() const;
	void chooseAction(int action);
	void viewMarks();
};

