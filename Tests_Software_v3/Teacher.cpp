#include "Teacher.h"

void Teacher::addTest()
{
}

void Teacher::showActions()
{
	std::cout << "Available actions:" << std::endl;
	std::cout << "--(1) Exit" << std::endl;
	std::cout << "--(2) Start test" << std::endl;
	std::cout << "--(3) View marks" << std::endl;
	std::cout << "--(4) Create new test" << std::endl;
	std::cout << "--(5) Edit test" << std::endl;
	std::cout << "--(6) Delete test" << std::endl;
	std::cout << "--(7) View test" << std::endl;
}

void Teacher::chooseAction(int action)
{
	Student::chooseAction(action);
	enum teacherActions {
		Nothing = -1,
		CreaateTest = 4,
		EditTest,
		DeleteTest,
		ViewTest
	};
	int choose = 0;
	switch (action) {
	case CreaateTest:
		break;
	case EditTest:
		choose = chooseTest();
		if (choose == Nothing)
			return;
		break;
	case DeleteTest:
		choose = chooseTest();
		if (choose == Nothing)
			return;
		break;
	case ViewTest:
		choose = chooseTest();
		if (choose == Nothing)
			return;
		break;
	}
}

void Teacher::viewMarks(std::string nameofTest)
{
	int choose = chooseTest();
	for (int i = 0; i < studentAnswers->studentsNames.size(); i++) {
		std::vector<int>* marks = studentAnswers->getStudentAnswers(studentAnswers->studentsNames[i], nameofTest);
		if (marks) {
			std::cout << studentAnswers->studentsNames[i] << " (" << sumOfMarks(marks) << "): ";
			printMarks(marks);
		}
	}
}

//void Teacher::activate(Editor* editor, StudentAnswers* studentAnswers, User* user){
//	Student::activate(editor, studentAnswers, user);
//	
//}
