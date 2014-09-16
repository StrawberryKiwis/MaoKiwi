#ifndef ___PLAYER_H
#define ___PLAYER_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "card.h"

class Player
{
public:
	int getHandSize();
	string getName();
	Card playCard();
	void drawCard();
private:
	int ID;
	vector<Card> hand;
	string name;
};

#endif
