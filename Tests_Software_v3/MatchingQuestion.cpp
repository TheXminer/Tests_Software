#include "MatchingQuestion.h"

void MatchingQuestion::addPair(char leftOption, const std::string& left, char rightOption, const std::string& right)
{
    pairs.push_back(Pair(leftOption, left, rightOption, right));
}

void MatchingQuestion::display() const
{
    Question::display();
    std::cout << "Type: " << MATCHING_CHOISE << std::endl;
    std::cout << "Pairs:" << std::endl;

    for (const auto& pair : pairs)
    {
        std::cout << "- " << pair.getLeftOption() << ". " << pair.getLeft() << " <-> " << pair.getRightOption() << ". " << pair.getRight() << std::endl;
    }
}

bool MatchingQuestion::checkAnswer(char leftOption, char rightOption) const
{
    auto it = find_if(pairs.begin(), pairs.end(),
        [leftOption, rightOption](const auto& pair)
        {
            return pair.getLeftOption() == leftOption && pair.getRightOption() == rightOption;
        });

    return it != pairs.end();
}
