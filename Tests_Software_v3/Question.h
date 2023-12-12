#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Answer.h"
enum type_of_test {
    SINGLE_CHOISE, // equal 0
    MULTIPLE_CHOISE, // equal 1
    MATCHING_CHOISE // equal 2
    // Add other types of tests
};

class Question
{
    std::string questionText;
    std::vector<Answer> answers;
public:
    Question(const std::string& questionText) : questionText(questionText) {}

    const std::string& getQuestionText() const;
    virtual void addAnswer(char option, const std::string& text, bool isCorrect);
    const std::vector<Answer>& getAnswers() const;
    virtual void display() const;
    bool checkAnswer(char userAnswer) const;
    virtual ~Question() {}
};

