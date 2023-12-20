#include "MultipleChoiseQuestion.h"

int MultipleChoiceQuestion::checkAnswer(std::vector<int> answers) const
{
	/*for (int i = 0; i < answers.size(); i++)
		if (!allAnswers[answers[i]].checkIsCorrect())
			return 0;*/
    if (answers.size() != correctAnswersIndex.size())
        return 0;
    int size = answers.size();
    for (int i = 0; i < size; i++) {
        bool isContain = false;
        for (int j = 0; j < size; j++) {
            if (correctAnswersIndex[j] == answers[i]) {
                isContain = true;
                break;
            }
        }
        if (!isContain)
            return 0;
    }
	return mark;
}

bool MultipleChoiceQuestion::fullAnswers()
{
    int iterator = 0;
    while (true) {
        iterator++;
        std::cout << "Answer " << iterator << ": ";
        std::string answer;
        std::cin.ignore();
        getline(std::cin, answer);
        if (answer == "/stop")
            return true;
        if (answer == "/break")
            return false;
        std::cout << "Is it True? (Enter T/F or 1/0, S to stop, B to break): ";
        char truth;
        std::cin >> truth;
        if (truth == 'S')
            return true;
        if (truth == 'B')
            return false;
        if (truth == '1' || truth == 'T')
            correctAnswersIndex.push_back(iterator - 1);
        allAnswers.push_back(Answer(iterator, answer));
    }
    return true;
}

int MultipleChoiceQuestion::checkEnterQuestion()
{
    std::cout << "Enter answers numbers (to stop enter '-1'):" << std::endl;
    int curAnswer = 0;
    std::vector<int> enteredAnswers;
    while (true) {
        std::cin >> curAnswer;
        if (curAnswer < 1 || curAnswer > allAnswers.size()) {
            break;
        }
        enteredAnswers.push_back(decodeOrder[curAnswer - 1]);
    }
    return checkAnswer(enteredAnswers);
}

void MultipleChoiceQuestion::display()
{
    Question::display();
}

void MultipleChoiceQuestion::viewTest() const
{
    std::cout << question << std::endl;
    std::cout << "Mark: " << mark << std::endl;
    int j = 0;
    for (int i = 0; i < allAnswers.size(); i++) {
        std::cout << "\t" << allAnswers[i].getNumber() << " (";
        if (j < correctAnswersIndex.size() && i == correctAnswersIndex[j]) {
            std::cout << "T";
            j++;
        }
        else
            std::cout << "F";
        std::cout << ") " << allAnswers[i].getAnswer() << std::endl;
    }
}
