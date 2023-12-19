#include "Student.h"

void Student::swap(int* a, int* b)
{
	int* save = a;
	a = b;
	b = save;
}

int* Student::randomizeNumbers(int size)
{
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}
	return array;
}

std::vector<int>* Student::transformOrder(std::vector<int>* currentMarks, int* key)
{
	//std::vector<int>* resultOrder;
	//for (int i = 0; i < currentMarks->size(); i++) {
	//	resultOrder->push_back(currentMarks->at(key[i]));
	//}
	return currentMarks;
}

void Student::printMarks(std::vector<int>* marks)
{
	int size = marks->size();
	for (int i = 0; i < size; i++) {
		std::cout << marks->at(i) << " ";
	}
	std::cout << std::endl;
}

void Student::showActions()
{
	std::cout << "Available actions:" << std::endl;
	std::cout << "--(1) Exit" << std::endl;
	std::cout << "--(2) Start test" << std::endl;
	std::cout << "--(3) View my marks" << std::endl;
}

void Student::startTest(std::string testName)
{
	std::vector<Question*>* tests = editor->getSetOfTests(testName);
	int* answer;
	int size = tests->size();
	int* numbersOrder = randomizeNumbers(size);
	std::vector<int> currentMarks;
	time_t start, end;
	time(&start);
	for (int i = 0; i < size; i++) {
		tests->at(*numbersOrder)->display();
		std::cout << "Enter your answer: ";
		std::cin >> *answer;
		if (*answer == Exit) {
			user->Exit();
			return;
		}
		if (tests->at(*numbersOrder)->checkAnswer(answer))
			currentMarks.push_back(1);
		else currentMarks.push_back(0);
	}
	time(&end);
	studentAnswerData answers(end - start, transformOrder(&currentMarks, numbersOrder));
	studentAnswers->addStudentAnswer("UnknownGuy", testName, answers);
}

void Student::viewMarks()
{
	enum viewMarkActions {
		Exit = 1
	};
	int size = editor->nameOfTests.size();
	for (int i = 0; i < size; i++) {
		std::vector<int>* marks = studentAnswers->getStudentAnswers("UnknownGuy", editor->nameOfTests[i]).marks;
		if (marks) {
			std::cout << editor->nameOfTests[i] << " (" << sumOfMarks(marks) << "): ";
			printMarks(marks);
			std::cout << std::endl;
		}
	}
	int choose = 0;
	while (choose != Exit) {
		std::cout << "--(" << Exit << ") Exit" << std::endl;
		std::cin >> choose;
	}
}

int Student::sumOfMarks(std::vector<int>* marks)
{
	int sum = 0;
	for (int i = 0; i < marks->size(); i++) {
		sum += marks->at(i);
	}
	return sum;
}

int Student::chooseTest()
{
	//enum choosetestActions {
	//	Nothing = -1,
	//	Exit = 1,
	//	Return
	//};

	std::cout << "Choose test:" << std::endl;
	std::cout << "--(" << Exit << ") Exit" << std::endl;
	std::cout << "--(" << Return << ") Return" << std::endl;
	if (editor->nameOfTests.size() == 0) { 
		std::cout << "There's nothing here :(" << std::endl;
	} else for (int i = 0; i < editor->nameOfTests.size(); i++) {
		std::cout << "--(" << i + 3 << ") " << editor->nameOfTests[i]<<std::endl;
	}
	int userChoice;
	std::cin >> userChoice;
	if (userChoice == Exit) {
		user->Exit();
		return Nothing;
	}
	if (userChoice == Return)
		return Nothing;
	if (userChoice > editor->nameOfTests.size() + 3 || userChoice < 1) {		
		return chooseTest();
	}
	return userChoice - 3;
}

void Student::chooseAction(int action)
{
	int choise;
	switch (action) {
	case Exit:
		user->Exit();
		break;
	case StartTest:
		choise = chooseTest();
		if (choise == Nothing)
			return; 
		startTest(editor->nameOfTests[choise]);
		break;
	case ViewMyMarks:
		viewMarks();
		break;
	}
}

void Student::activate(Editor* editor, StudentAnswers* studentAnswers, User* user)
{
	this->editor = editor;
	this->studentAnswers = studentAnswers;
	this->user = user;

	showActions();
	int action;
	std::cin >> action;
	chooseAction(action);
}
