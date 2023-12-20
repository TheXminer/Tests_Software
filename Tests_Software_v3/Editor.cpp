#include "Editor.h"

bool Editor::deleteTestSetName(std::string nameOfSet)
{
	for (int i = 0; i < nameOfTests.size(); i++) {
		if (nameOfTests[i] == nameOfSet) {
			nameOfTests.erase(nameOfTests.begin() + i);
			setOfTests.erase(nameOfSet);
			return true;
		}
	}
	return false;
}

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
		nameOfTests.push_back(nameOfSet);
		return;
	}
}

void Editor::deleteTest(std::string nameOfSet, int nOfTest) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		if (setOfQuestions->begin() + nOfTest > setOfQuestions->end())
			return;
		setOfQuestions->erase(setOfQuestions->begin() + nOfTest);
		if (setOfQuestions->size() != 0)
			return;
		for (int i = 0; i < nameOfTests.size(); i++) {
			if (nameOfTests[i] == nameOfSet) {
				nameOfTests.erase(nameOfTests.cbegin() + i);
				setOfTests.erase(nameOfSet);
			}
		}
		return;
	}
	catch (const std::exception& e) {
		return;
	}
}

void Editor::editTest(std::string nameOfSet, int nOfTest, Question* question) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		if (setOfQuestions->begin() + nOfTest > setOfQuestions->end())
			return;
		Question* toDelete = setOfQuestions->at(nOfTest);
		setOfQuestions->emplace(setOfQuestions->begin() + nOfTest, question);
		delete toDelete;
	}
	catch (const std::exception& e) {
		return;
	}
}

Question* Editor::getTest(std::string nameOfSet, int nOfTest) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		if (setOfQuestions->begin() + nOfTest > setOfQuestions->end())
			return nullptr;
		return setOfQuestions->at(nOfTest);
	}
	catch (const std::exception& e) {
		return nullptr;
	}
}

std::vector<Question*>* Editor::getSetOfTests(std::string nameOfSet) {
	try {
		std::vector<Question*>* setOfQuestions = setOfTests.at(nameOfSet);
		return setOfQuestions;
	}
	catch (const std::exception& e) {
		return nullptr;
	}
}

void Editor::deleteSetOfTests(std::string nameOfSet) {
	try {
		setOfTests.erase(nameOfSet);
		deleteTestSetName(nameOfSet);
		return;
	}
	catch (const std::exception& e) {
		return;
	}
}
