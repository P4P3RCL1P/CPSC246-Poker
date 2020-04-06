#pragma once
#ifndef BOT_H
#define BOT_H



class Bot
{
private:
	Hand botHand;
	Balance botBalance;
	bool bigBlind;
	bool smallBlind;
	bool dealer;
	bool loosePassive = false;
	bool looseAgressive = false;
	bool tightPassive = false;
	bool tightAgressive = false;
	static int betAmount;
public:
	Bot()
	{
		bigBlind = false;
		smallBlind = false;
		dealer = false;
		betAmount = 0;
	}
	bool toggleBigBlind()
	{
		if (bigBlind = false)
		{
			bigBlind = true;
			return true;
		}
		else if (bigBlind = true)
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
		if (smallBlind = false)
		{
			smallBlind = true;
			return true;
		}
		else if (smallBlind = true)
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
		if (dealer = false)
		{
			dealer = true;
			return true;
		}
		else if (dealer = true)
		{
			dealer = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	Hand drawCard()
	{
		botHand.drawCard();
	}
	int placeBet(int amt)
	{
		botBalance.removeBal(amt);
		botBalance.getBalance();
	}
	int win(int amt)
	{
		botBalance.addBal(amt);
		botBalance.getBalance();
	}
	//bot personality methods?
	void getPersonality()
	{
		switch (rand() % 4)
		{
		case 0:
			loosePassive = true;
			isLoosePassive();
			break;
		case 1:
			looseAgressive = true;
			isLooseAgressive();
			break;
		case 2:
			tightAgressive = true;
			isTightAgressive();
			break;
		case 3:
			tightPassive = true;
			isTightAgressive();
			break;
		}
	}
	void isLoosePassive()
	{
		if (botHand.calcHandVal < 1000)
		{
			//actions for loose passive? idk i don't play poker
		}
	}
	void isLooseAgressive()
	{
		if (botHand.calcHandVal < 1000)
		{
			//actions for loose passive? idk i don't play poker
		}
	}
	void isTightAgressive()
	{
		if (botHand.calcHandVal < 1000)
		{
			//actions for loose passive? idk i don't play poker
		}
	}
	void isTightPassive()
	{
		if (botHand.calcHandVal < 1000)
		{
			//actions for loose passive? idk i don't play poker
		}
	}
};


#endif // !BOT_H
