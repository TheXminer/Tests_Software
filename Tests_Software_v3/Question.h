#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Answer.h"

enum type_of_test {
    SINGLE_CHOISE, // equal 0
    MULTIPLE_CHOISE, // equal 1
    MATCHING_CHOISE // equal 2
    // Add other types of tests
};

class Question
{
    std::string questionText;
    std::vector<Answer> answers;
public:
    Question(const std::string& questionText) : questionText(questionText) {}

    const std::string& getQuestionText() const
    {
        return questionText;
    }

    virtual void addAnswer(char option, const std::string& text, bool isCorrect)
    {
        answers.push_back(Answer(option, text, isCorrect));
    }

    const std::vector<Answer>& getAnswers() const
    {
        return answers;
    }

    virtual void display() const
    {
        std::cout << "Question: " << getQuestionText() << std::endl;
        std::cout << "Answers:" << std::endl;

        for (const auto& answer : answers)
        {
            std::cout << "- " << answer.getOption() << ". " << answer.getText() << std::endl;
        }
    }

    bool checkAnswer(char userAnswer) const
    {
        auto it = find_if(answers.begin(), answers.end(),
            [userAnswer](const Answer& answer) { return answer.getOption() == userAnswer; });

        return it != answers.end() && it->isCorrectAnswer();
    }

    virtual ~Question() {}
};

