#include "Card.h"

Card::Card(int InValue, Suit InSuit)
{
    mValue = InValue;
    mSuit = InSuit;
}

int Card::GetValue() const
{
    return mValue;
}

Suit Card::GetSuit() const
{
    return mSuit;
}

Card::~Card()
{
    std::cout << "Card Destroyed " << mValue << " of " << mSuit << std::endl;
    mValue = 0;
    mSuit = Suit::UNDEFINED;
}
