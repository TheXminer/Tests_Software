#include "Question.h"

void Question::randomizeAnswersOrder()
{
    srand(time(0));
    int size = allAnswers.size();
    randomizedOrder = new int[size];
    decodeOrder = new int[size];
    for (int i = 0; i < size; i++) {
        randomizedOrder[i] = i;
    }
    //std::random_shuffle(randomizedOrder, randomizedOrder + size);
    for (int i = 0; i < size; i++) {
        decodeOrder[randomizedOrder[i]] = i;
    }
    return;
}

bool Question::fullAnswers()
{
    int iterator = 0;
    while (true) {
        iterator++;
        std::cout << "Answer " << iterator << ": ";
        std::string answer;
        std::cin.ignore();
        getline(std::cin, answer);
        if (answer == "stop")
            break;
        if (answer == "break")
            return false;
        allAnswers.push_back(Answer(iterator, answer));
        //std::cout << "Is it True? (Enter T/F or 1/0, S to stop, B to break): ";
        //char truth;
        //std::cin >> truth;
        //if (truth == 'S')
        //    return true;
        //if (truth == 'B')
        //    return false;
        //if (truth == '1' || truth == 'T')
        //    allAnswers.push_back(Answer(iterator, answer, true));
        //else
        //    
    }
    std::cout << "Choose true answer number:";
    int number = 0;
    while (number < 1 || number > allAnswers.size())
        std::cin >> number;
    correctAnswersIndex.push_back(number - 1);
    return true;
}

int Question::checkAnswer(int answerNumber) const
{
    if (decodeOrder[answerNumber - 1] == correctAnswersIndex[0])
        return mark;
    return 0;
}

int Question::checkEnterQuestion()
{
    int answer;
    std::cout << "Choose answer number: ";
    std::cin >> answer;
    return checkAnswer(answer);
}

void Question::display()
{
    randomizeAnswersOrder();
    std::cout << question << std::endl;
    for (int i = 0; i < allAnswers.size(); i++) {
        std::cout << "\t" << i + 1 << ") " << allAnswers[randomizedOrder[i]].getAnswer() << std::endl;
    }
}

void Question::viewTest() const
{
    std::cout << question << std::endl;
    std::cout << "Mark: " << mark << std::endl;
    for (int i = 0; i < allAnswers.size(); i++) {
        std::cout << "\t" << allAnswers[i].getNumber() << " (";
        if (i == correctAnswersIndex[0])
            std::cout << "T";
        else
            std::cout << "F";
        std::cout << ") " << allAnswers[i].getAnswer() << std::endl;
    }
}

bool Question::enterQuestion()
{
    std::cout << "Enter question:" << std::endl;
    std::cin.ignore();
    getline(std::cin, question);
    std::cout << "Enter mark: ";
    std::cin >> mark;
    std::cout << "Enter available answers (enter '/stop' to stop, '/break' to break):" << std::endl;
    return fullAnswers();
}
