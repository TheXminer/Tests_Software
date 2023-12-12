#pragma once
#include <string>
class Pair
{
    char leftOption;
    std::string left;
    char rightOption;
    std::string right;

public:
    Pair(char leftOption, const std::string& left, char rightOption, const std::string& right) : leftOption(leftOption), left(left), rightOption(rightOption), right(right) {}

    char getLeftOption() const;
    const std::string& getLeft() const;
    char getRightOption() const;
    const std::string& getRight() const;
};

