#pragma once
#include "Question.h"
#include "Pair.h"
class MatchingQuestion :
    public Question
{
    std::vector<Pair> pairs;
public:
    using Question::Question;
    void addPair(char leftOption, const std::string& left, char rightOption, const std::string& right);
    void display() const override;
    bool checkAnswer(char leftOption, char rightOption) const;
};

