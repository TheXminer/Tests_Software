#include "Question.h"

int Question::checkAnswer(int* answerNumber) const
{
    if(allAnswers[*answerNumber-1].checkIsCorrect())
        return mark;
    return 0;
}

void Question::display() const
{
    std::cout << question << std::endl;
    for (int i = 0; i < allAnswers.size(); i++) {
        std::cout << allAnswers[i].getAnswer() << std::endl;

    }
}

void Question::enterQuestion() const
{

}
