#include "player.h"
#include "Card.h"
#include <iostream>

// Precondition: Player must exist.
// Postcondition: Returns the size vector of the hand. Returns -1 if hand is undefined.

int Player::getHandSize() {
		if(hand.empty()){
			Player::HandSize = -1;
		} else {
			Player::HandSize = hand.size();
		}
		return HandSize;
	}

// Precondition: Must access the name variable of the player at the current index.
// Postcondition: Returns a string of the player's name.

string Player::getName(vector<int> player, int playerNum){
	Player::name = player[playerNum-1];  //I assume that playerNum will be 2, 3, or 4 for easy cout in the game
	return name;
}

// Precondition:
// Postcondition: Returns the card played
Card Player::playCard(int cardIndex){
	return hand[cardIndex]; //(A variable needs to be passed to this function so that it gives JUST the last card and not the whole hand)
}

// Precondition:
// Postcondition: A card from the deck is added to the player's hand. 
void Player::drawCard(Card addCard){
	Player::hand.push_back(addCard);
}