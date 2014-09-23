#ifndef ___PLAYER_H
#define ___PLAYER_H

// File:  Player.h
// Date:  9/19/2014
// Class:  COMP 220, Computer Programming II
// Contents:  This player header will hold all the info of the player.
  

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "card.h"

class Player {
public:
	Player(string name = "Ben") : name(name) {}

	// Precondition: Player must exist.
	// Postcondition: Returns the size vector of the hand. Returns -1 if hand is undefined.
	int getHandSize();

	// Precondition: Must access the name variable of the player at the current index.
	// Postcondition: Returns a string of the player's name.
	string getName();

	// Precondition:
	// Postcondition: Returns the card played
	Card playCard();

	// Precondition:
	// Postcondition: A card from the deck is added to the player's hand. 
	void drawCard(Card addCard);

private:
	int cardIndex, HandSize;
	vector<Card> hand;
	string name;
};

#endif
