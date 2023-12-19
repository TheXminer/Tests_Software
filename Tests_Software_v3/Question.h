#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "Answer.h"
enum type_of_test {
    SINGLE_CHOISE, // equal 0
    MULTIPLE_CHOISE, // equal 1
    MATCHING_CHOISE // equal 2
    // Add other types of tests
};

class Question
{
    int mark;
    std::string question;
    std::vector<Answer> allAnswers;
public:
    virtual int checkAnswer(int* answer) const;
    virtual void display() const;
    virtual void enterQuestion() const;
};

