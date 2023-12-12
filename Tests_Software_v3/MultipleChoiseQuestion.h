#pragma once
#include "Question.h"
class MultipleChoiseQuestion :
    public Question
{
public:
    Question::Question;
    void display() const override;
};

