#include "MultipleChoiseQuestion.h"

void MultipleChoiseQuestion::display() const
{
    Question::display();
    std::cout << "Type: " << MULTIPLE_CHOISE << std::endl;
}
