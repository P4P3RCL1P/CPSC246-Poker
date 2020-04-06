#pragma once
#ifndef BALANCE_H
#define BALANCE_H

class Balance
{
private:
	int amount;
public:
	Balance()
	{
		amount = 1000;
	}
	bool addBal(int addAmt)
	{
		amount += addAmt;
		return true;
	}
	bool removeBal(int remBal)
	{
		if (amount > remBal)
		{
			amount -= remBal;
		}
		return true;
	}
	int getBalance()
	{
		return amount;
	}
	~Balance()
	{
		amount = 0;
	}
};


#endif // !BALANCE_H
