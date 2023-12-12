#include "Pair.h"

char Pair::getLeftOption() const
{
    return leftOption;
}

const std::string& Pair::getLeft() const
{
    return left;
}

char Pair::getRightOption() const
{
    return rightOption;
}

const std::string& Pair::getRight() const
{
    return right;
}
