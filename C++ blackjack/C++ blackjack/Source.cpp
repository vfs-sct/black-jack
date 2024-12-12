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
		while (mPlayerCards <= 21 && mPlayerChoice != "no")
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

	int GetPlayerCards() const
	{
		return mPlayerCards;
	}

private:
	int mPlayerCards = 0;
	String mPlayerChoice;
};

class AI
{
public:
	AI()
	{
		srand(time(NULL));
	}

	int GetCard()
	{
		return (rand() % 13) + 1; // return 1 - 13
	}

	void AIChoice()
	{
		if (mAICards <= 15)
		{
			SetAICards(GetCard());
			AIChoice();
		}
	}

	void PrintAICards()
	{
		LOG_LN("AI's card: " << mAICards);
	}

	int SetAICards(int newCard)
	{
		mAICards = mAICards + newCard;
		return mAICards;
	}

	int GetAICards() const
	{
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
	Cards decks;

	player.SetPlayerCards(decks.GetCard());
	ai.SetAICards(decks.GetCard());

	// print cards
	player.PrintPlayerCards();
	ai.PrintAICards();

	player.PlayerChoice();
	ai.AIChoice();

	EMPTY_LN;
	player.PrintPlayerCards();
	ai.PrintAICards();

	result(player.GetPlayerCards(), ai.GetAICards());
	return 0;
}