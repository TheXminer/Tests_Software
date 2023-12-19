#pragma once
#include <stdio.h>
#include "Teacher.h"

//enum userAction {
//	Exit,
//	StartTest,
//	ViewMarks,
//	ViewTest,
//	Edit,
//	Delete,
//	Add,
//	DeleteSet
//};

class Test
{
	StudentAnswers studentAnswers;
	Editor editor;
	User user;
	void authorize();
	//userAction getAction(std::string nameOfAction);
	//void studentActions();//stud
	//void teacherActions();//teach
	//void showTeacherAction();
public:
	void startApplication();
};
