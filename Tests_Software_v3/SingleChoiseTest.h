#pragma once
#include "Question.h"

class SingleChoiceTest :
    public Question
{
public:
    Question::Question;

    void display() const override;
};

