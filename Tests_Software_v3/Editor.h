#pragma once
#include "Question.h"
#include <string>
#include <vector>
#include <unordered_map>

class Editor
{
	std::unordered_map<std::string, std::vector<Question*>*> setOfTests;
public:
	void addTest(std::string nameOfSet, Question* question);
	void deleteTest(std::string nameOfSet, int nOfTest);
	void editTest(std::string nameOfSet, int nOfTest, Question* question);
	Question* getTest(std::string nameOfSet, int nOfTest);
	std::vector<Question*>* getSetOfTests(std::string nameOfSet);
};

