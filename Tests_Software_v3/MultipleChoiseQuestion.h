#pragma once
#include "Question.h"
class MultipleChoiceQuestion : public Question
{
public:
    using Question::Question;
    int checkAnswer(std::vector<int> answers) const;
    bool fullAnswers();
    int checkEnterQuestion();
    void display();
    void viewTest() const;
};

