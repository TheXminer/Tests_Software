#include "Editor.h"

void Editor::addTest(std::string nameOfSet, Question* question) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		setOfQuestions->push_back(question);
		return;
	}
	catch (const std::exception& e) {
		std::vector<Question*>* newSetOfQuestion = new std::vector<Question*>;
		newSetOfQuestion->push_back(question);
		setOfTests.insert({ nameOfSet, newSetOfQuestion });
		return;
	}
}
void Editor::deleteTest(std::string nameOfSet, int nOfTest) {

}
void Editor::editTest(std::string nameOfSet, int nOfTest, Answer* question) {

}
Question* Editor::getTest(std::string nameOfSet, int nOfTest) {
	return nullptr;
}