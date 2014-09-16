#ifndef ___GAMEMAO_H
#define ___GAMEMAO_H

#include <vector>
using std::vector;

#include "card.cpp"
#include "player.cpp"

class GameMao
{
public:
	bool checkLegalMove(Card x);
	void shuffle();
	void lastCard();
	void playerCardCount();
	bool winCondition(Player y);
	void cardFunction(Card x);
	void playerPlay();
private:
	int drawTwoCount;
	int playerTurn;
	vector<Card> discard;
	vector<Card> deck;
};

#endif
