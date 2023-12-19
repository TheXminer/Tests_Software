#include "Teacher.h"

void Teacher::addTest()
{
	std::cout << "Enter question:" << std::endl;
	std::string question;
	std::cout << "Enter answer:" << std::endl;
	std::cin >> question;
	std::string answers;
}

void Teacher::addTestSet()
{
	enum choosenTestType { Exit = 1, Return, SingleChoiceTest, MultipleChoiceTest	};

	std::cout << "Enter name for set of tests: " << std::endl;
	std::string testSetName;
	std::cin >> testSetName;
	while (true) {
		showTestTypes();
		int choice;
		std::cin >> choice;
		Question* newQuestion;

		switch (choice) {
		case Exit:
			user->Exit();
			return;
		case Return:
			return;
		case SingleChoiceTest:
			newQuestion = new Question("");
			break;
		case MultipleChoiceTest:
			newQuestion = new Question("");
			break;
		}
	}
}

void Teacher::viewTest(std::string testName)
{
	std::vector<Question*>* testSet = editor->getSetOfTests(testName);
	for (int i = 0; i < testSet->size(); i++) {
		testSet->at(i)->display();
	}
}

void Teacher::editTestSet(std::string testName)
{
	std::cout << "Choose action:" << std::endl;
	std::cout << "--(1) Exit" << std::endl;
	std::cout << "--(2) Return" << std::endl;
	std::cout << "--(3) Add new test" << std::endl;
	std::cout << "--(4) Delete exist test" << std::endl;
	std::cout << "--(5) Edit exist test" << std::endl;
	std::cout << "--(6) View all test" << std::endl;
}

void Teacher::deleteTestSet(std::string testName)
{
	editor->deleteSetOfTests(testName);
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
	//std::cout << "--(7) View test" << std::endl;
}

void Teacher::showTestTypes()
{
	std::cout << "Available types:" << std::endl;
	std::cout << "--(1) Exit" << std::endl;
	std::cout << "--(2) Return" << std::endl;
	std::cout << "--(3) Single choise" << std::endl;
	std::cout << "--(4) Multiple choise" << std::endl;
}

void Teacher::chooseAction(int action)
{
	Student::chooseAction(action);
	int choice = 0;
	switch (action) {
	case CreateTest:
		addTestSet();
		break;
	case EditTest:
		choice = chooseTest();
		if (choice == Nothing)
			return;
		editTestSet(editor->nameOfTests[choice]);
		break;
	case DeleteTest:
		choice = chooseTest();
		if (choice == Nothing)
			return;
		deleteTestSet(editor->nameOfTests[choice]);
		break;
	//case ViewTest:
	//	choice = chooseTest();
	//	if (choice == Nothing)
	//		return;
	//	viewTest(editor->nameOfTests[choice]);
	//	break;
	}
}

void Teacher::viewMarks()
{
	int choice = chooseTest();
	if (choice == Nothing)
		return;
	std::string testName = editor->nameOfTests[choice];

	bool isTyped = false;
	int choose = chooseTest();
	for (int i = 0; i < studentAnswers->studentsNames.size(); i++) {
		studentAnswerData marks = studentAnswers->getStudentAnswers(studentAnswers->studentsNames[i], testName);
		if (marks.marks) {
			std::cout << studentAnswers->studentsNames[i] << " (" << sumOfMarks(marks.marks) << "): ";
			printMarks(marks.marks);
			isTyped = true;
		}
	}
	if (!isTyped)
		std::cout << "Students haven`t completed tests yet :(" << std::endl;
}
