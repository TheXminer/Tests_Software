#include "SingleChoiseQuestion.h"

void SingleChoiceQuestion::display() const
{
    Question::display();
    std::cout << "Type: " << SINGLE_CHOISE << std::endl;
}
