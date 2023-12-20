#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <time.h> 
#include "Answer.h"

class Question
{
protected:
    int mark;
    std::string question;
    int* randomizedOrder = nullptr;
    int* decodeOrder = nullptr;
    std::vector<Answer> allAnswers;
    std::vector<int> correctAnswersIndex;
    void randomizeAnswersOrder();
    virtual bool fullAnswers();
public:
    int checkAnswer(int answer) const;
    virtual int checkEnterQuestion();
    virtual void display();
    virtual void viewTest() const;
    bool enterQuestion();
};

