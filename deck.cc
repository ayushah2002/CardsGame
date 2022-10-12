#include "deck.h"
//#include "card.h"
//#include <iostream>
#include <algorithm>
using namespace std;

// Deck constructor
// returns: a constructed Deck Object
Deck::Deck(int seed1) : rng{seed1} { //might not need seed
        char allsuits[4] = {'C', 'D', 'H', 'S'};
        for(int j=0; j < 4; ++j) {
                for(int i=1; i <= 13; ++i) {
                        deckOfCards.emplace_back(i, allsuits[j]);
	    	}
        }
}

// returns: the deck of cards in the form of vector of cards
vector<Card> Deck::findDeck() {
    return deckOfCards;
}

// modifies: deckOfCards by shuffling it
void Deck::shuffle() {
	std::shuffle( deckOfCards.begin(), deckOfCards.end(), rng );
}
