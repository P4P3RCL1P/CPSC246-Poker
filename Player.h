#pragma once
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	//Player variables
	Balance playerBal;
	static int betAmount;
	bool bigBlind;
	bool smallBlind;
	bool dealer;

	//Hand variables
	static Deck cardDeck;
	vector<Card> hand;
	static const int STARTINGCARD = 2;
	int handValue;
public:
	Player()
	{
		bigBlind = false;
		smallBlind = false;
		dealer = false;
		betAmount = 0;


		//Hand variables
		handValue = 0;
		cardDeck.shuffleDeck();

	}
	bool toggleBigBlind()
	{
		if (bigBlind == false)
		{
			bigBlind = true;
			return true;
		}
		else if (bigBlind == true)
		{
			bigBlind = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool toggleSmallBlind()
	{
		if (smallBlind == false)
		{
			smallBlind = true;
			return true;
		}
		else if (smallBlind == true)
		{
			smallBlind = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool toggleDealer()
	{
		if (dealer == false)
		{
			dealer = true;
			return true;
		}
		else if (dealer == true)
		{
			dealer = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	void placeBet(int amt)
	{
		playerBal.removeBal(amt);
		playerBal.getBalance();
	}
	void callBet(int amt)
	{
		playerBal.removeBal(amt);
		playerBal.getBalance();
	}
	void win(int amt)
	{
		playerBal.addBal(amt);
		playerBal.getBalance();
	}
	//Hand methods
	void drawCard()
	{
		hand.push_back(cardDeck.getTopCard());
		cardDeck.removeTopCard();
	}
	int getCardValue(int index)
	{
		return hand[index].getCardVal();
	}
	void printHand()
	{
		for (int count = 0; count < hand.size(); count++)
		{
			cout << hand.at(count).getCardVal() << ":" << hand.at(count).getSuit() << endl;
		}
	}
	void calcHandVal(vector<Card> hand)
	{
		vector<int> cardVals;
		vector<string> cardSuits;
		vector<int> sortedCardVals;
		bool isPair, isTwoPair, isThreeOfKind, isFourOfKind, isStraight, isFlush, isFullHouse, isStraightFlush, isRoyal;
		isPair = false;
		isTwoPair = false;
		isThreeOfKind = false;
		isFourOfKind = false;
		isStraight = false;
		isFlush = false;
		isFullHouse = false;
		isStraightFlush = false;
		isRoyal = false;

		for (int i = 0; i < hand.size(); i++)
		{
			cardVals.push_back(hand[i].getCardVal());
			sortedCardVals.push_back(hand[i].getCardVal());
		}

		for (int i = 0; i < hand.size(); i++)
		{
			cardSuits.push_back(hand[i].getSuit());
		}

		sort(sortedCardVals.begin(), sortedCardVals.end()); //Sorts the sorted cardvals vector

		if (isFourOfKind == false) //checks for 4 of kind
		{
			int fourCount = 0;
			for (int i = 0; i < hand.size(); i++)
			{
				for (int j = 0; j < hand.size(); j++)
				{
					if (cardVals[i] == cardVals[j])
					{
						fourCount++;
					}
				}
				if (fourCount == 4)
				{
					isFourOfKind = true;
				}
			}
		}

		if (isThreeOfKind == false && isFourOfKind == false) // checks for 3 of kind
		{
			int threeCount = 0;
			for (int i = 0; i < hand.size(); i++)
			{
				for (int j = 0; j < hand.size(); j++)
				{
					if (cardVals[i] == cardVals[j])
					{
						threeCount++;
					}
				}
				if (threeCount == 3)
				{
					isThreeOfKind = true;
				}
			}
		}

		if (isPair == false && isThreeOfKind == false && isFourOfKind == false) //checks for pair
		{
			int sameCount = 0;
			int pairCount = 0;
			for (int i = 1; i <= 13; i++)
			{
				for (int j = 0; j < hand.size(); j++)
				{
					if (cardVals[i] == cardVals[j])
					{
						sameCount++;
					}
				}
				if (sameCount == 4)
				{
					isFourOfKind = true;
				}
				if (sameCount == 3 && isFourOfKind == false)
				{
					isThreeOfKind = true;
				}
				if (sameCount == 2 && isFourOfKind == false)
				{
					isPair = true;
					pairCount++;
				}
			}
			if (pairCount <= 2)
			{
				isTwoPair = true;
			}
		}

		if (isStraight == false) //checks for straight
		{
			int straightCount = 0;
			for (int i = 0; i < sortedCardVals.size(); i++)
			{
				if (sortedCardVals[i] == sortedCardVals[i + 1] + 1)
				{
					straightCount++;
				}
			}
			if (straightCount >= 5)
			{
				isStraight = true;
				//return the top card value of the straight
			}
		}

		if (isFlush == false) //checks for flush
		{
			int flushCount = 0;
			for (int i = 0; i < cardSuits.size(); i++)
			{
				if (cardSuits[i] == cardSuits[i + 1])
				{
					flushCount++;
				}
			}
			if (flushCount >= 5)
			{
				isFlush = true;
				//return highest and lowest card of flush
			}
		}

		if (isFullHouse == false)
		{
			if (isPair == true && isThreeOfKind == true)
			{
				isFullHouse = true;
				//get the values for the pair and the 3 of a kind
			}
		}

		if (isStraightFlush == false)
		{
			//PROBLEM: cant use isStraight and isFlush for straight flush because straight is just 5 cards in a row, and flush is any 5 same suit, so have to match them up precisely
			//Check if the card is same suit && next value is the same suit
			//can start with if isStraight and if isFlush but need more to verify
		}

		if (isRoyal == false)
		{

		}
	}
};



#endif // !PLAYER_H
