#include "Answer.h"

std::string Answer::getAnswer() const
{
	return answerText;
}

bool Answer::checkIsCorrect() const
{
	return isTrue;
}

int Answer::getNumber() const
{
	return number;
}
