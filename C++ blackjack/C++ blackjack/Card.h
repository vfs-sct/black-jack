#pragma once
#include "iostream"

enum class Suit
{
	Heart,
	Diamond,
	Club,
	Spade,
	UNDEFINED
};

inline std::ostream& operator<<(std::ostream& OutputStream, const Suit& InSuit)
{
	switch (InSuit)
	{
	case Suit::Heart:
		OutputStream << "Hearts";
		break;
	case Suit::Diamond:
		OutputStream << "Diamonds";
		break;
	case Suit::Club:
		OutputStream << "Clubs";
		break;
	case Suit::Spade:
		OutputStream << "Spades";
		break;
	default:
		OutputStream << "Undefined";
		break;
	}
	return OutputStream;
}

class Card
{
public:
	Card(int InValue, Suit InSuit);
	~Card();
	int GetValue() const;
	Suit GetSuit() const;
private:
	Card() = delete;
	int mValue;
	Suit mSuit;
};

