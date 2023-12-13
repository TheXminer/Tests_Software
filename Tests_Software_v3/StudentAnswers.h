#pragma once
#include <vector>
#include <string>
#include <unordered_map>

class StudentAnswers
{
	std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int>*>*> studentAnswers;
public:
	void addStudentAnswer(std::string studentName, std::string nameOfTest, std::vector<int>* marks);
	std::vector<int>* getStudentAnswers(std::string studentName, std::string nameOfTest);
	bool isTestPassed(std::string studentName, std::string nameOfTest);
};

