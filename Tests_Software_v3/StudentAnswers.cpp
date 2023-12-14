#include "StudentAnswers.h"

bool StudentAnswers::addStudentAnswer(std::string studentName, std::string nameOfTest, std::vector<int>* marks)
{
	try {
		if (studentAnswers.at(studentName)->count(nameOfTest) != 0)
			return false;
		studentAnswers.at(studentName)->insert({ nameOfTest, marks });
		return true;
	}
	catch (const std::exception& e) {
		std::unordered_map<std::string, std::vector<int>*>* map = new std::unordered_map<std::string, std::vector<int>*>;
		map->insert({ nameOfTest, marks });
		studentAnswers.insert({ nameOfTest, map });
		studentsNames.push_back(studentName);
	}
}

std::vector<int>* StudentAnswers::getStudentAnswers(std::string studentName, std::string nameOfTest)
{
	try {
		return studentAnswers.at(studentName)->at(nameOfTest);
	}
	catch (const std::exception& e) {
		return nullptr;
	}
}

bool StudentAnswers::isTestPassed(std::string studentName, std::string nameOfTest)
{
	try {
		std::vector<int>* marks = studentAnswers.at(studentName)->at(nameOfTest);
		return true;
	}
	catch (const std::exception& e) {
		return false;
	}
}

bool StudentAnswers::deleteStudentAnswers(std::string studentName, std::string nameOfTest)
{
	try {
		studentAnswers.at(studentName)->erase(nameOfTest);
		return true;
	}
	catch (const std::exception& e) {
		return false;
	}
}
