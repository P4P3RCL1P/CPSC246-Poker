#pragma once
#ifndef DECK_H
#define DECK_H


class Deck
{
private:
	static const int DECKSIZE = 52;
	static const int SUITS = 4;
	static const int VALUES = 13;
	//Card topCard;
	vector<Card> cardDeck;
public:
	Deck()
	{
		for (int count = 0; count < SUITS; count++)
		{
			for (int suitCount = 0; suitCount < VALUES; suitCount++)
			{
				switch (count)
				{
				case 0:
					cardDeck.push_back(Card("DIAMOND", suitCount + 1));
					break;
				case 1:
					cardDeck.push_back(Card("HEART", suitCount + 1));
					break;
				case 2:
					cardDeck.push_back(Card("SPADE", suitCount + 1));
					break;
				case 3:
					cardDeck.push_back(Card("CLUB", suitCount + 1));
					break;
				}
			}
		}
	}
	int getCardsLeft()
	{
		return cardDeck.size();
	}
	Card getTopCard()
	{
		return cardDeck.back();
	}
	void removeTopCard()
	{
		cardDeck.pop_back();
	}
	void shuffleDeck()
	{
		srand(time(0));
		random_shuffle(cardDeck.begin(), cardDeck.end());
	}
	void printDeck()
	{
		for (int count = 0; count < DECKSIZE; count++)
		{
			cout << cardDeck.at(count).getCardVal() << ":" << cardDeck.at(count).getSuit() << endl;
		}
	}
};



#endif // !DECK_H

