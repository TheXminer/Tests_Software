#pragma once
#include <string>

class Answer
{
    int number;
    std::string answerText;
    bool isTrue;
public:
    Answer() : number(0), answerText(""), isTrue(false){}
    Answer(int number, std::string answerText, bool isTrue) :number(number), answerText(answerText), isTrue(isTrue) {};
    std::string getAnswer() const;
    bool checkIsCorrect() const;
    int getNumber() const;
};

