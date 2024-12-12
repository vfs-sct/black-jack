#include "Utils.h"

class Player
{
public:
	Player()
	{
		srand(time(NULL));
	}

	int GetCard()
	{
		return (rand() % 13) + 1; // return 1 - 13
	}

	void PlayerChoice()
	{
		EMPTY_LN;
		LOG_LN("Are you going to get a new Card?");
		INPUT("yes or no: ", mPlayerChoice);
		if (mPlayerChoice == "yes")
		{
			int newCard = GetCard();
			SetPlayerCards(newCard);
			LOG_LN("Your new card is: " << newCard);
			LOG_LN("Your new sum is: " << mPlayerCards);
			PlayerChoice();
		}
		else if (mPlayerChoice == "no")
		{
			LOG_LN("no");
		}
		else
		{
			LOG_LN("retry");
			PlayerChoice();
		}
	}

	void PrintPlayerCards()
	{
		LOG_LN("Player's card: " << mPlayerCards);
	}

	int SetPlayerCards(int newCard)
	{
		mPlayerCards = mPlayerCards + newCard;
		return mPlayerCards;
	}

private:
	int mPlayerCards = 0;
	String mPlayerChoice;
};

class AI
{
public:
	void PrintAICards()
	{
		LOG_LN("AI's card: " << mAICards);
	}

	int SetAICards(int newCard)
	{
		mAICards = mAICards + newCard;
		return mAICards;
	}

private:
	int mAICards = 0;
};

class Cards
{
public:
	Cards()
	{
		srand(time(NULL));
	}

	int GetCard()
	{
		return (rand() % 13) + 1; // return 1 - 13
	}

private:
	int mCards;
};

int main()
{
	Player player;
	AI ai;
	Cards decks;

	player.SetPlayerCards(decks.GetCard());
	ai.SetAICards(decks.GetCard());

	// print cards
	player.PrintPlayerCards();
	ai.PrintAICards();

	player.PlayerChoice();
	return 0;
}