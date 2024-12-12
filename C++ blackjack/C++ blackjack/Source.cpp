#include "Utils.h"
#include "Dealer.h"
#define DEALER Dealer::GetInstance()


class Player
{
public:
	Player()
	{
		srand(time(NULL));
	}

	// iterates through all the cards in the Player's hand and deletes them.
	~Player()
	{
		for (int i = 0; i < mPlayerCards.size(); i++)
		{
			delete mPlayerCards[i];
		}
	}

	void PlayerChoice()
	{
		while (GetPlayerCardValue() <= 21 && mPlayerChoice != "no")
		{
			EMPTY_LN;
			LOG_LN("Are you going to get a new Card?");
			INPUT("yes or no: ", mPlayerChoice);
			EMPTY_LN;
			if (mPlayerChoice == "yes")
			{
				Card newCard = DEALER->PullCard();
				AddCard(&newCard);
				LOG_LN("Your new card is: " << newCard.GetValue() << " of " << newCard.GetSuit());
				LOG_LN("Your new sum is: " << GetPlayerCardValue());
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
	}

	void PrintPlayerCards()
	{
		for (int i = 0; i < mPlayerCards.size(); i++)
		{
			LOG_LN("You Pulled: " << mPlayerCards[i]->GetValue() << " of " << mPlayerCards[i]->GetSuit());
		}
		LOG_LN("Player Total: " << GetPlayerCardValue());
		EMPTY_LN;
	}

	// Creates a Card on the heap based on the values of the passed card.
	void AddCard(Card* InCard)
	{
		Card* card = new Card(InCard->GetValue(), InCard->GetSuit());
		mPlayerCards.push_back(card);
	}

	int GetPlayerCardValue() const
	{
		int value = 0;
		for (int i = 0; i < mPlayerCards.size(); i++)
		{
			int cardValue = mPlayerCards[i]->GetValue();
			if (value < 10 && cardValue == 1)
			{
				value += 11;
				continue;
			}
			value += mPlayerCards[i]->GetValue();
		}
		return value;
	}

private:
	std::vector<Card*> mPlayerCards;
	String mPlayerChoice;
};

class AI
{
public:
	AI()
	{
		srand(time(NULL));
	}

	// iterates through all the cards in the AI's hand and deletes them.
	~AI()
	{
		for (int i = 0; i < mAICards.size(); i++)
		{
			delete mAICards[i];
		}
	}

	void AIChoice()
	{
		if (GetAICardsValue() <= 15)
		{
			AddCard(&DEALER->PullCard());
			AIChoice();
		}
	}

	void PrintAICards()
	{
		for (int i = 0; i < mAICards.size(); i++)
		{
			LOG_LN("AI Pulled: " << mAICards[i]->GetValue() << " of " << mAICards[i]->GetSuit());
		}
		LOG_LN("AI Total: " << GetAICardsValue());
		EMPTY_LN;
	}

	// Creates a Card on the heap based on the values of the passed card.
	void AddCard(Card* InCard)
	{
		Card* card = new Card(InCard->GetValue(), InCard->GetSuit());
		mAICards.push_back(card);
	}

	int GetAICardsValue() const
	{
		int value = 0;
		for (int i = 0; i < mAICards.size(); i++)
		{
			int cardValue = mAICards[i]->GetValue();
			if (value < 10 && cardValue == 1)
			{
				value += 11;
				continue;
			}
			value += mAICards[i]->GetValue();
		}
		return value;
	}

private:
	std::vector<Card*> mAICards;
};

void result(int player, int ai)
{
	if (player > 21 && ai > 21)
	{
		LOG_LN("both lose no winner");
	}
	else if (player > 21)
	{
		LOG_LN("AI won player's card is over 21");
	}
	else if (ai > 21)
	{
		LOG_LN("Player won ai's card is over 21");
	}
	else if (player > ai)
	{
		LOG_LN("Player won");
	}
	else if (ai > player)
	{
		LOG_LN("AI won");
	}
	else
	{
		LOG_LN("draw");
	}
}

int main()
{
	Player player;
	AI ai;
	DEALER->GenerateDeck(1);

	player.AddCard(&DEALER->PullCard());
	player.AddCard(&DEALER->PullCard());
	ai.AddCard(&DEALER->PullCard());

	// print cards
	player.PrintPlayerCards();
	ai.PrintAICards();

	player.PlayerChoice();
	ai.AIChoice();

	EMPTY_LN;
	player.PrintPlayerCards();
	ai.PrintAICards();

	result(player.GetPlayerCardValue(), ai.GetAICardsValue());
	DEALER->DeleteInstance();
	return 0;
}