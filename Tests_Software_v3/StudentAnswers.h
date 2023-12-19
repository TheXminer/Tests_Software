#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

struct studentAnswerData {
	time_t usedTime;
	std::vector<int>* marks;
	studentAnswerData() :usedTime(0), marks(nullptr) {}
	studentAnswerData(time_t usedTime, std::vector<int>* marks) : usedTime(usedTime), marks(marks) {}
	~studentAnswerData() {
		delete marks;
	}
};

class StudentAnswers
{
	std::unordered_map<std::string, std::unordered_map<std::string, studentAnswerData>*> studentAnswers;
public:
	std::vector<std::string> studentsNames;
	bool addStudentAnswer(std::string studentName, std::string nameOfTest, studentAnswerData marks);
	studentAnswerData getStudentAnswers(std::string studentName, std::string nameOfTest);
	bool isTestPassed(std::string studentName, std::string nameOfTest);
	bool deleteStudentAnswers(std::string studentName, std::string nameOfTest);
};

