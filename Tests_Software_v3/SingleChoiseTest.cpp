#include "SingleChoiseTest.h"

void SingleChoiceTest::display() const
{
    Question::display();
    std::cout << "Type: " << SINGLE_CHOISE << std::endl;
}
