#include "player.h"
#include "Card.h"
#include <iostream>
using namespace std;

// Precondition: Player must exist.
// Postcondition: Returns the size vector of the hand. 

int Player::getHandSize() {
		if(hand.empty()){
			HandSize = 0;
		} else {
			HandSize = hand.size();
		}
		cout<< "Your handsize is " << HandSize;
		return HandSize;
	}

// Precondition: Must access the name variable of the player at the current index.
// Postcondition: Returns a string of the player's name.
string Player::getName(){
	return name;
}

// Precondition:
// Postcondition: Returns the card played
Card Player::playCard(){
	cout << "Your hand includes " << endl;
	cardIndex = hand.size();

	for(int i = 0; i < cardIndex; i++){
		cout << i + 1 << " " << hand[i].name() << endl;
	}
	bool check = false;
	while(check == false){
	cin >> cardIndex;
	cardIndex--;
	if(cardIndex > hand.size()){
		check = false;
		cout << "Please put in a correct value between 1 and " << hand.size()-1 ;
	} else {
		check = true;
	}
}
	return hand[cardIndex]; //(A variable needs to be passed to this function so that it gives JUST the last card and not the whole hand)
}

// Precondition:
// Postcondition: A card from the deck is added to the player's hand. 
void Player::drawCard(Card addCard){
	Player::hand.push_back(addCard);
}