#pragma once
#include "SetQA.h"
#include <string>
#include <vector>
#include <unordered_set>

class Editor
{
	std::unordered_set<std::string, std::vector<SetQA*>> setOfSets;
public:
	void addTest(SetQA* question);
	void deleteTest(std::string nameOfSet, int nOfTest);
	void editTest(std::string nameOfSet, int nOfTest, SetQA* question);
	Question* getTest(std::string nameOfSet, int nOfTest);
	std::vector<SetQA*> getSetOfTests(std::string nameOfSet, int nOfTest);
};

