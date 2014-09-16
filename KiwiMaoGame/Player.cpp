#include "player.h"
#include <iostream>
using std::cout;

// Precondition: Player must exist.
// Postcondition: Returns the size vector of the hand. Returns -1 if hand is undefined.
int Player::getHandSize()
{
	return hand.size();
}

/* DEPRICATED */
// void Player::setID(int i)
// {
// 	ID = i;
// 	return;
// }

/* DEPRICATED */
// int Player::getID()
// {
// 	return ID;
// }

/* DEPRICATED */
// void Player::setName(string n)
// {
// 	name = n;
// 	return;
// }

// Precondition: Must access the name variable of the player at the current index.
// Postcondition: Returns a string of the player's name.
string Player::getName()
{
	return name;
}

// Precondition:
// Postcondition: Returns the card played
Card Player::playCard()
{
	Card ballon;
	return ballon;
}

// Precondition:
// Postcondition: A card from the deck is added to the player's hand. 
void Player::drawCard()
{
	return;
}
