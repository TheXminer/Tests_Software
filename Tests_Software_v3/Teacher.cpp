#include "Teacher.h"

Question* Teacher::addTest()
{
	enum choosenTestType { Exit = 1, Return, SingleChoiceTest, MultipleChoiceTest };
	showTestTypes();
	int choice;
	std::cin >> choice;
	Question* newQuestion = nullptr;

	switch (choice) {
	case Exit:
		user->Exit();
		return nullptr;
	case Return:
		return nullptr;
	case SingleChoiceTest:
		newQuestion = new Question;
		if (!newQuestion->enterQuestion()) {
			delete newQuestion;
		}
		return newQuestion;
		break;
	case MultipleChoiceTest:
		//newQuestion = new Question("");
		break;
	}
	return nullptr;
}

void Teacher::addTestSet()
{

	std::cout << "Enter name for set of tests: " << std::endl;
	std::string testSetName;
	std::cin.ignore();
	getline(std::cin, testSetName);
	//std::cin >> testSetName;
	while (true) {
		Question* question = addTest();
		if (!question)
			break;
		editor->addTest(testSetName, question); 
	}
}

void Teacher::viewTest(std::string testName)
{
	std::vector<Question*>* testSet = editor->getSetOfTests(testName);
	for (int i = 0; i < testSet->size(); i++) {
		std::cout << i + 1 << ". ";
		testSet->at(i)->viewTest();
	}
}

void Teacher::editTestSet(std::string testName)
{
	enum editActions {
		AddTest = 3,
		DeleteTest,
		EditTest,
		ViewTest
	};
	showEditSetActions();
	int choice;
	int number;
	Question* question;
	std::cin >> choice;
	switch (choice) {
	case Exit:
		user->Exit();
		break;
	case Return:
		break;
	case editActions::AddTest:
		question = addTest(); 
		if (!question)
			break;
		editor->addTest(testName, question);
		break;
	case editActions::DeleteTest:
		std::cout << "Enter delete test number: ";
		std::cin >> number;
		editor->deleteTest(testName, number - 1);
		break;
	case editActions::EditTest:
		std::cout << "Enter edit test number: ";
		std::cin >> number;
		question = addTest(); 
		if (!question)
			break;
		editor->editTest(testName, number, question);
		break;
	case editActions::ViewTest:
		viewTest(testName);
		break;
	}
}

void Teacher::deleteTestSet(std::string testName)
{
	editor->deleteSetOfTests(testName);
}

void Teacher::showActions() const
{
	std::cout << "Available actions:" << std::endl;
	std::cout << "--(" << Exit << ") Exit" << std::endl;
	std::cout << "--(2) Start test" << std::endl;
	std::cout << "--(3) View marks" << std::endl;
	std::cout << "--(4) Create new test" << std::endl;
	std::cout << "--(5) Edit test" << std::endl;
	std::cout << "--(6) Delete test" << std::endl;
}

void Teacher::showTestTypes() const
{
	std::cout << "Available types:" << std::endl;
	std::cout << "--(" << Exit << ") Exit" << std::endl;
	std::cout << "--(" << Return << ") Return" << std::endl;
	std::cout << "--(3) Single choise" << std::endl;
	std::cout << "--(4) Multiple choise" << std::endl;
}

void Teacher::showEditSetActions() const
{
	std::cout << "Choose action:" << std::endl;
	std::cout << "--(" << Exit << ") Exit" << std::endl; 
	std::cout << "--(" << Return << ") Return" << std::endl; 
	std::cout << "--(3) Add new test" << std::endl;
	std::cout << "--(4) Delete exist test" << std::endl;
	std::cout << "--(5) Edit exist test" << std::endl;
	std::cout << "--(6) View all test" << std::endl;
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
	bool isTyped = false;
	int choice = chooseTest();
	if (choice == Nothing) 
		return;
	for (int i = 0; i < studentAnswers->studentsNames.size(); i++) {
		studentAnswerData* marks = studentAnswers->getStudentAnswers(studentAnswers->studentsNames[i], editor->nameOfTests[choice]);
		if (marks && marks->marks) {
			std::cout << studentAnswers->studentsNames[i] << " (" << marks->usedTime / 60 << "m " << marks->usedTime % 60 << "s, " << sumOfMarks(marks->marks) << "): ";
			printMarks(marks->marks);
			std::cout << std::endl;
			isTyped = true;
		}
	}
	if (!isTyped)
		std::cout << "Students haven`t completed tests yet :(" << std::endl;
}
