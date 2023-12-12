#pragma once
#include "Question.h"
class MultipleCoiseTest :
    public Question
{
public:
    Question::Question;
    void display() const override
    {
        Question::display();
        std::cout << "Type: " << MULTIPLE_CHOISE << std::endl;
    }
};

