#include "Dealer.h"
Dealer* Dealer::sInstance = nullptr;

Dealer::Dealer()
{
	mCards = std::vector<Card*>();
}

void Dealer::GenerateDeck(int AmountOfDecks)
{
	for (int i = 0; i < AmountOfDecks * 4; i++)
	{
		Suit suit = Suit::UNDEFINED;
		switch (i % 4)
		{
		case 0:
			suit = Suit::Heart;
			break;
		case 1:
			suit = Suit::Diamond;
			break;
		case 2:
			suit = Suit::Club;
			break;
		case 3:
			suit = Suit::Spade;
			break;
		default:
			suit = Suit::UNDEFINED;
			break;
		}

		for (int j = 0; j < 13; j++)
		{
			Card* card = new Card((j > 9 ? 9 : j) + 1, suit);					/// ensure this is deleted in the destructor.
			mCards.push_back(card);
			std::cout << card->GetValue() << " of " << card->GetSuit() << std::endl;
		}
	}
}

void Dealer::RemoveCardFromDeck(int index)
{
	delete mCards[index];
}

Card& Dealer::PullCard()
{
	int deckLength = mCards.size() - 1;
	int cardIndex = (rand() % deckLength) + 1;
	Card& card = *mCards[cardIndex];
	RemoveCardFromDeck(cardIndex);
	return card;
}
