#pragma once
#include "Card.h"
#include "vector"

class Card;
/// <summary>
/// This is a singleton Factor class that will control what cards the players and the dealer get.
/// </summary>
class Dealer
{
private:
	Dealer();
	~Dealer();
	// This is going to be the pool of cards, as cards are given to the dealer and players the appropriate cards will be removed from this collection.
	std::vector<Card*> mCards;
	static Dealer* sInstance;
	void RemoveCardFromDeck(int index);
public:
	static Dealer* GetInstance()
	{
		if (sInstance != nullptr)
		{
			return sInstance;
		}
		sInstance = new Dealer();
		return sInstance;
	};
	void CreateInstance()
	{
		if (sInstance != nullptr)
		{
			DeleteInstance();
		}
		sInstance = new Dealer();
	};
	void DeleteInstance()
	{
		delete sInstance;
		sInstance = nullptr;
	};
	void GenerateDeck(int AmountOfDecks);
	Card& PullCard();
};