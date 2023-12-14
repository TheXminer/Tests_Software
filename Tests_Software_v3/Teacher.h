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
class Teacher :
    public Student
{
	void addTest();
	void viewTest();
	void showActions();
	void chooseAction(int action);
	void viewMarks(std::string nameofTest);
};

