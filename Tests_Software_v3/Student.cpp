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
	std::string answer;
	int size = tests->size();
	int* numbersOrder = randomizeNumbers(size);
	std::vector<int> currentMarks;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) {
		tests->at(*numbersOrder)->display();
		std::cout << "Enter your answer: ";
		std::cin >> answer;
		if (answer == "exit") {
			user->Exit();
			return;
		}
		if (tests->at(*numbersOrder)->checkAnswer(answer[0]))
			currentMarks.push_back(1);
		else currentMarks.push_back(0);
	}
	auto end = std::chrono::high_resolution_clock::now();
	studentAnswers->addStudentAnswer("UnknownGuy", testName, transformOrder(&currentMarks, numbersOrder));
	//ADD SAVE TIME
}

void Student::viewMarks()
{
	enum viewMarkActions {
		Exit = 1
	};
	int size = editor->nameOfTests.size();
	for (int i = 0; i < size; i++) {
		std::vector<int>* marks = studentAnswers->getStudentAnswers("UnknownGuy", editor->nameOfTests[i]);
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
	enum choosetestActions {
		Nothing = -1,
		Exit = 1,
		Return
	};

	std::cout << "Choose test:" << std::endl;
	std::cout << "--(" << Exit << ") Exit" << std::endl;
	std::cout << "--(" << Return << ") Return" << std::endl;
	if (editor->nameOfTests.size() == 0) { 
		std::cout << "There's nothing here :(" << std::endl;
	} else for (int i = 0; i < editor->nameOfTests.size(); i++) {
		std::cout << "--(" << i + 3 << ") " << editor->nameOfTests[i]<<std::endl;
	}
	int userChoose;
	std::cin >> userChoose;
	if (userChoose == Exit) {
		user->Exit();
		return Nothing;
	}
	if (userChoose == Return)
		return Nothing;
	if (userChoose > editor->nameOfTests.size() + 3 || userChoose < 1) {		
		return chooseTest();
	}
	return userChoose - 3;
}

void Student::chooseAction(int action)
{
	enum studentActions {
		Nothing = -1,
		Exit = 1,
		StartTest,
		ViewMyMarks,
	};
	int choose;
	switch (action) {
	case Exit:
		user->Exit();
		break;
	case StartTest:
		choose = chooseTest();
		if (choose == Nothing)
			return; 
		startTest(editor->nameOfTests[choose]);
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
