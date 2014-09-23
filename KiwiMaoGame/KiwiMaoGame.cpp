// KiwiMaoGame.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <windows.h>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include "GameMao.h"

//Min and Max number of players that can play
const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;

int main()
{
	cout << "Welcome to Mao: Kiwi Style!" << endl;
	//Initializes amount of players for the game
	int numPlayer = 0;
	bool validInput;
	while(numPlayer < MIN_PLAYERS || numPlayer > MAX_PLAYERS)
	{
		do{
			cout << "How many players?" << endl;
			validInput = cin >> numPlayer;
			if(!validInput)
			{  
			  cin.clear();
			  while( cin.get() != '\n' );
			}

			cout << endl;
		}while(!validInput);

		if (numPlayer < MIN_PLAYERS)
		{
			//cout << "That number is invalid" << endl;
			cout << "No friends? You must be homeschooled. LOL" << endl;
			Sleep(1600);
			cout << "Clap...";
			Sleep(1000);
			cout << "Clap...";
			Sleep(1000);
			cout << "Clap..." << endl;
			Sleep(1000);
			cout << "BTW: We're all homeschooled." << endl;
			Sleep(1000);
		}
		else if (numPlayer == 52)
		{
			cout << "Congratulations! I've delt every player a single card and now we don't have anything left to start with." << endl;
			cout << "The only forseeable option is playing Rock Paper Scissors to determine who gives up a card..." << endl;
		}
		else if (numPlayer > 53)
		{
			cout << "Really?! How do you expect me to deal 52 cards across " << numPlayer << " players..?" << endl;
		}
		else if (numPlayer > MAX_PLAYERS)
		{
			cout << "Too many players (MAX: " << MAX_PLAYERS << ")" << endl;
		}
		cout << endl;
	}

	//Initializing a game and adding players
	GameMao kiwiGame;
	string enterName;
	for(int i = 0; i < numPlayer; i++)
	{
		//Checks for double name...
		bool doubleName = false;
		do
		{
			doubleName = false;
			cout << "Enter the name of Player " << i+1 << ": ";
			cin >> enterName;

			//This loop prevents the user from inputting the same name twice (different CAPS is okay though)
			if(kiwiGame.getPlayerVec().size() > 0)
			for(unsigned int k = 0; k < kiwiGame.getPlayerVec().size(); k++)
			{
				if(enterName == kiwiGame.getPlayerVec()[k].getName())
				{
					cout << "That name has already been used..." << endl << endl;
					doubleName = true;
					break;
				}
			}

		}while(doubleName);

		Player play(enterName);
		kiwiGame.addPlayer(play);
	}


	//GAME BEGINS!
	int turn = kiwiGame.getPlayerTurn();
    
    //Deals out the cards (once the function is defined)
	kiwiGame.deal();
	cout << endl << "A " << kiwiGame.lastCard().name() << " is placed on the discard." << endl;
	cout << "Let the game begin!" << endl << endl;
	do
	{
	    //Set who goes next
		turn = kiwiGame.getPlayerTurn();

        //Checks if the player has anything in his hand.
		if(kiwiGame.getPlayerVec()[turn].getHandSize() == 0)
		{
		    //Gives him a card because he cannot play
			cout << "You can't end on a two " << kiwiGame.getPlayerVec()[turn].getName() <<  "." << endl;
			kiwiGame.noCardsInHand(kiwiGame.getPlayerVec()[turn]);
		}
		else
		{
		    //Let's the player play a card from their hand
			kiwiGame.playerPlay(kiwiGame.getPlayerVec()[turn]);
		}
		
		//Prints cards in the deck and goes to the next turn
		kiwiGame.cardsInDeck();
		kiwiGame.changeTurn();
		
		//Prints what card is currently on the discard pile
		cout << "::: Card in Play: " << kiwiGame.lastCard().name() << ". :::" << endl;

    //Once someone reaches zero and it is not their turn, exit the loop, they have won!
	}while(!(kiwiGame.winCondition(kiwiGame.getPlayerVec()[turn]) && turn != kiwiGame.getPlayerTurn()));
	
	//Announces winner!
	cout << endl << kiwiGame.getPlayerVec()[turn].getName() << " wins the game!" << endl << endl;

	system("pause");
	return 0;
}
