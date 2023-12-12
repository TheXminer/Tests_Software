#include "Question.h"

const std::string& Question::getQuestionText() const
{
    return questionText;
}

void Question::addAnswer(char option, const std::string& text, bool isCorrect)
{
    answers.push_back(Answer(option, text, isCorrect));
}

const std::vector<Answer>& Question::getAnswers() const
{
    return answers;
}

void Question::display() const
{
    std::cout << "Question: " << getQuestionText() << std::endl;
    std::cout << "Answers:" << std::endl;

    for (const auto& answer : answers)
    {
        std::cout << "- " << answer.getOption() << ". " << answer.getText() << std::endl;
    }
}

bool Question::checkAnswer(char userAnswer) const
{
    auto it = find_if(answers.begin(), answers.end(),
        [userAnswer](const Answer& answer) { return answer.getOption() == userAnswer; });

    return it != answers.end() && it->isCorrectAnswer();
}
