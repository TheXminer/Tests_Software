#include "Question.h"

int Question::checkAnswer(int answerNumber) const
{
    if(allAnswers[answerNumber-1].checkIsCorrect())
        return mark;
    return 0;
}

void Question::display() const
{
    std::cout << question << std::endl;
    for (int i = 0; i < allAnswers.size(); i++) {
        std::cout << "\t" << allAnswers[i].getNumber() << ") " << allAnswers[i].getAnswer() << std::endl;
    }
}

void Question::viewTest() const
{
    std::cout << question << std::endl;
    std::cout << "Mark: " << mark << std::endl;
    for (int i = 0; i < allAnswers.size(); i++) {
        std::cout << "\t" << allAnswers[i].getNumber() << " (" << allAnswers[i].checkIsCorrect() << ") " << allAnswers[i].getAnswer() << std::endl;
    }
}

bool Question::enterQuestion()
{
    std::cout << "Enter question:" << std::endl;
    std::cin.ignore();
    getline(std::cin, question);
    std::cout << "Enter mark: ";
    std::cin >> mark;
    std::cout << "Enter available answers (enter '/stop' to stop, 'break' to break):" << std::endl;
    int iterator = 0;
    while (true) {
        iterator++;
        std::cout << "Answer " << iterator << ": ";
        std::string answer;
        std::cin.ignore();
        getline(std::cin, answer);
        if (answer == "/stop")
            break;
        if (answer == "/break")
            return false;
        std::cout << "Is it True? (Enter T/F or 1/0, S to stop, B to break): ";
        char truth;
        std::cin >> truth;
        if (truth == 'S')
            break;
        if (truth == 'B')
            return false;
        Answer newAnswer;
        if (truth == '1' || truth == 'T')
            allAnswers.push_back(Answer(iterator, answer, true));
        else
            allAnswers.push_back(Answer(iterator, answer, false));
    }
    return true;
}
