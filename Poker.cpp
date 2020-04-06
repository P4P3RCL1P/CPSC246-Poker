#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Balance.h"
#include "Player.h"
#include "Bot.h"
#include "Pot.h"
using namespace std;




int main()
{	
	//int botAmount;
	//Array of hands?
	//cout << "How many bots would you like? ( 1-4 )" << endl;
	//cin >> botAmount;
	int playerCount = 4;
	int dealerStart;
	int count = 0;
	int amount = 0;
	bool roundGoing = true;
	string userTurn = "";
	Pot pot;
	vector<Player> players;
	srand(time(0));

	for (count; count < playerCount; count++)
	{
		players.push_back(Player());
	}

	dealerStart = rand() % playerCount;
//***** Fix this to jump to back of array if going below 0
	players[dealerStart].toggleDealer();
	players[dealerStart - 1].toggleSmallBlind();
	players[dealerStart - 2].toggleBigBlind();

	for (count = 0; count < players.size(); count++)
	{
		players[count].drawCard;
		players[count].drawCard;
	}
	do {
		for (count = 0; count < players.size(); count++)
		{
			//consider bot starting, count will not start at 0, maybe reassign array 
			//only difference between bot and player is that bot will auto-enter inputs and player enters through UI
			cout << "Enter user turn";
			cin >> userTurn;
			if (userTurn == "CHECK")
			{
				//move on
			}

			else if (userTurn == "BET")
			{
				cin >> amount;
				players[count].placeBet(amount);
				pot.addAmt(amount);
				//move on
			}
			else if (userTurn == "CALL")
			{
				cin >> amount;
				players[count].callBet(amount);
				pot.addAmt(amount);
				//move on
			}
			else if (userTurn == "FOLD")
			{
				players.erase(players.begin() + count);
				//flip cards
				cout << "FOLDED";
				//fast forward round
			}
		}
		//Flip 3 cards on first loop
		//Flip 1 card on second loop
		//Flip 1 card on third loop
		//When cards are flipped, pushback hand vector 
		//Each loop, check hand value, display best hand to player/bot
		//If all hands are played/players fold/bets placed and no more cards to be flipped
		//set roundGoing to false to end the loop
	} while (roundGoing == true);
		//END While loop

		//Compare the vector of hands by their values, determine winner

		if (hand values are equal between mutliple players)
		{
			//distribute evenly between players, unless one has all inned, then do that shit	
		}
		players[winner].addValue(amount);
		pot.resetPot();

		//RESET PLAYER HANDS, KEEP PLAYER BALANCES, GO AGAIN
		//Check if player balances have reached 0, if so, remove them from game
		//If player still has balance, keep playing

	/*Deal cards for amount of players, randomly distribute blinds to 2 adjacent players
	Start with small blind, maybe with a delay to simulate semi realism, still sped up to make game speedy
	Give choices to fold (end round but quick simulate without player)/check (if player already paid "debt"/bet based on hand or by choice if player
	For loop to go through the choices for each player
	Deduct from balance for bets
	Add to balance bets
	Basic checks to see if balances are adquate, players can "All in"
	Each hand evaluates the hand value for each player, showing the players their best hands.
	End of round procedure:
	Check hand values, compare against eachother to determine winners
	If winners tie, split pot
	If only one winner, distribute to winner
	If a player all in, give at most double to that player of what they bet per person left in round, and give rest back to players that lost
	Reset round, keep balances, loop again until player quits, or bots lose all their money
	If a bot loses all chips, kick bot from game and play with 1 less bot */
	

}