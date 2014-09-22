#include "GameMao.h"
#include <iostream>
using std::cout;
using std::endl;



// Precondition: Function must be passed a card.
// Postcondition: Returns true or false.
bool GameMao::checkLegalMove(Card x)
{
	Card topCard = lastCard();

	//For testing purposes, set true;
	//return true;

	if(topCard.getValue() != jack && x.getValue() == jack)
		return true;

	if(topCard.getValue() == jack && x.getValue() != jack && drawTwoCount == 0)
		return true;

	if(drawTwoCount > 0)
		if(x.getValue() == seven || x.getValue() == jack)
			return !(topCard.getValue() == jack && x.getValue() == jack);

	if((drawTwoCount == 0) && (topCard.getSuit() == x.getSuit() || topCard.getValue() == x.getValue()))
		return !(topCard.getValue() == jack && x.getValue() == jack);

	return false;
}

// Precondition: The deck must be empty.
// Postcondition: If refills the deck.
void GameMao::shuffle()
{
	cout << "The deck has been shuffled." << endl;
	return;
}

//Precondition: ---
//Postcondition: Adds the cards to the deck, shuffles them, gives 7 cards to players
//places a card in the discard and runs the card's function (unless it is a two)
void GameMao::deal()
{
	return;
}


// Precondition: The player's turn has ended.
// Postcondition: Returns true or false.
bool GameMao::winCondition(Player y)
{
	return (y.getHandSize() == 0);
}

// Precondition: 
// Postcondition: Returns the last card in the discard pile.
Card GameMao::lastCard()
{
	return discard[discard.size()-1];
}


// Precondition: Something "special" has happened (e.g. the player has laid down a 2 and must be prompted to lay down another card)
// Postcondition: There are multiple outcomes.
void GameMao::cardFunction(Card x)
{
	switch(x.getValue())
	{

	case deuce:
		if (reverse == true)
		{
			playerTurn++;
			if (unsigned(playerTurn) > players.size())
				playerTurn = 0;
		}
		else
		{
			playerTurn--;
			if(playerTurn < 0)
				playerTurn = players.size();
		}
		return;
	case seven:
		drawTwoCount++;
		return;
	case eight:
		if(reverse)
			reverse = false;
		else
			reverse = true;
		return;
	case jack:
		if (drawTwoCount == 0)
		{
			//Wild function
			//As of right now, the next player gets to play any card.
		}
		else
		{
			drawTwoCount++;
		}
		return;
	case ace:
		if (reverse == true)
		{
			playerTurn--;
			if(playerTurn < 0)
				playerTurn = players.size();
		}
		else
		{
			playerTurn++;
			if (unsigned(playerTurn) > players.size())
				playerTurn = 0;
		}
		return;
	}

	return;
}

// Precondition: It is time for a player's turn to start. Function must be passed a player object.
// Postcondition: The player's turn has ended. Prints the player's hand size.
void GameMao::playerPlay(Player& y)
{
	cout << "It is your turn " << y.getName() << "." << endl;
	Card cardSelect = y.playCard();
	if (checkLegalMove(cardSelect))
	{
		y.getHand().erase(y.getHand().begin() + findCardIndex(y, cardSelect));

		discard.push_back(cardSelect);
		cardFunction(cardSelect);
		cout << y.getName() << " has played " << cardSelect.name() << endl;
	}
	else
	{
		cout << "You can't do that, ";
		Card topCard;
		if (drawTwoCount > 0)
		{
			cout << "take " << drawTwoCount * 2 << " cards.";
			for(int i = 0; i < drawTwoCount * 2; i++)
			{
				topCard = deck[deck.size()-1];
				if(deck.size() == 0)
					shuffle();
				y.drawCard(topCard);
				deck.pop_back();
			}
			drawTwoCount = 0;
		}
		else
		{
			if(deck.size() == 0)
				shuffle();
			cout << "take a card";
			topCard = deck[deck.size()-1];
			y.drawCard(topCard);
			deck.pop_back();
		}
		cout << endl;
	}

	cout << y.getName() << " has " << y.getHandSize() << " cards now." << endl << endl;
	return;
}

//
vector<Player>& GameMao::getPlayerVec()
{
	return players;
}

void GameMao::addPlayer(Player y)
{
	players.push_back(y);
}

bool GameMao::getReverse()
{
	return reverse;
}

int GameMao::findCardIndex(Player& y, Card x)
{

	for(unsigned int i = 0; i < y.getHand().size(); i++)
		if (y.getHand()[i].name() == x.name())
			return i;
	return 0;
}

int GameMao::getPlayerTurn()
{
	return playerTurn;
}

void GameMao::changeTurn()
{
	if(reverse)
		{
			playerTurn--;
			if(playerTurn < 0)
				playerTurn = players.size()-1;
		}
		else
		{
			playerTurn++;
			if (unsigned(playerTurn) > players.size()-1)
				playerTurn = 0;
		}
	return;
}

void GameMao::cardsInDeck()
{
	cout << "There are " << deck.size() << " cards in the deck." << endl << endl;
	return;
}

void GameMao::noCardsInHand(Player& y)
{
	if(deck.size() == 0)
		shuffle();

	Card topCard = deck[deck.size()-1];
	y.drawCard(topCard);
	cout << "Oh, looks like you need a card " << y.getName() << "." << endl;
	deck.pop_back();
}
