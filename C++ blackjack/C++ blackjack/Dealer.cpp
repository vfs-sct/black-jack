#include "Dealer.h"
Dealer* Dealer::sInstance = nullptr;

// initializes the mCards collection
Dealer::Dealer()
{
	mCards = std::vector<Card*>();
}

// deletes every card from the mCards collection.
Dealer::~Dealer()
{
	for (int i = 0; i < mCards.size(); i++)
	{
		delete mCards[i];
	}
}

// generates decks of cards, for every one deck 52 cards is generated. 
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
			Card* card = new Card((j > 9 ? 9 : j) + 1, suit);
			mCards.push_back(card);
		}
	}
}

// does not delete the memory, only the card from the deck
void Dealer::RemoveCardFromDeck(int index)
{
	mCards.erase(mCards.begin() + index);
}

// retuns a refernce to a card
Card& Dealer::PullCard()
{
	int deckLength = mCards.size() - 1;
	int cardIndex = (rand() % deckLength) + 1;
	Card& card = *mCards[cardIndex];
	RemoveCardFromDeck(cardIndex);
	return card;
}
