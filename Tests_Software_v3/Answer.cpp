#include "Answer.h"

char Answer::getOption() const
{
    return option;
}

const std::string& Answer::getText() const
{
    return text;
}

bool Answer::isCorrectAnswer() const
{
    return isCorrect;
}
