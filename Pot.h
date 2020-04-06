#pragma once
#ifndef POT_H
#define POT_H


class Pot
{
private:
	int potAmount;
	//float splitVal;
public:
	Pot()
	{
		potAmount = 0;
	}
	bool addAmt(int bet)
	{
		potAmount += bet;
		return true;
	}
	bool resetPot()
	{
		potAmount = 0;
	}
	~Pot()
	{
		potAmount = 0;
	}
};



#endif // !POT_H
