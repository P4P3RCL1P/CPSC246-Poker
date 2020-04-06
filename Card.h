#pragma once
#ifndef CLASS_H
#define CLASS_H


class Card
{
private:
	int cardVal;
	string cardSuit;
public:
	Card()
	{
		cardVal = 0;
		cardSuit = "NONE";
	}
	Card(string suit, int val)
	{
		cardVal = val;
		cardSuit = suit;
	}
	string getSuit()
	{
		return cardSuit;
	}
	int getCardVal()
	{
		return cardVal;
	}
	bool setSuit(string suit)
	{
		cardSuit = suit;
		return true;
	}
	bool setCardVal(int val)
	{
		cardVal = val;
		return true;
	}
	~Card()
	{
		cardVal = 0;
		cardSuit = "NONE";
	}
};



#endif 
