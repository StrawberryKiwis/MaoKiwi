#ifndef ___GAMEMAO_H
#define ___GAMEMAO_H

#include <vector>
using std::vector;

//Added random and time.h for generating random numbers
#include <random>
using std::srand;

#include <time.h>

#include "Player.h"
#include "Card.h"

class GameMao
{
public:
	//Added some needed initialization.
	GameMao(int playerTurn = 0, bool reverse = false, int drawTwoCount = 0) : 
		playerTurn(0), reverse(false), drawTwoCount(0) {}
	bool checkLegalMove(Card x);
	void shuffle();
	
	//Added deal() to start the game.
	//Should shuffle all the cards in the deck, give seven to each player
	//and then place one card on the discard pile.
	void deal();
	Card lastCard();
	bool winCondition(Player y);
	void cardFunction(Card x);
	void playerPlay(Player& y);
	vector<Player>& getPlayerVec();
	
	//Adds a player to vector<player> players
	void addPlayer(Player y);
	bool getReverse();
	
	//Locates the card chosen by a player
	int findCardIndex(Player& y, Card x);
	int getPlayerTurn();
	
	//Changes whos turn it is
	void changeTurn();
	
	void noCardsInHand(Player& y);
private:
	int drawTwoCount;
	int playerTurn;
	vector<Card> discard;
	vector<Card> deck;
	vector<Player> players;
	bool reverse;
};

#endif
