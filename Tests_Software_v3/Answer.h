#pragma once
#include <string>

class Answer
{
    int number;
    std::string answerText;
public:
    Answer() : number(0), answerText("") {}
    Answer(int number, std::string answerText) :number(number), answerText(answerText) {};
    std::string getAnswer() const;
    int getNumber() const;
};

