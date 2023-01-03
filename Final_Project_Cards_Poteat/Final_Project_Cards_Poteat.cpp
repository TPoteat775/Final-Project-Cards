// Final_Project_Cards_Poteat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Tiana Poteat

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//Global Constants
const string RANKS[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" }; //13 Values in this array (0-12)
const string SUITS[] = { "Spades", "Hearts", "Diamonds", "Clubs" }; //4 values in this array (0-3);
const int DECK_SIZE = 52;

//Structs
struct Players {
	string playerName;
	vector<int> cards;
};

//Fuctions
vector<int> unWrap(); //This one doesn't need parameters but must return a value
vector<int> shuffle(vector<int>); //This one has parameters and returns them shuffled
vector<int> deal(vector<int>, int);//This one will take the deck and return 13 cards to each player
bool showHand(string, vector<int>); //This one will return true for whoever has the Ace of Spades

int main()
{
	srand(time(0));

	Players cardplayers[4];

	cardplayers[0].playerName = "Christina Clark"; cardplayers[1].playerName = "Louise Lewis"; 
	cardplayers[2].playerName = "Michael Mitchell"; cardplayers[3].playerName = "Jason James";

	int counter = 0, position = -1;
	bool found = false;
	
	vector<int> deckOfCards = unWrap();

	//Shuffles the cards
	deckOfCards = shuffle(deckOfCards);

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++) {
			//Deals cards to players
			cardplayers[j].cards = deal(deckOfCards, counter);
		}
		counter += 13;

		//Search for the Ace of Spades
		found = showHand(cardplayers[i].playerName, cardplayers[i].cards);
		if (found == true) {
			position = i;//Saves who has the Ace of Spades
		}	
	}

	cout << "\n" << cardplayers[position].playerName << " has the Ace of Spades." << "\n";
}

vector<int> unWrap() {
	vector<int> deck;

	// Store the integers 0 to 51 in the vector
	for (int i = 0; i < DECK_SIZE; i++) {
		deck.push_back(i);
	}
	return deck;
}

vector<int> shuffle(vector<int> deck) {
	// Shuffle the values within the vector
	for (int i = 0; i < DECK_SIZE; i++) {
		int r = i + (rand() % (DECK_SIZE - i));
		swap(deck[i], deck[r]);
	}
	return deck;
}

vector<int> deal(vector<int> deck, int counter) {
	vector<int> playerscards;

	// Stores 13 within the vector 0-12
	for (int i = 0; i < 13; i++) {
		playerscards.push_back(i);
	}

	// Returns 13 cards to each player
	for (int i = 0; i < 13; i++) {
		playerscards[i] = deck[counter];
		counter++;
	}
	return playerscards;
}

bool showHand(string name, vector<int> cards) {
	cout << "\n" << name << " holds: \n";

	for (int i = 0; i < 13; i++) {
		cout << RANKS[cards[i] % 13] << " of " << SUITS[cards[i] / 13] << "\n";
	}

	//Searches for Ace of Spades
	for (int i = 0; i < 13; i++) {
		if (RANKS[(cards[i]) % 13] == "Ace" && SUITS[(cards[i]) / 13] == "Spades") {
			return true;
		}
	}
	return false;
	
}


