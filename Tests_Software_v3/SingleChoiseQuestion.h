#pragma once
#include "Question.h"

class SingleChoiceQuestion :
    public Question
{
public:
    Question::Question;

    void display() const override;
};

