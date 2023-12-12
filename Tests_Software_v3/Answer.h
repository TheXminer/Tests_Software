#pragma once
#include <string>

class Answer
{
    char option;
    std::string text;
    bool isCorrect;
public:
    Answer(char option, const std::string& text, bool isCorrect) : option(option), text(text), isCorrect(isCorrect) {}
    char getOption() const;
    const std::string& getText() const;
    bool isCorrectAnswer() const;
};

