#include "player.h"
#include <iostream>
using std::cout;

int Player::getHandSize()
{
	return hand.size();
}

void Player::setID(int i)
{
	ID = i;
	return;
}

int Player::getID()
{
	return ID;
}

void Player::setName(string n)
{
	name = n;
	return;
}

string Player::getName()
{
	return name;
}

Card Player::playCard()
{
	Card ballon;
	return ballon;
}
void Player::drawCard()
{
	return;
}
